alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def solve(senators):
    senators.sort(key=lambda x: x[1], reverse=True)
    sol = ''
    while senators[0][1] > senators[1][1]:
        if senators[0][1] == senators[1][1] + 1:
            sol += senators[0][0]
            senators[0][1] -= 1
        else:
            sol += senators[0][0]*2
            senators[0][1] -= 2
        sol += ' '
    while len(senators)>2:
        if senators[-1][1] > 1:
            sol += senators[-1][0]*2
            senators[-1][1] -= 2
        else:
            sol += senators[-1][0]
            senators[-1][1] -= 1
        if senators[-1][1] == 0:
            senators.pop()
        sol += ' '
    remaining = senators[0][1]
    pair = senators[0][0]+senators[1][0]+' '
    sol += pair*remaining
    return sol


if __name__ == '__main__':
    T = int(input())
    for case in range(1,T+1):
        N = int(input())
        senators = [[alphabet[index],int(n)] for index,n in enumerate(input().split())]
        print("Case #{0}: {1}".format(case,solve(senators)))