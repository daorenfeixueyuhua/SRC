def sort(A):
    cnt = 0
    sorted = False
    while (not sorted):
        sorted = True
        # print('moo')
        print(A)
        cnt += 1
        for i in range(len(A)-1):
            if A[i + 1] < A[i]:
                temp = A[i]
                A[i] = A[i + 1]
                A[i+1]  = temp
                sorted = False
    return A, cnt

n = int(input())
# L = [int(input()) for i in range(n)]
L = list(map(int, input().split()))
# print(L)
L, cnt = sort(L)
print(cnt)
