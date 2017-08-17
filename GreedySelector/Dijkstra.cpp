#include<stdio.h>
#include<string.h>
#include<limits.h>
void Dijkstra(int,int,int**,int*,int*);
void show(int,int*,int*);

int main() {
    int N;
    scanf("%d",&N);
    int** arr = new int*[N];
    for(int i=0;i<N;i++) {
        arr[i] = new int[N];
        memset(arr[i],0,N*sizeof(arr));
    }
    // 邻接矩阵存储有向带权图，顶点用1,2...N表示，无边用-1表示
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == -1)
                arr[i][j] = INT_MAX;
        }
    }
    // 源点坐标
    int v;
    scanf("%d",&v);
    // 其他点到源点的距离
    int* dist = new int[N];
    // 其他点到源点的前驱节点坐标
    int* prev = new int[N];
    Dijkstra(v,N,arr,dist,prev);
    for(int i=0;i<N;i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete [] dist;
    delete [] prev;
    return 0;
}

void Dijkstra(int v,int n,int** c,int* dist,int* prev) {
    bool s[n];
    //当S集合中只有源点时各数组的状态
    for(int i=0;i<n;i++) {
        dist[i] = c[v][i];
        s[i] = false;
        if(dist[i] == INT_MAX) {
            prev[i] = 0;
        }
        else {
            prev[i] = v;
        }
    }
    // 将源点添加进S集合中
    dist[v] = 0;
    s[v] = true;
    // 将剩下的n-1个元素添加进集合S中
    for(int i=1;i<n;i++) {
        int u = v;
        int temp = INT_MAX;
        // 计算当前S集合以外到S最小路径的元素
        for(int j=0;j<n;j++) {
            if(!s[j] && dist[j]<temp) {
                temp = dist[j];
                u = j;
            }
        }
        //printf("%d-\n",u);
        // 加入到S中
        s[u] = true;
        // 更新S外的元素最小距离
        for(int j=0;j<n;j++) {
            if(!s[j] && c[u][j]<INT_MAX) {
                int newDist = c[u][j] + dist[u];
                // 判断新距离是否比原距离小
                if(newDist < dist[j]) {
                    dist[j] = c[u][j] + dist[u];
                    prev[j] = u;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        show(i,dist,prev);
        if(dist[i] == INT_MAX)
            printf("\tdist: intmax\n");
        else
            printf("\tdist: %d\n",dist[i]);
    }
}


void show(int i,int* dist,int* prev) {
    if(dist[i] == 0) {
        printf("%d ",i);
        return;
    } else if(dist[i] == INT_MAX) {
        printf("no way to start point");
        return;
    }
    else {
        show(prev[i],dist,prev);
    }
    printf("%d ",i);
}
/*
5
0 10 -1 30 100
-1 0 50 -1 -1
-1 -1 0 -1 10
-1 -1 20 0 60
-1 -1 -1 -1 0
0
*/

/*
五个点：0 1 2 3 4
有向带权图用邻接矩阵表示：arr[i][i] = 0 表示该点本身；
arr[i][j] = -1 表示i点到j点不存在边；
arr[i][j] = 10 表示存在权为10的有向边(i,j)
*/





