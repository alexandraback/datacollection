from sys import stdin

T = int(stdin.readline())
for t in range(1,T+1):
    possible_cards = set(range(1,17))

    for guess in range(2):
        A = int(stdin.readline())-1
        T = [ [int(word) for word in stdin.readline().strip().split()]
                for j in range(4) ]

        possible_cards &= set(T[A])
        #print possible_cards
    
    print "Case #"+str(t)+":",
    if len(possible_cards)>1:
        print "Bad magician!"
    elif len(possible_cards)==0:
        print "Volunteer cheated!"
    else:
        print possible_cards.pop()

