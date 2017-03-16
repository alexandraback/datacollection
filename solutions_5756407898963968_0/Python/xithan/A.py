#!/Library/Frameworks/Python.framework/Versions/3.3/bin/python3.3
# Codejam ID 2974486
# Run with parameter
# -p for preprocessing
# -s for small input
# -l for large input
# -m=<int> for multithreading


from GCJ import GCJ
def parse(infile):
    F = GCJ.readint(infile)
    Fmatrix = [GCJ.readintarray(infile) for i in range(4)]
    S = GCJ.readint(infile)
    Smatrix = [GCJ.readintarray(infile) for i in range(4)]
    return Fmatrix[F-1], Smatrix[S-1]
    
def solve(data):
    f, s = data
    res = set(f) & set(s)
    if len(res) == 0:
        return "Volunteer cheated!"
    elif len(res) > 1:
        return "Bad magician!"
    else:
        return res.pop()
            
            


if __name__ == "__main__":
    GCJ('A', solve, parse, None).run()
