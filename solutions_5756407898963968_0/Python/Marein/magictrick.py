import sys


class Logger:
    """
    Log to a file as well as the standard console
    """

    def __init__(self, filename, use_console=True):
        self.console = sys.stdout
        self.log = open(filename, 'w')
        self.use_console = use_console

    def write(self, content):
        if self.use_console: self.console.write(content)
        self.log.write(content)

    def flush(self):
        if self.use_console: self.console.flush()

problem = "A-small-attempt0"
filename = "{}.in".format(problem)
sys.stdout = Logger("{}.out".format(problem))

with open(filename) as file:

    def readint():
        return int(file.readline())

    def readints(sep=" "):
        return list(map(int,file.readline().strip().split(sep)))

    def readarrangement():
        return [readints() for i in range(4)]

    def readcandidates():
        answer = readint()
        arrangement = readarrangement()
        return arrangement[answer-1]

    nr_of_cases = readint()

    for case_nr in range(1,nr_of_cases+1):

        intersection = set(readcandidates()).intersection(readcandidates())

        if len(intersection) == 1:
            answer = list(intersection)[0]
        elif len(intersection) > 1:
            answer = "Bad magician!"
        else:
            answer = "Volunteer cheated!"

        print("Case #{}:".format(case_nr),answer)
