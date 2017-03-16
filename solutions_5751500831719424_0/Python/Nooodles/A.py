def FindMap(s):
    Map = s[0];
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            Map += s[i];
    return Map;

def FindLengths(s, master):
    L = [0]*len(master);
    i = 0;
    for j in range(len(s)):
        if s[j] == master[i]:
            L[i] += 1;
        else:
            i += 1;
            L[i] = 1;
    return L;

def FindMedianSum(lValue):
    n = len(lValue)/2;
    ans = 0;
#    print lValue
    for i in range(len(lValue[0])):
        # consider all values at index k;
        arr = [];
        for line in lValue:
            arr.append(line[i]);

        arr.sort();
        target = arr[n];
        diff = 0;
        for j in arr:
            diff += abs(j-target);
#        print arr, target,  diff
        ans += diff;
    print ans;
    
def Solve(strings):
    Master = FindMap(strings[0]);
    #print Master,
    for s in strings:
        if FindMap(s) != Master:
            print "Fegla Won";
            return;

    Lengths = [];
    for s in strings:
        Lengths.append( FindLengths(s, Master) );
    
    #print Lengths, 

    FindMedianSum(Lengths);
    
    #print 'needs work';
    return;
    

T = int(raw_input());
for q in range(T):
    print "Case #%d:" % (q+1),;

    N = int(raw_input());
    String = [];
    for i in range(N):
        String.append(raw_input().split()[0]);

    Master = FindMap(String[0]);
    Solve(String);
        
