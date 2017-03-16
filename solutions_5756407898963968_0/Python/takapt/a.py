T = int(input())
for case_no in range(1, T + 1):
    def solve():
        def cards():
            y = int(input())
            a = [input().split() for i in range(4)]
            return a[y - 1]

        f = cards()
        s = cards()
        common = list(set(f) & set(s))
        if len(common) == 1:
            return common[0]
        elif len(common) == 0:
            return "Volunteer cheated!"
        else:
            return "Bad magician!"

    print("Case #{}: {}".format(case_no, solve()))
