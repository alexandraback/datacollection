import re
from operator import itemgetter

def normalise(string):
    return re.sub(r"((.)\2*)", r"\2", string)

def group(string):
    return map(itemgetter(0), re.findall(r"((.)\2*)", string))

def operations(groups, N):
    operations = 0
    center = N // 2
    for group in groups:
        group = sorted(group, key=len)
        median_len = len(group[center])
        for i, seq in enumerate(group):
            if i == center: continue
            operations += abs(median_len - len(seq))
    return operations

def main():
    num_cases = int(input())
    for case in range(1, num_cases + 1):
        N = int(input())
        strings = []
        for i in range(N):
            strings.append(input().strip())

        normalised = list(map(normalise, strings))
        groups = zip(*map(group, strings))

        output = "Fegla Won"
        if len(set(normalised)) == 1:
            output = operations(groups, N)
        
        print("Case #{}: {}".format(case, output))

if __name__ == '__main__':
    main()
