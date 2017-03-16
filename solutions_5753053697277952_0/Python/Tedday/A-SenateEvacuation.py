level = __file__.split("\\")[-1][0]
file_is_small = 1
attempt = 0
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")



letters = [chr(ord("A")+i) for i in xrange(26)]
def test_case():
    B = int(input_file.readline())
    sen = [int(i) for i in input_file.readline().split()]
    total = sum(sen)
    arr = [list(x) for x in zip(sen,[chr(ord("A")+i) for i in xrange(26)])]
    arr.sort(key=lambda(x): x[0])
    majority = False
    s = ""
    while(total > 0):
        char = arr[-1][1]
        arr[-1][0] -= 1
        total -= 1
        arr.sort(key=lambda(x): x[0])
        if(majority):
            s += char
            majority = False
        else:
            if(arr[-1][0]*2 > total):
                majority = True
            s += " " + char
    
    return s[1:]
        

T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    #print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
