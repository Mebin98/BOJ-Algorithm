from itertools import zip_longest
from collections import defaultdict

def solution(points, routes):
    def bfs(route):
        record = []
        for i in range(len(route)-1):
            sx, sy = points[route[i]-1]
            ex, ey = points[route[i+1]-1]

            while sx != ex:
                record.append((sx,sy))
                if sx < ex:
                    sx += 1
                elif sx > ex:
                    sx -= 1
                             
            while sy != ey:
                record.append((sx,sy))
                if sy < ey:
                    sy += 1
                elif sy > ey:
                    sy -= 1 
        record.append((sx,sy))
        return record      

    way_record = []
    for route in routes: 
        way_record.append(bfs(route))

    way_record_t = list(zip_longest(*way_record))
    answer = 0

    for step in way_record_t:
        position_count = defaultdict(int)
        for s in step:
            if s is not None:
                position_count[s] += 1

        answer += sum(1 for count in position_count.values() if count >= 2)

    return answer