num_test = int(raw_input())
for test_case in xrange(1,num_test+1):

    parties = raw_input();
    senators_str = raw_input().split()
    senators = []
    letter = 'A'
    for s in senators_str:
        senators.append( (int(s), letter) )
        letter = chr( ord(letter) + 1)
 
    print "Case #{}: ".format(test_case),
    while (len(senators)>0):
        senators.sort(reverse=True)
        if len(senators) > 2:
            senators[0] = (senators[0][0]-1, senators[0][1])
            print "{}".format(senators[0][1]),
        else:
            if (senators[0][0] == senators[1][0]):
                senators[0] = (senators[0][0]-1, senators[0][1])
                senators[1] = (senators[1][0]-1, senators[1][1])
                print "{}{}".format(senators[0][1], senators[1][1]),
            elif (senators[0][0] > senators[1][0]):
                senators[0] = (senators[0][0]-1, senators[0][1])
                print "{}".format(senators[0][1]),
            else:
                senators[1] = (senators[1][0]-1, senators[1][1])
                print "{}".format(senators[1][1]),
          
        for i in xrange(len(senators)):
            if senators[-i][0] == 0:
                del senators[-i]
    
    
    print ""
    