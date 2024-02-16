import sys
n = int(sys.stdin.readline())
score = []
for i in range(n):
    score.append(int(sys.stdin.readline()))

dp = []
for i in range(n):
    if i == 0:
        dp.append(score[i])
    elif i == 1:
        dp.append(score[0]+score[1])
    elif i == 2:
        dp.append(max(score[0],score[1]) + score[2])
    else:
        dp.append(max(dp[i-2],dp[i-3]+score[i-1]) + score[i])

print(dp[n-1])