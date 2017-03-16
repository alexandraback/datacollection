if __name__ == "__main__":
    with open('1input.txt', 'r') as infile, open('1output.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(map(int, line.split()))

        N = int(data[0][0])
        i = 1
        for s in xrange(N):
            cards = []
            for turn in xrange(2):
                chosen = data[i][0] - 1
                i+=1
                cards.append(data[i + chosen])
                i+=4
            union = list(set(cards[0]) & set(cards[1]))
            if len(union) == 1:
                str = "Case #{0}: {1}\n".format(s+1, union[0])
            elif len(union) == 0:
                str = "Case #{0}: Volunteer cheated!\n".format(s+1)
            else:
                str = "Case #{0}: Bad magician!\n".format(s+1)
            outfile.write(str)
