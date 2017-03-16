def read_list_of_ints():
    return map(int, raw_input().split())


def read_matrix(lines):
    result = []
    
    for row in range(lines):
        result.append(read_list_of_ints())

    return result


def calculate(first, second, matrix1, matrix2):
    options1 = set(matrix1[first])
    options2 = set(matrix2[second])

    intersection = options1.intersection(options2)

    if len(intersection) == 0:
        return 'Volunteer cheated!'
    elif len(intersection) == 1:
        return list(intersection)[0]
    else:
        return 'Bad magician!'


def main():
    for case_number in xrange(int(raw_input())):
        first = int(raw_input())
        matrix1 = read_matrix(4)
        second = int(raw_input())
        matrix2 = read_matrix(4)

        result = calculate(first-1, second-1, matrix1, matrix2)

        print 'Case #%d: %s' % (case_number+1, result)

main()

#print calculate(2-1, 3-1, [[1, 2, 3, 4], [5,6,7,8], [9,10,11,12], [13,14,15,16]], [[1,2,5,4], [3,11,6,15],[9,10,7,12], [13,14,8,16]]) == 7
#print calculate(2-1, 2-1, [[1, 2, 3, 4], [5,6,7,8], [9,10,11,12], [13,14,15,16]], [[1, 2, 3, 4], [5,6,7,8], [9,10,11,12], [13,14,15,16]]) == 'Bad magician!'
#print calculate(2-1, 3-1, [[1, 2, 3, 4], [5,6,7,8], [9,10,11,12], [13,14,15,16]], [[1, 2, 3, 4], [5,6,7,8], [9,10,11,12], [13,14,15,16]]) == 'Volunteer cheated!'

#print calculate(3, ['...', '..#', '.##']) # false
#print calculate(3, ['...', '..#', '..#']) # false
#print calculate(3, ['...', '..#', '...']) # false
#print calculate(3, ['###', '###', '###']) # true
#print calculate(3, ['###', '#.#', '###']) # false
#print calculate(4, ['..##', '..##', '....', '....']) # true
#print calculate(4, ['..##', '..##', '#...', '....']) # false
#print calculate(4, ['####', '#..#', '#..#', '####']) # false
#print calculate(5, ['#####', '#####', '#####', '#####', '.....']) # false
#print calculate(5, ['#####', '#####', '#####', '#####', '#####']) # true
