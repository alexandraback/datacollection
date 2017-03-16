import sys
import math



def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for c in range(T):
		first = int(f.readline().strip());
		arng1 = []
		for i in range(4):
			row = f.readline().strip().split(' ')
			arng1.append([int(row[0]), int(row[1]), int(row[2]), int(row[3])])

		second = int(f.readline().strip())
		arng2 = []
		for i in range(4):
			row = f.readline().strip().split(' ')
			arng2.append([int(row[0]), int(row[1]), int(row[2]), int(row[3])])

		sel1 = arng1[first-1];
		sel2 = arng2[second-1];

		find_map = {}
		found = []
		for i in range(len(sel1)):
			find_map[sel1[i]] = 0
		for i in range(len(sel2)):
			if find_map.get(sel2[i]) is not None:
				found.append(sel2[i])

		if len(found)==1:
			of.write('Case #'+str(c+1) + ': ' + str(found[0])+'\n')
		elif len(found)>1:
			of.write('Case #'+str(c+1) + ': Bad magician!\n')
		else:
			of.write('Case #'+str(c+1) + ': Volunteer cheated!\n')

	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

