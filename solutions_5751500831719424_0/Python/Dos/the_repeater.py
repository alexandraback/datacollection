"""
Created on 03/05/apr/2014

@author: dosdos

Problem A. The Repeater
https://code.google.com/codejam/contest/2994486/dashboard#s=p0



***Sample***

Input
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

Output
Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3

"""
import unittest


class ProblemA(object):

    def __init__(self, input_file_name=None, output_file_name=None, log_file_name=None):
        self.input_file_name = input_file_name
        self.output_file_name = output_file_name
        self.log_file_name = log_file_name

    # file I/O
    def read_word(self, file):
        return next(file).strip()

    def read_int(self, file, b=10):
        return int(self.read_word(file), b)

    def read_words(self, file, d=' '):
        return self.read_word(file).split(d)

    def read_ints(self, file, b=10, d=' '):
        return [int(x, b) for x in self.read_words(file, d)]

    def read_decimals(self, file, b=10, d=' '):
        return [float(x) for x in self.read_words(file, d)]


    def remove_double(self, s):
        l = list(s)
        res = ''.join(l[0])
        prev = l[0]

        for i in range(1,len(l)):

            if l[i] != prev:
                res += ''.join(l[i])
                prev = l[i]

        return res

    def char_occs(self, s):
        l = list(s)
        res = [1,]
        prev = l[0]

        for i in range(1,len(l)):

            if l[i] == prev:
                res[len(res)-1] += 1
            else:
                res.append(1)
                prev = l[i]

        return res



    def solve_small(self):

        # create I/O files
        input_file = open(self.input_file_name, 'r')
        output_file = open(self.output_file_name, "w")
        log_file = open(self.log_file_name, "w")

        # read file size
        T = self.read_int(input_file)

        log_file.write("There are %d cases to solve! :)\n" % T)
        print("There are %d cases to solve! :)\n" % T)

        # iterate on each case
        for case in range(T):

            log_file.write("\nCase #%d: " % (case+1) )
            print("\nCase #%d: " % (case+1) )

            # get problem data
            N = self.read_int(input_file) # the number of strings
            strings = []
            for _ in range(N):
                strings.append(self.read_word(input_file))
            log_file.write("%d %s" % (N, strings))
            print("%d %s" % (N, strings))



            root = self.remove_double(strings[0])
            for s in strings[1:]:
                if self.remove_double(s) != root:
                    output_file.write("Case #%d: %s\n" % (case+1,"Fegla Won"))
                    break
            else: # Fegla lose!

                roots_all = []
                for s in strings:
                    # char occurrencies for each strings
                    roots_all.append(self.char_occs(s))

                print("roots_all",roots_all)

                median_matrix = []
                for i in range(len(root)):
                    l = []
                    for j in range(len(roots_all)):
                        l.append(roots_all[j][i])
                    l.sort()
                    median_matrix.append(l)

                print("median_matrix",median_matrix)

                medians = []
                for median_line in median_matrix:
                    medians.append(median_line[int(len(median_line)/2)])

                print("medians",medians)

                counter = 0
                for i in range(len(roots_all)):
                    for j in range(len(roots_all[0])):
                        counter += abs( roots_all[i][j] - medians[j] )

                output_file.write("Case #%d: %d\n" % (case+1,counter))

        # close I/O files
        input_file.close()
        output_file.close()
        log_file.close()



class Test(unittest.TestCase):
    def setUp(self):
        self.problem_A = ProblemA()

    def test_remove_double(self):
        self.assertEqual(self.problem_A.remove_double('aaba'),'aba')
        self.assertEqual(self.problem_A.remove_double('abba'),'aba')
        self.assertEqual(self.problem_A.remove_double('abc'),'abc')
        self.assertEqual(self.problem_A.remove_double('aaabbbaaa'),'aba')

    def test_char_occs(self):
        self.assertEqual(self.problem_A.char_occs('aaba'),[2,1,1])
        self.assertEqual(self.problem_A.char_occs('abba'),[1,2,1])
        self.assertEqual(self.problem_A.char_occs('abc'),[1,1,1])
        self.assertEqual(self.problem_A.char_occs('aaabbbaaa'),[3,3,3])

    def test_solve_small(self):
        # problem_A = ProblemA("A-sample.in", "A-sample.out", "A-log.out")
        problem_A = ProblemA("A-small-attempt3.in", "A-small-attempt3.out", "A-log.out")
        # problem_A = ProblemA("A-large-attempt0.in", "A-large-attempt0.out", "A-log.out")
        problem_A.solve_small()


if __name__ == '__main__':
    unittest.main()
