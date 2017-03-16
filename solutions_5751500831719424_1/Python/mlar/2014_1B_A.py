import sys
import numpy as np


def string_counter(string):
    characters = []
    counters = []

    n = 1
    curr = string[0]
    for c in string:
        if c == curr:
            n += 1
        else:
            characters.append(curr)
            counters.append(n)
            curr = c
            n = 1

    characters.append(curr)
    counters.append(n)
    
    return (characters, counters)

def solve_case(case_num, case_data):
    result = 'Case #' + str(case_num) + ': '

    
    char_arr = None
    n_arr = []

    for i in range(len(case_data)):
        (c, n) = string_counter(case_data[i])
        n_arr.append(n)
        if i == 0:
            char_arr = c
        elif c != char_arr:
            result += 'Fegla won'
            return result

    n = np.array(n_arr)
    ##print n
    moves = 0

    for i in range(n.shape[1]):
        char_count = n[:,i]
        m = np.median(char_count)
        moves += int(np.sum(np.abs(char_count - m)))

    result += str(moves)
    return result


def process_file(input_file, output_file):
    file_in = open(input_file, 'rU')
    file_out = open(output_file, 'w')

    i = 0
    num_cases = None
    case_num = 0
    case_data = None
    case_n = 0

    for row in file_in:
 
        if not num_cases:
            num_cases = int(row)

        elif i == 0:
            case_num += 1
            i += 1
            case_n = int(row)
            case_data = []
            
        elif i == case_n:
            case_data.append(row.strip())
            result = solve_case(case_num, case_data)
            file_out.write(result+'\n')
            i = 0

        else:
            case_data.append(row.strip())
            i += 1

        
    file_out.close()
            

def main():
    if len(sys.argv) == 3:
        print 'Program starts'
        process_file(sys.argv[1], sys.argv[2])
        sys.exit(1)
        
    else:
        print 'Give two arguments (INPUT_FILE OUTPUT_FILE)'
        sys.exit(1)


if __name__ == '__main__':
    main()
