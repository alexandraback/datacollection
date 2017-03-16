#GJAM
#inn.in
from sys import * 

def execute():
        input_name = argv[1]
        output_name = "out.txt"
        input_file = open(input_name)
        output_file = open(output_name, 'w')

        main(input_file, output_file)

        input_file.close()
        output_file.close()

def main(input_file, output):
        # main algorithm goes here
        T = int(next(input_file))
        for i in range(T):
                N = int(next(input_file).strip())
                senators = [int(t) for t in next(input_file).strip().split()]
                upper_case = map(chr, range(65, 91))
                nr_senetors = sum(senators)
                sorted_senetors = []
                for j in range(len(senators)):
                        sorted_senetors.append([senators[j], upper_case[j]])
                sorted_senetors = sorted(sorted_senetors, reverse=True)
                output.write("Case #" + str(i + 1) + ":")
                while nr_senetors > 0 and nr_senetors != 3:
                        if sorted_senetors[0][0] == nr_senetors:
                                output.write(" " + sorted_senetors[0][1] + sorted_senetors[0][1])
                                sorted_senetors[0][0] -= 2
                        else:
                                output.write(" " + sorted_senetors[0][1] + sorted_senetors[1][1])
                                sorted_senetors[0][0] -= 1
                                sorted_senetors[1][0] -= 1
                        sorted_senetors = sorted(sorted_senetors, reverse=True)
                        nr_senetors -= 2
                if nr_senetors == 3:
                        letters = []
                        for l in sorted_senetors:
                                if l[0] > 0:
                                        letters.append(l[1])
                                else:
                                        break
                        output.write(" " + letters[0])
                        output.write(" " + letters[1] + letters[2])
                output.write("\n")

execute()
