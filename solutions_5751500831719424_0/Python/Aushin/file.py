def find_avg_chars(strings, basic_string):
    averages = []
    n2 = 0
    for i in range(len(basic_string)):
        x = basic_string[i]
        y = 0.0
        nums = []
        for n in range(len(strings)):
            v = 0
            for j in range(len(strings[n])):
                if strings[n][j] == x:
                    y += 1
                    v += 1
                    if j == len(strings[n]) - 1:
                        nums.append(v)
                        break
                else:
                    if j < len(strings[n]):
                        strings[n] = strings[n][j:]
                        nums.append(v)
                        break
        
        n = int(round(y / len(strings)))
        for num in nums:
            n2 += abs(num-n)
    return n2

def build_basic_string(string):
    res = string[0]
    j = 0
    for i in range(len(string)):
        if string[i] != res[j]:
            j+=1
            res = res + string[i]
    return res

def solve(strings):
    basic_strings = [build_basic_string(x) for x in strings]
    first_string = basic_strings[0]
    for basic_string in basic_strings:
        if basic_string != first_string:
            return "Fegla Won"
    x = find_avg_chars(strings, basic_string)
    return str(x)  

with open('c:\\python27\\codejam\\outputs.out', 'w') as w, open('c:\\python27\\codejam\\A-small-attempt0.in') as r:
    cases = int(r.readline())
    for case in range(1, cases+1):
        N = int(r.readline())
        strings = []
        for i in range(N):
            x = r.readline().rstrip()
            strings.append(x)
        w.write('Case #{0}: {1}\n'.format(str(case), solve(strings)))

