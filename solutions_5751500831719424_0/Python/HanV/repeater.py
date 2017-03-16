__author__ = 'bozo'
import math

if __name__ == "__main__":
    input = open("A-small-attempt0.in")
    output = open("output.txt", 'w+')

    T = int(input.readline())

    for i in range(0, T):
        N = int(input.readline())

        strs = []
        ptrs = []
        counts = []

        for j in range(0, N):
            strs.append(input.readline())
            ptrs.append(0)
            counts.append(0)

        fin = False
        lost = False
        total = 0

        while not fin and not lost:
            current_letter = strs[0][ptrs[0]]
            fin = True
            max = 0
            min = 1
            for j in range(0, N):
                k = ptrs[j]
                counts[j] = 0

                while k < len(strs[j]) and strs[j][k] == current_letter:
                    counts[j] += 1
                    k += 1

                if counts[j] > max:
                    max = counts[j]

                if counts[j] < min:
                    min = counts[j]

                if k == len(strs[j]):
                    k -= 1

                ptrs[j] = k

                if k != len(strs[j]) - 1:
                    fin = False

                if counts[j] == 0:
                    lost = True
                    output.write("Case #{0}: {1}\n".format(i + 1, "Fegla Won"))

            minimal = 10000000
            for b in range(0, N):
                current = 0
                for a in range(0, N):
                    current += math.fabs(counts[b] - counts[a])

                if current < minimal:
                    minimal = current

            total += minimal

        if fin and not lost:
            output.write("Case #{0}: {1}\n".format(i + 1, int(total)))

    input.close()
    output.close()
