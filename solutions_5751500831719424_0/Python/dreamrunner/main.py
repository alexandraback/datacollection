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
    char_count = [[]]
    count = 0
    for char in first:
        if char != last_char:
            if last_char != "":
                char_count[0].append(count)
            count = 1
            char_list.append(char)
            last_char = char
        else:
            count += 1
    char_count[0].append(count)
    num_list = 1
    for l in range(n-1):
        new_list = input()
        new_char_list = []
        char_count.append([])
        last_char = ""
        for char in new_list:
            if char != last_char:
                if last_char != "":
                    char_count[num_list].append(count)
                count = 1
                new_char_list.append(char)
                last_char = char
            else:
                count += 1
        char_count[num_list].append(count)
        if "".join(char_list) != "".join(new_char_list):
            lose = True
            print("Fegla Won")
            break
        num_list += 1
    if not lose:
        total = 0
        # print(char_count)
        for pos in range(len(char_count[0])):
            min_sum = 99999999999999999999
            for i in range(101):
                char_sum = 0
                for ll in char_count:
                    char_sum += abs(ll[pos] - i)
                if char_sum < min_sum:
                    min_sum = char_sum
            total += min_sum
        print(total)




