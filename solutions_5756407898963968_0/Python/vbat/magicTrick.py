def magicTrickVerifier(inputFile):
    data = [i.strip() for i in open(inputFile).readlines()]
    caseCount=int(data[0])
    cases=[]
    for caseID in range(caseCount):
        cases.append(data[1+caseID*10:11+caseID*10])

    def solveCase(caseID, case):
        ans1=int(case[0])
        ans2=int(case[5])
        matrix1=map(lambda x: x.split(), case[1:5])
        matrix2=map(lambda x: x.split(), case[6:10])
        row1=set(matrix1[ans1-1])
        row2=set(matrix2[ans2-1])
        candidates=list(row1 & row2)

        caseText='Case #'+str(caseID)+': '

        print len(candidates)==1, candidates
        
        if len(candidates)==1:
            informationText=candidates[0]
        elif len(candidates)>1:
            informationText='Bad magician!'
        else:
            informationText='Volunteer cheated!'

        return caseText+informationText+'\n'

    output=[solveCase(caseID+1, case) for (caseID, case) in enumerate(cases)]
    
    f=open('sampleOutput.txt', 'wb')
    f.write('')
    f.writelines(output)
    f.close()
    
    return output
