#!/usr/bin/python
import sys


def read_cards():
    selection = int(sys.stdin.readline())
    cards = []

    for i in xrange(4):
        parts = sys.stdin.readline().strip().split(" ")
        cards.append(parts)
    return selection, cards


def solve_game(first_selection, first_cards, second_selection, second_cards):
    first_group = first_cards[first_selection - 1]
    second_group = second_cards[second_selection - 1]

    intersect = list(set(first_group) & set(second_group))
    if len(intersect) == 0:
        return "Volunteer cheated!"
    elif len(intersect) == 1:
        return intersect[0]
    else:
        return "Bad magician!"


def main():
    tests = int(sys.stdin.readline())

    for test in xrange(tests):

        first_selection, first_cards = read_cards()
        second_selection, second_cards = read_cards()

        r = solve_game(first_selection, first_cards, second_selection, second_cards)
        print "Case #%d: %s" % (test + 1, r)

main()
