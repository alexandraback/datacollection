f = open("A.in")
num = int(f.readline())
output = ""
for n in range(num):
    N, L = [int(x) for x in f.readline().strip().split(" ")]
    outlets = [x for x in f.readline().strip().split(" ")]
    devices = [x for x in f.readline().strip().split(" ")]

    trials = [
    #output += "Case #"+str(n+1) + ": " + output_val +"\n"

f = open ("A.out", "w+")
f.write(output)
f.close()



