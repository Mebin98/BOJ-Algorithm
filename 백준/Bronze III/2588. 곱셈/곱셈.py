import sys
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())

hund = int(b / 100)
ten = int((b - (hund*100))/10)
one = int(b-((10*ten)+(100)*hund))

print(a*one)
print(a*ten)
print(a*hund)
print(a*one+a*ten*10+a*hund*100)