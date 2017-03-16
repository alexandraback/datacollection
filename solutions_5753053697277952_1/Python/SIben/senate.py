def parsing():
    nb_tests = int(raw_input())
    cases = []
    
    for _ in range(nb_tests):
        nb_parties = raw_input()
        cases.append([int(a) for a in raw_input().split(' ')])
    
    return (nb_tests, cases)

def display(case_number, result):
    print "Case #" + str(case_number) + ": " + str(result)

def solve(case, nb_parties):
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    evacuation_plan = ''
    while len([a for a in case if a != 0]) != 0:
        max_party = 0
        amount = case[0]
        case_solution = ''

        for i in range(1, len(case)):
            if case[i] > amount:
                max_party = i
                amount = case[i]

        case[max_party] = amount - 1

        case_solution += alphabet[max_party]

        possible_other = []

        for i in range(0, len(case)):
            if case[i] == amount:
                possible_other.append(i)

        if len(possible_other) == 1:
            case[possible_other[0]] = amount - 1
            case_solution += alphabet[possible_other[0]]

        case_solution += ' '
        evacuation_plan += case_solution

    return evacuation_plan

def main():
    nb_tests, cases = parsing()
    for i in range(nb_tests):
        display(i + 1, solve(cases[i], len(cases[i])))

if __name__=='__main__':
    main()
