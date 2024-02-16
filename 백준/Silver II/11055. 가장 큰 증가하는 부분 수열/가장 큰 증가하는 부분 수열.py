import sys
n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
dp = [x for x in arr]

for i in range(1,n):
    prev = 0
    for j in range(i):
        if arr[i] > arr[j] and dp[j] > prev:
            dp[i] = arr[i] + dp[j]
            prev = dp[j]   
print(max(dp))