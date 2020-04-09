def gray_create(n: int) -> list:
    res = []
    for i in range(1 << n):
        res.append(i ^ (i >> 1))
    return res


if __name__ == '__main__':
    print(gray_create(31))
