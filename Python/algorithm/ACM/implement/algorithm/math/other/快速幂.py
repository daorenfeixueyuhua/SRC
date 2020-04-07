# 计算 a^i mod n
# O(log i)

def pow_mod(a: int, i: int, n: int) -> int:
    if i == 0: return 1 % n;
    temp = pow_mod(a, i >> 1, n)
    temp = temp * temp % n
    if i & 1:
        temp = temp * a % n
    return temp


if __name__ == '__main__':
    print(pow_mod(2, 3, 6))
