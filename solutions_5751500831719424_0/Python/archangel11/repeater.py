impossible = "Fegla Won"

def solve(f):
    n = int(f.readline())

    strings = []
    counts = []
    smallest = []

    for i in range(n):
        string = f.readline().split("\n")[0]
        unique = [-1]
        stringCounts = []
        count = 0
        for j in range(len(string)):
            count += 1
            if string[j] != unique[-1]:
                unique.append(string[j])
                stringCounts.append(count)
                count = 0

        strings.append(string)
        stringCounts.append(count+1)
        smallest.append(unique[1:])
        counts.append(stringCounts[1:])

    if not all(map(lambda x: x==smallest[0], smallest)):
        return impossible

    output = 0

    for c in range(len(counts[0])):
        arr = sorted(map(lambda x: x[c], counts))
        median1 = arr[n/2]
        output1 = sum(map(lambda x: abs(x - median1), arr))
        if n%2 == 0:
            median2 = arr[(n-1)/2]
            output2 = sum(map(lambda x: abs(x - median1), arr))
            output1 = min(output1, output2)
        output += output1

    return output
