input_file = open('A-small-attempt0.in','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('A.out','w')
output_text = ''
start_line = 1

debug=0

while case_num<=num_cases:
    num_strings = int(lines[start_line])

    str_list=[]
    for i in range(num_strings):
        str_list.append(lines[start_line+i+1])
    if debug>=2:
        print(str_list)

    letters_lists=[]
    counts_lists=[]
    for s in str_list:
        letters=s[0]
        counts=[1]
        for i in range(1,len(s)):
            if s[i]==s[i-1]:
                counts[-1]+=1
            else:
                letters = letters+s[i]
                counts.append(1)
        if debug>=2:
            print(letters)
            print(counts)
            print('')
        
        letters_lists.append(letters)
        counts_lists.append(counts)
    if len(set(letters_lists))>1:
        output_text += 'Case #'+str(case_num)+': Fegla Won\n'
    else:
        if debug>=2: print(letters_lists[0])
        if debug>=2: print(counts_lists)
        total=0
        for i in range(len(letters_lists[0])): #all in letters_lists are same
            i_counts=[]
            for counts in counts_lists:
                i_counts.append(counts[i])
            i_counts.sort()
            median = i_counts[len(i_counts)//2]  #integer division
            if debug>=2: print(median)
            i_total = 0
            for j in i_counts:
                i_total += abs(j-median)
            if debug>=2: print(i_total)
            total += i_total
        if debug: print(total)
        output_text += 'Case #'+str(case_num)+': '+str(total)+'\n'

    case_num += 1
    start_line+=num_strings+1

if debug: print(output_text)

output_file.write(output_text)
input_file.close()
output_file.close()
