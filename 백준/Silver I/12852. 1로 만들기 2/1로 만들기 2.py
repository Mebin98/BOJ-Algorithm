import sys
n = int(sys.stdin.readline())

def one(n):
    dp = [0,0,1,1,2] + [float('inf')]*(n-4)
    for i in range(5,n+1):
        dp[i] = dp[i-1]+1
        if i % 3 == 0:
            dp[i] = min(dp[i],dp[i//3]+1)
        if i % 2 == 0:
            dp[i] = min(dp[i],dp[i//2]+1)
    return dp

def two(n,dp):
    answer = []

    while True:
        answer.append(n)
        if n == 1:
            break
        test = []
        test.append(n-1)
        if n % 3 == 0:
            test.append(n//3)
        if n % 2 == 0:
            test.append(n//2)
        
        mini = float('inf')
        for i,idx in enumerate(test):
            if i == 0:
                if dp[idx] < mini:
                    mini = idx
            else:
                if dp[idx] < dp[mini]:
                    mini = idx        
        n = mini

    return answer

dp = one(n)
answer = two(n,dp)
print(len(answer)-1)
print(' '.join(map(str,answer)))