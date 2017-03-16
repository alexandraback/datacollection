t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	t2 = int(raw_input())
	answer = ""
	members = raw_input().split(" ")
	for j in xrange(len(members)):
		members[j] = int(members[j])
	if t2 == 2:
		while members[0] != 0:
			answer += "AB "
			members[0] -= 1
			members[1] -= 1
	else:
		while max(members) != 0:
			max_index = members.index(max(members))
			if members[len(members) - 1] == 1 and members[len(members) - 2] == 1 and members[len(members) - 3] == 0:
				members[max_index + 1] -= 1
				answer += unichr(max_index + 65) + unichr(max_index + 66) + " "
			else:
				answer += unichr(max_index + 65) + " "
			members[max_index] -= 1
	print "Case #{}: {}".format(i, answer.rstrip(" "))