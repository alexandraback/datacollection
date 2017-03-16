import sys

def get_party(index):
	return chr(index + ord('A'))

def evacuate(repartition):
	if len(repartition) == 2 and repartition[0] == repartition[1]:
		evacuation_plan = ['AB'] * repartition[0] 
	else:
		evacuation_plan = general_case(repartition)

	return ' '.join(evacuation_plan)

def general_case(repartition):
	evacuation_plan = []
	nb_people = sum(repartition)
	while(nb_people > 2):
		chosen_party = repartition.index(max(repartition))
		repartition[chosen_party] -=1
		evacuation_plan.append(get_party(chosen_party))
		nb_people -= 1
	final_member1 = repartition.index(max(repartition))
	repartition[final_member1] -=1
	final_member2= repartition.index(max(repartition))
	evacuation_plan.append(get_party(final_member1)+get_party(final_member2))
	return evacuation_plan

def main():
	t = int(sys.stdin.readline().strip())
	for i in range(1,t+1):
		n = int(sys.stdin.readline().strip())
		repartition = map(int, sys.stdin.readline().strip().split())
		print "Case #%d: %s" % (i, evacuate(repartition))

if __name__ == '__main__':
	main()