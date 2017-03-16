#a.py
#By Saul de Nova

def fun(N, strings):
	index, pindex = [0 for i in range(N)], [0 for i in range(N)]
	result = 0
	while True:
		for i in range(N):
			while index[i] < len(strings[i]) and strings[i][index[i]] == strings[i][pindex[i]]:
				index[i] += 1

		for i in range(N - 1):
			if strings[i][pindex[i]] != strings[i + 1][pindex[i + 1]]:
				return -1

		currMin = 1E9
		for val in range(1, 102):
			currRes = 0
			for i in range(N):
				currRes += abs(val - (index[i] - pindex[i]))
			currMin = min(currMin, currRes)

		result += currMin

		end = 0
		for i in range(N):
			pindex[i] = index[i]
			if pindex[i] >= len(strings[i]):
				end += 1

		if end > 0 and end < N:
			return -1
		elif end == N:
			return result

def main():
	T = int(raw_input())
	for t in range(1, T + 1):
		N = int(raw_input())
		strings = ["" for i in range(N)]
		for i in range(N):
			strings[i] = str(raw_input()).rstrip()
			#print(strings[i])
			#print(counts[i])

		val = fun(N, strings)
		if val == -1:
			print("Case #" + str(t) + ": Fegla Won")
		else:
			print("Case #" + str(t) + ": " + str(val))



if __name__ == '__main__':
	main()