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
members = []
B = 0
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
            B = int(inputs[0])
            N = int(inputs[1])

        if tc_ln == 1:
            members = []
            for i in range(B):
                members.append(int(inputs[i]))

        tc_ln += 1
        if tc_ln > 1:
            time = 0
            atending = []
            interval_to_0 = 1
            fast_barber = -1
            fast_time = -1
            for i in range(B):
                if fast_time == -1 or members[i] <= fast_time:
                    fast_time = members[i]
                    fast_barber = i
                interval_to_0 *= members[i]
                atending.append(0)

            persons_in_interval = 0
            for i in range(B):
                persons_in_interval += int(interval_to_0/members[i])

            persons_left = N % persons_in_interval

            counter = 0
            last_barber = fast_barber
            while counter < persons_left:
                counter += 1
                min_time = -1
                min_barber = -1
                for i in range(B):
                    if min_time == -1 or atending[i] < min_time:
                        min_barber = i
                        min_time = atending[i]
                atending[min_barber] += members[min_barber]
                last_barber = min_barber

            out.write("Case #"+str(testcase)+": "+str(last_barber + 1)+"\n")
            out.flush()

            tc_ln = 0
            testcase += 1
        line_number += 1
    else:
        break
file.close()
out.close()
exit()