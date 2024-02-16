import sys
n = int(sys.stdin.readline())
line = []
for i in range(n):
    line.append(int(sys.stdin.readline()))

dp = [1 for _ in range(n)]

cnt = [1]
for i in range(1,n):
    num = 0
    for j in range(i):
        if (line[j]<line[i]) and (dp[i] <= dp[j]):
            dp[i] = dp[j] + 1
            num += 1
    cnt.append(num+1)

print(n-max(cnt))