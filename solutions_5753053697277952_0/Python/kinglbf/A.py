'''
Senate Evacuation

'''
import string

f = open(r"C:\Projects\CodeJam2016\1C\A\A-small-attempt0.in", "r+")
foutput = open(r"C:\Projects\CodeJam2016\1C\A\A-small-attempt0.out","w+")
data = []
Letters = list(string.ascii_uppercase)

for line in f:
	data.append(line.strip())
f.close()

for i in range(int(data[0])):
	output = ""
	NumParties = int(data[2*i+1])
	Parties = [int(x) for x in data[2*i +2].split()]
	while (sum(Parties) > 0):
		RemainingMembers = [k for k,y in enumerate(Parties) if y > 0]
		output += " "
		if len(RemainingMembers) == 2:
			Parties[RemainingMembers[0]] -= 1
			Parties[RemainingMembers[1]] -= 1
			output += Letters[RemainingMembers[0]] + Letters[RemainingMembers[1]]
		else:
			if sum(Parties) > 3:
				index = Parties.index(max(Parties))
				Parties[Parties.index(max(Parties))] -= 1
				output += Letters[index] 
				index = Parties.index(max(Parties))
				Parties[Parties.index(max(Parties))] -= 1
				output += Letters[index]		
			else:
				index = Parties.index(max(Parties))
				Parties[Parties.index(max(Parties))] -= 1
				output += Letters[index] 				
	foutput.write("Case #" + str(i+1) + ":" + output + "\n")
foutput.close()