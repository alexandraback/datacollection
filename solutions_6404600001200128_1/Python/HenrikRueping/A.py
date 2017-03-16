#f = open("A-small-attempt0.in",'r')
f = open("A-large.in",'r')
#f = open("A-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    N= int(f.readline())
    S=[int(j) for j in str.split(f.readline())]
    count1=0
    diff = [S[j] -S[j+1] for j in range(len(S)-1) if S[j]>S[j+1]]
    if diff ==[]:
        diff =[0]
    maxi= max(diff)
    diff2= [S[j] if S[j]<maxi else maxi for j in range(len(S)-1)]
    #print(N)
    #print(S)
    #print(diff)
    output.write("Case #"+str(case)+": "+str(sum(diff))+" "+str(sum(diff2))+"\n")
output.close()
f.close()
