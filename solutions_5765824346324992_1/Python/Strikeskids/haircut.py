
import fractions
import functools

import sys

def test():
    B, N = map(int, input().split(' '))
    times = list(map(int, input().split(' ')))
    gcf = functools.reduce(fractions.gcd, times)

    for i in range(len(times)):
        times[i] //= gcf

    permin = sum(1 / x for x in times)


    guess = N / permin

    print('Permin', permin, 'Guess', guess, file=sys.stderr)
    
    rng = max(times)
    low = int(guess) - rng
    high = int(guess) + rng

    print('Running from', low, 'to', high, file=sys.stderr)

    while low <= high:
        mid = (high+low+1)//2
        count = sum(mid // x + 1 for x in times)
        if count < N:
            low = mid+1
        else:
            high = mid-1

    loc = low - 1
    count = sum(loc // x + 1 for x in times)
    left = N - count
    loc = low
    for i in range(B):
        if loc % times[i] == 0:
            if left <= 1:
                return i+1
            else:
                left -= 1
    raise Exception('Location not found')

def main():
    cases = int(input())
    for case in range(1, cases+1):
        print('Case #%d: %s'%(case, test()))

if __name__ == '__main__': main()