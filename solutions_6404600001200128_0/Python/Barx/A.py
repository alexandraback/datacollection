#import math

def solve(N, M):
    deltas = [0]*(N-1)
    for i in range(N-1):
        deltas[i] = M[i+1] - M[i]

    res1 = -1*sum([d for d in deltas if d < 0])
    rate = -1*min(deltas)
    res2 = sum([min(d,rate) for d in M[:-1]])
    return "%d %d"%(res1, res2)

def main(source, dest):
	fd = open(source, 'r')
	fo = open(dest, 'w')
	T = int(fd.readline())
	for i in range(1,T+1):
		N = int(fd.readline().rstrip())
		M = [int(m) for m in fd.readline().split(' ')]
		result = solve(N, M)
	
		print 'Case #' + str(i) + ': ' + result + '\n',
		fo.write('Case #' + str(i) + ': ' + result + '\n')
	
	fd.close()
	fo.close()


if __name__ == "__main__":
	filename = os.path.basename(sys.argv[1])
	source = sys.argv[1]
	dest = os.path.join(sys.argv[2], filename.replace(".in.txt",".out.txt"))
	main(source, dest)