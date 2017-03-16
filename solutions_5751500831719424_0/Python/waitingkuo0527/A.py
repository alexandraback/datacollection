def solve(N, S):
    """ solve the problem """

    #print(N)
    #print(S)

    cutted_S = []
    for s in S:
        cutted_s = ''
        last_ch = None
        for ch in s:
            if ch != last_ch: cutted_s += ch
            last_ch = ch
        cutted_S.append(cutted_s)

    #print( set(cutted_S) )
    if len(set(cutted_S)) != 1: return 'Fegla Won'

    count = 0
    sections = []
    for s in S:
        sec = []
        last_ch = None
        c = 0
        #print(s)
        for ch in s:
            if last_ch is None:
                c += 1
            elif ch != last_ch :
                sec.append(c)
                c = 1
            else:
                c += 1
            last_ch = ch
        sec.append(c)
        sections.append(sec)
    #print(sections)

    count = 0
    for i in range(len(sections[0])):
        arr = [sec[i] for sec in sections]
        arr.sort()
        mi = int(len(arr) / 2)
        m = arr[mi]
        count += sum( abs(m-j) for j in arr )

    return count


def parse():
    """ parse input """

    N = int(input())
    S = []
    for i in range(N): 
        S.append(input())

    return N, S


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
