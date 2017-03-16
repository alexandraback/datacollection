for tc in range(int(input())):
  numplates = int(input())
  plates = [int(x) for x in input().split()]
  
  eaten1 = 0
  lastcount = plates[0]
  #method1
  for i in range(1, numplates):
    if plates[i]<lastcount:
      eaten1 += lastcount-plates[i]
    lastcount = plates[i]


  #method2
  eaten2 = 0
  rate = max([plates[i]-plates[i+1] for i in range(0, numplates-1)])
  rate = max(rate, 0)
  for i in range(0, numplates-1):
    if rate>plates[i]:
    	eaten2 += plates[i]
    else:
    	eaten2 += rate

  print ("Case #%d: %d %d" % (tc+1, eaten1, eaten2))
