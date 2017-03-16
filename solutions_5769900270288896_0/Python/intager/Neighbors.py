import os, time, sys, itertools
sys.setrecursionlimit(1800000)
cur_dir=os.path.dirname( os.path.abspath(__file__) )
output=open( os.path.join( cur_dir, 'output.txt' ), 'w' )

def log( msg ):
    print msg
    output.write( msg + '\n' )

lines=[]
for f in os.listdir( cur_dir ):
    if f.lower().endswith( '.in' ):
    	print f
        lines=open( os.path.join( cur_dir, f ), 'r' ).readlines()
        break

# ------------------------------------------------------- 

best=10**5
#R, C = 0,0
#apt=[]

def recurse( r, c, t, u ):
	global best

	#print r, c, t, u

	if u>=best: return
	if t<0: return

	if t==0:
		best=u
		print 'best=', best
		return

	if c==C+1:
		recurse( r+1,1,t,u )
		return

	if r==R+1:
		return

	recurse( r, c+1, t, u )

	apt[r][c]=1
	cost=0
	if apt[r-1][c]==1: cost+=1
	if apt[r][c-1]==1: cost+=1
	recurse( r, c+1, t-1, u+cost )
	apt[r][c]=0

R=5
C=3
apt=[]
for i in range(17):
	apt.append( [0]*17 )

#print apt

#recurse( 1,1,10,0 )
#print best


# ------------------------ main ------------------------------- 


k=1
case=1

while k<len(lines):
	d=[ int(x) for x in lines[k].strip().split() ]; k+=1
	R=d[0]
	C=d[1]
	lim=d[2]
	best=10**5
	recurse( 1,1,lim,0 )
	log( 'Case #%d: %d' % (case,best) )
	case+=1
