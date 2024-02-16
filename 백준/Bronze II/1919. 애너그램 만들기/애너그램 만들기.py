import sys
a = list(sys.stdin.readline().strip())
b = list(sys.stdin.readline().strip())
answer = 0
c = set(a + b)
for i in c:
    a_cnt = a.count(i)
    b_cnt = b.count(i)
    answer += abs(a_cnt-b_cnt)
print(answer)