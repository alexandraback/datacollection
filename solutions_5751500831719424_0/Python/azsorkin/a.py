#! /usr/bin/env python

def main():
    with open('a.in', 'r') as fin, open('a.out', 'w') as fout:
        num_cases = int(fin.readline())
        for case in range(1, num_cases + 1):
            num_strings = int(fin.readline())
            strings = [fin.readline().strip('\n') for _ in range(num_strings)]
            answer = solve(splitter(strings))
            fout.write('Case #{0}: {1}\n'.format(case, answer))
    return


def splitter(strings):
    """strings = [s1, s2, ...]
    output: [t1, ...]
    e.g., s1 = 'mmaw', t1 = ['mm', 'a', 'w']
    s1 = 'abbcdd' t1 = ['a', 'bb', 'c', 'dd']
    """
    split_strings = []
    for s in strings:
        new_s = [s[0]]
        s = s[1:]
        while s:
            if s[0] == new_s[-1][0]:
                new_s[-1] += s[0]
            else:
                new_s.append(s[0])
            s = s[1:]
        split_strings.append(new_s)
    return split_strings

def solve(split_strings):
    no_soln = 'Fegla Won'
    if (len(max(split_strings, key=len))
        != len(min(split_strings, key=len))):  # different sizes, no soln
        return no_soln
    strings = [[s[i] for s in split_strings] for i in range(len(split_strings[0]))]
    num_actions = 0
    for s in strings: # s = list of strings of form 'x'*k for k an int
        if len(set(''.join(s))) != 1:  # not all strings same repeated letter
            return no_soln
        t = [len(x) for x in s]
        num_action = float('inf')
        for len_str in range(min(t), max(t) + 1):
            num_action = min(num_action, sum([abs(len_str - x) for x in t]))
        num_actions += num_action
    return num_actions




if __name__ == '__main__':
    main()
