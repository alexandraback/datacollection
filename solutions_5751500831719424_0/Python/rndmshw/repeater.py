import sys
import math

def findchars(s):
	chararray = [];
	prevchar = '';
	for c in s:
		if c != prevchar:
			chararray.append(c);
			prevchar = c;
	# print chararray;
	return chararray;

def matchchars(chararray, s):
	i = 0;
	# start with wrong char
	if chararray[i] != s[i]:
		return False
	for c in s:
		if c == '\n':
			break
		if c != chararray[i]:
			i += 1
			# print i
			# print c
			# extra chars
			if i > len(chararray) - 2:
				# print 1
				return False
			if c != chararray[i]:
				# print 2
				return False
	# missing chars
	if i != len(chararray) - 2:
		# print i
		# print chararray
		# print len(chararray) - 1
		# print 3
		return False
	return True

def countchars(stringarray, chararray):
	chars = []
	for c in chararray:
		chars.append([])
	# print chararray
	# print chars
	for s in stringarray:
		prevchar = s[0];
		charcount = 0;
		i = 0
		for c in s:
			if c == prevchar:
				charcount += 1;
			else:
				# print ord(prevchar) - ord('a')
				chars[i].append(charcount);
				prevchar = c;
				charcount = 1;
				i += 1;
		if charcount != 1:
			chars[i].append(charcount);
	# print chars

	for array in chars:
		array.sort()
	# print chars
	return chars

def countnum(chars, chararray):
	totalmoves = 0;
	for i in range(0, len(chararray)):
		if chararray[i] == '\n':
			break
		a = chars[i]
		mid = int(math.ceil(len(a) / 2))
		# print mid
		moves = 0
		# print a
		for j in a:
			moves += int(math.fabs(j - a[mid]))
		totalmoves += moves
	# print totalmoves
	return totalmoves

def main():
	f = open(sys.argv[1], 'r');
	T = int(f.readline());
	for i in range(0, T):
		# print i;
		N = int(f.readline());
		strings = [];
		first = "";
		chararray = [];
		exit = False
		for n in range (0, N):
			Line1 = f.readline();
			if not exit:
				if n == 0:
					first = Line1;
					chararray = findchars(first);
				# Check if Felga won
				if matchchars(chararray, Line1) == False:
					print "Case #%d: Fegla Won" % (i + 1);
					exit = True
					# break
				strings.append(Line1);
		if exit:
			exit == False
			continue
		chars = countchars(strings, chararray)
		totalmoves = countnum(chars, chararray)

		print "Case #%d: %d" % (i + 1, totalmoves);
	f.close();

main();