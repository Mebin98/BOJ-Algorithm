import sys
n = int(sys.stdin.readline())

list = []
for i in range(n):
    line = sys.stdin.readline().strip().split()
    age = int(line[0])
    name = line[1]
    list.append([age,name,i])

sorted_list = sorted(list,key=lambda x: (x[0],x[2]))
for i in sorted_list:
    print(i[0],i[1])