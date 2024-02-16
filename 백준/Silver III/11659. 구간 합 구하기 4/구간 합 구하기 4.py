import sys
n,m = map(int,sys.stdin.readline().split())
num = list(map(int,sys.stdin.readline().split()))
s = [0]
temp = 0
for i in range(n):
    temp += num[i]
    s.append(temp)

answer = []
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    answer.append(s[b]-s[a-1])

for i in answer:
    print(i)