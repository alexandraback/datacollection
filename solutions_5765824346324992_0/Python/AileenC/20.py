file = open("input")
counter_i = 1
counter_end_i = file.readline()

a = []
num = 0
b = []

def min_f(b):
	mini=b[0]
	minnum = 0
	it = 1
	while(it<len(b)):
		if b[it]<mini:
			mini=b[it]
			minnum = it
		it = it+1
	return minnum


def normal_f(a):
	tmp = a[min_f(a)]
	it = 0
	while(it<len(a)):
		a[it]=a[it]-tmp+1
		it=it+1
	return a



def detect(B,C,a):
        b=[]
        it = 0
        tmp = 0
        while(it<B):
                b.append(0)
                it=it+1
        it = 1
        while(it>0):
                tmp = min_f(b)
                b[tmp]=b[tmp]+a[tmp]
		it2=1
		equ=1
		while(it2<len(b)):
			if(b[it2-1]!=b[it2]):
				equ=0
				break
			it2=it2+1
		if (equ==1):
			break	
                it = it+1
		
        return it





def solve(B,C,a):
	discount = detect(B,C,a)
	C=C%discount
	if C==0:
		C=discount
	b=[]
	it = 0
	tmp = 0
	while(it<B):
		b.append(0)
		it=it+1
	it = 1
	while(it<C+1):
		tmp = min_f(b)
		b[tmp]=b[tmp]+a[tmp]
		it = it+1
	return tmp+1	




while (counter_i <= int(counter_end_i.strip())):
	current_line = file.readline().strip().split(' ')
	Bnum=int(current_line[0])
	Ncus=int(current_line[1])
	current_line = file.readline().strip().split(' ')
	a = []
	i = 0
	while (i<Bnum):
		a.append(int(current_line[i]))
		i=i+1
	print "%s%d%s%d"%("Case #",counter_i,": ",solve(Bnum,Ncus,a))
	counter_i=counter_i+1
