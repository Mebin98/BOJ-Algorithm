import sys
n = int(sys.stdin.readline())
num = list(map(int,sys.stdin.readline().split()))
v = int(sys.stdin.readline())
answer = 0
for i in num:
    if i == v:
        answer += 1
print(answer)