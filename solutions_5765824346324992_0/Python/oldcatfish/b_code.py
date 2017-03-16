'''


Input 
 	
Output 
 
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1

Case #1: 1
Case #2: 3
Case #3: 1

'''
def getTheBarber(N, m):
    # return the number
    B = len(m);
    if N <= B:
        return(N);
        
    inv_m_sum = 0.0;
    for val in m:
        inv_m_sum += 1.0/val;
    #t_approx = (N-B)/inv_m_sum;
    t_approx1 = (N-2*B-1)/inv_m_sum;
    t_approx2 = (N +1 )/inv_m_sum;
    
    
    t_left = max(0, int(t_approx1));
    t_right = int(t_approx2);
    
    for t in range(t_left, t_right+1):
        N_serve = 0;
        for val in m:
            N_serve += int(t//val);
        if N_serve >= (N - B):
            break;
    N_serve_1 = 0;
    for val in m:
        N_serve_1 += int((t-1)//val);
    diff = N - B - N_serve_1;
    count = 0;
    for indx in range(B):
        if t%m[indx] == 0:
            count += 1;
        if count == diff:
            break;
    return(indx+1);
            
## test
## read file and output            
infile = open('B-small-attempt0.in', 'r');
num_test = int(next(infile));

for indx_test in range(num_test):
    tmp = next(infile);
    tmp1 = tmp.strip().split();
    B = int(tmp1[0]);
    N = int(tmp1[1]);
    m_str = next(infile);
    tmp = m_str.strip().split();
    m = [int(x) for x in tmp];
    
    res = getTheBarber(N, m);
    print('Case #' + str(indx_test + 1) + ': ', end="");
    print(str(res));
    