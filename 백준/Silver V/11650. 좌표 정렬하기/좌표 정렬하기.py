import sys
n = int(sys.stdin.readline())

coord = []
for i in range(n):
    x,y = sys.stdin.readline().split()
    x,y = int(x),int(y)
    coord.append([x,y])

sorted_coord = sorted(coord,key=lambda x:(x[0],x[1]))
for i in sorted_coord:
    print(i[0],i[1])