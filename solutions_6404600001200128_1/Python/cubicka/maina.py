raw = open("A-large.in").read().strip().split('\n')
fout = open("out.txt", "w")

ncase = int(raw[0])
for icase in range(1, ncase+1):
  nplate = int(raw[2*icase-1])
  plates = [int(x) for x in raw[2*icase].strip().split(' ')]
  # print plates

  total = 0
  rate = 0
  for i in range(1, nplate):
    total += max(0, plates[i-1]-plates[i])
    rate = max(rate, plates[i-1]-plates[i])

  total2 = 0
  for i in range(1, nplate):
    total2 += min(plates[i-1], rate)

  print total, rate, total2
  print >>fout, "Case #" + str(icase) + ":", total, total2

