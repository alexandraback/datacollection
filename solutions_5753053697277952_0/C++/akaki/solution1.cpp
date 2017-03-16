#include <bits/stdc++.h>

using namespace std;

int i,j,k,l,m,n,t;
int s[26];

int main(){
    freopen("output1.txt", "w", stdout);
    cin >> t;
    for (int test = 0; test < t; test++){
        cout << "Case #"<< test+1 << ": ";
        cin >> n;
        for (i = 0; i < n; i++){
            cin >> s[i];
        }    
        while (1){
            int max1 = -1, max2 = -1;
            int index1 = -1, index2 = -1;
            int sum = 0;       
            for (i = 0; i < n; i++){
                sum += s[i];            
                if (max1 < s[i]){
                    max1 = s[i];
                    index1 = i;
                }
            }       
            if (max1 == 0){
                cout << "\n";
                break;
            }                    
            s[index1]--;
            for (i = 0; i < n; i++){
                if (max2 < s[i]){
                    max2 = s[i];
                    index2 = i;
                }
            } 
            //cout << max1 << " " << index1 <<" " << max2 <<" " << index2 << "    " << sum << "\n";
            if (max2 == 0){
                cout << char('A' + index1) << " ";
                cout << "\n";                
                break;
            }                           
            if (max1 == 1 && sum == 3){
                cout << char('A' + index1) << " ";
                continue;                
            } 
            s[index2]--;                                                   
            cout << char('A' + index1) << char('A' + index2) << " ";
        }    
    }
    return 0;
}
