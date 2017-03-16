import os
import itertools

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        ss = inputs[1].strip()
        ss = [(int(x), chr(ord('A') + i)) for i, x in enumerate(ss.split())]
        ss.sort(key=lambda x: x[0])
        ss.reverse()
        rslt = []
        while ss[0][0] > ss[1][0]:
            rslt.append(ss[0][1])
            ss[0] = (ss[0][0] - 1, ss[0][1])
        for t in ss[2:]:
            x = t[0]
            while x > 0:
                rslt.append(t[1])
                x -= 1
        for i in range(ss[1][0]):
            rslt.append(ss[0][1]+ss[1][1])
        return ' '.join(rslt)
        pass
    
    def feed(self, inputs):
        lines = [x.strip() for x in inputs]
        outputs = []
        test_case_n = int(lines[0])
        cur = 1
        for i in range(test_case_n):
            i = i
            case_line_cnt = 2
            case_inputs = lines[cur:cur+case_line_cnt]
            cur += case_line_cnt
            outputs.append(self.solve(case_inputs))
        return outputs

if __name__ == '__main__':
    iname = 'A-small-attempt0.in'
    sample_in = '''4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
    '''
    sample_out = '''
Case #1: AB BA
Case #2: AA BC C BA
Case #3: C C AB
Case #4: BA BB CA
    '''
    if os.path.exists(iname):
        with open(iname) as f:
            inputs = f.readlines()
    else:
        inputs = [x.strip() for x in sample_in.split('\n') if x.strip()]
    solver = Solver()
    outputs = solver.feed(inputs)
    fail_flag = False
    if os.path.exists(iname):
        with open(iname+'.out', 'w') as f:
            for i, v in enumerate(outputs):
                print >> f, 'Case #%d: %s'%(i+1, str(v))
    else:
        ans = set([x.strip() for x in sample_out.split('\n') if x.strip()])
        for i, v in enumerate(outputs):
            t = 'Case #%d: %s'%(i+1, str(v))
            if t not in ans:
                print '!!! Wrong:', t
                fail_flag = True
    print '===================================================='
    for i, v in enumerate(outputs):
        print 'Case #%d: %s'%(i+1, str(v))
    print '===================================================='
    print 'done' if not fail_flag else 'fail'
    pass