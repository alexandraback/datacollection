#! python3
import sys

def main():
    with open("A-small-attempt0.in") as in_file:
        with open("A-small-attempt0.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                time_num = int(in_file.readline().replace('\n', ''))
                mushrooms = in_file.readline().replace('\n', '').split(' ')
                mushrooms = [int(x) for x in mushrooms]

                case_1 = 0
                case_2 = 0
                biggest_drop = 0
                for i in range(len(mushrooms) - 1):
                    curr = mushrooms[i]
                    next = mushrooms[i + 1]
                    if next < curr:
                        case_1 += curr - next
                        if curr - next > biggest_drop:
                            biggest_drop = curr - next

                case_2 = biggest_drop * (len(mushrooms) - 1)

                for i in range(len(mushrooms) - 1):
                    curr = mushrooms[i]
                    if curr < biggest_drop:
                        case_2 -= biggest_drop - curr

                fout.write("Case #{0}: {1} {2}\n".format(x + 1, case_1, case_2))

if __name__ == "__main__":
    main()
 