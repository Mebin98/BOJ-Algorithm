def solution(video_len, pos, op_start, op_end, commands):
    pos_hour = int(pos[0] + pos[1])
    pos_min = int(pos[3] + pos[4])
    opStart_hour = int(op_start[0] + op_start[1])
    opStart_min = int(op_start[3] + op_start[4])
    opEnd_hour = int(op_end[0] + op_end[1])
    opEnd_min = int(op_end[3] + op_end[4])
    video_hour = int(video_len[0]+video_len[1])
    video_min = int(video_len[3]+video_len[4])
    
    for cmd in commands:
        # Checks whether the position is within operation time
        if (opStart_hour < pos_hour < opEnd_hour):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (pos_hour == opStart_hour == opEnd_hour) and (opStart_min < pos_min < opEnd_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (opStart_hour == pos_hour != opEnd_hour) and (pos_min >= opStart_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (opStart_hour != pos_hour == opEnd_hour) and (pos_min <= opEnd_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        
        if cmd == "prev":
            pos_min -= 10
        elif cmd == "next":
            pos_min += 10
             
        # Adjusts hours and minutes when crossing boundaries
        if pos_min < 0:
            pos_min += 60
            pos_hour -= 1
        elif pos_min >= 60:
            pos_min -= 60
            pos_hour += 1
        
        if (pos_hour < 0):
            pos_hour = 0
            pos_min = 0
        if (pos_hour > video_hour) or ((pos_hour==video_hour) and (pos_min > video_min)):
            pos_hour = video_hour
            pos_min = video_min
        
        # Checks whether the position is within operation time
        if (opStart_hour < pos_hour < opEnd_hour):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (pos_hour == opStart_hour == opEnd_hour) and (opStart_min <= pos_min <= opEnd_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (opStart_hour == pos_hour != opEnd_hour) and (pos_min >= opStart_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        elif (opStart_hour != pos_hour == opEnd_hour) and (pos_min <= opEnd_min):
            pos_hour = opEnd_hour
            pos_min = opEnd_min
        
        
    if pos_hour < 10:
        pos_hour = '0' + str(pos_hour)
    else:
        pos_hour = str(pos_hour)

    if pos_min < 10:
        pos_min = '0' + str(pos_min)
    else:
        pos_min = str(pos_min)
    
    answer = pos_hour + ":" + pos_min
    return answer
