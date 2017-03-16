import string
alpha = string.ascii_uppercase

f = open('A-small-attempt0.in', 'r');
f2 = open('resultSmall.txt', 'w');

T = f.readline();

for t in range(0, int(T)):
    N = f.readline().strip('\n');
    line = f.readline().strip('\n');

    print "N: " + str(N)
    print "line: " + line

    numbers = line.split(' ')

    number = []
    sequence = []
    tot_evac = []

    
    for n in range(0, int(N)):
        number.append(int(numbers[n]))

    while True:
        maxnum = max(number)

        if maxnum <= 0:
            break

        #print "max: " + str(maxnum)
        #print "count: " + str(number.count(maxnum))

        evacString = ""
        
        if number.count(maxnum) % 2 != 0:
            #uneven
            for i in range(0,len(number)):
                if number[i] == maxnum:
                    evacString += alpha[i]
                    number[i] -= 1
                    break
        else:
            #even
            found = 0
            for i in range(0,len(number)):
                if number[i] == maxnum:
                    evacString += alpha[i]
                    number[i] -= 1
                    found += 1
                    if found > 1:
                        break

        
        tot_evac.append(evacString)

    end =  " ".join(tot_evac)
        
    
    f2.write("Case #" + str(t+1) + ": " + end + '\n');
   
f.close()
f2.close()
