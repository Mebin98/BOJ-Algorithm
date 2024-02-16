import sys
n = int(sys.stdin.readline())
dp = []

for i in range(n):
    line = sys.stdin.readline().split()
    line = [int(x) for x in line]
    dp.append(line)

dp.reverse()

for i in range(len(dp)):
    for j in range(len(dp[i])-1):
        dp[i+1][j] += max(dp[i][j],dp[i][j+1])

print(dp[len(dp)-1][0])