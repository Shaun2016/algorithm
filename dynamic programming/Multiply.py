# 计算两个矩阵相乘的结果
# matrix_a, matrix_b 为相乘的矩阵，matrix_c 为相乘结果，r*为行数，c*为列数


def matrix_multiply(matrix_a, matrix_b, matrix_c, ra, ca, rb, cb):
    if ca != rb:
        print('矩阵不可乘！')
        return
    # i，j 为结果矩阵的行列数，要计算 i * j 个位置上的值
    for i in range(ra):
        for j in range(cb):
            # 结果矩阵每个位置上的值要经过 k 对数的相乘并加和
            for k in range(ca):
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j]
'''
# Test for matrix_multiply
ma = [[1, 2], [3, 4], [2, 1]]
mb = [[1], [2]]
mc = [[0 for col in range(1)] for row in range(3)]
matrix_multiply(ma, mb, mc, 3, 2, 2, 1)
print(mc)
'''

'''
计算 m[i][j] 和 s[i][j]
    m[i][j] 为 AiAi+1...Aj 的最少数乘次数
    s[i][j] 为 AiAi+1...Aj 最少数乘次数应该断开的位置 k
    p (list) 保存连乘矩阵的行列维度
    n 连乘矩阵数
'''


def matrix_chain(p, n, m, s):
    # 根据递归式 i = j 时，m[i][j] = 0
    for r in range(n):
        m[r][r] = 0
    for r in range(1, n):
        for i in range(n - r):
            j = i + r
            m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1]
            s[i][j] = i
            for k in range(i + 1, j):
                t = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if t < m[i][j]:
                    m[i][j] = t
                    s[i][j] = k


'''
构造最优解： 具体按什么次序做矩阵乘法
i, j 为连乘矩阵下标
s[i][j] 为 i 到 j 的矩阵连乘应该断开的位置
'''


def trace_back(i, j, s, r):
    if i == j:
        return
    r.append(s[i][j])
    trace_back(i, s[i][j], s, r)
    trace_back(s[i][j] + 1, j, s, r)

'''
打印加括号的连乘式
'''


def multiply_parenthesis(r, l):
    s = ['A' + str(i) for i in range(l)]
    parentheses = ['' for i in range(l + 1)]
    parentheses[0] += '('
    parentheses[-1] += ')'
    for i in r:
        for j in range(i, -1, -1):
            if parentheses[j] != '':
                if j == i:
                    break
                parentheses[i + 1] += ')'
                parentheses[j] += '('
                break
        for j in range(i + 2, l + 1):
            if parentheses[j] != '':
                if j == i + 2:
                    break
                parentheses[i + 1] += '('
                parentheses[j] = ')' + parentheses[j]
                break

    for num in range(l):
        print(parentheses[num], s[num], end='')
    print(parentheses[-1])

'''
显示结果
'''


def multiply_show(arr):
    length = len(arr) - 1
    # m1 为从 i 到 j 的最少数乘次数，s1 为 i 到 j 应断开的位置
    m1 = [[0 for i in range(length)] for j in range(length)]
    s1 = [[0 for i in range(length)] for j in range(length)]
    matrix_chain(arr, length, m1, s1)

    def show(l):
        for i in l:
            for j in i:
                print(j, end=' ')
            print()
        print()
    print('i j 对应的最少数乘次数 m: ')
    show(m1)
    print('最少连乘次数为{}'.format(m1[0][length-1]))
    print('i j 对应的断开位置 s: ')
    show(s1)

    res = []
    trace_back(0, length - 1, s1, res)

    print('先后应该断开的位置')
    print(res)
    multiply_parenthesis(res, length)


# Test for matrix_chain and trace_back
# m_input 为 连乘矩阵行列数
m_input = [30, 35, 15, 5, 10, 20, 25]
multiply_show(m_input)








