import sys
room = sys.stdin.readline().strip()
list = [0 for _ in range(10)]

for i in room:
    if int(i) == 6 or int(i) == 9:
        if list[6] <= list[9]:
            list[6] += 1
        else:
            list[9] += 1
    else:
        list[int(i)] += 1
print(max(list))