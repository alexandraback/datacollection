debug = False
with open("A-small-attempt0.in","r") as f:
    with open("out.txt","w") as o:
        count = 0
        case = int(f.readline())
        while case-count>0:
            count += 1
            
            ########################################
            # Solve Problem
            ans1 = f.readline().strip()
            #line11 = list(map(int, f.readline().split()))
            #line12 = list(map(int, f.readline().split()))
            #line13 = list(map(int, f.readline().split()))
            #line14 = list(map(int, f.readline().split()))
            line1 = {
                '1':list(map(int, f.readline().split())),
                '2':list(map(int, f.readline().split())),
                '3':list(map(int, f.readline().split())),
                '4':list(map(int, f.readline().split())),
                }
            ans2 = f.readline().strip()
            #line21 = list(map(int, f.readline().split()))
            #line22 = list(map(int, f.readline().split()))
            #line23 = list(map(int, f.readline().split()))
            #line24 = list(map(int, f.readline().split()))
            line2 = {
                '1':list(map(int, f.readline().split())),
                '2':list(map(int, f.readline().split())),
                '3':list(map(int, f.readline().split())),
                '4':list(map(int, f.readline().split())),
                }            

            result = [val for val in line1[ans1] if val in line2[ans2]]
            if len(result) == 1:
                result = result[0]
            elif len(result) >1:
                result = "Bad magician!"               
            else:
                result = "Volunteer cheated!"
            
            ########################################
            # Output
            case_result = "Case #%s: %s" % (count,result)
            if debug:
                print(case_result)
            o.write(case_result+'\n')
            
        
