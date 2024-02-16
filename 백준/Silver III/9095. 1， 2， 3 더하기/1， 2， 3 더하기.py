import sys
n = int(sys.stdin.readline())

l = []
for i in range(n):
    l.append(int(sys.stdin.readline()))

def dp(n):
    dp = [0,1,2,4]+[0]*(n-3)
    for i in range(4,n+1):
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
    return dp[n]

for i in l:
    print(dp(i))