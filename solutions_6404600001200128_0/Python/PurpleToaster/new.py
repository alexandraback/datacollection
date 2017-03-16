def method1(plates):
    changes = zip(plates[:-1], plates[1:])
    return sum([a-b for a, b in changes if a > b])

def method2(plates):
    changes = zip(plates[:-1], plates[1:])
    rate = max([a-b if a > b else 0 for a, b in changes])
    print(rate, [rate if m > rate else m for m in plates])
    return sum([rate if m > rate else m for m in plates[:-1]])

filename = '.\data\A-small-attempt0'
output = ''
with open(filename+'.in', 'r') as file:
    case_num = 0
    _ = file.readline()  # Number of cases
    line = file.readline()  # Number of plates with pancakes
    while line is not '':
        case_num += 1
        txt = file.readline().strip('\n').split(' ')
        plates = list(map(int, txt))
        output += 'Case #{}: {} {}\n'.format(case_num, method1(plates), method2(plates))
        line = file.readline()

with open(filename+'.out', 'w') as file:
    file.write(output)