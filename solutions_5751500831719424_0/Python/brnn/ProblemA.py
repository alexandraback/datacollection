from decimal import *
getcontext().prec = 100

fin = open('inputA.txt')
fout = open('outputA.txt','w')
num_tests = int(fin.readline())

for test_num in range(1, num_tests + 1):
    line = fin.readline().split(" ")
    N = int(line[0])
    fegla = False
    
    word = fin.readline().split()[0]
    characters = []
    for j in range(len(word)):
        if j == 0 or word[j] != word[j-1]:
            characters.append(word[j])
    sizes = [[0 for j in range(N)] for i in range(len(characters))]
    ind = 0
    for j in range(len(word)):
        if j >= 1 and word[j] != word[j-1]:
            ind += 1
        sizes[ind][0] += 1

    for i in range(N-1):
        word = fin.readline().split()[0]
        ind = 0
        for j in range(len(word)):
            if j >= 1 and word[j] != word[j-1]:
                ind += 1
            if ind >= len(characters) or word[j] != characters[ind]:
                fegla = True
                break
            else:
                sizes[ind][i+1] += 1
        if ind < len(characters)-1:
            fegla = True
        if fegla:
            break

    if fegla:
        fout.write("Case #" + str(test_num) + ": Fegla Won" + "\n")
    else:
        cost = 0
        for i in range(len(sizes)):
            if N % 2 == 1:
                target = sorted(sizes[i])[N/2]
            else:
                sorts = sorted(sizes[i])
                target = int(0.5*sorts[(N-1)/2]+0.5*sorts[N/2]+0.5)
            cost += sum([abs(x-target) for x in sizes[i]])
        fout.write("Case #" + str(test_num) + ": " + str(cost) + "\n")
    print test_num
    
fin.close()
fout.close()
