import math
f = open("input.txt", "rU")
cases = int(f.readline().strip())
results = ""
for case in range(cases):
    line_number = int(f.readline().strip())
    thing = {}
    silly = ""
    actions = 0
    for i in range(line_number):
        s = f.readline().strip()
        new_silly = ""
        cur_char = ""
        char_num = 0
        count = 0
        for char in s:
            if cur_char == "":
                cur_char = char
                new_silly += char
                count = 1
            elif char != cur_char:
                if cur_char+str(char_num) in thing:
                    thing[cur_char+str(char_num)].append(count)
                else:
                    thing[cur_char+str(char_num)] = [count]
                new_silly += char
                cur_char = char
                char_num += 1
                count = 1
            else:
                count += 1
        if char_num in thing:
            thing[char_num].append(count)
        else:
            thing[char_num] = [count]
        if silly == "":
            silly = new_silly
        elif silly != new_silly:
            results += "Case #{}: Fegla Won\n".format(case+1)
            break
    else:
        for key in thing:
            l = thing[key]
            tot = 0
            for item in l:
                tot += item
            mid = tot//len(l)
            for e in l:
                actions += int(math.fabs(e-mid))
        results += "Case #{}: {}\n".format(case+1, actions)

f.close()
results = results.strip()

o = open("output.txt", "w")
o.write(results)
o.close()
