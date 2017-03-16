'''
0 0
10 0
10 10
0 10
5 5
'''
#import numpy as np;
#points = [[0, 0], [10, 0], [10, 10], [0, 10], [5, 5]];
def cutMin(points):
    N = len(points);
    res = [0 for dummy_indx in range(N)];
    
    for i in range(N):
        xi = points[i][0];
        yi = points[i][1];
        cut_min = N + 1;
    
        for j in range(N):
            if j == i:
                continue;
    
            xj = points[j][0];
            yj = points[j][1];
            count_up= 0;
            count_down = 0;
            for k in range(N):
                if k == i or k == j:
                    continue;
                xk = points[k][0];
                yk = points[k][1];
                # cross prod
                val = (xj - xi) * (yk - yi) - (xk - xi) * (yj - yi);
                if val > 0:
                    count_up += 1;
                if val < 0:
                    count_down += 1;
            cut_min = min(cut_min, count_up, count_down);
        res[i] = cut_min;
    return(res);
##
infile = open('C-small-attempt2.in', 'r');
#infile = open('test_in.txt', 'r');
num_test = int(next(infile));

for indx_test in range(num_test):
    N = int(next(infile));
    points = [];
    for dummy_indx in range(N):
        tmp = next(infile);
        tmp = tmp.strip().split();
        x = int(tmp[0]);
        y = int(tmp[1]);
        points.append([x, y]);
    res = cutMin(points);
    print('Case #' + str(indx_test + 1) + ': ');
    for indx in range(N):
        print(str(res[indx]));
        
