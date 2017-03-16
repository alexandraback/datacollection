#!/usr/bin/pypy

def read_line():
    s = raw_input()
    while s == "":
        s = raw_input()
    return s

def read_int():
    return int(read_line())

def read_ints():
    return [int(s) for s in read_line().split()]

T = int(read_line())

def read_contents(y, board):
    return set(board[y-1])

def read_board():
    return [read_ints() for y in range(4)]
def solve():
    iA = read_int()
    boardA = read_board()

    iB = read_int()
    boardB = read_board()

    rowA = read_contents(iA, boardA)
    rowB = read_contents(iB, boardB)

    possibilities =  rowA & rowB
    N = len(possibilities)
    if N == 0:
        return "Volunteer cheated!"
    elif N == 1:
        return possibilities.pop()
    else:
        return "Bad magician!"


for i in range(1, T+1):
    solution = solve()
    print "Case #{0}: {1}".format(i, solution)
