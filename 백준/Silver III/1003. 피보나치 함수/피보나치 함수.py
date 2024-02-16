import sys
n = int(sys.stdin.readline())

dp = [[1,0],[0,1]]
for i in range(2,41):
    a = dp[i-1][0] + dp[i-2][0]
    b = dp[i-1][1] + dp[i-2][1]
    dp.append([a,b])

answer = []
for i in range(n):
    idx = int(sys.stdin.readline())
    answer.append(dp[idx])

for i in answer:
    print(' '.join(map(str,i)))