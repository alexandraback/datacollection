import sys
from math import sqrt

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
for n_case in range(1,number_case+1):
	lines=data[1+(n_case-1)*10:1+n_case*10]
	a=int(lines[0])
	b=int(lines[5])
	l1=set(lines[a].split())
	l2=set(lines[b+5].split())
	i=set.intersection(l2,l1)
	if len(i)==0:
		ret="Volunteer cheated!"
	elif len(i)==1:
		ret=i.pop()
	else:
		ret="Bad magician!"
	write_output(("Case #%d: %s\n")%(n_case,ret))
	
	
	