import sys
n = int(sys.stdin.readline())

sort = []
for i in range(n):
    x = int(sys.stdin.readline())
    sort.append(x)

for i in sorted(sort,reverse=True):
    print(i)