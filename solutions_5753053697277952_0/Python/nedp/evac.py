#!/usr/bin/env python3

def evac(P):
    P = P[:]
    N = len(P)

    # Maintain a stack of lists of evacuees.
    # Each list contains the evacuees which were evacuated at a time.
    evacs = []
    choices = []

    # DFS through the possible choices for evacuation.
    choice = 0
    while P:
        # If we ran out of choices, backtrack.
        while choice == N**2:
            for e in evacs.pop():
                P[e] += 1
            choice = choices.pop()
        assert(choice < N**2)

        # The choices at any one point are:
        # Evacuate any one.
        # Evacuate any pair.
        if (choice < N):
            evacs.append([choice])
        else:
            a = (choice//N) - 1
            b = choice % N
            evacs.append([a, b])
        ##print('trying', list(map(itop, evacs[-1])))

        for e in evacs[-1]:
            P[e] -= 1
        #print('P', P)

        # If we reach a point where a party has strict majority, choose again.
        # Otherwise move to the choice for the next step.
        okay = True
        for p in P:
            #print(p, 'out of', sum(P))
            if (p * 2) > sum(P) or p < 0:
                okay = False
                break
        if okay:
            # If everyone evacuated okay, we're done,
            # else go to the next step.
            if sum(P) == 0:
                #print(evacs)
                return evacs
            choices.append(choice)
            choice = 0
        else:
            for e in evacs.pop():
                P[e] += 1
            # Move to the next choice.
            choice += 1


def oracle(P, evacs):
    # Simulate the evacuation, ensuring that no party has strict
    # majority after any step.
    for evac in evacs:
        for e in evac:
            P[e] -= 1

        for p in P:
            #print('p', p)
            #print('sum(P)', sum(P))
            assert(p * 2 <= sum(P))
            assert(p >= 0)

def itop(i):
    return chr(ord('A') + i)

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        N = int(input())
        P = list(map(int, input().split()))
        assert(len(P) == N)

        evacs = evac(P)
        oracle(P, evacs)

        output = map(lambda es: ''.join(map(itop, es)), evacs)
        print("Case #{}: {}".format(i, ' '.join(output)))
