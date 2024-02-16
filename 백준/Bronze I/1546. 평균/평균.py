import sys
n = int(sys.stdin.readline())
score = list(map(int,sys.stdin.readline().split()))

max_score = max(score)

for i in range(n):
    score[i] = (score[i] / max_score)*100

print(sum(score) / n)