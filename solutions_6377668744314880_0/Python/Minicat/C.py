fi = open("C-small-attempt0.in", "r")
fo = open("C-small-attempt0.out", "w")

T = int(fi.readline())

def trees_to_remove(s, trees):
    # Early break - if 3 or less trees, all trees on edge
    if len(trees) < 4:
        return 0
    # For each other squirrel
    best_remove = None
    for s2 in trees:
        if s != s2:
            above = 0
            below = 0
            # stored in this form because float inaccuracies
            gradient_x = s2[0] - s[0]
            gradient_y = s2[1] - s[1]
            # Check above and below the line (ignore on line)
            for s3 in trees:
                if s != s3 and s2 != s3:
                    # Prevent errors with gradient_x = 0
                    if gradient_x == 0:
                        # its a vertical line
                        if s3[0] < s[0]:
                            above += 1
                        elif s3[0] > s[0]:
                            below += 1
                    else:
                        # Extrapolate y of line at that s3.x
                        y = s[1] + (s3[0] - s[0])/float(gradient_x) * gradient_y
                        if y > s3[1]:
                            below += 1
                        elif y < s3[1]:
                            above += 1
            # k
            result = min(above, below)
            if result == 0:
                return 0 # it's on an edge, we're done
            # otherwise save it and continue
            if not best_remove or result < best_remove:
                best_remove = result
    return best_remove


for case in xrange(1, T+1):
    N = int(fi.readline())

    # read in squirrel pairs
    trees = []
    for i in xrange(0, N): 
        trees.append(tuple([int(x) for x in fi.readline().split()]))

    out = "\n".join(["Case #{}:".format(case)] + [str(trees_to_remove(s, trees)) for s in trees])
    print out
    fo.write(out+"\n")





fi.close()
fo.close()
