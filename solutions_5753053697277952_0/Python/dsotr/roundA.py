import time

alphabet = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]

def solve_case(P):
    result = ""
    zeros = sum([1 for x in P if x == 0])
    L = []
    for i,v in enumerate(P):
        L.append([int(v), alphabet[i]])
    L = sorted(L, reverse=True)
    while 1:
        l = len(L)
        if l == 0:
            return result
        m = L[0][0]
        if l == 1:
            result += (" " + L[0][1]) * m
            return result
        if l == 2:
            while L[0][0] > L[1][0]:
                result += " " + L[0][1]
                L[0][0] -= 1
            while L[0][0] > 0:
                result += " " + L[0][1] + L[1][1]
                L[0][0] -= 1
                L[1][0] -= 1
            return result
        if l == 3:
            #print(L)
            while L[0][0] > L[1][0]:
                result += " " + L[0][1]
                L[0][0] -= 1
            while L[2][0] > 0:
                result += " " + L[2][1]
                L[2][0] -= 1
            while L[0][0] > 0:
                result += " " + L[0][1] + L[1][1]
                L[0][0] -= 1
                L[1][0] -= 1
            return result
        if m > 1:
            result += " " + L[0][1] + L[0][1]
            L[0][0] -= 2
        else:
            result += " " + L[0][1]
            L[0][0] -= 1
        L = sorted(L, reverse=True)






if __name__ == '__main__':
    start = time.time()
    path = './A-small-attempt0.in'
    # path = './A-large.in'
    out = open(path + '.out', 'w', newline='')
    count = 1
    with open(path) as f:
        T = int(f.readline().strip())
        for i in range(T):
            print(count)
            N = int(f.readline().strip())
            P = f.readline().strip().split(" ")
            out.write("Case #%i: %s\n" % (count, solve_case(P)))
            count += 1
    out.close()
    print("Elapsed: %f seconds" % (time.time() - start))
