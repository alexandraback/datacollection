def extract_sizes(strs, letter):
    sizes = []
    for i in range(len(strs)):
        count = 0
        while strs[i].startswith(letter):
            strs[i] = strs[i][1:]
            count += 1
        sizes.append(count)
    return sizes

def solve():
    N = input()
    min = []
    strs = []
    for i in xrange(N):
        new_str = raw_input()
        str_min = ""
        j = 1
        curr = new_str[0]
        while j < len(new_str):
            if new_str[j] != curr:
                str_min += curr
                curr = new_str[j]
            j += 1
        if not str_min.endswith(curr):
            str_min += curr
        min.append(str_min)
        strs.append(new_str)
    a = set(min)
    if len(a) > 1:
        print "Fegla Won"
        return
    moves = 0
    for letter in min[0]:
        sizes = extract_sizes(strs, letter)
        sizes.sort()
        median = sizes[len(sizes)/2]
        moves += sum([abs(median - size) for size in sizes])
    print moves
        
    

if __name__ == "__main__":
    T = input()
    for i in xrange(T):
        print "Case #%d:" % (i+1),
        solve()