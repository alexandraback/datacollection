from sys import stdin, stdout

T = int(stdin.readline())
for i in xrange(1, T + 1):
    first_row = int(stdin.readline())
    first_arrangement = [stdin.readline().strip().split(' ') for num in xrange(4)]
    second_row = int(stdin.readline())
    second_arrangement = [stdin.readline().strip().split(' ') for num in xrange(4)]
    result_set = set.intersection(set(first_arrangement[first_row - 1]), set(second_arrangement[second_row - 1]))
    if len(result_set) == 0:
        result_text = 'Volunteer cheated!'
    elif len(result_set) > 1:
        result_text = 'Bad magician!'
    else:
        result_text = result_set.pop()
    stdout.write('Case #%d: %s\n' % (i, result_text))