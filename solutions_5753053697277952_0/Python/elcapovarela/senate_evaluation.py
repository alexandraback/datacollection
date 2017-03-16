f = open("A-small-attempt0.in", "r")
new_file = open("Asmallsol", "w")
t = int(f.readline())

def senate_evacuation (Pis):
	sum_pis= sum(Pis)
	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	result = []
	n = len(Pis)
	pis_tuppled = []
	for i in range(n):
		pis_tuppled.append([i,Pis[i]])
	while sum_pis>2:
		pis_tuppled.sort(key = lambda x:x[1],reverse=True)
		if pis_tuppled[0][1] == pis_tuppled[1][1]:
			if n>2:
				if pis_tuppled[1][1] != pis_tuppled[2][1]:
					result.append(alphabet[pis_tuppled[0][0]]+alphabet[pis_tuppled[1][0]])
					pis_tuppled[0][1] -= 1
					pis_tuppled[1][1] -= 1
					sum_pis -= 2
				else:
					result.append(alphabet[pis_tuppled[0][0]])
					pis_tuppled[0][1] -= 1
					sum_pis -= 1
			else:
				result.append(alphabet[pis_tuppled[0][0]]+alphabet[pis_tuppled[1][0]])
				pis_tuppled[0][1] -= 1
				pis_tuppled[1][1] -= 1
				sum_pis -= 2
		else:
			result.append(alphabet[pis_tuppled[0][0]])
			pis_tuppled[0][1] -= 1
			sum_pis -= 1
	last_one = ""
	for i in pis_tuppled:
		if i[1] == 1:
			last_one += alphabet[i[0]]
	result.append(last_one)
	return " ".join(result)


for i in range(1,t+1):
	n = int(f.readline())
	Pis = [int(x) for x in f.readline().split(" ")]
	new_file.write("Case #"+str(i)+ ": "+str(senate_evacuation(Pis))+"\n")