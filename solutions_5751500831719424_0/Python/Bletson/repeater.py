def integer_distance_to_median(points):
    points.sort()
    l = len(points)
    median = points[l/2]
    return sum([abs(median - x) for x in points])

def n_conversions(strings):
    compressed = [compress(s) for s in strings]
    for c in compressed[1:]:
        if c[0] != compressed[0][0]:
            return "Fegla Won"
    letterwise = [[compressed[i][1][j] for i in xrange(len(compressed))] for j in xrange(len(compressed[0][0]))]
    moves = sum([integer_distance_to_median(x) for x in letterwise])
    return moves


def compress(string):
    letters = [string[0]]
    counts = [1]
    for let in string[1:]:
        if let == letters[-1]:
            counts[-1] += 1
        else:
            letters.append(let)
            counts.append(1)
    return letters, counts


with open("repeater_small.txt", "rb") as f:
    t = int(f.next().strip())
    answers = []
    for _ in xrange(t):
        n = int(f.next().strip())
        strings = []
        for __ in xrange(n):
            strings.append(f.next().strip())
        answers.append(n_conversions(strings))

with open("repeater_small_ans.txt", "wb") as g:
    g.write("\r\n".join(["Case #%d: %s" % (i + 1, str(answers[i])) for i in xrange(len(answers))]))

