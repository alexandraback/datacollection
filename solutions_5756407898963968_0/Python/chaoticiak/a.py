"""
Google Code Jam Qualification Round 2014 Problem A

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "a.in"
    target = "a.out"
    sfile = None
    tfile = None

    def __init__(self):
        self.sfile = open(self.source, "r")
        self.tfile = open(self.target, "w+")

    def getInput(self, s = False):
        inputs = self.sfile.readline().strip()
        if not s:
            return inputs.split(" ")
        else:
            return inputs

    def writeOutput(self, s = ""):
        self.tfile.write(s)

IOHandler = IOHandlerObject()
g = IOHandler.getInput
w = IOHandler.writeOutput

############################## SOLUTION ##############################

t = int(g(True))
for i in range(1, t+1):
    w("Case #" + str(i) + ": ")

    rno1 = int(g(True)) - 1
    grid1 = [g(), g(), g(), g()]
    rno2 = int(g(True)) - 1
    grid2 = [g(), g(), g(), g()]
    row1 = grid1[rno1]
    row2 = grid2[rno2]
    a = [i if i == j else 0 for i in row1 for j in row2]
    while a.count(0): a.remove(0)
    if len(a) == 1:
        w(str(a[0]))
    elif len(a) == 0:
        w("Volunteer cheated!")
    else:
        w("Bad magician!")
    w("\n")