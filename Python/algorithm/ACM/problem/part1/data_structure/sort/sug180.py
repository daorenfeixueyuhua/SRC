# 寻找逆序对
from random import randint

A = [randint(0, 20) for _ in [0] * 20]


# 失败

# A = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]


# array[0, len(array))
def merge_sort(array: list, p: int, r: int):
    if p < r - 1:
        q = (p + r) // 2
        merge_sort(array, p, q)
        merge_sort(array, q, r)
        merge(array, p, q, r)


def merge(array: list, p: int, q: int, r: int):
    L = array[p:q]
    R = array[q:r]
    i = 0
    j = 0
    k = p
    print(L, R)
    while i < len(L) and j < len(R) and k < r:
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        elif j < len(R):

            array[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        array[k] = L[i]
        k += 1
        i += 1

    while j < len(R):
        array[k] = L[j]
        k += 1
        j += 1


if __name__ == '__main__':
    print(A)
    merge_sort(A, 0, len(A))
    print(A)
