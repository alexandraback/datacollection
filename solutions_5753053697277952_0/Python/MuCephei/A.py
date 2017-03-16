
import operator
class Party():

	def __init__(self,name,number):
		self.Name = chr(65 + name)
		self.Number = number

def RemoveOne(senators):
	senators = sorted(senators, key=lambda x: x.Number)
	senators.reverse()
	senators[0].Number -= 1
	return senators[0].Name

def A():
	n = input()
	senators = raw_input().split()

	totalInRoom = 0

	for party in range(n):
		senators[party] = Party(party,int(senators[party]))
		totalInRoom += senators[party].Number

	Order = ""

	while (totalInRoom > 0):
		if totalInRoom == 3:
			Order += RemoveOne(senators) + " "
			totalInRoom -= 1
		else:
			Order += RemoveOne(senators) + RemoveOne(senators) + " "
			totalInRoom -= 2


	return Order

def toString(data):
	result = ""
	for x in data:
		result = result + str(x)
	return result


times = input()

for x in range(times):
    print ("Case #" + str(x+1) + ": " + A())