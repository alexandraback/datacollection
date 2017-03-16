LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'C-small-attempt1.in'
OUTPUT_FILE_NAME = 'C-small-attempt1.out'

def cutTrees(trees,first,second):
        higher=0
        lower=0
        orthX=int(first[1])-int(second[1])
        orthY=-int(first[0])+int(second[0])
        if orthX==0 and orthY==0:
                return 5000
        reference=int(first[0])*orthX+int(first[1])*orthY

        for i in trees:
                if int(i[0])*orthX+int(i[1])*orthY>reference:
                        higher=higher+1
                elif int(i[0])*orthX+int(i[1])*orthY<reference:
                        lower=lower+1
        return min(higher,lower)
def do_case(parsed_input):
        to_remove=""
        for tree in parsed_input:
                Min=5000
                for second in parsed_input:
                    Min=min(Min,cutTrees(parsed_input,tree,second))
                if Min==5000:
                        Min=0
                to_remove=to_remove+'\n'+str(Min)
        return to_remove

def do_parse(input):
        a=input
        for i in range(len(input)):
                a[i]=input[i].rstrip().split(" ")
        return a
def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
        temp=input_f.readlines()
        index=0
        for test_case in range(num_of_test_cases):
                lines=int(temp[index])
                parsed_input = do_parse(temp[index+1:index+lines+1])
                index=index+1+lines
                output.append('Case #' + str(test_case + 1) + ':' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
