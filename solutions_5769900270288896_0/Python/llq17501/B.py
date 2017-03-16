#!/usr/bin/env python
#-*- coding:utf-8 -*-


from itertools import combinations

def r(R, C, k):
    result = 0
    for i in k:
        if (i + 1) % C != 0 and i + 1 in k:
            result += 1
        if i + C in k:
            result += 1
    return result

def f(R, C, N):
    return min(r(R, C, k) for k in combinations(range(R * C), N))

def main():
    f_name = "B-small-attempt0"
    in_f = "{0}.in".format(f_name)
    out_f = "{0}.out".format(f_name)
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file).strip()
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f() for i in range(n)]
        T = read_int()
        for i in range(T):
            R, C, N = read_ints()
            result = f(R, C, N)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
