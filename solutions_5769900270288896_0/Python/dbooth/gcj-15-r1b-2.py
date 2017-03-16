#python 2.7

import sys
import itertools

def calc_unhappiness(R, C, fillmask):
	unhappiness = 0
	for i in range(0, len(fillmask)):
		apt_one = fillmask[i]
		for j in range(i, len(fillmask)):
			apt_two = fillmask[j]
			x_delta = apt_one[0] - apt_two[0]
			y_delta = apt_one[1] - apt_two[1]
			if ((abs(x_delta) + abs(y_delta)) == 1):
				unhappiness += 1
	return unhappiness
	
# def solve_inner(R, C, N, fillmask):
# 	print str(len(fillmask)) + " " + str(N)

# 	if (len(fillmask) == N):
# 		return calc_unhappiness(R, C, fillmask)
	
# 	best_res = float("inf")

	
# 			new_res = solve_inner(R, C, N, fillmask + [[r,c]])
# 			best_res = min(new_res, best_res)

# 	return best_res
	

def solve(inputs):
	R = inputs[0]
	C = inputs[1]
	N = inputs[2]
	
	if (N == 0):
		return "0"
	
	elms = [ [r, c] for r in range(0,R) for c in range(0,C) ] 
	combos = list(itertools.combinations(elms, N))
	print "combos gened"
	#print combos
	best_res = float("inf")
	for elm in combos:
		best_res = min(best_res, calc_unhappiness(R, C, elm))
	return best_res
#return str(solve_inner(R, C, N, list()))

def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        print ("Case #" + str(i + 1))
        #res = solve([ int(x) for x in split_input[2 + 2*(i)].split(" ") ])
        #res = solve(int[split_input[i+1]]
        res = solve([ int(x) for x in split_input[(i+1)].split(" ") ])
        output_file.write("Case #" + str(i + 1) + ": " + str(res) + "\n")
    
if __name__ == "__main__":
    main()
    
