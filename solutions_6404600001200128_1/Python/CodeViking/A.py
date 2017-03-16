import os, sys


class ReadWrite:
    def __init__(self, file_name=None, verbose=True):
        self.verbose = verbose
        if file_name is None:
            self.in_file = sys.stdin
            self.out_file = sys.stdout
        else:
            self.in_file = open(file_name)
            self.out_file = open(os.path.splitext(file_name)[0] + '.out', 'w')
        self.case_idx = 1


    def msg(self, output, end='\n'):
        sys.stderr.write(str(output) + end)


    def read_line(self, *types, all=None):
        words = self.in_file.readline().strip().split()
        if all is not None:
            return [all(w) for w in words]
        if len(types) == 0:
            return words
        assert (len(words) == len(types))
        if len(types) == 1:
            return types[0](words[0])
        return [t(w) for t, w in zip(types, words)]


    def write_case(self, output, true="YES", false="NO", join='\n'):
        pfx = "Case #%d:" % self.case_idx
        self.case_idx += 1
        if isinstance(output, list):
            text = join.join([pfx] + output)
        elif isinstance(output, bool):
            text = pfx + ' ' + (true if output else false)
        else:
            text = pfx + ' ' + str(output)
        self.out_file.write(text + '\n')
        if self.verbose:
            self.msg(text)
        else:
            self.msg(pfx)


def mush1(mushrooms):
    eaten = 0
    m_last = mushrooms[0]
    for m in mushrooms[1:]:
        if m_last > m:
            eaten += m_last - m
        m_last = m
    return eaten


def mush2(mushrooms):
    def min_rate(mushrooms):
        m_last = mushrooms[0]
        mr = 0
        for m in mushrooms[1:]:
            if m_last > m:
                eaten = m_last - m
                mr = max(eaten, mr)
            m_last = m
        return mr

    rate = min_rate(mushrooms)
    plate = mushrooms[0]
    eaten = 0
    for m in mushrooms[1:]:
        assert plate - rate <= m
        eaten += min(plate, rate)
        plate = m

    # this still might not be enough
    return eaten


def solve_mushrooms(mushrooms):
    return mush1(mushrooms), mush2(mushrooms)


if __name__ == '__main__':
    input_name = sys.argv[1] if len(sys.argv) > 1 else 'A-tiny-practice.in'
    rw = ReadWrite(input_name)
    T = rw.read_line(int)
    for t in range(T):
        N = rw.read_line(int)
        rw.write_case("%d %d" % solve_mushrooms(rw.read_line(all=int)))
