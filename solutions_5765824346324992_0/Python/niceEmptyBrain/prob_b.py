__author__ = 'Haewon'

def lcm(x, y):
    if x > y:
        greater = x
    else:
        greater = y

    while(True):
        if((greater % x == 0) and (greater % y == 0)):
            lcm = greater
            break
        greater += 1

    return lcm


# do the job
def main_job(n, b, m):
    occupied = [0]*b

    ll = m[0]
    for i in range(b-1):
        ll = lcm(ll, m[i+1])

    count = 0
    assign = []
    while True:
        curr = occupied.index(min(occupied))
        occupied[curr] += m[curr]
        assign.append(curr)
        flag = True
        for i in range(b):
            if occupied[i] != ll:
                flag = False
        if flag:
            break

    idx = (n-1) % len(assign)
    return assign[idx]+1


def main():
    #input read
    input_file = open("input_b1.in", 'rt')
    num_cases = int(input_file.readline())

    #output write
    output_file = open("output_b1.txt", 'w')

    for i in range(num_cases):
        line = input_file.readline()
        line = line.split()
        b = int(line[0])
        n = int(line[1])
        line = input_file.readline()
        line = line.split()
        m = []
        for j in range(b):
            m.append(int(line[j]))

        result = main_job(n, b, m)
        output = "Case #%d: %d\n" %(i+1, result)
        output_file.write(output)
        print(i+1)
    input_file.close()
    output_file.close()


if __name__ == "__main__":
    main()