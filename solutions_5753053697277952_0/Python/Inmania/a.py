
def solve(l_of_s):
    as_list = solve_(l_of_s)
    #print as_list
    return ' '.join(as_list)

def solve_(list_of_senators):
    evac = []
    alphabet = [chr(x) for x in range(65, 90)]
    tagged_list = zip(list_of_senators, alphabet)
    tagged_sorted = sorted(tagged_list, key=lambda x: x[0], reverse=True)
    #print "tagged_sorted", tagged_sorted
    most = tagged_sorted[0]
    second = tagged_sorted[1]
    #make two biggest the same
    if most[0] > second[0]:
        first_to_leave = [most[1]] * (most[0] - second[0])
        evac.extend(first_to_leave)
        most = (second[0], most[1])
        #print "start: ", evac
    middle = all_leave(tagged_sorted[2:])
    #print "middle: ", middle
    evac_pair = ''.join([most[1], second[1]])
    #print evac_pair
    end = [evac_pair] * most[0]
    #print end
    evac.extend(middle)
    evac.extend(end)
    return evac

def all_leave(s_l):
    if s_l == []:
        return []
    else:
        evac = []
        for party in s_l:
            #print "party: ", party
            num, letter = party
            evac.extend([letter] * num)
    return evac
if __name__=="__main__":
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        n = [int(s) for s in raw_input().split(" ")]
        list_in = [int(s) for s in raw_input().split(" ")]
        print "Case #{}: {}".format(i, solve(list_in))
          # check out .format's specification for more formatting options
