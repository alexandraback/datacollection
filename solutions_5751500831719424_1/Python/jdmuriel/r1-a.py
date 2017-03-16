#coding=UTF-8
__author__ = 'jesus'

FILE = 'r1-a.in'
FILEOUT = 'r1-a.out'

f = open(FILE, 'r')
fout = open (FILEOUT, 'w')

def evaluar (numcadenas, letras, ocurrencias):
    for i in range (numcadenas-1):
        if len(letras[i])!=len(letras[i+1]):
            return 'Fegla Won'
    numletras = len(letras[i])

    #Para cada letra, ver el nº mínimo y el máximo
    for j in range (numletras):
        for i in range(numcadenas-1):
            if letras[i][j] != letras [i+1][j]:
                #Una letra diferente
                return 'Fegla Won'

    distancia=0
    for j in range (numletras):
        max=-1
        min=10000
        for i in range(numcadenas):
            #obtenemos el mínimo y el máximo de ocurrencias
            if ocurrencias[i][j] < min:
                min=ocurrencias[i][j]
            if ocurrencias[i][j] > max:
                max=ocurrencias[i][j]
        #ahora iteramos entre el mínimo y el máximo calculando la cuenta
        cuenta2=0
        mindistancia=100000
        for k in range (min, max+1):
            cuenta2=0
            for i in range(numcadenas):
                cuenta2 += abs(ocurrencias[i][j]-k)
            if cuenta2<mindistancia:
                mindistancia=cuenta2
        #print 'letra', j, letras[i][j], 'distancia:', mindistancia, 'min:', min, 'max:', max
        distancia += mindistancia
    return str(distancia)

testcases = int(f.next())
for icase in range (testcases):

    N = int(f.next())
    letras=[]
    ocurrencias=[]
    for i in range(N):
        cadena= f.next().strip('\n')
        #letrasi lleva las diferentes letras de la iesima cadena
        #ocurrenciasi lleva las diferentes veces que aparece cada letrai
        letrasi=[]
        ocurrenciasi=[]

        letra = ''
        count = 0
        for j in range(len(cadena)):
            letraj=cadena[j]
            if letra==letraj:
                count += 1
            else:
                if letra != '':
                    letrasi.append(letra)
                    ocurrenciasi.append(count)
                letra = letraj
                count=1
        #add last letter
        letrasi.append(letraj)
        ocurrenciasi.append(count)

        #print cadena, letrasi, ocurrenciasi
        letras.append(letrasi)
        ocurrencias.append(ocurrenciasi)

    fout.write ("Case #{0}: {1}\n".format (icase+1, evaluar(N, letras, ocurrencias)))
    print "Case #{0}: {1}\n".format (icase+1, evaluar(N, letras, ocurrencias))

f.close()
fout.close()

