filename = 'input.txt'

with open(filename) as f:
    cases = int(f.readline()[:-1])

    def process():
        card_row = int(f.readline()[:-1])
        grid = []
        for _ in range(4):
            line = f.readline()[:-1]
            row = [int(n) for n in line.split()]
            grid.append(row)
        return card_row, grid

    for case in range(cases):
        case = case + 1
        row, grid = process()
        cards = grid[row - 1]

        row, grid = process()
        cards = [c for c in cards if c in grid[row - 1]]
        if len(cards) == 0:
            print "Case #%s: Volunteer cheated!" % (case,)
        elif len(cards) == 1:
            print "Case #%s: %s" % (case, cards[0])
        else:
            print "Case #%s: Bad magician!" % (case,)