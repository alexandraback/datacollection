fileHandle = open('in.txt', 'r')
outputHandle = open('out.txt', 'w')


def all_equal(number_array):
    first_number = number_array[0]
    for i in range(len(number_array)):
        if first_number != number_array[i]:
            return False
    return True


def cal_shortest(number_array):
    result_number = 0
    temp_array = number_array
    temp_array.sort()
    mid_number = temp_array[len(temp_array)/2]
    for i in range(len(temp_array)):
        result_number += abs(temp_array[i] - mid_number)
    return result_number


def process_string(fegla_string):
    temp_char = fegla_string[0]
    result_array = []
    char_array = [temp_char]
    repeat_number = 0
    for i in range(len(fegla_string)):
        if fegla_string[i] == '\n':
            continue
        if fegla_string[i] == temp_char:
            repeat_number += 1
        else:
            result_array.append(repeat_number)
            char_array.append(fegla_string[i])
            repeat_number = 1
            temp_char = fegla_string[i]
    result_array.append(repeat_number)
    return result_array, char_array


def give_len_array(matrix):
    result_array = []
    for i in range(len(matrix)):
        result_array.append(len(matrix[i]))
    return result_array


def give_col(matrix, i):
    result_array=[]
    for j in range(len(matrix)):
        result_array.append(matrix[j][i])
    return result_array


caseNumber = int(fileHandle.readline())

for i in range(caseNumber):
    lineNumber = int(fileHandle.readline())
    tempMatrix = []
    charMatrix = []
    resultMove = 0
    continueFlag = False
    for j in range(lineNumber):
        [num, cha] = process_string(fileHandle.readline())
        tempMatrix.append(num)
        charMatrix.append(cha)

    if not all_equal(give_len_array(tempMatrix)):
        outputHandle.write("Case #"+str(i+1)+": Fegla Won\n")
        continue

    for k in range(len(tempMatrix[0])):
        if not all_equal(give_col(charMatrix, k)):
            outputHandle.write("Case #"+str(i+1)+": Fegla Won\n")
            continueFlag = True
            break
        resultMove += cal_shortest(give_col(tempMatrix, k))
    if continueFlag:
        continue
    outputHandle.write("Case #"+str(i+1)+": "+str(resultMove)+"\n")


fileHandle.close()
outputHandle.close()