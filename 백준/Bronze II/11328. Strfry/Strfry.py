import sys
n = int(sys.stdin.readline())
list = []
for i in range(n):
    o,t = sys.stdin.readline().strip().split()
    if sorted(o) == sorted(t):
        list.append("Possible")
    else:
        list.append("Impossible")
for i in list:
    print(i)
