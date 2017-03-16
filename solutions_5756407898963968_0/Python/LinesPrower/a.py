'''
Created on Apr 12, 2014

@author: linesprower
'''
import io, sys
import datetime

def solve(fin):
    def nums():
        return [int(x) for x in fin.readline().split()]
    def num():
        return int(fin.readline())
    
    def f():
        a = num()
        arr = [nums() for _ in range(4)]
        return set(arr[a-1])
    
    s1 = f()
    s2 = f()
    s = s1.intersection(s2)   
    if not s:
        return 'Volunteer cheated!'
    elif len(s) > 1:
        return 'Bad magician!'
    else:
        return list(s)[0]
    
        
def main():
    fname = 'a.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve(fin)))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()
        
if __name__ == '__main__':
    main()    