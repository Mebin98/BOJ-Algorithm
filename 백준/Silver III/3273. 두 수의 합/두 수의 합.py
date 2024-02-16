import sys
n = int(sys.stdin.readline())
a = []
a = list(map(int,sys.stdin.readline().split()))
x = int(sys.stdin.readline())
a.sort()
start = 0
end = n-1
pair = 0
while end > start and n > 1:
    if a[start]+a[end] == x:
        pair += 1
        start += 1
        end -= 1
    if a[start]+a[end] > x:
        end -= 1
    if a[start]+a[end] < x:
        start += 1
print(pair)