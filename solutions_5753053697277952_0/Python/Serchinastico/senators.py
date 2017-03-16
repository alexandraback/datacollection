import fileinput


party_names = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def is_valid_situation(senators):
    total_count = 0
    max_count = 0
    for party, count in senators.iteritems():
        total_count += count
        if count > max_count:
            max_count = count

    if total_count == 0:
        return True

    return (float(max_count) / total_count) <= 0.5


def pick_next_evacuated_senator(senators):
    next_party = None
    next_count = 0
    for party, count in senators.iteritems():
        if count > next_count:
            next_party = party
            next_count = count
    return next_party


def evacuate(senators):
    evacuations = []
    while senators:
        party1 = pick_next_evacuated_senator(senators)
        senators[party1] -= 1
        party2 = pick_next_evacuated_senator(senators)
        senators[party2] -= 1

        if is_valid_situation(senators):
            evacuations.append(party1 + party2)
        else:
            senators[party2] += 1
            evacuations.append(party1)

        senators = {k: v for k, v in senators.iteritems() if v > 0}

    return " ".join(evacuations)


def read_problems():
    problems = []
    lines = fileinput.input()
    for i in range(1, int(lines[0]) * 2, 2):
        parties_count = int(lines[i])
        senators_raw = lines[i + 1].split()
        senators = {}
        for j in range(parties_count):
            senators[party_names[j]] = int(senators_raw[j])
        problems.append(senators)
    return problems

problems = read_problems()
for i, problem in enumerate(problems):
    solution = evacuate(problem)
    print "Case #" + str(i + 1) + ": " + solution
