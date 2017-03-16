import heapq

def GCD(x, y):
  if y == 0: return x
  return GCD(y, x%y)

def Sieve(lim):
  global primes
  isprime = [False  if x%2 == 0 else True for x in range(lim)]
  isprime[1] = False
  isprime[2] = True

  primes.append(2)
  for k in range(3, lim, 2):
    if isprime[k]:
      primes.append(k)
      for m in range(k+k, lim, k):
        isprime[m] = False

primes = []
Sieve(100000)

raw = open("B-large.in").read().strip().split('\n')
fout = open("out.txt", "w")
# print >>fout, " ".join(map(str,primes[-1000:]))

ncase = int(raw[0])
for xcase in range(1, ncase+1):
  print xcase
  nb, nn = [int(x) for x in raw[xcase*2-1].strip().split(' ')]
  barberTime = [int(x) for x in raw[xcase*2].strip().split(' ')]

  # print >>fout, nb, nn

  timeSeries = []
  heapq.heapify(timeSeries)

  total = 1
  for idx, x in enumerate(barberTime):
    d = GCD(total, x)
    total /= d
    total *= x

  turnMult = 0
  for x in barberTime:
    turnMult += total / x

  nn -= 1
  nn %= turnMult
  nn += 1

  remainder = [[0 for x in barberTime], [0 for x in barberTime]]
  mults = [[0 for x in barberTime], [0 for x in barberTime]]
  sums = [0, 0]
  ntime = 100000000

  ii = 0
  while ntime > 100:
    while nn - sums[ii] > 1000000:
      print sums[ii], nn-sums[ii]
      iix = 1 - ii
      sums[iix] = sums[ii]
      for k in range(nb):
        mults[iix][k] = mults[ii][k] + (ntime+remainder[ii][k])/barberTime[k]
        sums[iix] += (ntime+remainder[ii][k])/barberTime[k]
        remainder[iix][k] = (ntime+remainder[ii][k])%barberTime[k]
      ii = iix

    if sums[ii] >= nn:
      ii = 1 - ii

    ntime /= 10

  for idx, x in enumerate(barberTime):
    heapq.heappush(timeSeries, (mults[ii][idx]*x, idx+1, x))

  for i in xrange(sums[ii]+1, nn):
    if i%10000 == 0: print "time", i
    node = heapq.heappop(timeSeries)
    heapq.heappush(timeSeries, (node[0] + node[2],node[1], node[2]))

  # print >>fout, barberTime
  print >>fout, "Case #" + str(xcase) + ":", timeSeries[0][1]

