from __future__ import print_function

def remove_double(word):
    last = False
    nw = ""
    for c in word:
        if c != last:
            nw += c
        last = c
    return nw

def min_count(l):
    mini = 9999999
    temp = max(l)
    for i in xrange(temp):
        v = 0
        for j in l:
            v += abs(j - (temp - i))
        if v < mini:
            mini = v
        if v > mini:
            break
    return mini

def count_letter(word):
    i = 1
    l = word[0]
    while(len(word) > i and word[i] == l):
        i+=1
    word = word[i:]
    return i, word

if __name__ == '__main__':
    T = int(raw_input())
    for pb_i in xrange(T):
        N = int(raw_input())
        words = []
        for i in xrange(N):
            words.append(raw_input())

        # is possible ?
        a = remove_double(words[0])
        c = False
        for word in words:
            if remove_double(word) != a:
                result = "Fegla Won"
                print("Case #{}: {}".format(pb_i+1, result))
                c = True
                continue
        if c:
            continue

        # diff
        result = 0
        for letter in a:
            occ = []
            for i in xrange(len(words)):
                count, words[i] = count_letter(words[i])
                occ.append(count)
            res = min_count(occ)
            result += res

        print("Case #{}: {}".format(pb_i+1, result))