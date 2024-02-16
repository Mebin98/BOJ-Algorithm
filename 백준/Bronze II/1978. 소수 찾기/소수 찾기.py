import sys
import math
n = int(sys.stdin.readline())
num_set = sys.stdin.readline().split()
num_set = list(map(int,num_set))

answer = 0
for num in num_set:
    test = 0
    u = int(math.sqrt(num))
    for x in range(2,u+1):
        if num % x != 0:
            test += 1
    if test == u-1 and num != 1:
        answer += 1
print(answer)