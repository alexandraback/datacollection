import copy

def red(arr):
    lcm = 1
    sorted  = copy.deepcopy(arr)
    sorted.sort(reverse=True)
    for val in sorted:
        if lcm%val!=0:
            lcm *= val
    return sum([lcm/val for val in arr])


def solve(B, N, M):
    queue = [0]*B
    current = 0
    next = 0
    reduce =red(M)

    if N > reduce:
        N = N%reduce
        if N == 0:
            N = reduce
    
    while current < N:
    
        try:
            next = queue.index(0)
            #print 'next to %d'%next
            queue[next] = M[next]
            current += 1
            
        except ValueError:
            mn = min(queue)
            for i in range(B):
                queue[i] -= mn

    return "%d"%(next+1)
	
	
def main(source, dest):
	fd = open(source, 'r')
	fo = open(dest, 'w')
	T = int(fd.readline())
	for i in range(1,T+1):
		B, N = fd.readline().rstrip().split(' ')
		M = [int(m) for m in fd.readline().split(' ')]
		result = solve(int(B), int(N), M)
	
		print 'Case #' + str(i) + ': ' + result + '\n',
		fo.write('Case #' + str(i) + ': ' + result + '\n')
	
	fd.close()
	fo.close()


if __name__ == "__main__":
	filename = os.path.basename(sys.argv[1])
	source = sys.argv[1]
	dest = os.path.join(sys.argv[2], filename.replace(".in.txt",".out.txt"))
	main(source, dest)