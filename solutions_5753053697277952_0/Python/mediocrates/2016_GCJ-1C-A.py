def solve(ns):
    order = []
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    remaining = {letter: 0 for letter in letters}
    for i, n in enumerate(ns):
        remaining[letters[i]] = n
    parties = letters[:len(ns)]
    left = sum(ns)
    while left > 0:
        if left == 1:
            max_p = [p for p in parties if remaining[p] > 0][0]
            order.append(max_p)
            left -= 1
            remaining[max_p] -= 1
        elif left ==  2:
            max_ps = [p for p in parties if remaining[p] > 0]
            if len(max_ps) == 1:
                order.append(max_p + max_p)
                remaining[max_p] -= 2
            else:
                order.append(''.join(max_ps))
            left -= 2
        elif left == 3:
            # Can never remove 2 here
            max_ps = [p for p in parties if remaining[p] == max(remaining.values())]
            order.append(max_ps[0])
            remaining[max_ps[0]] -= 1
            left -= 1
        else:
            max_ps = [p for p in parties if remaining[p] == max(remaining.values())]
            # others = [p for p in parties if 0 < remaining[p] < max(ns)]
            if len(max_ps) > 1:
                order.append(max_ps[0] + max_ps[1])
                remaining[max_ps[0]] -= 1
                remaining[max_ps[1]] -= 1
                left -=2
            else:
                order.append(max_ps[0] + max_ps[0])
                remaining[max_ps[0]] -= 2
                left -=2

    return order


def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            t = int(f.readline().strip())
            for i in range(1, t+1):
                _ = int(f.readline().strip())
                senators = map(int, f.readline().strip().split())
                order = solve(senators)
                print "Case #%d: %s" % (i, ' '.join(order))

if __name__ == '__main__':
    main()
