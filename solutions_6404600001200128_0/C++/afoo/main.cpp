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

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    int T,T_i;
    int N;
    int x[1002];
    cin >> T;
    for (T_i=1;T_i<=T;T_i++){
        cin >> N;
        for (int i=0;i<N;i++){
            cin >> x[i];
        }
        int pre = x[0];

        int ans1=0;
        int max=0;
//        printf("pre is [%d]\n", pre);
        for (int i=1;i<N;i++){
//            printf("x[%d] is [%d]\n",i,x[i]);
            if (pre-x[i]>0){
                ans1+=(pre-x[i]);
            }
            if (pre-x[i]>max){
                max=pre-x[i];
            }
            pre=x[i];
        }
        
        int ans2=0;
        int sum,left;
        sum = x[0];
//        printf("maxis [%d]\n",max);
        for (int i=1;i<N;i++){
//            printf("i is [%d], sum is [%d], ans2[%d]\n",i,sum,ans2);
            if (sum>max){
                ans2+=max;
                sum=x[i];
            }
            else {
                ans2+=sum;
                sum=0;
                sum+=x[i];

            }
//            printf("i is [%d], sum is [%d], ans2[%d]\n",i,sum,ans2);
            
        }
        
        cout << "Case #" << T_i << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
