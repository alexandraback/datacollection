
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

int main(int argc, const char * argv[])
{

    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        int r;
        cin >> r;
        r--;
        
        int a[4][4];
        for(int i=0;i<4;i++) for(int j=0;j<4;j++){
            cin >> a[i][j];
        }
        int r2;
        cin >> r2;
        r2--;
        int b[4][4];
        for(int i=0;i<4;i++) for(int j=0;j<4;j++)
            cin >> b[i][j];
        int cnt = 0;
        int z =-1;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)for(int m=0;m<4;m++)
                if(a[i][j] == b[k][m] && i == r && k==r2){
                    z = a[i][j];
                    cnt++;
                }
        if(cnt==0){
            cout << "Case #" << t+1 << ": " << "Volunteer cheated!" << endl;
            
        }
        else if(cnt ==1){
            cout << "Case #" << t+1 << ": "<< z << endl;
        }
        else cout << "Case #" << t+1 << ": Bad magician!"<< endl;
        
    }
    
       return 0;
}

