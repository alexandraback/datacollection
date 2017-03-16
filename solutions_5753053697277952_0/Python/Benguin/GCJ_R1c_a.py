def sol(A):

    if len(A) == 2:
         return (int(sum(A)/2)-1)*"AB "+"AB"


    sol = ""
    max2 = max(A)
    while max2 > 1:
        for i, a in enumerate(A):
            if a == max2:
                sol += chr(ord('A')+i) + " "
                A[i] -= 1
        max2 = max(A)


    for i, a in enumerate(A):
        if sum(A) <= 2:
                break
        if a == 1:
            sol += chr(ord('A')+i) + " "
            A[i] -= 1
            

    for i, a in enumerate(A):
            if a == 1:
                sol += chr(ord('A')+i)
                A[i] -= 1

    return sol

            



fIn = open('input.txt', 'r')
fOut = open('output.txt', 'w')
case = 0
for line in fIn:
    print(case)
    if case > 0 and case%2 == 0:
        A = line.split(" ")
        A = [int(a) for a in A]
        fOut.write("Case #"+str(int(case/2))+": "+sol(A)+"\n")
    case += 1