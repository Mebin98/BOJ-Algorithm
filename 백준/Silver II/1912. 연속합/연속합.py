import sys
n = int(sys.stdin.readline())
seq = list(map(int,sys.stdin.readline().split()))
dp = [x for x in seq]

for i in range(1,n):
    dp[i] = max(dp[i-1]+seq[i],dp[i])

print(max(dp))