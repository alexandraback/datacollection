import sys

def typeify(type, str):
    return [type(chr) for chr in str.split(" ")]

class Monad:
    def __init__(self):
        self.state = None
        self.DEBUG = False
    def __str__(self):
        return self.state.__str__()

    def _debug(self, string):
        if self.DEBUG: print(string)

    def debug(self, *strings):
        if strings: self._debug(" ".join(str(x) for x in strings))
        else:       self._debug(self.state)

    def startDebugging(self):
        self.DEBUG = True
        self.debug("Debug output on.")

    # filename -> [str]
    def read(self, filename):
        with open(filename) as fd:
            self.state = fd.read().split("\n")
            # chomp trailing newline
            if self.state[-1] == "": self.state.pop()
        return self

    # [str] -> int, [[str]]
    def splitCases(self):
        numCases = int(self.state.pop(0))
        # check this is in the format we expect
        assert len(self.state) % numCases == 0
        caseLength = len(self.state) / numCases
        self.state = [self.state[i:i+caseLength] for i in [x*caseLength for x in range(numCases)]]
        return self

    def type(self, *args):
        def cast(i, string):
            type = args[min(i, len(args)-1)]
            if i < len(args) - 1:
                return type(string)
            else:
                return [type(num) for num in string.split(" ")]

        self.state = [[cast(i, str) for i, str in enumerate(case)] for case in self.state]
        return self

    def floatify(self):
        self.state = [[floatify(line) for line in case] for case in self.state]
        return self

jam = Monad()
