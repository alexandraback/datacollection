import sys
import math
import itertools
import copy

def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for t in range(T):
		N = int(f.readline().strip())
		
		strings = []
		for i in range(N):
			strings.append(f.readline().strip())

		chr_sets = []
		for string in strings:
			c = string[0]
			chr_set = []
			cnt = 1
			for i in range(1, len(string)):
				if c == string[i]:
					cnt += 1
				else:
					chr_set.append((c, cnt))
					cnt = 1
				c = string[i]
			chr_set.append((c, cnt))
			chr_sets.append(chr_set)
		#print chr_sets
		feglar_won = False
		for chr_set in chr_sets:
			if len(chr_set)!=len(chr_sets[0]):
				feglar_won = True
				break
			for i in range(len(chr_set)):
				if (chr_set[i][0]!=chr_sets[0][i][0]):
					feglar_won = True
					break 
			if feglar_won:
				break
		if feglar_won:
			print 'Case #'+str(t+1)+': Fegla Won'
			of.write('Case #'+str(t+1)+': Fegla Won\n')
		else:
			values = []
			for i in range(len(chr_sets[0])):
				values.append([])
			
			for chr_set in chr_sets:
				for i in range(len(chr_set)):
					values[i].append(chr_set[i][1])
			#print values
			total = 0
			for value in values:
				#print value
				#print value
				indexes = range(len(value))
				indexes.sort(key=value.__getitem__)
				midx = len(value)/2
				#print 'idx ', midx
				refv = value[indexes[midx]]
				#print 'ref ', refv
				for v in value:
					#print v, refv, abs(v-refv)
					total += abs(v-refv)
			#print total
			of.write('Case #'+str(t+1)+': '+str(total)+'\n')
			print 'Case #'+str(t+1)+': '+str(total)
		#f.readline().strip().split(' ')
		#of.write('Case #'+str(t+1)+': '+str(minSwitch)+'\n')
		#print 'Case #'+str(t+1)+': '+str(minSwitch)
	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

