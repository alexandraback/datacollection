_f_in = open('a.large.in')
_f_out = open('a.large.out', 'w')

def do_it(_f_in):
    N = int(_f_in.readline())
    nums = _f_in.readline().split()
    nums = [int(i) for i in nums]
    s = sum(nums)
    chars = [chr(i) for i in range(65, 65+N)]

    ret = []
    print chars
    while sum(nums) > 0:
        chars = sorted(chars, key=lambda x: -nums[ord(x)-65])
        second = nums[ord(chars[1]) - 65]
        if second * 2 > sum(nums) - 1:
            ret.append(chars[0] + chars[1])
            nums[ord(chars[0]) - 65] -= 1
            nums[ord(chars[1]) - 65] -= 1
        else:
            print chars
            print nums
            c = chars[0]
            ret.append(c)
            nums[ord(c)-65] -= 1

    # chars = sorted(chars, key=lambda x: -nums[ord(x)-65])
    # ret.append(chars[0] + chars[1])
    _f_out.write('{}'.format(' '.join(ret)))


_NUM_CASES = int(_f_in.readline())
for _CASE in range(_NUM_CASES):
    _f_out.write('Case #{}: '.format(_CASE+1))
    do_it(_f_in)
    _f_out.write('\n')

_f_out.close()
_f_in.close()
