for T in range(int(input())):
	R1 = int(input())
	A = []
	for i in range(4):
		if i+1 == R1: 
			A = list(map(int, input().split()))
		else:
			input()
	R2 = int(input())
	B = []
	for i in range(4):
		if i+1 == R2: 
			B = list(map(int, input().split()))
		else:
			input()
	X = [val for val in A if val in B]
	if len(X) == 0:
		result = "Volunteer cheated!"
	elif len(X) == 1:
		result = str(X[0])
	else:
		result = "Bad magician!"
	print ("Case #%d: %s" % (T+1, result))