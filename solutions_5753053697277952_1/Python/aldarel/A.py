

if __name__ == '__main__':
    t = int(input())
    for z in range(1, t+1):
        n = int(input())
        p = [int(s) for s in raw_input().split(" ")]
        p_sum = sum(p)
        answer = str()
        while p_sum > 0:
            p_sum = sum(p)
            p_max = max(p)
            max_indexes = [i for i, j in enumerate(p) if j == p_max]
            if p_sum == 3:
                p[max_indexes[0]] -= 1
                answer += chr(ord('A') + max_indexes[0])
                answer += " "
            else:
                if len(max_indexes)>1:
                    p[max_indexes[0]] -= 1
                    answer += chr(ord('A') + max_indexes[0])
                    p[max_indexes[-1]] -= 1
                    answer += chr(ord('A') + max_indexes[-1])
                    answer += " "
                else:
                    p[max_indexes[0]] -= 2
                    answer += chr(ord('A') + max_indexes[0])
                    answer += chr(ord('A') + max_indexes[0])
                    answer += " "
            p_sum = sum(p)
        print("Case #%d: %s" % (z, answer))
