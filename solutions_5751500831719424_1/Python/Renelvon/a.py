def uniques(s):
    cur_char = None
    groups = []
    cur_group = []
    for char in s:
        if cur_char is None or char != cur_char:
            if cur_char is not None:
                groups.append(cur_char)
            cur_char = char
    groups.append(cur_char)
    return groups

def rle(s):
    cur_char = None
    groups = []
    counter = 0
    for char in s:
        if cur_char is None or char != cur_char:
            if cur_char is not None:
                groups.append(counter)
            cur_char = char
            counter = 1
        else:
            counter += 1
    groups.append(counter)
    return groups

def solve(N, strings):
    unique_seq = uniques(strings[0])
    for string in strings[1:]:
        if uniques(string) != unique_seq:
            return -1
    
    rlest = list(zip(*[rle(s) for s in strings]))

    moves = 0
    for group in rlest:
        moves += min(sum([abs(level - c) for c in group]) for level in group)
    return moves

def main():
    T = int(input())
    for i in range(1, T + 1):
        N = int(input())
        strings = [input().strip() for s in range(N)]
        moves = solve(N, strings)
        #print(N, L, outlets, devices)
        if moves > -1:
            print('Case #', i, ': ', moves, sep='')
        else:
            print('Case #', i, ': Fegla Won', sep='')

if __name__ == "__main__":
    main()
