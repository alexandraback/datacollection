import sys

def get_evacuation(data):
    number = max(data)
    if number == 0:
        return None
    for i in range(len(data)):
        if data[i] == number:
            data[i] -= 1
            return chr(ord('A') + i)

def count_data(data):
    number = 0
    for i in range(len(data)):
        if data[i] > 0:
            number += 1
    return number

def run_test(case_number, generator):
    number = int(next(generator))
    data = [int(x) for x in next(generator).split()]
    
    result = []
    while count_data(data):
        evac_one = get_evacuation(data)
        evac_two = get_evacuation(data)

        if count_data(data) == 1:
            result.append(evac_one)
            result.append(evac_two + get_evacuation(data))
        else:
            result.append(evac_one + evac_two)

    print('Case #%d: %s' % (case_number, ' '.join(result)))

def main():
    generator = get_file()
    number_of_tests = int(next(generator))
    for test in range(1, number_of_tests + 1):
        run_test(test, generator)

def get_file():
    for line in sys.stdin:
        yield line
        
if __name__ == '__main__':
    main()