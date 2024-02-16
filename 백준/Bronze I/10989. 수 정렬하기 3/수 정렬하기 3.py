import sys
n = int(sys.stdin.readline())

quan = [0]*10000
for i in range(n):
    x = int(sys.stdin.readline())
    quan[x-1] += 1

for i,q in enumerate(quan):
    if q != 0:
        for j in range(q):
            print(i+1)