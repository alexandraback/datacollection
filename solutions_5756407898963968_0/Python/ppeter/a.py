__author__ = 'peter'

results=[]
with open("a.in","r") as inF:
    T= int(inF.readline())
    for iT in range(0,T):
        poss=[True]*16
        for iAns in range(0,2):
            currAns= int(inF.readline())
            mat=[]
            for ir in range(0,4):
                mat.append(map(int,inF.readline().split()))
            for ir in range(0,4):
                if ir== currAns-1:
                    continue
                for ic in range(0,4):
                    poss[mat[ir][ic]-1]=False
        nums=[]
        for num in range(0,16):
            if poss[num]:
                nums.append(num)

        if len(nums)== 0:
            results.append("Volunteer cheated!")
        if len(nums)==1:
            results.append(str(nums[0]+1))
        if len(nums)>1:
            results.append("Bad magician!")

for iRes in range(0,len(results)):
    print "Case #%d: %s"%(iRes+1,results[iRes])