import sys
word = sys.stdin.readline()
alpha = [0 for _ in range(26)]

for i in word:
    if i != '\n':
        alpha[ord(i)-ord('a')] += 1
answer = ' '.join(str(x) for x in alpha)
print(answer)