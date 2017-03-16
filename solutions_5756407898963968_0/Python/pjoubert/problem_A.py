import numpy as np
from os.path import join


def read_cards(fin):

    row = int(fin.readline())
    for i in range(4):
        line = fin.readline()
        if i == row - 1:
            cards = set([a for a in line.split()])

    return cards
    

if __name__=='__main__':

    directory = '/home/paul/large/personal/programming/code-jam/2014/round_0'
    name = 'A-small-attempt0'
    filename = join(directory, '%s.in' % name)
    fout = open(join(directory, '%s.out' % name), 'w')

    with open(filename, 'r') as fin:
        T = int(fin.readline())
        for t in range(T):
            cards1 = read_cards(fin)
            cards2 = read_cards(fin)
            cards = cards1 & cards2
            n = len(cards)
            fout.write('Case #%d: ' % (t + 1))
            if n > 1:
                fout.write('Bad magician!\n')
            if n == 1:
                fout.write('%s\n' % cards.pop())
            if n == 0:
                fout.write('Volunteer cheated!\n')

                
                
    fout.close()
