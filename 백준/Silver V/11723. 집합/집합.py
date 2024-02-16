import sys
m = int(sys.stdin.readline())
set = set()

for i in range(m):
    line = sys.stdin.readline().strip().split()
    cmd = line[0]
    x = int(line[1]) if len(line) > 1 else 0
    if cmd == 'add':
        set.add(x)
    elif (cmd == 'remove') and (x in set):
        set.remove(x)
    elif cmd == 'check':
        if x in set:
            print(1)
        else:
            print(0)
    elif cmd == 'toggle':
        if x in set:
            set.remove(x)
        else:
            set.add(x)
    elif cmd == 'all':
        set.clear()
        set = {x for x in range(1,21)}
    elif cmd == 'empty':
        set.clear()



