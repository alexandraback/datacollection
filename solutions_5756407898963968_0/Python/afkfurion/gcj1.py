with open('A-small-attempt5.in') as f:
    data = [line.rstrip() for line in f]
i = 1
ncase = 1
while i < len(data):
    print "Case #%d:" % ncase,
    fg = int(data[i])-1
    fs = [[int(k) for k in j.split()] for j in data[i+1:i+5]]
    sg = int(data[i+5])-1
    ss = [[int(k) for k in j.split()] for j in data[i+6:i+10]]
    i += 10
    insec = []
    for j in fs[fg]:
        if j in ss[sg]:
            insec.append(j)
    if len(insec) == 1:
        print insec[0]
    elif len(insec) == 0:
        print "Volunteer cheated!"
    elif len(insec) > 1:
        print "Bad magician!"
    else:
        print 1232
    #print insec, fs[fg], ss[sg]
    ncase += 1