# 将一个x进制的数转换成y进制


def R(): return map(int, input().split())


def transfrom(x, y, s: str):
    res = ''
    sum = 0
    for i in range(len(s)):
        if s[i] == '-':
            continue
        if '0' <= s[i] <= '9':
            sum = sum * x + (ord(s[i]) - ord('0'))
        else:
            sum = sum * x + (ord(s[i]) - ord('A') + 10)
    # print(sum)
    # 字符相加这里有问题的
    while sum:
        temp = chr(sum % y)
        sum /= y
        if temp < 9:
            temp += '0'
        else:
            temp = temp - 10 + 'A'
        res = temp + res
    if not len(res):
        res = '0'
    if s[0] == '-':
        res = '-' + res
    return res








if __name__ == "__main__":
    x, y = R()
    s = input()
    transfrom(x, y, s)
