#include<stdio.h>
#include<queue>
#define MAXSIZE 100
using namespace std;

int arr[MAXSIZE][MAXSIZE];
int uset[MAXSIZE];  // uset[i] :元素i所属集合的根节点
int urank[MAXSIZE]; // urank[i] :元素i为根节点集合的高度
int Kruscal(int);
int res = 0;

struct Edge {
    int x;
    int y;
    int weight;
    Edge(int x,int y,int weight) {
        this->x = x;
        this->y = y;
        this->weight = weight;
    }
    friend bool operator < (Edge edge1, Edge edge2) {
        return edge1.weight > edge2.weight;
    }

};

priority_queue<Edge> q;

int main() {
    int N;
    while(~scanf("%d",&N)) {
        // 输入
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                scanf("%d",&arr[i][j]);
            }
        }
        // 将边放入优先队列中
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                q.push(Edge(i,j,arr[i][j]));
            }
        }
        Kruscal(N);
        printf("%d\n",res);
    }
    return 0;
}

void makeSet(int N) {
    // 初始时每个元素独立成为一个集合，根节点是本身，集合（树）高度为0
    for(int i=0;i<N;i++) {
        uset[i] = i;
        urank[i] = 0;
    }
}

int findRoot(int x) {
    // 只有根节点的父节点是本身
    if(uset[x] == x) {
        return x;
    }
    // 不是根节点递归寻找根节点
    return findRoot(uset[x]);
}

bool unionSet(int x,int y) {
    // 取 x,y 所在集合的根节点
    x=findRoot(x);
    y=findRoot(y);
    // x,y 属于一个集合，不可合并
    if(x == y) {
        return false;
    }
    // x,y 不在同一集合，将高度小的集合加到高度大的集合根节点
    else if(urank[x] > urank[y]) {
        // y 集合的根节点的父亲是 x 集合的根节点
        uset[y] = x;
    } else {
        uset[x] = y;
        // 高度相等，x所在集合根节点接到y集合根节点，y集合高度加一
        if(urank[x] == urank[y]) {
            urank[y]++;
        }
    }
    return true;
}

int Kruscal(int N) {
    makeSet(N);
    int qsize = q.size();
    int lineNum = 0;
    for(int i=0;i<qsize;i++) {
        // e为当前最小权值边
        Edge e = q.top();
        // 按权值降序处理每一条边，如果两点不在一个集合中，合并两点所在的集合返回true，说明生成了一条连线
        if(unionSet(e.x, e.y)) {
            lineNum ++;
            res += arr[e.x][e.y];
            printf("%d--%d\n",e.x,e.y);
            // 连线数 = 点数 - 1 时为最小生成树，结束循环
            if(lineNum == N - 1) {
                break;
            }
        }
        q.pop();
    }
}
/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
*/
