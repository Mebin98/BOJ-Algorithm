import sys 
t,w = map(int,sys.stdin.readline().split())
jadu = []

for i in range(t):
    x = int(sys.stdin.readline())
    jadu.append(x)

dp = [[0]*(w+1) for _ in range(t+1)]

for i in range(t):
    if jadu[i] == 1:
        dp[i+1][0] = dp[i][0] + 1
    else:
        dp[i+1][0] = dp[i][0] 
    for j in range(1,w+1):
        if (j % 2 == 0) and (jadu[i] == 2):
            dp[i+1][j] = max(dp[i][j],dp[i][j-1]) 
        elif (j % 2 == 0) and (jadu[i] == 1):
            dp[i+1][j] = max(dp[i][j],dp[i][j-1]) + 1
        elif (j % 2 != 0) and (jadu[i] == 2):
            dp[i+1][j] = max(dp[i][j],dp[i][j-1]) + 1
        else:
            dp[i+1][j] = max(dp[i][j],dp[i][j-1]) 
        

print(max(dp[t]))  