import sys
from math import sqrt, ceil, floor

def get_input_lines():
	f=open(sys.argv[1],"r")
	ret=[(i[:-2] if i[-2:]=="\r\n" else (i[:-1] if i[-1]=="\n" else i)) for i in f.readlines()]
	f.close()
	return ret

def write_output(v):
	try:
		write_output.f
	except:
		write_output.f=open(sys.argv[1]+"_out","w")
	write_output.f.write(v)
	sys.stdout.write(v)
	
data=get_input_lines()
number_case=int(data[0])
data=data[1:]
for n_case in range(1,number_case+1):
	n=int(data[0])
	s=data[1:n+1]
	data=data[n+1:]
	lc=s[0][0]
	p=s[0][0]
	for i in s[0]:
		if i != lc:
			lc=i
			p+=lc
	c=[]
	bad=0
	for i in range(n):
		ci=[]
		for j in p:
			cj=0
			while len(s[i])>0 and s[i][0]==j:
				cj+=1
				s[i]=s[i][1:]
			if cj==0:
				bad=1
				break
			ci.append(cj)
		c.append(ci)
		if len(s[i])>0:
			bad=1
		if bad:
			break
	if bad:
		write_output(("Case #%d: Fegla Won\n")%n_case)
	else:
		#print("\n".join(",".join(str(ia)for ia in ib)for ib in c))
		c=tuple(zip(*c))
		ret=0
		for i in c:
			avg=sum(i)/n
			k=9999999
			for d in [ceil(avg), floor(avg)]:
				k=min(k,sum(abs(d-j) for j in i))
			#print (k)
			ret+=k
		write_output(("Case #%d: %d\n")%(n_case, ret))
	
	
	
	