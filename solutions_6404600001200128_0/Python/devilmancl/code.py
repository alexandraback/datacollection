import sys
import math
#obtain the name of the input
def fileName():
    filename = 'input'
    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        print("File was not indicated")
        exit()
    return filename

fn = fileName()
fn_se = fn.split('.')
fn_se = fn_se[0]
file = open(fn, 'r')
out = open(fn_se+'.out', 'w')
line_number = 0
max_testcases = 0
tc_ln = 0
mushroms = []
N = 0
testcase = 0

while True:
    line = file.readline()
    if line:
        line = line.replace("\n","")
        inputs = line.split(" ")
        #how many test cases are
        if line_number == 0:
            max_testcases = int(inputs[0])
            line_number = 1
            tc_ln = 0
            testcase = 1
            continue
        #just check the test cases given
        if testcase > max_testcases:
            break

        if tc_ln == 0:
            N = int(inputs[0])

        if tc_ln == 1:
            mushroms = []
            for i in range(N):
                mushroms.append(int(inputs[i]))

        tc_ln += 1
        if tc_ln > 1:
            answer = "BAD"

            eaten_any = 0
            plate = 0
            max_diff = 0
            for i in range(N):
                if plate > mushroms[i]:
                    diff = plate - mushroms[i]
                    eaten_any += diff
                    if diff > max_diff:
                        max_diff = diff
                plate = mushroms[i]
            print(str(max_diff))

            eaten_const = 0
            plate = 0
            for i in range(N):
                if plate >= max_diff:
                    eaten_const += max_diff
                else:
                    eaten_const += plate
                plate = mushroms[i]
            
            out.write("Case #"+str(testcase)+": "+str(eaten_any)+' '+str(eaten_const)+"\n")
            out.flush()

            tc_ln = 0
            testcase += 1
        line_number += 1
    else:
        break
file.close()
out.close()
exit()