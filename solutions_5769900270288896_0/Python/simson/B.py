import sys
from functools import lru_cache

def get_line():
	return sys.stdin.readline()

def get_ints():
	return [int(i) for i in get_line().split()]

@lru_cache(maxsize=None)
def numberOfSetBits(i):
    i = i - ((i >> 1) & 0x55555555)
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
    return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24

def get(w, x, y, r, c):
	if x<0 or y<0 or x==c or y==r:
		return 0
	return (w >> (y*c + x)) & 1
	
def noisyness(w,r,c):
	n=0
	for x in range(c):
		for y in range(r):
			if get(w,x,y,r,c)==0:
				continue
			n +=get(w, x - 1, y    , r, c) +\
			    get(w, x    , y - 1, r, c)
	return n

for e,n in enumerate(range(get_ints()[0])):
	r, c, n = get_ints()

	minn = 100000
	for w in range(2**(r*c)):
		if numberOfSetBits(w)==n:
			tt=noisyness(w,r,c)
			if tt < minn:
				minn=tt

	print("Case #%i: %i" % (e+1, minn))
				
