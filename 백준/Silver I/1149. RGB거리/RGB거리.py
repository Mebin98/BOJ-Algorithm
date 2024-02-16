import sys
n = int(sys.stdin.readline())
cost = []
for i in range(n):
    R,G,B = map(int,sys.stdin.readline().split())
    cost.append([R,G,B])
dp = []
r,g,b = [cost[0][0]],[cost[0][1]],[cost[0][2]]
for i in range(n-1):
    r.append(min(g[i],b[i])+cost[i+1][0])
    g.append(min(r[i],b[i])+cost[i+1][1])
    b.append(min(r[i],g[i])+cost[i+1][2])
    dp.append(min(r[i+1],g[i+1],b[i+1]))
print(dp[n-2])