a = []
b = []
c = []
i = 0
while True:
    A,B,C = map(int,input().split())
    a.append(A)
    b.append(B)
    c.append(C)
    if(a[i] == 0 and b[i] == 0 and c[i] == 0):
        break
    i += 1
for j in range(i):
    if a[j] == 0 and b[j] == 0 and c[j] == 0:
        break
    if max(a[j],b[j],c[j]) >= (a[j]+b[j]+c[j])-max(a[j],b[j],c[j]):
        print("Invalid")
    elif a[j]==b[j]==c[j]:
        print("Equilateral")
    elif a[j]==b[j] or b[j]==c[j] or c[j]==a[j]:
        print("Isosceles")
    elif (a[j] != b[j] and b[j] != c[j] and c[j] != a[j]):
        print("Scalene")