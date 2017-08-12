#include<stdio.h>
#define MIN 100001
int Prim(int[100][100],int);

int main() {
    int N;
    int arr[100][100];
    while(~scanf("%d",&N)) {
        // ����
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                scanf("%d",&arr[i][j]);
            }
        }
        // Prim
        printf("��С������Ȩֵ�ͣ�%d\n",Prim(arr,N));
    }

    return 0;
}
// lowcost[i]:V-S�е�i��S�еĵ�������СȨֵ
// closet[i]:V-S�е�i��s��Ȩֵ��С����Ӧ�����ĵ�����
int Prim(int c[100][100],int N) {
    int lowcost[N],closest[N], res=0;
    bool s[N];
    // S �����ʼֻ��0��Ԫ��ʱ����lowcost, clostest��ʼ��
    s[0] = true;
    for(int i=1;i<N;i++) {
        lowcost[i] = c[i][0];   // �ʼ S ��ֻ�� 0
        closest[i] = 0;
        s[i] = false;
    }
    // �� V-S �����е�Ԫ�طŵ� S ��
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
        // ���� S ������һ���µ�Ԫ�أ�V-S �и��� lowcost ֵ���ܷ����仯
        for(int j=1;j<N;j++) {
            if(!s[j] && lowcost[j] > c[j][k]) {
                lowcost[j] = c[j][k];
                closest[j] = k;
            }
        }
    }
    return res;
}
