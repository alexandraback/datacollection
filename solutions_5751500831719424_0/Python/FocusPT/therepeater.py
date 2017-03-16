#__author__ = 'afonso-ferreira'

file = open('bini2.in', 'r')
matrix=file.read().split('\n')

t=matrix[0]
#print( matrix)
k=1
for aux in range(0,int(matrix[0])):
    sets=[]
    table=[]
    str_table=[]
    #print(matrix[aux+1])

    for aux2 in range(1,int(matrix[k])+1):
        ant=-1
        cont=1
        aux_list=[]
        aux_string=[]
        counter=1
        for aux3 in matrix[aux2+k]:
            if aux3==ant:
                cont=cont+1;
            if ant!=aux3 and ant!=-1:
                aux_list.append(cont);
                cont=1
                aux_string.append(ant)
            #if(counter==len(matrix[aux2+k])):
            #    aux_list.append(cont)
            #    aux_string.append(aux3)
            ant=aux3
            counter=counter+1

        aux_string.append(ant)
        aux_list.append(cont);
        table.append(aux_list)
        str_table.append(aux_string)

    for aux6 in range(1,len(str_table)):
        if str_table[aux6-1] != str_table[aux6]:
            flag=0
            break
        flag=1

    k=k+int(matrix[k])+1

    if flag==0:
        print('Case #',end="")
        print(aux+1,end="")
        print(": Fegla Won")
    else:
        action=0
        table=[list(i) for i in zip(*table)]

        for aux3 in table:
            aux3.sort()
            #print(aux3)
            med=aux3[int(len(aux3)/2)]
            for b in aux3:
                action=action+abs(med-b)
        print('Case #',end="")
        print(aux+1,end="")
        print(': ',end="")
        print(action)

    #print(table)
    #print(str_table)

    #print(k)