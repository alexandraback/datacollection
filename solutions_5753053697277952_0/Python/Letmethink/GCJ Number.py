file = open('A-small-attempt0(2).in', 'r')
myList = file.readlines()
for count in range(len(myList)):
    myList[count] = myList[count].replace('\n', '')

inputs = int(myList[0])
myList.pop(0)

#myList[0] = myList[0].split()
alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
            'V', 'W', 'X', 'Y', 'Z']

#print(myList)

fout = open('output.out', 'w')
for count in range(inputs):
    parties = myList[2*count]
    number = myList[2*count+1].split(' ')
    for counter in range(len(number)): number[counter] = int(number[counter])
    #print(parties)
    #print(number)
    answer = []
    while not number.count(0) == len(number):
        maxpeople = 0
        maxparty = -1
        difference = 0
        count2 = 0
        same = []
        for item in number:
            if item > maxpeople:
                difference = item-maxpeople
                maxpeople = item
                maxparty = count2
                same = [maxparty]
            else:
                if maxpeople - item <= difference:
                    difference = maxpeople-item
                    if difference == 0:
                        same.append(count2)         
            count2 += 1

        if len(same) != 1 and (sum(number) >= 4 or sum(number) == 2):
            #print(same)
            number[same[0]] -= 1
            number[same[1]] -= 1
            answer.append(alphabet[same[0]] + alphabet[same[1]])
        else:
            if number[maxparty] % 2 == 0 and difference > 1:
                number[maxparty] -= 2
                answer.append(alphabet[maxparty] + alphabet[maxparty])
            else:
                number[maxparty] -= 1
                answer.append(alphabet[maxparty])

    #print(answer)
        #print(number)
    drop = ''
    for item in answer:
        drop = drop + item + ' '
    output = 'Case #' + str(count+1) + ': ' + drop
    print(output)
    fout.write(output + '\n')
fout.close()
    
        
