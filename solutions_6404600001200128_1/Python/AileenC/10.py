file = open("input")
counter_i = 1
counter_end_i = file.readline()

a = []
num = 0

def solve1(num,a):
	it = 0
	eaten1 = 0
	while(it<num-1):
		diff=a[it]-a[it+1]
		if diff>0:
			eaten1=eaten1+diff
		it=it+1
	return eaten1


def solve2(num,a):
	it = 0
	eaten2 = 0
	inter = 0
	back = 0
	while(it<num-1):
		diff=a[it]-a[it+1]
		if diff>inter:
			inter = diff
		it = it+1
	it = 0
	while(it<num-1):
		diff=a[it]-inter
		if diff<0:
			back=back+diff
		it = it+1
	eaten2 = (num-1)*inter+back
	return eaten2


def solve(a,num,helper):
	helper = 0
	it=1
	sum=0
	newhelp=0
	while(it<num):
		sum=a[it-1]+sum
		if(a[it]>0 and it > sum):
			newhelper = it-sum
			sum = sum + newhelper
			helper=helper+newhelper
		it=it+1
	return helper


while (counter_i <= int(counter_end_i.strip())):
	current_line = file.readline().strip()
	num=int(current_line)
	current_line = file.readline().strip().split(' ')
	a = []
	i = 0
	while (i<num):
		a.append(int(current_line[i]))
		i=i+1
	print "%s%d%s%d %d"%("Case #",counter_i,": ",solve1(num,a),solve2(num,a))
	counter_i=counter_i+1
