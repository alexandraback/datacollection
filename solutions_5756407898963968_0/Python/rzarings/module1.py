def compare(caseNo,list1,list2):
    count = 0
    card = ''
    for i in range(len(list1)):
        for j in range(len(list2)):
            if list1[i] == list2[j]:
                count += 1
                card = list1[i]
    if count == 0:
        print 'Case #'+str((caseNo+1))+': Volunteer cheated!'
    elif count == 1:
        print 'Case #'+str((caseNo+1))+': '+str(card)
    else:
        print 'Case #'+str((caseNo+1))+': Bad magician!'

def main():
    with open('G:\Documents and Settings\Masta\Desktop\input.in') as f:
        firstline = f.readline()
        testNo = int(firstline)
        for a in range(testNo):
            firstdeck = []
            seconddeck = []
            row1 = int(f.readline())
            for n in range(4):
                firstdeck.append(f.readline())
            row2 = int(f.readline())
            for n in range(4):
                seconddeck.append(f.readline())
            firstchoice = firstdeck[row1-1].split()
            secondchoice = seconddeck[row2-1].split()
            compare(a,firstchoice,secondchoice)


if __name__ == '__main__':
    main()