### Google code jam 2015
### Round 1A
### Problem A: Mushrooms

def Case1(seq):
    ret = 0;
    for i in range(1, len(seq)):
        if seq[i] < seq[i-1]:
            ret += seq[i-1]-seq[i];
    return ret;

def Case2(seq):
    minRate = seq[0] - seq[1];
    for i in range(2, len(seq)):
        minRate = max(minRate, seq[i-1] - seq[i]);

    ret = 0;
    for i in range(0, len(seq)-1):
        ret += min(minRate, seq[i]);
    
    return ret;

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    N = int(raw_input());
    m = map(int, raw_input().split());

    print Case1(m), Case2(m);
