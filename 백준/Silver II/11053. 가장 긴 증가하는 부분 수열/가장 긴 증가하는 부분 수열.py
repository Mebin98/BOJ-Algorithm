import sys
n = int(sys.stdin.readline())
seq = list(map(int,sys.stdin.readline().split()))

dp = [1 for _ in range(n)]

for i in range(n):
    for j in range(i+1,n):
        if (seq[j] > seq[i]):
            if dp[i]+1 > dp[j]:
                dp[j] = dp[i] + 1
            
print(max(dp))