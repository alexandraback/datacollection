output = ""
file = open('in','r')

cases = int(file.readline())
a = 0
for case_no in range(cases):
    a = a + 1
    i = file.readline().split();
    barberTimes = [];
    barberInUse = [];
    noInLine = int(i[1]);
    times = file.readline().split();
    currentPerson = 1;
    
    for i in range(len(times)):
        barberTimes.append(int(times[i]))
        barberInUse.append(0)
    
    
    done = False
    peopleDone = 0;
    while(not done):
        allZero = True
        for b in range(len(barberInUse)):
            barberInUse[b] = barberInUse[b] - 1
            allZero = allZero and barberInUse[b] <= 0
        if(allZero and peopleDone > 0):
            currentPerson = currentPerson + (peopleDone * int((noInLine - currentPerson) / peopleDone))
            peopleDone = 0
            
        for b in range(len(barberInUse)):
            if(barberInUse[b] <= 0):
                if(currentPerson == noInLine):
                    output += "Case #{}: {}\n".format(a,b+1)
                    done = True
                    print("Done {}".format(a))
                    break
                
                currentPerson = currentPerson + 1
                peopleDone = peopleDone + 1
                barberInUse[b] = barberTimes[b]
                
                if(currentPerson > noInLine):
                    print("Error!!! {}".format(a));
                    print(currentPerson)
                    print(noInLine)
                    quit()
        

print(output)
out_file = open("out","w")
out_file.truncate(0);
out_file.write(output)