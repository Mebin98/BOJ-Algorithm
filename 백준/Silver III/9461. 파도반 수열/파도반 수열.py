import sys
n = int(sys.stdin.readline())
input = []
for i in range(n):
    input.append(int(sys.stdin.readline()))


def dynamicProgramming(n):
    dp = [1,1,1] + [0]*(n-3)
    for i in range(3,n):
        dp[i] = dp[i-2]+dp[i-3]
    return dp[n-1]


for i in input:
    print(dynamicProgramming(i))