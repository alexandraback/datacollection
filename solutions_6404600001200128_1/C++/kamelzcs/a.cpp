/*
 * a.cpp
 * Copyright (C) 2015 zhao <zhao@kamel-ThinkPad-X201>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int plate[10010];

int main() {

    //Create an input file stream
    //fstream in("A-small.in",ios::in);
    //fstream out("A-small.out", ios::out);
    fstream in("A-large.in",ios::in);
    fstream out("A-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        int n, ans1 = 0, ans2 = 0, rate = 0;
        in>>n;
        for(int pos = 0; pos < n; ++pos){
            in>>plate[pos];
        }
        for(int pos = 1; pos < n; ++pos){
            if(plate[pos] < plate[pos - 1]){
                ans1 += plate[pos - 1] - plate[pos];
                rate = max(rate, plate[pos - 1] - plate[pos]);
            }
        }
        for(int pos = 0; pos < n - 1; ++pos){
            ans2 += min(rate, plate[pos]);
        }
        string temp = "Case #";
        out << temp.c_str()<<index<<": "<<ans1<<" "<<ans2<<endl;
    }
	//Close the file stream
	in.close();
        out.close();
	return 0;
}


