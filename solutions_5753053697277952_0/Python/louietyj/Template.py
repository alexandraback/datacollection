with open('A-small-attempt0 (4).in', 'r') as f:
    data = f.read()

data = data.split('\n')
output = []

def is_majority(parties):
    for party in parties:
        if 2 * party > sum(parties):
            return True
    return False

def to_alphabet(index):
    return chr(ord('A') + index)

print(data.pop(0), 'cases.\n')
while data:
    if data[0] == '':
        break
    data.pop(0)
    parties = list(map(int, data.pop(0).split(' ')))
    answer = []
    while sum(parties) > 0:
        curr_p = max(enumerate(parties), key=lambda x: x[1])[0]
        parties[curr_p] -= 1
        next_p = max(enumerate(parties), key=lambda x: x[1])[0]
        parties[next_p] -= 1
        if is_majority(parties): # cannot
            parties[next_p] += 1
            answer.append(to_alphabet(curr_p))
        else:
            answer.append(to_alphabet(curr_p) + to_alphabet(next_p))
    output.append(' '.join(answer))

with open('submission.txt', 'w+') as f:
    i = -1
    for i, answer in enumerate(output):
        f.write("Case #%i: %s\n" % (i+1, answer))
        print("Case #%i: %s" % (i+1, answer))
    print('\n%i cases written to file' % (i+1))
