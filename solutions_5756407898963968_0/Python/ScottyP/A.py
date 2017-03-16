import numpy as np
import math
import time
##import os
##import shutil

input_file_name = './A-small-attempt0.in'
output_file_name = './A-small-attempt0.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        first_row = int(file_line)
        for i in range(first_row):
            file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        first_row_list = file_line.split()
        for i in range(4 - first_row + 1):
            file_line = input_file.readline()
        second_row = int(file_line)
        for i in range(second_row):
            file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        second_row_list = file_line.split()
        for i in range(4 - second_row):
            input_file.readline()

        candidate_list = []
        for number in first_row_list:
            if number in second_row_list:
                candidate_list.append(number)

        if len(candidate_list) == 0:
            output_file.write('Case #' + str(case_num) + ': Volunteer cheated!' + '\n')
        elif len(candidate_list) == 1:
            output_file.write('Case #' + str(case_num) + ': ' + candidate_list[0] + '\n')
        else:
            output_file.write('Case #' + str(case_num) + ': Bad magician!' + '\n')
        print(case_num)
        case_num += 1
        
    output_file.close()











