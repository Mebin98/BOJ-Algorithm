import sys
n,m = map(int,sys.stdin.readline().split()) 
# n : 사람의 수, m : 파티의 수
line = list(map(int,sys.stdin.readline().strip().split()))
know = set(line[1:]) # know : 진실을 아는 사람들의 명단
party = []
for i in range(m):
    line2 = list(map(int,sys.stdin.readline().strip().split()))
    party.append(set(line2[1:]))

def black(party,know):
    cnt = 0
    for i,p in enumerate(party):
        if p & know: # 파티에 진실을 아는 사람이 있는경우
            know.update(p)
            party[i] = {0}
        else:
            cnt += 1
    return party,know,cnt
org_party = party
while True:
    party,know,cnt = black(party,know)
    if cnt == len(org_party):
        break
answer = len([x for x in party if x != {0}])
print(answer)