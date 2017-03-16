from __future__ import division
import string

t = int(raw_input(""))
for case in range(t): 
    n = raw_input("")
    parties_n = raw_input("").split(" ")
    parties_n = [int(a) for a in parties_n]
    parties_alph = list(string.ascii_uppercase)
    parties = zip(parties_n, parties_alph)
    parties = [list(tup) for tup in parties]
    sum_people = sum(parties_n)
    result = ""
    while sum_people:
        parties.sort(reverse=True)
        if not (parties[1][0] > (sum_people - 2) / 2):
            parties[0][0] -= 2
            sum_people -= 2
            result += parties[0][1] * 2 + " "
        elif not (parties[1][0] > (sum_people - 1) / 2):
            parties[0][0] -= 1
            sum_people -= 1
            result += parties[0][1] + " "
        else:
            parties[0][0] -= 1
            parties[1][0] -= 1
            sum_people -= 2
            result += parties[0][1]
            result += parties[1][1] + " "
    print "Case #%s: %s" % (case + 1, result)

