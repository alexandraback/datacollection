def seRompe(cantidades):
    maximo = max(cantidades)
    suma = sum(cantidades)
    return maximo > suma/2


def resolver(cantidades):
    salida = ""
    while sum(cantidades) != 0:
        maximo = max(cantidades)
        indice = cantidades.index(maximo)
        salida += chr(65 + indice)
        cantidades[indice] -= 1        
        if seRompe(cantidades):
            maximo = max(cantidades)
            indice = cantidades.index(maximo)
            salida += chr(65 + indice)
            cantidades[indice] -= 1   
        salida += " "
                    
    return salida   


f = open("A-large.in", 'r')
s = open("salidaA.txt", 'w')

cases = int(f.readline())

for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    linea = f.readline()
    N = int(linea.strip())
    cantidades = [int(x) for x in f.readline().strip().split(" ")]
    print N
    print cantidades
    s.write(resolver(cantidades))
    s.write("\n")    
    


f.close()
s.close()