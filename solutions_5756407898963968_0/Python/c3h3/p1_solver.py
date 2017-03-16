'''
Created on Apr 13, 2014

@author: c3h3
'''

from PlaYdata.util import tools
import numpy as np
import sys


if __name__ == '__main__':
    assert len(sys.argv) > 1
    input_filename = str(sys.argv[1])

    with open(input_filename, "r") as input_file:
        input_file_read = input_file.read()

    input_file_lines = input_file_read.split("\n")
    input_file_lines
    n_cases = int(input_file_lines[0])
    case_seps = map(lambda x: 10 * x + 1, range(n_cases + 1))
    case_seps_idx = list(tools.ngram(case_seps, 2))

    i_case = 0

    for one_case_idx in case_seps_idx:
        i_case = i_case + 1
        one_case_data = input_file_lines[one_case_idx[0]:one_case_idx[1]]
        first_select = int(one_case_data[0])
        second_select = int(one_case_data[5])
        first_select_row = np.array(map(lambda xx: xx.split(),
                                        one_case_data[1:5])[first_select - 1])

        second_select_row = np.array(map(lambda xx: xx.split(),
                                         one_case_data[6:10])[second_select - 1])

        inter_rows = np.intersect1d(first_select_row, second_select_row)
        if len(inter_rows) == 1:
            print "Case #%s: %s" % (i_case, inter_rows[0])
        elif len(inter_rows) > 1:
            print "Case #%s: %s" % (i_case, "Bad magician!")
        else:
            print "Case #%s: %s" % (i_case, "Volunteer cheated!")




