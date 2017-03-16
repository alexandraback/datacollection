#!/usr/bin/python3

def get_party(pid):
    return(chr(ord('A') + pid))


def evacuate(parties, case_id):
    order = [_ for _ in range(len(parties))]
    solution = ""
    
    while (sum(parties) > 0):
        order.sort(key=lambda ii: parties[ii], reverse=True)
        total = sum(parties)
        if (total == 3):
            solution += get_party(order[0])
            parties[order[0]] -= 1
        elif (total == 2): # Finish the evacuation
            if (parties[order[0]] == 2): # Should not happen, except as initial situation
                solution += get_party(order[0]) + get_party(order[0])
                parties[order[0]] -= 2
            else:
                solution += get_party(order[0]) + get_party(order[1])
                parties[order[0]] -= 1
                parties[order[1]] -= 1
        else:
            solution += get_party(order[0]) + get_party(order[1])
            parties[order[0]] -= 1
            parties[order[1]] -= 1

        solution += " "

    print("Case #" + str(case_id+1) + ": " + solution.strip())

TT = int(input())
for ii in range(TT):
    NN = int(input())
    parties = [int(_) for _ in input().split(" ")]
    evacuate(parties, ii)
