infile = open('C-small-attempt2.in','r')
outfile = open('output2.txt', 'w')

T = int(infile.readline().strip())
out = ""
for tc in range(T):
    out += "Case #"+str(tc+1)+":\n"
    
    #solution here
    N = int(infile.readline().strip())
    T = []
    for i in range(N):
        coord = infile.readline().strip().split()
        T.append((int(coord[0]),int(coord[1])))
    if len(T) <= 3:
        out += "0\n"*len(T)
        continue
    for tree in T: # for each squirrel's tree
        mincuts = len(T)
        for tree2 in T: # draw line to every other tree
            if tree != tree2: 
                left, right = 0,0
                if tree[0] == tree2[0]: # vertical line
                    for tree3 in T:
                        if tree3 != tree2 and tree3 != tree:
                            if tree3[0]<tree[0]:
                                left+=1
                            elif tree3[0]>tree[0]:
                                right+=1
                elif tree[1] == tree2[1]: # horizontal line
                    for tree3 in T:
                        if tree3 != tree2 and tree3 != tree:
                            if tree3[1]<tree[1]:
                                left+=1
                            elif tree3[1]>tree[1]:
                                right+=1
                else: # diagonal line
                    # y = mx + b
                    m = (tree[1]-tree2[1])/(tree[0]-tree2[0])
                    b = -1*m*tree[0]+tree[1]
                    # y >  or < mx + b for remaining trees?
                    epsilon = 0.000000001
                    for tree3 in T:
                        if tree3 != tree2 and tree3 != tree:
                            ytest = m*tree3[0]+b
                            if ytest - tree3[1] > epsilon:
                                right+=1
                            elif ytest - tree3[1] < -1*epsilon:
                                left+=1
                #print(tree, tree2, left, right)
                mincuts = min(mincuts, left, right)
                #print(mincuts)
            # end if tree1 != tree2
        # end tree2 loop
        out += str(mincuts)+"\n"
        #print("end of tree",tree)
    # end tree loop
    #print("end of test case")
                    
    
print(out)
outfile.write(out)
    
outfile.close()
infile.close()