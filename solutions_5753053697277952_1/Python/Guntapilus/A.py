import re
dic = {-1:'',0:'A',1:'B',2:'C',3:'D',4:'E',5:'F',6:'G',7:'H',8:'I',9:'J',10:'K',11:'L',12:'M',13:'N',14:'O',15:'P',16:'Q',17:'R',18:'S',19:'T',20:'U',21:'V',22:'W',23:'X',24:'Y',25:'Z'}

f = open("in.in","r")
w = open("output.txt","w")
num = f.readline()
for it in range(0,int(num)):
	
	N, = [int(l) for l in f.readline().split()]
	P = [int(l) for l in f.readline().split()]
	
	res = []
	member = sum(P)
	while member >0:
		select1 = P.index(max(P))
		P[select1] -= 1
		member -= 1
		select2 = P.index(max(P))
		P[select2] -= 1
		member -= 1
		if max(P)>member//2:
			P[select2] += 1
			member +=1
			select2 = -1
		res.append(dic[select1]+dic[select2])
	res = ' '.join(res)
	print("Case #{0}: {1} ".format(it+1,res))
	w.write("Case #{0}: {1}\n".format(it+1,res))
w.close()