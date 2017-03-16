
input_file  = "e1.txt"
output_file = "output.txt"


with open(input_file, 'r') as inputf, open(output_file, 'w') as outputf:
    lines = inputf.readlines()
    N = int(lines.pop(0))
    for k in range(N):
        i = 10*k
        row  = int(lines[i])
        row2 = int(lines[i+5])
        a1 = map(int, lines[i+row].split(' ')) 
        a2 = map(int, lines[i+row2+5].split(' ')) 
        c = set(a1).intersection(set(a2))
        if len(c)==1:
            outputf.write("Case #%s: %s\n" % (k+1, c.pop()))
        elif len(c)>1:
            outputf.write("Case #%s: %s\n" % (k+1, "Bad magician!"))
        elif len(c)==0:
            outputf.write("Case #%s: %s\n" % (k+1, "Volunteer cheated!"))

