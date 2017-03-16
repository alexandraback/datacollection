# coding=utf-8 *** gatopeich for Google Code Jam 2014

# Problem A. Magic Trick

def solution(C,Ps):
    prev = {}
    for i,P in enumerate(Ps,1):
        try:
            return prev[C-P], i
        except:
            prev[P] = i

input = open('A-small-attempt0.in')

T = int(input.readline())
print(T,"cases")

out = open('A-small-attempt0.out', 'w')
for case in range(1, T+1):
    A1 = int(input.readline())
    Row1 = [map(int, input.readline().split()) for _ in range(4)][A1-1]
    A2 = int(input.readline())
    Row2 = [map(int, input.readline().split()) for _ in range(4)][A2-1]

    possible = list(set(Row1).intersection(Row2))

    solution = possible[0] if len(possible)==1 else 'Volunteer cheated!' if len(possible)==0 else 'Bad magician!'

    print('Case #%d:'%case, solution, file=out)

out.close()
