import sys
n = int(sys.stdin.readline())

stack = []
for i in range(n):
    line = sys.stdin.readline().strip().split()
    cmd = line[0]
    x = int(line[1]) if len(line) > 1 else 0
    if cmd =='push':
        stack.append(x)
    elif cmd == 'pop':
        if len(stack)>0:
            print(stack.pop())
        else:
            print(-1)
    elif cmd == 'size':
        print(len(stack))
    elif cmd == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif cmd == 'top':
        if len(stack) > 0:
            print(stack[len(stack)-1])
        else:
            print(-1)