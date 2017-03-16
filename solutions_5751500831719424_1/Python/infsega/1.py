def test(test_num, f):
    n = int(f.readline())
    words = []
    for i in range(n):
        word = f.readline()
        if word[-1] == '\n':
            word = word[:-1]
        words.append(word)
    pattern0 = []
    counts = []
    pattern = None
    for word in words:
        cur_letter = None
        cur_count = 0
        cur_letter_num = -1
        for letter in word:
            if letter != cur_letter:
                if cur_letter_num != -1:
                    if pattern is None:
                        pattern0.append(cur_letter)
                        counts.append([cur_count])
                    else:
                        if cur_letter_num >= len(pattern) or pattern[cur_letter_num] != cur_letter:
                            print("Case #%d: Fegla Won" % test_num)
                            return
                        counts[cur_letter_num].append(cur_count)
                cur_count = 1
                cur_letter = letter
                cur_letter_num += 1
            else:
                cur_count += 1
        if pattern is None:
            pattern0.append(cur_letter)
            pattern = pattern0
            counts.append([cur_count])
        else:
            if (cur_letter_num != len(pattern) - 1) or pattern[cur_letter_num] != cur_letter:
                print("Case #%d: Fegla Won" % test_num)
                return
            counts[cur_letter_num].append(cur_count)
    moves = 0
    for counters in counts:
        s = sum(counters)
        letter_moves = None
        for target in range(min(counters),max(counters) + 1):
            target_moves = sum(abs(count-target) for count in counters)
            if (letter_moves is None) or (letter_moves > target_moves):
                letter_moves = target_moves
        moves += letter_moves
    print("Case #%d: %d" % (test_num, moves))

def tests(f):
    t = int(f.readline())
    for i in range(t):
        test(i + 1, f)

f = open(r"A-large.in")
#f = open(r"1in.txt")
tests(f)
