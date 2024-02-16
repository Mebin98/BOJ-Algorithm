import sys
n = int(sys.stdin.readline())
seq = list(map(int,sys.stdin.readline().split()))

dp = [1 for _ in range(n)]

for i in range(n):
    cnt = 0
    for j in range(i+1,n):
        if (seq[j] > seq[i]):
            if dp[i]+1 > dp[j]:
                dp[j] = dp[i] + 1

length = max(dp)            
print(length)

# 역추적
answer = []
idx = n-1
while True:
    if dp[idx] == length:
        length -= 1
        answer.append(seq[idx])
    else:
        idx -= 1
    
    if length == 0:
        break

answer.reverse()
print(' '.join(map(str,answer)))