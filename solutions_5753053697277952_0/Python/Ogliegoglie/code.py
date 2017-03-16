import logging
import string
# import numpy as np
# import random


def exA(filename='inputA'):
    # reader
    rownum = 0
    s = list()
    with open('Input/' + filename, 'rb') as file:
        for row in file:
            if rownum > 0 and rownum % 2 == 0:
                s.append(row.split(' '))
            rownum += 1
    sint = list()
    for e in s:
        sint.append([int(x) for x in e])

    print sint

    # algo
    d = dict()
    for x, y in zip(range(1, 27), string.ascii_uppercase):
        d[x] = y

    with open('Output/' + filename.split('.')[0] + '.out', 'w') as file:
        solnum = 0
        for e in sint:
            solnum += 1
            file.write('Case #' + str(solnum) + ': ')
            while max(e) > 0:
                tmpSol = ''
                idx = e.index(max(e))
                e[idx] -= 1
                tmpSol += d[idx + 1]

                if max(e) == 0:
                    file.write(tmpSol)
                    break

                if sum(e) % 2 == 0:
                    # take only one argument
                    file.write(tmpSol + ' ')
                    continue

                idx = e.index(max(e))
                e[idx] -= 1
                tmpSol += d[idx + 1]
                file.write(tmpSol + ' ')
            file.write('\n')

    # for i in range(len(sol)):
    # file.write('Case #' + str(i+1) + ': ' + sol[i] + '\n')


def exB(filename='inputB.in'):
    # reader
    rownum = 0
    s = list()
    with open('Input/' + filename, 'rb') as file:
        for row in file:
            if rownum > 0:
                s.append((row.split(' ')[0].strip(),
                          row.split(' ')[1].strip()))
            rownum += 1

    # writer
    # with open('Output/' + filename.split('.')[0] + '.out', 'w') as file:
    # for i in range(len(sol)):
    # file.write('Case #' + str(i+1) + ': ' + sol[i] + '\n')


def exC(filename='inputC.in'):
    pass


if __name__ == "__main__":

    FORMAT = '%(levelname)s: %(message)s'
    logging.basicConfig(format=FORMAT, level=logging.DEBUG)

    exA('inputA.in')
    # exB('inputB.in')
    # exC('inputC.in')
