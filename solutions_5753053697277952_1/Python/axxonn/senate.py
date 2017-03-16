def c(i): # char of int, 0-indexed (0 = 'A')
    return chr(i+ord('A'))

t = int(raw_input())
for case in range(1, t+1):
    n = int(raw_input())
    ps = map(int, raw_input().split(" "))
    x = max(ps) # highest number of senators in single party
    array = [[1 if ps[j] >= (x-i) else 0 for j in range(n)] for i in range(x)]
    #print ps
    #print array
    seq = []
    for line in array:
        ones = []
        for i in range(len(line)):
            if line[i] == 1:
                ones.append(i)
        # for each number, pick off one senator if the number of parties at that
        # number is odd, then pick off two at a time
        if len(ones) % 2 == 1:
            last = ones.pop()
            seq.append(c(last))
        for i in range(len(ones) / 2):
            seq.append(c(ones[2*i]) + c(ones[2*i+1]))
    print "Case #%d: %s" % (case, " ".join(seq))
