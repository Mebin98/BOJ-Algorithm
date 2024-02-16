import sys
import math
m,n = map(int,sys.stdin.readline().split())

era = [False,False] + [True]*(n-1)
primes = []
for i in range(2,n+1):
    if era[i]:
        primes.append(i)
    for j in range(2*i,n+1,i):
        era[j] = False

answer = [x for x in primes if x>=m and x<=n]
for i in answer:
    print(i)