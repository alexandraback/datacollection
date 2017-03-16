def get_letters(s):
	letters = []
	letters.append(s[0])
	for j in range(1,len(s)):
		if s[j]!=letters[len(letters)-1]:
			letters.append(s[j])
	return letters

def get_count(s):
	letters = []
	count = []
	count.append(1)
	letters.append(s[0])
	for j in range(1,len(s)):
		if s[j]!=letters[len(letters)-1]:
			letters.append(s[j])
			count.append(1)
		else:
			count[len(letters)-1]+=1
	return count


def check_letters(N,A):
	letters = get_letters(A[0])
	for i in range(1,len(A)):
		new_letters = get_letters(A[i])
		if letters!=new_letters:
			return False
	return True
def make_count_array(N,A):
	letters = get_letters(A[0])
	B = [[0]*len(letters) for i in range(len(A))]
	for i in range(len(A)):
		B[i] = get_count(A[i])
	return B



for T in range(int(input())):
	N = int(input())
	A = []
	for i in range(N):
		A.append(input())
	if not check_letters(N,A):
		print ("Case #"+str(T+1)+": Fegla Won")
		continue
	B = make_count_array(N,A)
	result = 0
	for j in range(len(B[0])):
		sum = 0
		for i in range(N):
			sum+=B[i][j]
		avg = float(sum)/float(N)
		avg = round(avg)
		for i in range(N):
			result+=abs(B[i][j]-avg)
		

	print ("Case #"+str(T+1)+": "+str(result))
