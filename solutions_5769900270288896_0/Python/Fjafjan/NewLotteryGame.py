def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())



def write_output(file_out, case_nr, intersections):
    output_string = "Case #" + str(case_nr) + ": "
    output_string += str(intersections)
    file_out.write(output_string)
    file_out.write("\n")


f_out = open('A-small-practice.out', 'w')

def angry_level(R, C, N):
    ## first off, if there is enough space for everyone we just happy
    if R == C == 1:
        return 0
    if N <= R*C/2:
        return 0
    
    nr_holes = R*C - N
    #~ nr_walls = (R+1)*(C+1) - 2*(R+C)
    nr_walls = (R-1)*C + (C-1)*R
    print "R, C = " , R, C, " with a total of ", nr_walls, " walls and ", nr_holes, " empty rooms"
    
    great_holes = (R-2)*(C-2)
    great_holes = max(0,great_holes)
    great_holes = great_holes / 2 + great_holes%2
    
    print "we thus have ", great_holes, " usable 4 wall holes"
    good_holes = (2*(R-2)) + (2*(C-2))
    if R == 1 or C == 1:
        good_holes = 0
    if great_holes == 1 and N > 1:
        great_holes = 0
    
    ## Aaand now we just try to remove the correct holes
    print "we start with", nr_holes, " and ", nr_walls
    if nr_holes > great_holes:
        nr_holes -= great_holes
        nr_walls -= 4*great_holes
        print "first we remove ", 4*great_holes
        if nr_holes > good_holes:
            nr_holes -= good_holes
            nr_walls -= 3*good_holes
            nr_walls - nr_holes*2
        else: 
            nr_walls -= nr_holes * 3
            nr_holes = 0
    else:
        nr_walls -= nr_holes * 4
        nr_holes = 0
    print "WE find that the remaining anger is ", nr_walls
    return nr_walls
    
R = 3
C = 3
N = 13
print "the angry level for ", R, C, N, " is ", angry_level(R, C, N)
T =  readint()

for test_case in range(T):
    print test_case
    [R, C, N] = readlinearray(int)
    write_output(f_out, test_case + 1, angry_level(R, C, N))
