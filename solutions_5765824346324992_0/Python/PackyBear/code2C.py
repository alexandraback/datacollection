#-*- coding: utf-8 -*-
import math

def lcm(x, y):
   """This function takes two
   integers and returns the L.C.M."""

   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

def barber(bbno, me, bbvec):
    print bbvec
    xxx = 1
    for bb in bbvec:
        xxx = lcm(xxx, bb)
    print xxx
    bbbbb = 0
    for bb in bbvec:
        bbbbb += xxx/bb
        
    if me >= bbbbb:
        me = me % bbbbb
    if me == 0:
        me = bbbbb
    print "me"
    print me
    
    bbcur = []
    remaincur = me
    time = 0
    stop = False
    ava = 0
    


    for i in range(0, bbno):
        bbcur.append(0)

    while stop == False:
        deltatime = 0
        ava = bbcur.count(0)
        #print("re: " + str(remaincur) + ' ' + str(ava)) 
        if ava >= remaincur:
            for j in range(0,remaincur - 1):
                bbcur[bbcur.index(0)] = 10000
                #print bbcur.index(0)
            #print "output"
            #print bbcur.index(0)
            return str(bbcur.index(0) + 1)
            stop == True
        else:
            remaincur -= ava
            for j in range(0, ava):
                bbcur[bbcur.index(0)] = bbvec[bbcur.index(0)]
                #print "sb"
                #print bbcur
            deltatime = min(bbcur)
            bbcur[:] = [x - deltatime for x in bbcur]
            #print "hi"
            #print bbcur
        

var = raw_input("Enter something: ").split('\n')
text = ""

caseno = 0
double = 0
para = []
bbvec = []
bbno = 0
me = 0
for line in var[1:]:
    if line != "":
        double += 1
        if double % 2 == 1:
            bbno = 0
            me = 0
            bbvec = []
            (bbno, me) = line.split(" ")
            bbno = int(float(bbno))
            me = int(float(me))
            caseno += 1
        elif double % 2 == 0:
            bbvv = line.split(" ")
            for bbv in bbvv:
                bbvec.append(int(float(bbv)))
            re = barber(bbno, me, bbvec)
        
            newline = "Case #" + str(caseno) + ": " + str(re)
            text += "%s\n" % newline
print text
filew = open("output.txt",'w')
filew.write(text)
filew.close()
