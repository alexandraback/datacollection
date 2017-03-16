LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'B-large.in'
OUTPUT_FILE_NAME = 'B-large.out'

def startsInT(barbers,t,N):
        sum=0
        for i in barbers:
                sum=sum+int(t/(int(i)))+1
        return sum>=N
def searchT(barbers,N):
        top=100000000000000
        bott=-1
        while top-bott>0:
                mid=int((top+bott+1)/2)
                if startsInT(barbers,mid,N):
                        top=mid-1
                else:
                        bott=mid
        return bott
def do_case(parsed_input):
        N=int(parsed_input[0])
        barbers=parsed_input[1]
        t=searchT(barbers,N)
        sum=0
        for i in barbers:
                sum=sum+int((t)/int(i))+1
        for i in range(len(barbers)):
                if (t+1)%int(barbers[i])==0:
                        sum=sum+1
                        if sum==N:                                
                                return str(i+1)
        return 'www'

def do_parse(input):
        return [input[0].rstrip().split(" ")[1],input[1].rstrip().split(" ")]
        

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
