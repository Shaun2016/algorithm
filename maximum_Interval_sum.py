# n 为输入数组长度
# a 为输入数字数组
# b 为以 i 结尾的最大子段和


def max_sum(n, a):
    m_sum = 0
    b = 0
    for i in range(0, n):
        if b > 0:
            b += a[i]
        else:
            b = a[i]
        if b > m_sum:
            m_sum = b
    return m_sum


def maximum_interval_sum(s_input):
    res = max_sum(len(s_input), s_input)
    print(res)

'''
Test for maximum_interval_sum
Input: number list separate by space
Output: max interval sum
'''
arr = [int(x) for x in input().split(' ')]
maximum_interval_sum(arr)