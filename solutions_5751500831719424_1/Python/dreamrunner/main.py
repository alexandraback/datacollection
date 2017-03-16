T = int(input())
test = 1

while test <= T:
    lose = False
    print("Case #" + str(test) + ": ", end="")
    test += 1
    n = int(input())
    first = input()
    last_char = ""
    char_list = []
    char_count = [[] for i in range(100)]
    count = 0
    ct_i = 0
    for char in first:
        if char != last_char:
            if last_char != "":
                char_count[ct_i].append(count)
                ct_i += 1
            count = 1
            char_list.append(char)
            last_char = char
        else:
            count += 1
    char_count[ct_i].append(count)
    num_list = 1
    for l in range(n-1):
        new_list = input()
        new_char_list = []
        last_char = ""
        ct_i = 0
        for char in new_list:
            if char != last_char:
                if last_char != "":
                    char_count[ct_i].append(count)
                    ct_i += 1
                count = 1
                new_char_list.append(char)
                last_char = char
            else:
                count += 1
        char_count[ct_i].append(count)
        if "".join(char_list) != "".join(new_char_list):
            lose = True

        num_list += 1
    if lose:
        print("Fegla Won")
    if not lose:
        total = 0
        # print(char_count)
        for pos in range(len(char_count)):
            min_sum = 99999999999999999999
            if len(char_count[pos]) == 0:
                break
            for i in range(min(char_count[pos]), max(char_count[pos])+1):
                char_sum = 0
                for ll in char_count[pos]:
                    char_sum += abs(ll - i)
                if char_sum < min_sum:
                    min_sum = char_sum
            total += min_sum
        # print(char_count)
        print(total)




