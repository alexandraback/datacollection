import math;
str = "A-small-attempt1.in";
fo = open(str,"r");
T = int(fo.readline());
for m in range(T):
    k = int(fo.readline());
    x1 = fo.readline().strip();
    x2 = fo.readline().strip();
    l = [];
    for i in range(len(x1)):
        if i == 0:
            l.append(x1[i]);
            count = 1;
        elif x1[i] == l[len(l) - 1]:
            count += 1;
        else:
            l.append(count);
            l.append(x1[i]);
            count = 1;
        if i == len(x1) -1:
            l.append(count);
#    print l;
    l2 = [];
    for i in range(len(x2)):
        if i ==0:
            l2.append(x2[i]);
            count = 1;
        elif x2[i] == l2[len(l2) -1]:
            count += 1;
        else:
            l2.append(count);
            l2.append(x2[i]);
            count = 1;
        if i == len(x2) -1:
            l2.append(count);
#print l2;
    l_1 = l[::2];
    l2_1 = l2[::2];
    l_2 = l[1::2];
    l2_2 = l2[1::2];
#    print l_2;
#   print l2_2;
    c =0;
    if len(l_1) != len(l2_1):
        print "Case #%d: Fegla Won" % (m+1);
    else:
        l3 =[]
        for x,y in zip(l_2,l2_2):
            l3.append(math.ceil((x+y)/2));
        for x,y,z in zip(l_2,l2_2,l3):
            c += abs(x-z) + abs(y-z);
        print "Case #%d: " % (m+1), int(c);
