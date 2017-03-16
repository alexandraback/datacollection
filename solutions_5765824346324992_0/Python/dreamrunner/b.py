import math


def verify(time, must_can=False):
    finished = 0
    doing = 0
    available = list()
    i = 0
    for b_speed in bb:
        i += 1
        finished += time // b_speed
        if time % b_speed > 0:
            doing += 1
        else:
            available.append(i)
    # print("f", finished, doing, n, available)
    if finished + doing + len(available) >= n > doing + finished:
        nth = n - finished - doing
        # print("nth", nth)
        print(available[nth-1])
        return 0
    elif finished + doing + len(available) < n:
        return -1
    else:
        return 1


test = int(input())

for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")
    b, n = [int(i) for i in input().split(" ")]
    bb = [int(i) for i in input().split(" ")]
    lower = 0
    upper = n * bb[0]
    while True:
        mid = (lower + upper) // 2
        # if upper - lower == 1:
        #     print("use mid", mid)
        #     verify(mid, True)
        #     break
        # print(lower, upper, mid)
        ans = verify(mid)
        if ans == 0:
            break
        elif ans < 0:
            lower = mid
        else:
            upper = mid