'''

Input 
 	
Output 
 
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9

Case #1: 15 25
Case #2: 0 0
Case #3: 81 567
Case #4: 181 244


'''
s = [10, 5, 15, 5];

def minEat(s):
    # return (y, z)
    y = 0;
    n = len(s);
    min_rate = 0;
    for indx in range(1, n):
        diff = s[indx-1] - s[indx];
        if diff >= 0:
            y += diff;
            min_rate = max(min_rate, diff);
    z = 0;
    for indx in range(n-1):
        if s[indx] >= 0:
            z += min(min_rate, s[indx]);
    return((y, z));

infile = open('A-large.in', 'r');
num_test = int(next(infile));

for indx_test in range(num_test):
    num_input = int(next(infile));
    s = next(infile);
    s = s.strip().split();
    s = [int(x) for x in s];
    y, z = minEat(s);
    print('Case #' + str(indx_test + 1) + ': ', end="");
    print(str(y) + ' ' + str(z));
    
    
        
            
    