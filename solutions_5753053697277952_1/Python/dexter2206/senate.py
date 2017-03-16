import string

letters = string.ascii_uppercase


def get_plan(N, P):
    senators = {}
    for k in range(N):
        senators[k] = P[k]

    plan = []
    current_sum = sum(senators.values())
    while current_sum != 0:
        next_plan = ""
        m = max(senators.values())
        k = [k for k in senators if senators[k] == m][0]
        next_plan = letters[k]
        current_sum -= 1
        senators[k] -= 1
        for party in senators:
            if senators[party] > current_sum * 0.5:
                current_sum -= 1
                senators[party] -= 1
                next_plan += letters[party]
                break
        plan.append(next_plan)
    return plan


def main():
    T = int(input())
    for test in range(T):
        N = int(input())
        P = [int(s) for s in input().split()]
        plan = get_plan(N, P)
        print("Case #{0}: {1}".format(
            test+1, " ".join(plan)))

if __name__ == "__main__":
    main()
