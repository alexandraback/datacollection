#coding:utf-8

#四元数

def main():
    fr=open("A-large.in","r")
    output=""
    ans=[]
    casenum=0
    count=0
    for line in fr:
        if count==0:
            casenum=int(line)
        else:
            tmpans=0
            if (count%2) == 1:
                repeatnum=int(line)
            else:
                cur=-1
                maxdif=0
                vals=line.split()
                for cell in vals:
                    a=int(cell)
                    if cur==-1:#最初
                        cur=a
                    else:
                        dif = cur-a
                        if maxdif < dif:
                            maxdif=dif
                        if dif > 0:
                            tmpans=tmpans+dif
                        cur=a
                #ここでのtmpansが一つ目の答え
                tmpans2=0
                vals.pop()
                for cell in vals:
                    a=int(cell)
                    if a < maxdif:
                        tmpans2=tmpans2+a
                    else:
                        tmpans2=tmpans2+maxdif
                ans.append([tmpans,tmpans2])




                
        count=count+1

    for i in range(0,casenum):
        output=output+"Case #"+str(i+1)+": "+str(ans[i][0])+" "+ str(ans[i][1]) + "\n"

    fr.close()


    fw=open("out.txt","w")
    fw.write(output)
    fw.close()

main()