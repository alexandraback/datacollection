/*
 * b.cpp
 * Copyright (C) 2015 zhao <zhao@kamel-ThinkPad-X201>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef long long LL;

LL M[1010];


int main() {

    //Create an input file stream
    fstream in("B-small.in",ios::in);
    fstream out("B-small.out", ios::out);
    //fstream in("B-large.in",ios::in);
    //fstream out("B-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        LL B, N, max_M = 0, ans;
        in>>B>>N;
        for(int pos = 0; pos < B; ++pos){
            in>>M[pos];
            max_M = max(max_M, M[pos]);
        }
        LL left = 0, right = N * max_M;
        while(left <= right){
            LL middle = left + ((right - left) >> 1LL);
            LL sum = 0;
            for(int pos = 0; pos < B; ++pos){
                sum += (middle + M[pos] - 1) / M[pos];
            }
            if(sum >= N){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        cout << right <<endl;
        LL finished = 0;
        for(int pos = 0; pos < B; ++pos){
            finished += (right + M[pos] - 1) / M[pos];
        }
        N -= finished;
        cout<<N<<endl;
        for(int pos = 0; ;++pos){
            if(!(right % M[pos])){
                if(N == 1){
                    ans = pos + 1;
                    break;
                }
                N--;
            }
        }
        string temp = "Case #";
        out << temp.c_str()<<index<<": "<<ans<<endl;
    }

	//Close the file stream
	in.close();
        out.close();
	return 0;
}


