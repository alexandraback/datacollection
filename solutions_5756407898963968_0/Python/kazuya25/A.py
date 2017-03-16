

class Case(object):
    def __init__(self, lines, number):
        self.rows = {}
        self.candidate = []
        self.number = number
        for i in range(4):
            self.rows[i+1] = map(int, lines[i].split())
        self.candidate = self.rows[number]
        
    @staticmethod
    def intersect(case1, case2):
        return list(set(case1.candidate) & set(case2.candidate))
    @staticmethod
    def solve(case1, case2):    
        sol = Case.intersect(case1, case2)
        
        if len(sol) > 1:
            return "Bad magician!"
        elif len(sol) == 0 :
            return "Volunteer cheated!"
        else:
            return str(sol[0])
class GJ(object):
    def __init__(self, file_in = "input.txt", file_out = "output.txt"):
        self.solutions = []
        with open(file_in) as f:
            lines = f.readlines()
            self.T = int(lines[0])
            self.lines = lines[1:]
        self.process()
        self.output(file_out) 
           
    def process(self):
        for i in range(self.T):
            c = [None, None]
            for j in range(2):
                number = int(self.lines[(i * 10 + j * 5)])
                c[j] = Case(self.lines[(i * 10 + j * 5 + 1) : (i * 10 + (j+1) * 5 )], number)
            
            self.solutions.append(Case.solve(*c))
        
    
    
    def output(self, output):
        l = map(lambda x: "Case #%s: %s\n"%(int(x[0])+1, x[1]), enumerate(self.solutions))
        with open(output, "w") as f:
            f.writelines(l)
            

GJ()