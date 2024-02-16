N = int(input())
num = set()
for i in range(N):
    val = int(input())
    num.add(val)
for i in sorted(num):
    print(i)