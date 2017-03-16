def main():
    f = open('a.txt', 'r')
    o = open('a.out', 'w')

    n = int(f.readline().split()[0])

    for k in range(1, n+1):
        array = []
        s = set()
        c = int(f.readline().split()[0])
        m = int(f.readline().split()[0])
        array = ([int(x) for x in (f.readline().split())])
 #       print(len(array))
        i = 0
        while i < len(array):
            j = i+1
            while j < len(array):
                if array[i] + array[j] == c:
                    o.write('Case #' + str(k)+': ' + str(i+1) + ' ' +str(j+1)+'\n')
                    i = j = len(array)
                j = j+1
            i = i + 1

if __name__ == "__main__":
    main()
