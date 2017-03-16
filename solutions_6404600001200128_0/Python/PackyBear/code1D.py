#-*- coding: utf-8 -*-
import math

var = raw_input("Enter something: ").split('\n')
text = ""

caseno = 0
double = 0
for line in var[1:]:
    if line != "":
        double += 1
        if double % 2 == 0:
            vvv = []
            vec = line.split(" ")
            for vv in vec:
                vvv.append(int(float(vv)))
            case1 = 0
            case2 = 0
            pp = 0
            c2vvv = []
            for vv in vvv:
                c2vvv.append((pp-vv))
                if vv < pp:
                    case1 += (pp-vv)                    
                pp = vv

            cc = max(c2vvv)
            for vv in vvv[:-1]:
                if vv < cc:
                    case2 += vv
                else:
                    case2 += cc
            caseno += 1
        
            newline = "Case #" + str(caseno) + ": " + str(case1) + ' ' + str(case2)
            text += "%s\n" % newline
print text
filew = open("output.txt",'w')
filew.write(text)
filew.close()
