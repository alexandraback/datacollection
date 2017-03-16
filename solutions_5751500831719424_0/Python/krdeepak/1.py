import sys
import os

        
        

def minmove(nums):
    nums = sorted(nums)
    median = nums[len(nums)/2]

    moves = 0
    for num in nums:
        moves += abs(num-median)
    return moves

if __name__ == '__main__':

    cases = int(sys.stdin.readline())

    for i in xrange(cases):
        strings = int(sys.stdin.readline())
        s = []
        for j in xrange(strings):
            s.append(sys.stdin.readline().strip())
        
            achars = []
            acounts = []
            ac = []
            for st in s:
                chars = []
                counts = []
                count = 0
                d = dict()
                for x in xrange(len(st)):
                    if x == 0:
                        chars.append(st[x])
                        counts.append(1)
                    else:
                        if st[x] == st[x-1]:
                            counts[count] += 1
                        else:
                            chars.append(st[x])
                            count += 1
                            counts.append(1)

                achars.append(chars)
                acounts.append(counts)
                ac.append(count)

        fail = 0
        for x in xrange(strings-1):
            if str(achars[x]) != str(achars[x+1]):
                fail = 1
                sys.stdout.write('Case #{0}: {1}\n'.format(i+1, 'Fegla Won'))
                break

        if fail == 0:
            tot = 0
            for x in xrange(len(acounts[0])):
                arr = []
                for y in xrange(strings):
                    arr.append(acounts[y][x])

                ans = minmove(arr)
                tot += ans
            sys.stdout.write('Case #{0}: {1}\n'.format(i+1, tot))






        
