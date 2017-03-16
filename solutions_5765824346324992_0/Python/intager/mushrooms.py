import os, time, sys
sys.setrecursionlimit(1800000)
cur_dir=os.path.dirname( os.path.abspath(__file__) )
output=open( os.path.join( cur_dir, 'output.txt' ), 'w' )

def log( msg ):
    print msg
    output.write( msg + '\n' )

lines=[]
for f in os.listdir( cur_dir ):
    if f.lower().endswith( '.in' ):
        lines=open( os.path.join( cur_dir, f ), 'r' ).readlines()
        break

# ------------------------------------------------------- 

def solve( mush ):
	tot1,tot2=0,0
	drop=0

	for i in range( 1, len(mush) ):
		if mush[i] < mush[i-1]:
			tot1+=mush[i-1] - mush[i]
			drop=max(drop, mush[i-1] - mush[i])

	#cur=mush[0]
	for i in range( 1, len(mush) ):
		ate=min( mush[i-1], drop )
		tot2+=ate

	return (tot1,tot2)


#test=[23, 90 ,40 ,0 ,100, 9]
#test=[81 81 81 81 81 81 81 0]
#res=solve( test )
#print res

# ------------------------ main ------------------------------- 

k=1
case=1

while k<len(lines):
	d=lines[k].strip(); k+=1
	e=[ int(x) for x in lines[k].strip().split() ]; k+=1

	ans=solve( e )
	log( 'Case #%d: %d %d' % (case,ans[0],ans[1]) )
	#print
	case+=1
