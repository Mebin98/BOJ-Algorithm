import sys
# n : 수학여행에 참가하는 학생 수
# k : 한 방에 배정할 수 있는 최대 인원 수
n,k = sys.stdin.readline().strip().split()
n,k = int(n),int(k)
# 0 : 여학생, 1: 남학생
table = [[0 for _ in range(6)] for _ in range(2)]

for i in range(n):
    s,y = sys.stdin.readline().strip().split()
    s,y = int(s),int(y)
    table[s][y-1] += 1
how = 0
for i in range(2):
    for j in range(6):
        if 0<table[i][j]<=k:
            how += 1
        elif table[i][j] > k:
            if ((table[i][j]/k) - int(table[i][j]/k)) != 0:
                how += 1 + int(table[i][j]/k)
            else:
                how += int(table[i][j]/k)
print(how)