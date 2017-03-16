import fileinput, sys, operator

def next_from(d):
    return max(d.iteritems(), key=operator.itemgetter(1))[0]

def slurp(numbers):
    letters = {}
    l = 'A'
    for i in range(0, len(numbers)):
        letters[l] = int(numbers[i])
        l = chr(ord(l) + 1)
    return letters

def solve(s):
    senators = slurp(s.rstrip().split())
    #sorted_s = sorted(senators.items(), key=operator.itemgetter(1), reverse=True)
    num_senators = sum(senators.values())

    output = ""

    if num_senators % 2 == 1:
        max_key = next_from(senators)
        output = output + max_key + " "
        senators[max_key] = senators[max_key] - 1
        num_senators = num_senators - 1

    while num_senators > 0:
        max_key = next_from(senators)
        output = output + max_key
        senators[max_key] = senators[max_key] - 1
        num_senators = num_senators - 1

        max_key = next_from(senators)
        output = output + max_key
        senators[max_key] = senators[max_key] - 1
        num_senators = num_senators - 1

        output = output + " "

    return output

index = 0
for line in fileinput.input():
    index += 1
    if index == 1:
        continue
    if index % 2 == 0:
        continue
    print("Case #%d: %s" % ((index - 1)/2, solve(line)))
