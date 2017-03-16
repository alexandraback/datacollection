output = ""
file = open('in','r')



cases = int(file.readline())

for case_no in range(cases):
    interval_count = int(file.readline())
    ms = file.readline().split()
    
    s0 = 0;
    s1Rate = 0;
    
    for i in range(len(ms)):
        ms[i] = int(ms[i])
        if(i == 0):
            continue
        if(ms[i] > ms[i-1]):
            continue
        s0 += (ms[i-1] - ms[i])
        delta = (ms[i-1] - ms[i])
        s1Rate = delta if delta > s1Rate else s1Rate
    s1 = 0;
    for i in range(len(ms)-1):
        toEat = s1Rate
        if(toEat > ms[i]):
            toEat = ms[i]
        s1 += toEat
        
    output += "Case #{}: {} {}\n".format(case_no + 1, s0, s1)
    
    
print(output)
out_file = open("out","w")
out_file.truncate(0);
out_file.write(output)