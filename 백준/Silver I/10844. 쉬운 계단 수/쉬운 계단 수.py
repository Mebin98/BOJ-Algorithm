import sys
n = int(sys.stdin.readline())
# dp[n][10];
dp = [[0] * 10 for _ in range(n)]

dp[0] = [0] + [1 for _ in range(9)]

for i in range(1,n):
    dp[i][0] = dp[i-1][1]
    for j in range(1,9):
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
        # dp[i][j] %= 1000000000
    dp[i][9] = dp[i-1][8]

print(sum(dp[n-1]) % 1000000000)