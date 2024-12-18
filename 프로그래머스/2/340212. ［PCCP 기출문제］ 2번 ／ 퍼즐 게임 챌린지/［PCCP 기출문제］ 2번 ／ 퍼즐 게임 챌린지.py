def solution(diffs, times, limit):
    # Binary Search
    max_level = max(diffs)
    min_level = min(diffs)
    
    answer = 0
    while(True):
        if min_level == max_level:
            answer = min_level
            break

        crt_level = int((max_level + min_level) / 2)
        total = 0
        for i in range(len(diffs)):
            if diffs[i] <= crt_level:
                total += times[i]
            else:
                total += (times[i]+times[i-1])*(diffs[i]-crt_level) + times[i]
        
        if total <= limit:
            max_level = crt_level
        else:
            min_level = crt_level + 1

    return answer