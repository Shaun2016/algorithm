#include<stdio.h>
#define MIN 100001
int Prim(int[100][100],int);

int main() {
    int N;
    int arr[100][100];
    while(~scanf("%d",&N)) {
        // 输入
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                scanf("%d",&arr[i][j]);
            }
        }
        // Prim
        printf("最小生成树权值和：%d\n",Prim(arr,N));
    }

    return 0;
}
// lowcost[i]:V-S中点i到S中的点连线最小权值
// closet[i]:V-S中点i到s中权值最小连线应该连的点坐标
int Prim(int c[100][100],int N) {
    int lowcost[N],closest[N], res=0;
    bool s[N];
    // S 集合最开始只有0号元素时，对lowcost, clostest初始化
    s[0] = true;
    for(int i=1;i<N;i++) {
        lowcost[i] = c[i][0];   // 最开始 S 中只有 0
        closest[i] = 0;
        s[i] = false;
    }
    // 将 V-S 集合中的元素放到 S 中
    for(int i=1;i<N;i++) {
        int k, imin = MIN;
        for(int j=1;j<N;j++) {
            if(!s[j] && lowcost[j] < imin) {
                imin = lowcost[j];
                k = j;
            }
        }
        s[k] = true;
        printf("%d--%d \n",k,closest[k]);
        res += imin;
        // 由于 S 中有了一个新的元素，V-S 中各点 lowcost 值可能发生变化
        for(int j=1;j<N;j++) {
            if(!s[j] && lowcost[j] > c[j][k]) {
                lowcost[j] = c[j][k];
                closest[j] = k;
            }
        }
    }
    return res;
}
