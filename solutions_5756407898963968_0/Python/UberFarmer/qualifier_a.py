import argparse

def main():
    #parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    print(args.infile)
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        numCases = int(f_in.readline().strip())
        for i in range(numCases):
            firstAnswer = int(f_in.readline().strip())
            table = []
            for row in range(4):
                table += [f_in.readline().strip().split()]
            acceptableNumbers = table[firstAnswer-1]
            print(acceptableNumbers)
            
            secondAnswer = int(f_in.readline().strip())
            table2 = []
            for row in range(4):
                table2 += [f_in.readline().strip().split()]
            acceptableNumbers2 = table2[secondAnswer-1]
            print(acceptableNumbers2)
            
            finalNumbers = [x for x in acceptableNumbers if x in acceptableNumbers2]
            print(finalNumbers)
            if (len(finalNumbers) == 1):
                answer = str(finalNumbers[0])
            elif (len(finalNumbers) > 1):
                answer = "Bad magician!"
            elif (len(finalNumbers) == 0):
                answer = "Volunteer cheated!"
            
            outputline = "Case #" + str(i+1) + ": " + answer + "\n"
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        