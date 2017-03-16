//
//  main.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Solution.h"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream openFile;
    openFile.open("/Users/liuyujie/Downloads/B-small-attempt1 (1).in");
    
    if(openFile.good())
    {
        cout << "fileopened" << endl;
        int cases;
        string s="";
        openFile >> cases;

        for (int i = 0; i < cases; ++i) {
            doCase(openFile,i + 1,s);
        }
        ofstream writeFile("/Users/liuyujie/Downloads/out.out");
        writeFile << s;
        writeFile.close();
        //cout << s;
    }
    return 0;
}
