n = int(input())
a = list(range(1,n+1))
b = []
for i in range(len(a)):
    b.append(int(input()))

set_a = set()
set_b = set()
start = 0
answer = []
def dfs(start,answer,set_a,set_b):
    if start == len(a):
        return answer
    idx = start
    while True:
        if(b[idx] == a[start]):
            answer.append(start+1)
            break
        if a[idx] in set_a:
            break
        if b[idx] in set_b:
            break
        set_a.add(a[idx])
        set_b.add(b[idx])
        idx = b[idx]-1
    set_a.clear()
    set_b.clear()
    return dfs(start+1,answer,set_a,set_b)
answer = dfs(start,answer,set_a,set_b)
print(len(answer))
for i in answer:
    print(i)