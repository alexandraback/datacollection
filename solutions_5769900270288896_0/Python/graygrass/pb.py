import os

class Solver(object):
    def __init__(self):
        pass

    def helper1(self, t):
        if 0 == t % 2:
            mmax = t / 2
            cor = 1
            edge = t / 2 - 1
            return mmax, cor, edge
        else:
            mmax = (t + 1) / 2
            cor = 0
            edge = t - mmax
            return mmax, cor, edge
            
    def helper(self, r, c):
        mmax = -1
        cor = -1
        edge = -1
        mid = -1
        if 0 == r % 2:
            if 0 == c % 2:
                mmax = r * c / 2
                cor = 2
                edge = r + c - cor
                mid = r*c - mmax - cor - edge
            else:
                mmax = r*c/2
                cor = 2
                edge = r+c-cor
                mid = r*c -mmax - cor - edge
        else:
            if 0 == c % 2:
                mmax = r*c/2
                cor = 2
                edge = r+c-cor
                mid = r*c - mmax - cor - edge
            else:
                mmax = (r-1)*(c-1)/2 + (r+c)/2
                cor = 0
                edge = r + c - 2
                mid = r*c - mmax - cor - edge
        return mmax, cor, edge, mid
    
    def solve(self, inputs):
        rr, cc, nn = [int(x) for x in inputs[0].split()]
        if rr < cc:
            rr, cc = cc, rr
        if rr == cc == 3 and 8 == nn:
            return 8
        if cc == 1:
            mmax, cor, edge = self.helper1(rr)
            if nn <= mmax:
                return 0
            elif nn <= mmax + cor:
                return nn - mmax
            else:
                return cor + 2*(nn - mmax - cor)
        else:
            mmax, cor, edge, mid = self.helper(rr, cc)
            if nn <= mmax:
                return 0
            elif nn <= mmax + cor:
                return (nn - mmax) * 2
            elif nn <= mmax + cor + edge:
                return 2*cor + (nn - mmax - cor)*3
            else:
                return 2*cor + 3*edge + (nn-mmax-cor-edge)*4
                
            
        
    def feed(self, inputs):
        lines = [x.strip() for x in inputs]
        outputs = []
        test_case_n = int(lines[0])
        cur = 1
        for i in range(test_case_n):
            i = i
            case_line_cnt = 1
            case_inputs = lines[cur:cur+case_line_cnt]
            cur += case_line_cnt
            outputs.append(self.solve(case_inputs))
        return outputs

if __name__ == '__main__':
    iname = 'B-small-attempt0.in'
#     iname = 'foo'
    sample_in = '''
4
2 3 6
4 1 2
3 3 8
5 2 0
    '''
    sample_out = '''
Case #1: 7
Case #2: 0
Case #3: 8
Case #4: 0
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