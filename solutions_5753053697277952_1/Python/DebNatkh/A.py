def f(x):
	return ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"[x])

inf = open("input.txt", "r")
outf = open("output.txt", "w")
t = int(inf.readline())
for j in range(t):
	n = int(inf.readline())
	arr = list(map(int, inf.readline().split()))
	for i in range(n):
		arr[i] = [arr[i], i]
	print("Case #" + str(j+1) + ":", sep = "", end = " ", file = outf)
	while (sum([i[0] for i in arr]) > 0):
		arr.sort()
		if (arr[-2][0] == 0):
			if (arr[-1][0] == 1):
				print(f(arr[-1][1]), sep = "", end = " ", file = outf)
				arr[-1][0] -= 1
			else:
				print(f(arr[-1][1]), f(arr[-1][1]), sep = "", end = " ", file = outf)
				arr[-1][0] -= 2
		else:
			if (arr[-1][0] == 1):
				arr[-1][0] -= 1
				arr[-2][0] -= 1
				if (max([i[0] for i in arr]) * 2 > sum([i[0] for i in arr])):
					arr[-2][0] += 1
					print(f(arr[-1][1]), sep = "", end = " ", file = outf)
				else:
					print(f(arr[-1][1]), f(arr[-2][1]), sep = "", end = " ", file = outf)
			else:
				arr[-1][0] -= 1
				arr[-2][0] -= 1
				if (max([i[0] for i in arr]) * 2 > sum([i[0] for i in arr])):
					arr[-2][0] += 1
					arr[-1][0] -= 1
					if (max([i[0] for i in arr]) * 2 > sum([i[0] for i in arr])):
						arr[-1][0] += 1
						print(f(arr[-1][1]), sep = "", end = " ", file = outf)
					else:
						print(f(arr[-1][1]), f(arr[-1][1]), sep = "", end = " ", file = outf)
				else:
					print(f(arr[-1][1]), f(arr[-2][1]), sep = "", end = " ", file = outf)

		if (max([i[0] for i in arr]) * 2 > sum([i[0] for i in arr])):
			print("NOOO", sep = "", end = " ", file = outf)
	print("", file = outf)