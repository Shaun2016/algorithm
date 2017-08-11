# v，w 是物品的价值和重量，n 是物品数量，c 是背包容量，m[i][j] 为物品数量为 i 背包容量为 j 时的最大价值
def knapsack(v, w, n, c, m):
    for i in range(c):
        if i + 1 >= w[0]:
            m[0][i] = v[0]
    for j in range(c):
        for i in range(1, n):
            if j + 1 < w[i]:
                m[i][j] = m[i - 1][j]
            elif j + 1 == w[i]:
                m[i][j] = max(m[i - 1][j], v[i])
            else:
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i])


def bag_value(value, weight, bc):
    bm = [[0 for i in range(bc)] for j in range(len(value))]
    knapsack(value, weight, len(value), bc, bm)
    print(bm)
    print(bm[len(value) - 1][bc - 1])

'''
Test for knapsack
Input: 物品价格，重量列表，背包容量
Output: m[i][j]，背包能装的最大价值
'''
vl = [int(x) for x in input().split(' ')]
wl = [int(x) for x in input().split(' ')]
b = int(input())

bag_value(vl, wl, b)




