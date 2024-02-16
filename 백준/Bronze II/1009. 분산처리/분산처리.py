import sys
n = int(sys.stdin.readline())

l = []
for i in range(n):
    a,b = map(int,sys.stdin.readline().split())
    a = a % 10
    
    if a == 1:
        l.append(1)
    elif a == 2:
        temp = b % 4
        if temp == 1:
            l.append(2)
        elif temp == 2:
            l.append(4)
        elif temp == 3:
            l.append(8)
        elif temp == 0:
            l.append(6)
    elif a == 3:
        temp = b % 4
        if temp == 1:
            l.append(3)
        elif temp == 2:
            l.append(9)
        elif temp == 3:
            l.append(7)
        elif temp == 0:
            l.append(1)
    elif a == 4:
        temp = b % 2
        if temp == 1:
            l.append(4)
        elif temp == 0:
            l.append(6)
    elif a == 5:
        l.append(5)
    elif a == 6:
        l.append(6)
    elif a == 7:
        temp = b % 4
        if temp == 1:
            l.append(7)
        elif temp == 2:
            l.append(9)
        elif temp == 3:
            l.append(3)
        elif temp == 0:
            l.append(1)
    elif a == 8:
        temp = b % 4
        if temp == 1:
            l.append(8)
        elif temp == 2:
            l.append(4)
        elif temp == 3:
            l.append(2)
        elif temp == 0:
            l.append(6)
    elif a == 9:
        temp = b % 2
        if temp == 1:
            l.append(9)
        elif temp == 0:
            l.append(1)
    elif a == 0:
        l.append(10)
        
    
for i in l:
    print(i)
