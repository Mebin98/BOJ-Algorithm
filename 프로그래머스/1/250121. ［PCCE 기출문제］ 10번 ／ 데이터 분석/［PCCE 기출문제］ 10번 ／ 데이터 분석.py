def solution(data, ext, val_ext, sort_by):
    # feature -> code, date, maximum, remain
    stdIdx = -1
    if ext == "code":
        stdIdx = 0
    elif ext == "date":
        stdIdx = 1
    elif ext == "maximum":
        stdIdx = 2
    elif ext == "remain":
        stdIdx = 3
    else:
        print('Error case')
    
    answer = []
    
    for i in range(len(data)):
        temp = []
        if data[i][stdIdx] < val_ext:
            temp = [data[i][0], data[i][1], data[i][2], data[i][3]]
            answer.append(temp)
    
    sortIdx = -1
    if sort_by == "code":
        sortIdx = 0
    elif sort_by == "date":
        sortIdx = 1
    elif sort_by == "maximum":
        sortIdx = 2
    elif sort_by == "remain":
        sortIdx = 3
    else:
        print('Error case')
    
    answer = sorted(answer, key=lambda x: x[sortIdx])
    
    return answer