import sys

place_to_letter = {}
for i in range(26):
	place_to_letter[i] = chr(ord('A') + i)
	
def evac(places):
	plan = ""
	letters = [chr(ord('A') + i) for i in range(26)]
	places_with_letters = zip(places, letters)
	places_with_letters = map(list, places_with_letters)
	
	sorted_seats = list(reversed(sorted(places_with_letters, key=lambda x: x[0])))
	while sorted_seats[0][0] > sorted_seats[1][0]:
		plan += sorted_seats[0][1] + " "
		sorted_seats[0][0] = sorted_seats[0][0] - 1
	for i in range(len(sorted_seats) -2):
		while sorted_seats[i + 2][0] > 0:
			plan += sorted_seats[i + 2][1] + " "
			sorted_seats[i + 2][0] = sorted_seats[i + 2][0] - 1 
	while sorted_seats[0][0] > 0:
		plan += sorted_seats[0][1] + sorted_seats[1][1] + " "
		sorted_seats[0][0] = sorted_seats[0][0] - 1
	return plan

lines = sys.stdin.readlines()
cases = int(lines[0])
lines = lines[1:]
for i in xrange(cases):
	N = int(lines[0].split()[0])
	lines = lines[1:]
	places = [int(x) for x in lines[0].split() if x]
	lines = lines[1:]
	print 'Case #%d: %s' % (i + 1, evac(places))
