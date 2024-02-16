import sys
n = int(sys.stdin.readline())
t = []
p = []

for i in range(n):
    T,P = map(int,sys.stdin.readline().split())
    t.append(T)
    p.append(P)

dp = [0 for _ in range(n+1)]

for i in range(n):
    day = t[i]
    dp[i] = max(dp[i],dp[i-1])
    if i+day <= n: 
        dp[i+day] = max(dp[i+day],p[i]+dp[i])
    
print(max(dp))