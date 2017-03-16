'''
Created on Apr 12, 2014

@author: ononon1
'''

fname = "../MagicTrick3.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    r1 = f.readline()
    #print(r1)
    for j in range(int(r1)-1):
        f.readline()
    s1 = set(f.readline().split())
    #print (s1)
    for j in range(4-int(r1)):
        f.readline()

    r2 = f.readline()
    for j in range(int(r2)-1):
        f.readline()
    s2 = set(f.readline().split())
    #print (s2)
    for j in range(4-int(r2)):
        f.readline()
    s3 = s1 & s2
    print(s3)

    if(len(s3) == 0):
        fout.write("Case #"+str(i)+": Volunteer cheated!\n")
    elif(len(s3) > 1):
        fout.write("Case #"+str(i)+": Bad magician!\n")
    else:
        fout.write("Case #"+str(i)+": "+str(s3.pop())+"\n")


