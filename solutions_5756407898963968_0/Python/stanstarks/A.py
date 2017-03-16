import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

################################################################################

def read_case(f):
    r1 = read_int(f)
    m1 = []
    for i in range(4):
        m1.append(read_ints(f))
    r2 = read_int(f)
    m2 = []
    for i in range(4):
        m2.append(read_ints(f))
    return (r1, m1, r2, m2)

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')


################################################################################

def solve_small(case):
    r1, m1, r2, m2 = case
    x = [set(a) for a in [m1[r1-1], m2[r2-1]]]
    s = set.intersection(*x)
    if len(s) == 0:
        return "Volunteer cheated!"
    if len(s) > 1:
        return "Bad magician!";
    return s.pop()
    
solve_large = solve_small

solve(solve_large, 'A-small-attempt0')
