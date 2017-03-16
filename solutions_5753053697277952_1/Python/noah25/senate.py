# Google Code Jam 2016 Round 1C
# Problem A. Senate Evacuation

def majority(senators):
    if max(senators) == 0:
        return True
    return 2*max(senators) > sum(senators)

def evacuate(N, senators):
    new = [i for i in senators]
    order = ''
    while max(new) != 0:
        m = 0
        position = 0
        for i in range(N):
            if new[i] > m:
                position = i
                m = new[i]
        possible = [i for i in new]
        done = False
        if possible[position] > 1:
            possible[position] -= 2
            if not majority(possible):
                order += 2*chr(position + 65) + ' '
                done = True
            else:
                possible[position] += 2
        if not done:
            possible[position] -= 1
            if possible == N*[0] or not majority(possible):
                order += chr(position + 65) + ' '
                done = True
        if not done:
            n = 0
            second = 0
            for i in range(N):
                if i != position and new[i] > n:
                    n = new[i]
                    second = i
            possible[second] -= 1
            order += chr(position + 65)
            order += chr(second + 65) + ' '
        new = possible
    return order[:-1]

def senate():
    f = open('commands.txt', 'r')
    g = open('senate.txt', 'w')
    line = 0
    part = 0
    for i in f:
        if line == 0:
            T = int(i)
            line = 1
        else:
            if part == 0:
                N = int(i)
                part = 1
            else:
                senators = []
                current = ''
                for j in i:
                    if j in [' ', '\n']:
                        senators += [int(current)]
                        current = ''
                    else:
                        current += j
                g.write('Case #' + str(line) + ': ')
                g.write(evacuate(N, senators))
                g.write((T != line)*'\n')
                part = 0
                line += 1
    f.close()
    g.close()
