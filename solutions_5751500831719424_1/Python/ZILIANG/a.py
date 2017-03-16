from multiprocessing import Pool

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret

#======================== BOF  =============================#

def reduce_str(s):
    ret = ''
    for i in range(len(s)):
        if i == 0 or s[i] != s[i-1]:
            ret += s[i]
    return ret


def min_mod(nums):
    ans = 1e100
    for select in set(nums):
        cnt = 0
        for num in nums:
            cnt += abs(num - select)
        ans = min(ans, cnt)
    return ans


def solver(data_container):
    N = data_container.N
    strs = data_container.strs
    if len(set(map(reduce_str, strs))) != 1:
        return 'Fegla Won'

    reduced = reduce_str(strs[0])
    ans = 0
    for c in reduced:
        nums = []
        for i, s in enumerate(strs):
            cnt = 0
            while s and s[0] == c:
                s = s[1:]
                cnt += 1
            strs[i] = s
            nums.append(cnt)

        ans += min_mod(nums)

    return str(ans)


class DataContainer:
    def __init__(self):
        self.N = input()
        self.strs = [raw_input() for _ in range(self.N)]
        pass # read data

#======================== EOF  =============================#


if __name__ == '__main__':
    NUM_THREAD = 2
    USE_MULTI = False

    T = input()
    input_queue = [DataContainer() for _ in xrange(T)]
    
    if USE_MULTI:
        pool = Pool(NUM_THREAD)
        result = pool.map(solver, input_queue)
    else:
        result = []
        for i in xrange(T):
            result.append(solver(input_queue[i]))

    for i in range(T):
        print 'Case #%d: %s' % (i+1, result[i])
