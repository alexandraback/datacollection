from copy import copy, deepcopy

filename = "B-large.in"
filename = "B-small-attempt1.in"
#filename = "B-test.in"

lines = ()
with open(filename) as file:
	lines = file.read().splitlines()

number_of_sets = int(lines[0])


def evaluate_grid(grid):
	un_grid = [row[:] for row in grid]
	c = len(grid)
	r = len(grid[0])
	for i in range(0,r):
		for j in range(0,c):
			if grid[j][i] == 1:
				top = 0
				lef = 0
				rig = 0
				bot = 0
				if (j > 0):
					top += grid[j-1][i]
				if (j < (c-1)):
					bot += grid[j+1][i]
				if (i > 0):
					top += grid[j][i-1]
				if (i < (r-1)):
					bot += grid[j][i+1]
				un_grid[j][i] = top+lef+rig+bot
			else:
				un_grid[j][i] = 0
	return un_grid


def evaluate_grid_min(grid):
	un_grid = [row[:] for row in grid]
	c = len(grid)
	r = len(grid[0])
	for i in range(0,r):
		for j in range(0,c):
			if grid[j][i] == 0:
				top = 0
				lef = 0
				rig = 0
				bot = 0
				if (j > 0):
					top += grid[j-1][i]
				if (j < (c-1)):
					bot += grid[j+1][i]
				if (i > 0):
					top += grid[j][i-1]
				if (i < (r-1)):
					bot += grid[j][i+1]
				un_grid[j][i] = top+lef+rig+bot
			else:
				un_grid[j][i] = 5
			
	return un_grid



def getmax(grid):
	c = len(grid)
	r = len(grid[0])

	cmax = 0
	cmax_x = 0
	cmax_y = 0

	for i in range(0,r):
		for j in range(0,c):
			if grid[j][i] > cmax:
				cmax = grid[j][i]
				cmax_x = j
				cmax_y = i
	return (cmax_x,cmax_y)


def getmin(grid):
	c = len(grid)
	r = len(grid[0])

	cmin = 5
	cmin_x = 0
	cmin_y = 0

	for i in range(0,r):
		for j in range(0,c):
			if grid[j][i] < cmin:
				cmin = grid[j][i]
				cmin_x = j
				cmin_y = i
	return (cmin_x,cmin_y)


def calculate_red_walls(grid):
	c = len(grid)
	r = len(grid[0])

	r_w = 0

	for i in range(0,r):
		for j in range(0,c-1):
			if (grid[j][i] + grid[j+1][i]) == 2:
				r_w += 1

	for j in range(0,c):
		for i in range(0,r-1):
			if (grid[j][i] + grid[j][i+1]) == 2:
				r_w += 1
	return r_w



with open(filename+".solved","w") as outputfile:
	for i in range(0,number_of_sets):


		
		current_line = lines[i+1].split(" ")
		R = int(current_line[0])
		C = int(current_line[1])
		N = int(current_line[2])
		RC = R*C
		free_cells = RC - N
		print " "
		print "TRY"
		print " ".join(current_line)

		current_grid = [[1 for x in range(R)] for x in range(C)] 
		current_un_grid = [[0 for x in range(R)] for x in range(C)] 
		
		while free_cells > 0:
		 	current_un_grid = evaluate_grid(current_grid)
		 	(x,y) = getmax(current_un_grid)
		 	current_grid[x][y] = 0
		 	free_cells -= 1
			

		print "final:"
		print current_grid
		print current_un_grid

		rw_max = str(calculate_red_walls(current_grid))

		print "Red walls: " + str(rw_max)

		current_grid = [[0 for x in range(R)] for x in range(C)] 
		current_un_grid = [[0 for x in range(R)] for x in range(C)] 
		
		if N > 0:
			current_grid[0][0] = 1
			N -= 1

		while N > 0:
		 	current_un_grid = evaluate_grid_min(current_grid)
		 	(x,y) = getmin(current_un_grid)
		 	current_grid[x][y] = 1
		 	N -= 1


		rw_min = str(calculate_red_walls(current_grid))

		print "Red walls: " + str(rw_min)


		line = "Case #"+str(i+1)+": "+str(min(rw_min,rw_max))
		print line
		outputfile.write(line+"\n")				
					