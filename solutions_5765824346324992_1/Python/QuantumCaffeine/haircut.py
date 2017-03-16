# Solution to "Haircut" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys
import heapq

def solve(b, n, times):
    if n <= b:
        return n
    custpermin = sum(1.0/a for a in times)
    if n > 2*b:
        minutes = int((n - 2*b)/custpermin)
    else:
        minutes = 0
    done = 0
    progress = []
    for barber, t in enumerate(times):
        curdone, minsin = divmod(minutes, t)
        done += curdone
        progress.append((- minsin, barber))
    progress.sort()
    queue = []
    done += b
    for mins, barber in progress:
        queue.append((times[barber] + mins, barber))
    heapq.heapify(queue)
    for _ in xrange(n - done - 1):
        time, barber = heapq.heappop(queue)
        heapq.heappush(queue, (time + times[barber], barber))
    time, barber = heapq.heappop(queue)
    return barber + 1

def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            b, n = (int(x) for x in infile.readline().split())
            times = [int(x) for x in infile.readline().split()]
            yield b, n, times

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
