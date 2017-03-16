BAD_MAGICIAN="Bad magician!"
CHEATED="Volunteer cheated!"

def readRow():
	return set([int(x) for x in input().split()])

def readNums(rowNr):
	rows = [readRow(), readRow(), readRow(), readRow()]
	return rows[rowNr-1]

def solve():
	r = int(input())
	nums = readNums(r)
	r2 = int(input())
	nums2 = readNums(r2)
	intersection = nums.intersection(nums2)
	if len(intersection) == 1:
		return list(intersection)[0]
	elif len(intersection) == 0:
		return CHEATED
	else:
		return BAD_MAGICIAN

def main():
	T = int(input())
	for t in range(1, T+1):
		r = solve()
		print("Case #%d: %s" % (t, r))

if __name__ == '__main__':
	main()

