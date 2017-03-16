LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'A-large.in'
OUTPUT_FILE_NAME = 'A-large.out'

def do_case(parsed_input):
        Max=0
        sumVarys=0
        for i in range(len(parsed_input)-1):
                sumVarys=sumVarys+max(0,int(parsed_input[i])-int(parsed_input[i+1]))
                Max=max(Max,int(parsed_input[i])-int(parsed_input[i+1]))
        sum=0
        for i in range(len(parsed_input)-1):
                sum=sum+min(Max,int(parsed_input[i]))

        return str(sumVarys)+' '+str(sum)

def do_parse(input):
        return input[1].rstrip().split(" ")
        

def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
	
        input_lines = input_f.readlines()
	
        for test_case in range(num_of_test_cases):
                parsed_input = do_parse(input_lines[test_case*LINES_FOR_EACH_INPUT : (test_case + 1) * LINES_FOR_EACH_INPUT])
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
