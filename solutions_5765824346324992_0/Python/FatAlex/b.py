def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    _,n=read_tuple(f)
    return n,read_list(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def get_served(t,mk):
    n=0
    for m in mk:
        n=n+t//m+1
    return n
def find_start(n,mk):
    k=1
    while get_served(k,mk)<n:
        k=k*2
    return k
def find_div(n,mk):
    k=find_start(n,mk)
    a,b=0,k
    while b-a>1:
        assert b>a
        c=(b+a)//2
        s=get_served(c,mk)
        if s>=n:
            b=c
        else:
            a=c
    return b
def find_server(b,n,mk):
    np=get_served(b-1,mk)
    assert np<n
    exs=n-np
    for i,m in enumerate(mk):
        if b%m==0:
            exs=exs-1
            if exs==0:
                return i
    assert False
def solve(case):
    n,mk=case
    if len(mk)>=n:
        return n
    b=find_div(n,mk)
    #print b, get_served(b-1,mk), get_served(b,mk)
    return find_server(b,n,mk)+1






def outcome_string(outcome):
    return "{}".format(outcome)


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
    




def verify_outcome(case, outcome):
    ### IMPLEMENT ###
    return outcome==solve(case)

def test_solutions(path_in, until_first_fail=True):
    cases=load_cases(path_in)
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"
                
def gen_cases():
    ### IMPLEMENT ###
    return []

def test_solutions_gen(until_first_fail=True):
    cases=gen_cases()
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"