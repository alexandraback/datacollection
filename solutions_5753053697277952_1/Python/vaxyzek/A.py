import gcj


def to_exit(P):
	m1 = max(P)
	ix1 = P.index(m1)
	P[ix1] -= 1

	m2 = max(P)
	ix2 = P.index(m2)
	P[ix2] -= 1
	
	S = sum(P)
	if S > 0 and max(P) > S // 2:
		P[ix2] += 1
		return chr(ord('A') + ix1)

	return "" + chr(ord('A') + ix1) + chr(ord('A') + ix2)


ifile, ofile = gcj.get_files('A')

T = int(ifile.readline().strip())
for t in range(T):
	N = int(ifile.readline().strip())
	P = list(map(int, ifile.readline().strip().split(" ")))

	ans = []
	#print(P)
	while True:
		S = sum(P)

		if S > 0:
			a = to_exit(P)
			#print(P, a)

			ans.append("" + a)
		else:
			break
	
	gcj.print_answer(ofile, t, ' '.join(ans))