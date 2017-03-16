import sys
from itertools import groupby


def encode(input_string):
    return [(len(list(group)), key) for key, group in groupby(input_string)]


def word_key(word):
    return [key for (_, key) in word]


def word_run(word):
    return [run for (run, _) in word]


def minimum_changes(numbers):
    best_result = 10 ** 5
    for x in range(min(numbers), max(numbers) + 1):
        best_result = min(best_result, sum(abs(number - x) for number in numbers))
    return best_result


def read_numbers(line=None):
    if line is None:
        line = sys.stdin.readline()
    return [int(x) for x in line.split()]


def repeater(words):
    encoded_words = [encode(word) for word in words]
    first_key = word_key(encoded_words[0])
    if not all(word_key(word) == first_key for word in encoded_words):
        return 'Fegla Won'
    result = 0
    for counts in zip(*[word_run(word) for word in encoded_words]):
        result += minimum_changes(counts)
    return result


if __name__ == '__main__':
    case_count = int(sys.stdin.readline().strip())
    for i in range(1, case_count + 1):
        n = int(sys.stdin.readline().strip())
        words = [sys.stdin.readline().strip() for _ in range(n)]
        print "Case #%s: %s" % (i, repeater(words))
