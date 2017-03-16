from __future__ import absolute_import, division, print_function

oa = ord('A')

def solve(count):
    exit = ''

    while True:
        biggest = None

        for pos,c in enumerate(count):
            if biggest is None or c > count[biggest]:
                biggest = pos

        equal_biggest = None

        for pos,c in enumerate(count):
            if c == count[biggest] and pos != biggest:
                equal_biggest = pos
                break

        if sum(count) == 3: # special case
            count[biggest] -= 1
            exit += chr(oa + biggest)
        else:
            if equal_biggest is None:
                if count[biggest] == 1:
                    count[biggest] -= 1
                    exit += chr(oa + biggest)
                else:
                    count[biggest] -= 2
                    exit += chr(oa + biggest) + chr(oa + biggest)
            else:
                count[biggest] -= 1
                count[equal_biggest] -= 1
                exit += chr(oa + biggest) + chr(oa + equal_biggest)

        exit += ' '

        if sum(count) == 0:
            break
    return exit.strip()



#with open('A-sample.in') as f:
with open('A-small-attempt0.in') as f:
#with open('A-large.in') as f:
    T = int(f.readline())

    for puzzle_count in range(T):
        n_sen = f.readline().strip()
        senators = f.readline().strip()
        count = map(int, senators.split(' '))

        ans = solve(count)

        print('Case #%s: %s' % (str(puzzle_count + 1), ans))

