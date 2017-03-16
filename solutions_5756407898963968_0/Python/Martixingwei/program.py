input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
for i in range(T):
	set1 = set()
	set2 = set()
	n = int(input_file.readline().strip())-1
	for j in range(4):
		cl = input_file.readline()
		if j==n:
			set1 = set(cl.strip().split(" "))
	n = int(input_file.readline().strip())-1
	for j in range(4):
		cl = input_file.readline()
		if j==n:
			set2 = set(cl.strip().split(" "))
	set3 = set1.intersection(set2)
	output_file.write("Case #"+str(i+1)+": ")
	if len(set3)==1:
		output_file.write(set3.pop())
	elif len(set3)==0:
		output_file.write("Volunteer cheated!")
	else:
		output_file.write("Bad magician!")
	output_file.write("\n")
	