def solve(numParties, members):
	members = [int(i) for i in members.split()]
	emptyMembers = [0 for _ in members]

	toChar = ord('A')
	previous = members
	results = ""

	while previous != emptyMembers:
		result = ""
		index = maxIndex(previous)
		result += chr(toChar + index)
		previous[index] -= 1

		if previous != emptyMembers:
			temp = [i for i in previous]
			index = maxIndex(temp)
			temp[index] -= 1
			if not hasMajority(temp):
				result += chr(toChar + index)
				previous[index] -= 1

		results += result + " "

	return results.strip()

def hasMajority(members):
	total = sum(members)

	for member in members:
		if member > total/2:
			return True

	return False

def maxIndex(members):

	index = 0
	biggest = max(members)

	for member in members:
		if biggest == member:
			return index
		index += 1

def search(input_d, result, d):
	for letter in d:
		if letter in input_d and input_d[letter] > 0:
			occurrance = input_d[letter]
			word = d[letter]

			for w in word:
				input_d[w] -= occurrance

			if word in result:
				result[word] += occurrance
			else:
				result[word] = occurrance


input_file_name = "../A-large.in"
output_file_name = "output.out"


with open(input_file_name, "r") as input:
	number_cases = int(input.readline())

	with open(output_file_name, "w") as output:

		for i in range(number_cases):

			inputs1 = input.readline().strip()
			inputs2 = input.readline().strip()

			result = solve(inputs1, inputs2)

			if result is None:
				print("NOOOOOOOO")
			elif result ==  "IMPOSSIBLE":
				output.write("Case #" + str(i + 1) + ": " + result + "\n")
			else:
				output.write("Case #" + str(i + 1) + ": " + result + "\n")

