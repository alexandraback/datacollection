//
//  main.cpp
//  2015_1A_B
//
//  Created by Jui Jung Li on 2015/4/18.
//  Copyright (c) 2015年 Jui Jung Li. All rights reserved.
//

//
//  main.cpp
//  2015_1A_A
//
//  Created by Jui Jung Li on 2015/4/18.
//  Copyright (c) 2015年 Jui Jung Li. All rights reserved.
//


#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int f(int *x, int B, long int m){
    int sum = 0;
    for (int i=0;i<B;i++){
        sum += ( m/x[i] + 1 );
    }
//    printf("m is [%ld], sum is [%d]\n",m,sum);
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int T,T_i;
    int B,N;
    int x[1002];
    cin >> T;
    for (T_i=1;T_i<=T;T_i++){
        cin >> B >> N;
        for (int i=0;i<B;i++){
            cin >> x[i];
        }
        int ans = 0;
        
        long int max = 0;
        long int min = 0;
        while (f(x,B,max)<N){
            min = max;
            max = 2*min+1;
        }
//        printf("min is [%ld], mid is max is [%ld]\n", min, max);
        while (max-min>1) {
            long int mid = (min+max)/2;
            if (f(x,B,mid)<N) {
                min = mid;
            }
            else {
                max = mid;
            }
        }
//        printf("min is [%ld], max is [%ld]\n", min, max);
        
        int sum1 = f(x,B,min);
        int sum2 = f(x,B,max);
        ans = N-sum1;
        if (N <= B ) {
            ans = N;
        }
        else {
            int tmp = 0;
            for (int i=0;i<B;i++){
                if ((min+1)%x[i]==0){
                    tmp++;
                }
                if (tmp==N-sum1){
                    ans = i+1;
                    break;
                }
            }
        }
/*        if (ans <= 0){
            printf("error!!!!\n");
        }
        if (ans>B) {
            printf("error ans > B, [%d] > [%d]\n", ans, B);
        }
 */
//        printf("sum1 is [%d], sum2 [%d]\n", sum1, sum2);
        cout << "Case #" << T_i << ": " << ans << endl;
    }
    return 0;
}

