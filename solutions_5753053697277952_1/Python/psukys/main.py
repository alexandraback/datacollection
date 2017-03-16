alphabet_base = 65

def check_majority(members):
    majority = sum(members) / 2
    return any([m > majority for m in members])

def evacuate(members):
    # Find biggest party:
    plan = []
    while any(members):
        tmp = members
        first_ind = tmp.index(max(tmp))
        tmp[first_ind] = tmp[first_ind] - 1
        if max(tmp) != 0:
            second_ind = tmp.index(max(tmp))
            tmp[second_ind] = tmp[second_ind] - 1
        if check_majority(tmp):
            # Add only the first one
            plan.append(chr(alphabet_base + first_ind))
        else:
            # Add both
            plan.append(chr(alphabet_base + first_ind) + chr(alphabet_base + second_ind))
        members = tmp
    return plan

test_cases = int(raw_input())
for i in xrange(1, test_cases + 1):
    parties = int(raw_input())
    members = [int(s) for s in raw_input().split(" ")]
    print "Case #{0}: {1}".format(i, ' '.join(evacuate(members)))
