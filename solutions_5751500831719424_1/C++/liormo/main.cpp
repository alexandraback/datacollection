//
//  main.cpp
//  GC2014R1B_A
//
//  Created by lmotorin on 5/3/14.
//  Copyright (c) 2014 Lior. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 100

int main(int argc, const char * argv[])
{

    int tc =0 , tc_i = 0;
    cin >> tc;
    for (tc_i = 1; tc_i <= tc ; ++tc_i)
    {
        string a;
        string b;
        int n ;
        cin >> n >>  a >> b;
        
        int i = 0 , j = 0;

        int c = 0;
        for (i = 0 ; i < a.length();)
        {
            char last_char = a[i];
            bool new_char = true;
            cout << b[j] << " " << a[i] << endl;
            int c_i = 0;
            int c_j = 0;
            while (b[j] == a[i])
            {
                new_char = false;
                c_j++;
                j++;
            }
            while (last_char == a[i])
            {
                i++;
                c_i++;
            }
            if (new_char == false)
            {
                c += abs(c_i-c_j);
            }
            else
            {
                c = -1;
            }
            
        }
        
        if (c < 0)
        {
            cout << "Case #" << tc_i << ": Fegla Won" <<  endl;
        }
        else
        {
            cout << "Case #" << tc_i << ": " << c <<  endl;
        }
        
    }
    return 0;
}

