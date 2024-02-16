import math
s = int(input())
a = 1
b = 1
c = -2*s
x1 = (-b+math.sqrt(b**2 - 4*a*c))/2*a
x2 = (-b-math.sqrt(b**2 - 4*a*c))/2*a
if(x1 > 0):
    x = x1
elif(x2 > 0):
    x = x2 
x = int(x)
print(x)