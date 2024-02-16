h, w, n, m = map(int, input().split())
x = w / (m+1)
y = h / (n+1)
x_int = int(x)
y_int = int(y)
if x > x_int:
    x_int += 1
if y > y_int:
    y_int += 1
print(x_int*y_int)