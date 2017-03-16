from copy import copy
rfile = file('Q1small.in', 'r')
wfile = file('Q1small.out', 'w')
num_of_cases = int(rfile.readline().strip())
for case in range(1, num_of_cases+1):
    N = int(rfile.readline().strip())
    words = []
    for i in range(N):
        words.append(list(rfile.readline().strip()))
    to_write = ''
    #Do case number 'case'
    #check if possible
    minimize = []
    for i in range(N):
        word = copy(words[i])
        j = 0
        while j < len(word)-1:
            if word[j] == word[j+1]:
                word.pop(j)
            else:
                j += 1
        minimize.append(word)
    not_ok = False
    for i in range(N-1):
        if not minimize[i] == minimize[i+1]:
            not_ok = True
            break
    if not_ok:
        to_write = 'Fegla Won'
    else:
        #find minimum
        lens = []
        K = len(minimize[0])
        for word in words:
            cur_len = []
            cur = 1
            for i in range(len(word)-1):
                if not word[i] == word[i+1]:
                    cur_len.append(cur)
                    cur = 1
                else:
                    cur += 1
            cur_len.append(cur)
            lens.append(cur_len)
        print lens
        minimum_total = 0
        for i in range(K):
            mini = 100
            max = 1
            for word in lens:
                if word[i] < mini:
                    mini = word[i]
                if word[i] > max:
                    max = word[i]
            print mini, max
            cur_minimum = []
            for j in range(mini,max+1):
                temp = 0
                for word in lens:
                    temp += abs(word[i]-j)
                cur_minimum.append(temp)
            minimum_total += min(cur_minimum)
        to_write = str(minimum_total)
    #write result
    wfile.write('Case #'+str(case)+': '+to_write+'\n')
