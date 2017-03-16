import sys

import numpy as np 

letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def evacuation_plan(inputline):
    ### inputline is the second line of the testcase
    senators = np.array([int(s) for s in inputline.split(" ")])
    ret = ''
    while sum(senators)>3:
        print(sum(senators))
        tmpsens = np.array(senators)
        tmpsens[senators.argmax()] -= 1
        tmpsens = tmpsens/tmpsens.sum()
        if tmpsens.max()<.5:
            ret += letters[senators.argmax()] + ' '
            senators[senators.argmax()] -= 1
        else:
            party1 = senators.argmax()
            tmpsens[senators.argmax()] = 0
            party2 = tmpsens.argmax()
            ret += letters[party1] + letters[party2] + ' '
            senators[party1] -= 1
            senators[party2] -= 1
        print(ret, senators)

    print(sum(senators))
    print()

    if sum(senators)==3:
        ret += letters[senators.argmax()] + ' '
        senators[senators.argmax()] -= 1

    ret += letters[senators.argmax()]
    senators[senators.argmax()] -= 1
    ret += letters[senators.argmax()]
    senators[senators.argmax()] -= 1

    return ret



if "__main__" == __name__:
    
    # print(sys.argv[1])
    inputfile = sys.argv[1]

    out = []
    with open(inputfile, 'r') as f:
        T = int(f.readline())
        for _ in range(T):
            f.readline()
            out.append(evacuation_plan(f.readline()))
    
    with open("out_"+inputfile, 'w') as f:
        for i, o in enumerate(out):
            f.write("Case #{}: {}\n".format(i+1, o))
            print("Case #{}: {}".format(i+1, o))
