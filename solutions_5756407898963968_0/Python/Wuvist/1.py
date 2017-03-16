import sys

f = sys.stdin

def readline():
	l = f.readline().strip()
	# print l
	return l

game_num = 0

def read_row(row):
	for i in range(0, row - 1):
		f.readline()
	data = readline()

	for i in range(0, 4 - row):
		f.readline()

	return set(data.split(" "))
def read_game():
	global game_num
	row1 = read_row(int(f.readline()))
	row2 = read_row(int(f.readline()))

	data = row1.intersection(row2)

	game_num = game_num + 1
	if len(data) > 1:
		print "Case #%d: %s" % (game_num, "Bad magician!")
		return
	if len(data) == 0:
		print "Case #%d: %s" % (game_num, "Volunteer cheated!")
		return 

	print "Case #%d: %s" % (game_num, str(data.pop()))

def main():
	game_count = int(f.readline())
	for i in range(1, game_count + 1):
		read_game()

main()