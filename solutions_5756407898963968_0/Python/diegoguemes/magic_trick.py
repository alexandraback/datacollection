import sys

def magic_trick(arrangements, answers):
    first_guess = arrangements[0][answers[0] - 1]
    second_guess = arrangements[1][answers[1] - 1]
    intersection = set(first_guess).intersection(second_guess)
    if len(intersection) == 1:
        return intersection.pop()
    if len(intersection) == 0:
        return 'Volunteer cheated!'
    return 'Bad magician!'

T = int(sys.stdin.readline())
for t in range(1, T + 1):
    answers = []
    arrangements = []
    for i in range(2):
        answers.append(int(sys.stdin.readline()))
        arrangements.append([[int(x) for x in sys.stdin.readline().split()] for j in range(4)])
    print('Case #{0}: {1}'.format(t, magic_trick(arrangements, answers)))

