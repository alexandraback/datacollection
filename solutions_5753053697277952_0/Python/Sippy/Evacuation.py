import operator

def count_no_zero(map_alp_num):
    count = 0
    for i in map_alp_num:
        if map_alp_num[i] != 0: count += 1
    return count

def two_alph(map_alp_num):
    arr = []
    for i in map_alp_num:
        if map_alp_num[i] != 0: arr.append(i)
    return arr


def calc(in_file):
    n = int(in_file.readline())
    ps = map(int, in_file.readline().split())
    map_alp_num = dict()
    str = ord('A')
    map_alp_num = dict()
    for i in range(len(ps)):
        map_alp_num[chr(str + i)] = ps[i]

    ans = ""
    while count_no_zero(map_alp_num) > 2:
        alph = max(map_alp_num.iterkeys(), key=(lambda key: map_alp_num[key]))
        map_alp_num[alph] -= 1
        ans = ans + alph + " "

    while count_no_zero(map_alp_num) > 0:
        a1, a2 = two_alph(map_alp_num)
        map_alp_num[a1] -= 1
        map_alp_num[a2] -= 1
        ans = ans + a1 + a2 + " "

    return ans


if __name__ == '__main__':
    in_file = open("input.txt")
    ou_file = open("output.txt", 'w')
    T = int(in_file.readline())
    for t in range(T):
        ans = calc(in_file)
        ou_file.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    ou_file.close()
