import sys
from collections import deque
n = int(sys.stdin.readline())

dq = deque()
for i in range(n):
    line = []
    line = sys.stdin.readline().split()
    cmd = line[0]
    if len(line) == 2:
        x = int(line[1])
    
    if cmd == 'push_front':
        dq.appendleft(x)
    elif cmd == 'push_back':
        dq.append(x)
    elif cmd == 'pop_front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
    elif cmd == 'pop_back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
    elif cmd == 'size':
        print(len(dq))
    elif cmd == 'empty':
        if len(dq) == 0:
            print(1)
        else:
            print(0)
    elif cmd == 'front':
        if len(dq) > 0:
            print(dq[0])
        else:
            print(-1)
    elif cmd == 'back':
        if len(dq) > 0:
            print(dq[len(dq)-1])
        else:
            print(-1)

    

    