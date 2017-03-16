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
def main_job(n, m):
    method1 = 0
    method2 = 0
    diff_max = 0
    for i in range(n-1):
        diff = m[i]-m[i+1]
        if diff > 0:
            method1 += diff
            if diff > diff_max:
                diff_max = diff
        # print(diff)
    # print(diff_max)
    for i in range(n-1):
        method2 += min(diff_max, m[i])

    return [method1, method2]

def main():
    #input read
    input_file = open("input_a1.in", 'rt')
    num_cases = int(input_file.readline())

    #output write
    output_file = open("output_a1.txt", 'w')

    for i in range(num_cases):
        line = input_file.readline()
        n = int(line)
        line = input_file.readline()
        line = line.split()
        m = []
        for j in range(n):
            m.append(int(line[j]))

        result = main_job(n,  m)
        output = "Case #%d: %d %d\n" %(i+1, result[0], result[1])
        output_file.write(output)
        print(i+1)
    input_file.close()
    output_file.close()


if __name__ == "__main__":
    main()