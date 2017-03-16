file = open('A-small-attempt0.in', 'r')
output = open('output', 'w')

T = file.readline()

def remove_adjacent(nums):
    i = 1
    while i < len(nums):    
        if nums[i] == nums[i-1]:
            nums.pop(i)
            i -= 1  
        i += 1
    return nums

def switch(word):
    result = []
    if word == []:
        return result
    else:
        counter = 1
        while counter < len(word) and word[counter] == word[0]:
            counter = counter + 1
        result.append(counter)
        
        if counter < len(word):
            result.extend(switch(word[counter:]))
        return result

def listdiff(l1, l2):
    diff = 0
    for i in range(len(l1)):
        diff = diff + abs(int(l1[i])-int(l2[i]))
    return diff

def median(mylist):
    sorts = sorted(mylist)
    length = len(sorts)
    if not length % 2:
        return (sorts[int(length/2)] + sorts[int(length/2) - 1]) / 2.0
    return sorts[int(length / 2)]

for x in range(1, int(T)+1):
    N = int(file.readline().replace('\n', ''))
    words = []
    for i in range(N):
        words.append(file.readline().replace('\n', ''))
    
    removed = remove_adjacent(list(words[0]))
    impossible = False
    for word in words:
        if not remove_adjacent(list(word)) == removed:
            impossible = True
        
    if impossible:         
        answer = 'Fegla Won'
    else:
        lengths = []
        for word in words:
            lengths.append(switch(list(word)))
            
        help1 = []
        for i in range(len(lengths[i])):
            help2 = []
            for j in range(len(lengths)):
                help2.append(lengths[j][i])
            help1.append(help2)
            
        medians = list(map(lambda x: median(x), help1))
        msum = 0
        for length in lengths:
            msum = msum + listdiff(medians, length)
        answer = str(msum)
         
    solution = 'Case #' + str(x) + ': ' + answer + '\n'
    if x == int(T):
        solution.replace('\n', '')
    output.write(solution)
    print(solution)