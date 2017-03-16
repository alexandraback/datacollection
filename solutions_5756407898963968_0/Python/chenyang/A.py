for i in range(input()):
    first = input()
    first_l = [raw_input().split() for _ in range(4)]
    second = input()
    second_l = [raw_input().split() for _ in range(4)]

    first_s = set(first_l[first - 1])
    second_s = set(second_l[second - 1])

    inter = set.intersection(first_s, second_s)

    if len(inter) == 1:
        s = str(inter.pop())
    elif len(inter) == 0:
        s = "Volunteer cheated!"
    else:
        s = "Bad magician!"

    print "Case #{}: {}".format(i+1, s)
