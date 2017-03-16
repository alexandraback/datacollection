import argparse

def process(string):
    print(string)
    chars_out = []
    counts_out = []
    currentchar = string[0]
    num_current = 0
    for c in string:
        if c == currentchar:
            num_current += 1
        else:
            chars_out += [currentchar]
            counts_out += [num_current]
            currentchar = c
            num_current = 1
    chars_out += [currentchar]
    counts_out += [num_current]
    print(chars_out)
    print(counts_out)
    return chars_out, counts_out
        
def matcher(strings):
    stringlength = len(strings[0])
    for string in strings:
        if len(string) != stringlength:
            return False
        for c in range(stringlength):
            if string[c] != strings[0][c]:
                return False
    return True

def solve(counts, num_strings):
    totalmoves = 0
    for index in range(len(counts[0])):
        print("starting index {}".format(index))
        minmoves = 1000000
        minimum = min([x[index] for x in counts])
        print(minimum)
        maximum = max([x[index] for x in counts])
        print(maximum)
        for final_instances in range(minimum, maximum + 1):
            moves = 0
            for string in counts:
                moves += abs(final_instances - string[index])
            print(final_instances, moves)
            minmoves = min(moves, minmoves)
        totalmoves += minmoves
        print(index, minmoves)
    return totalmoves
        
        
def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        num_cases = int(f_in.readline().strip())
        for i in range(num_cases):
            num_strings = int(f_in.readline().strip())
            
            processed_strings = []
            processed_string_counts = []
            for string in range(num_strings):
                next_string = f_in.readline().strip()
                chars, counts = process(next_string)
                processed_strings += [chars]
                processed_string_counts += [counts]
            # [[(a,3),(b,2),(c,6)],[...]]
            print(processed_strings)
            print(processed_string_counts)
            
            possible = matcher(processed_strings)
            print("matched! {}".format(possible))
            if possible:
                result = solve(processed_string_counts, num_strings)
            else:
                result = -1
            
            if result == -1:
                result = "Fegla Won"
            outputline = "Case #{}: {}\n".format(i + 1, result)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        