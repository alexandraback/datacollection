def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    r1,=read_tuple(f)
    s1=[]
    for _ in xrange(4):
        s1.append(read_list(f))
    r2,=read_tuple(f)
    s2=[]
    for _ in xrange(4):
        s2.append(read_list(f))
    return ((r1,s1),(r2,s2))


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases






def solve(case):
    (r1,s1),(r2,s2)=case
    ch1=s1[r1-1]
    ch2=s2[r2-1]
    ch_fin=[ch for ch in ch2 if ch in ch1]
    return ch_fin






def outcome_string(outcome):
    if len(outcome)==0:
        return "Volunteer cheated!"
    elif len(outcome)>1:
        return "Bad magician!"
    else:
        return "{}".format(outcome[0])


def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
                f.write("Case #{0}: {1}\n".format( n+1 , outcome_string(o) ))
def process(path_in, path_out=None):
    if path_out==None:
        path_out=path_in.rsplit(".",1)[0]+".out"
    cases=load_cases(path_in)
    outcomes=[solve(c) for c in cases]
    save_outcomes(path_out, outcomes)