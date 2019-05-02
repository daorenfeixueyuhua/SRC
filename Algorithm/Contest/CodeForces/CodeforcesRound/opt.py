def rec_dp(arr, i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0], arr[1])
    else:
        return max(rec_dp(arr, i-1), rec_dp(arr, i-2)+arr[i])


def dp1(arr):
    dp = arr
    for i in range(2, len(arr)):
        dp[i] = max(dp[i-1], dp[i-2]+dp[i])
    return dp[len(arr)-1]


arr = [1, 8, 5, 6, 6]
print(dp1(arr))
print(rec_dp(arr, 4))
