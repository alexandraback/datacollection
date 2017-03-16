def del_letter(words, letter):
    new_words = []
    for word in words:
        if letter+letter in word:
            word.pop(word.index(letter+letter))
        new_words.append(word)
    return new_words

def add_letter(words, indices):
    for index in range(len(words)):
        word[index].insert(indices[index], word[index][indices[index]])
    return words

def split_letters(word):
    split_list = []
    prev_index = 0
    for index in range(len(word)):
        if word[prev_index] != word[index]:
            split_list.append(len(word[prev_index:index]))
            prev_index = index
    split_list.append(len(word[prev_index:]))
    return split_list

def ahhhhhh(word):
    split_list = []
    prev_index = 0
    for index in range(len(word)):
        if word[prev_index] != word[index]:
            split_list.append(word[prev_index:index])
            prev_index = index
    split_list.append(word[prev_index:])
    return split_list
            

filein = open('D:\\Users\\john\\My Documents\\Google Code Jam 2014\\repeat_small.txt','r+')
fileout = open('D:\\Users\\john\\My Documents\\Google Code Jam 2014\\repeat_small_answer.txt','w+')

T = int(filein.readline())
for case in range(T):
    
    N = int(filein.readline())
    num_actions = 0
    
    words = []
    for line in range(N):
        words.append(filein.readline().strip())
    
    #Done Test
    done = True
    previous_word = words[0]
    for word in words:
        if word != previous_word:
            done = False
            break
    
    if not done:
        #Impossible Test
        uniq_letters = []
        for word in words:
            uniq_letters.append(set(word))
    
        done = False
        total_set = set()
        for letter_set in uniq_letters:
            total_set = total_set | letter_set
        
        uniq = []
        for letter_set in uniq_letters:
            uniq = total_set ^ letter_set
            if uniq:
                fileout.write('Case #'+str(case+1)+': Fegla Won\n')
                done = True
                break
                
        if not done:
            mapped_letters = []
            for word in words:
                mapped_letters.append(split_letters(word))
                
            mapped_letters = np.array(mapped_letters)
            medians = []
            
            done = False
            prev_word = len(mapped_letters[0])
            for word in mapped_letters:
                if len(word) != prev_word:
                    fileout.write('Case #'+str(case+1)+': Fegla Won\n')
                    done = True
                    break
                    
            if not done:
                ahhhh_letters = []
                for word in words:
                    ahhhh_letters.append(ahhhhhh(word))
                
                done = False
                prev_word = ahhhh_letters[0]
                for word in ahhhh_letters:
                    for letter in range(len(word)):
                        if word[letter][0] != prev_word[letter][0]:
                            fileout.write('Case #'+str(case+1)+': Fegla Won\n')
                            done = True
                            break
            
                if not done:
                    for col in range(len(mapped_letters[0])):
                        medians.append(np.floor(np.median(mapped_letters[:,col])))
                    medians = np.array(medians)
                    for col in range(len(mapped_letters[0])):
                        num_actions += np.sum(np.absolute(medians[col] - mapped_letters[:,col]))
            
                    fileout.write('Case #'+str(case+1)+': '+str(int(num_actions))+'\n')
            
    else:
        fileout.write('Case #'+str(case+1)+': '+str(num_actions)+'\n')

filein.close()
fileout.close()