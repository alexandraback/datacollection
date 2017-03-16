
'''
t=input()
for j in xrange(t):
  l,x=map(int,raw_input().strip().split())
  s=raw_input().strip()
'''


inF = open('A-small-attempt0.in.txt','r')
ouF = open('MaryamQ1.out','w')
t = int(inF.readline())
for j in xrange(t):
    inF.readline()
    mush=map(int,inF.readline().split())
    eat = 0
    Max = 0
    for m in range(len(mush)-1):
        rate = mush[m+1]-mush[m]
        if rate < 0:
            eat += rate
            Max = max(Max, -rate)
    mEat = 0
    for m in range(len(mush)-1):
        if mush[m]<= Max :
            mEat += mush[m]
            #print mush[m]
        else:
            mEat+= Max 

    ouF.write('Case #'+str(j+1)+': '+str(-eat)+' '+str(mEat)+'\n')

ouF.close()
