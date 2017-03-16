import numpy as np

read = open('input.txt', 'rb')
write = open('output.txt', 'wb')

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

t = int(read.readline())
for epoch in range(t) :
	n = int(read.readline())
	num_list = [int(x) for x in read.readline().split()]
	write.write('Case #'+str(epoch+1)+': ')
	while True :
		maxval = 0
		maxidx = 0
		onenum = 0
		ones = []
		last = 0
		lasts = []

		for i in range(n) :
			if num_list[i] > maxval : 
				maxval = num_list[i]
				maxidx = i
			if num_list[i] == 1 :
				onenum += 1
				ones.append(i)
			if num_list[i] > 0 :
				last += 1
				lasts.append(i)

		if maxval == 0 :
			write.write('\n')
			break

		elif last == 2 :
			write.write(alphabet[lasts[0]]+alphabet[lasts[1]]+' ')
			num_list[lasts[0]] -=1
			num_list[lasts[1]] -= 1

		elif maxval == 1 :
			if onenum%2 == 0 :
				write.write(alphabet[ones[0]]+alphabet[ones[1]]+' ')
				num_list[ones[0]] -=1
				num_list[ones[1]] -= 1
			else :
				write.write(alphabet[ones[0]]+' ')
				num_list[ones[0]] -= 1

		else :
			write.write(alphabet[maxidx]+' ')
			num_list[maxidx] -= 1






