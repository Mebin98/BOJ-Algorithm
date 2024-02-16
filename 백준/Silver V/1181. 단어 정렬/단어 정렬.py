import sys
n = int(sys.stdin.readline())

dic = []
for i in range(n):
    word = sys.stdin.readline().strip()
    dic.append(word)

dic = list(set(dic))
dic = sorted(dic, key=lambda word: (len(word), word))
for i in dic:
    print(i)