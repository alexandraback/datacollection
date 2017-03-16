import re
import math

inp=open("A-small-attempt1.in","r")
outp=open("As_oupt.txt","w")
lines = inp.readlines()

def ans(a,b):
    a=re.sub("\n","",a)
    b=re.sub("\n","",b)
    la=re.split(" ",a)
    lb=re.split(" ",b)
    a_list=[x for x in la if x in lb]
    print la, lb, a_list
    if len(a_list)==0:
        return "Volunteer cheated!"
    elif len(a_list)>1:
        return "Bad magician!"
    else:
        return a_list[0]

k=int(lines.pop(0))

for i in range(k):
    line1=int(lines[10*i])
    line2=int(lines[10*i+5])
    a=lines[10*i+line1]
    b=lines[10*i+5+line2]
    outp.write("Case #"+str(i+1)+": "+ans(a,b)+"\n")
outp.close()
