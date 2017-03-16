import itertools 
import operator

def hamdist(inp):
	"""Count the # of differences between equal length strings str1 and str2"""
	return sum(c1 != c2 for c1, c2 in itertools.izip(inp[0],inp[1]))
def dotproduct(v1, v2):
	"""Calculate dot product of v1 and v2"""
	return sum(imap(operator.mul, v1, v2))
def RLE(input_string):
    count = 1
    prev = ''
    lst = []
    for character in input_string:
        if character != prev:
            if prev:
                entry = (prev,count)
                lst.append(entry)
                #print lst
            count = 1
            prev = character
        else:
            count += 1
    else:
        entry = (character,count)
        lst.append(entry)
    return lst

def all_equal(list_of_lists):
	check = list_of_lists[0]
	for l in list_of_lists:
		if l != check:
			return False
	return True

def first(in_list):
	return [x[0] for x in in_list]

def median(data):
	return sorted(data)[len(data)//2]

def min_dist(data):
	med = median(data)
	dist = 0
	for x in data:
		dist += abs(med-x)
	return dist

with open("A-large.in", "r") as z:
	cases = int(z.readline().strip())
	output = ""
	for i in range(cases):
		string_count = int(z.readline().strip())
		strings = []
		for j in range(string_count):
			strings.append(z.readline().strip())
		data = [x for x in itertools.imap(RLE, strings)]
		firsts = [first(k) for k in data]
		if all_equal(firsts):
			dists = []
			for string in data:
				dists.append([x[1] for x in string])
			dists = itertools.izip(*dists)
			output+="Case #%s: %s\n" %((i+1),sum(itertools.imap(min_dist, dists)))

		else:
			output+="Case #%s: Fegla Won\n" % (i+1)
	with open("A-large.out", 'w') as o:
		o.write(output)
