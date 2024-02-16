import sys
n = int(sys.stdin.readline())

queue = []
for i in range(n):
    line = sys.stdin.readline().strip().split()
    cmd = line[0]
    x = int(line[1]) if len(line) > 1 else 0
    if cmd =='push':
        queue.append(x)
    elif cmd == 'pop':
        if len(queue)>0:
            print(queue.pop(0))
        else:
            print(-1)
    elif cmd == 'size':
        print(len(queue))
    elif cmd == 'empty':
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif cmd == 'front':
        if len(queue)>0:
            print(queue[0])
        else:
            print(-1)
    elif cmd == 'back':
        if len(queue)>0:
            print(queue[len(queue)-1])
        else:
            print(-1)