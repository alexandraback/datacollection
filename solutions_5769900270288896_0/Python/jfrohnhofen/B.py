#!/usr/bin/python

from sys import stdin as I

def testcase():
  R, C, N = map(int, I.readline().split())
  
  cells = R * C
  if 2*N <= cells:
  	return 0

  if R == 1 or C == 1:
  	X = max(R, C)
  	return 2 * (N - (X+1)/2) - 1 + (X % 2)

  innerWalls = (R-1)*C + (C-1)*R
  freeRooms = cells - N

  if R % 2 == 0 and C % 2 == 0:
  	#gerade gerade
  	maxInnerFree = (R-2)*(C-2)/2
  	maxEdgeFree = (R-2) + (C-2)
  	maxCornerFree = 2

  if R % 2 == 0 and C % 2 == 1:
  	# gerade ungerade
  	maxInnerFree = (R-2)*(C-2)/2
  	maxEdgeFree = (R-2) + (C-2)
  	maxCornerFree = 2

  if R % 2 == 1 and C % 2 == 0:
  	# gerade ungerade
  	maxInnerFree = (R-2)*(C-2)/2
  	maxEdgeFree = (R-2) + (C-2)
  	maxCornerFree = 2

  if R % 2 == 1 and C % 2 == 1:
  	#ungerade ungerade
  	maxInnerFree = ((R-2)*(C-2)+1)/2
  	maxEdgeFree = (R-3)/2*2+(C-3)/2*2
  	maxCornerFree = 4

  maxInnerFree = max(0, maxInnerFree)
  maxEdgeFree = max(0, maxEdgeFree)
  maxCornerFree = max(0, maxCornerFree)

  innerFree = min(freeRooms, maxInnerFree)
  freeRooms -= innerFree
  edgeFree = min(freeRooms, maxEdgeFree)
  freeRooms -= edgeFree
  cornerFree = min(freeRooms, maxCornerFree)

  return max(0, innerWalls - 4*innerFree - 3*edgeFree - 2*cornerFree)

T = int(I.readline())
for t in range(T):
  print("Case #%i: %s" % (t+1, str(testcase())))
