# 最长公共子序列


'''
计算 c 矩阵的值
c[i][j] 为 Xi 到 Yj 的最长公共子序列的长度
m, n 分别是两字符串的长度
x, y 是两字符串
b[i][j] 是 c[i][j] 对应哪个子问题解得的
'''


def lcs_length(m, n, x, y, c, b):
    for i in range(m):
        c[0][i] = 0
    for j in range(n):
        c[j][0] = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if y[i - 1] == x[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = 1
            elif c[i][j - 1] >= c[i - 1][j]:
                c[i][j] = c[i][j - 1]
                b[i][j] = 2
            else:
                c[i][j] = c[i - 1][j]
                b[i][j] = 3

'''
构造最长公共子序列
res 为第一个字符串
i, j 为两个字符串的子串
tb 是m[i][j]对应哪种子问题的矩阵
'''


def lcs(i, j, res, tb):
    if i == 0 or j == 0:
        return
    if tb[i][j] == 1:
        lcs(i - 1, j - 1, res, tb)
        print(res[j - 1], end='')
    elif tb[i][j] == 2:
        lcs(i, j - 1, res, tb)
    else:
        lcs(i - 1, j, res, tb)


def longest_common_sub_sequence(str1, str2):
    len_str1 = len(str1) + 1
    len_str2 = len(str2) + 1
    mc = [[0 for i in range(len_str1)] for j in range(len_str2)]
    mb = [[0 for i in range(len_str1)] for j in range(len_str2)]
    lcs_length(len(str1), len(str2), str1, str2, mc, mb)
    print(mc)
    print(mb)
    lcs(len_str2 - 1, len_str1 - 1, str1, mb)

'''
Test for longest_common_sub_sequence
Input str1, str2
Output c[i][j], b[i][j], longest common subSequence
'''
s1 = input()
s2 = input()
longest_common_sub_sequence(s1, s2)