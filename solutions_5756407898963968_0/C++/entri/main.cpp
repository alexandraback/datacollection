#include <iostream>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >>T;
    //cout <<"There are "<<T<<" test cases\n";
    for(int i = 1; i<=T; i++){
        //cout <<"    Test case "<<i<<" :\n";
        int a1;
        cin >>a1;
        int Board1[4][4];
        for(int u = 0; u<4; u++){
            for (int v = 0; v<4; v++) cin >> Board1[u][v];
        };

        set<int> s1;
        for(int v =0; v<4; v++) s1.insert(Board1[a1-1][v]);

        int a2;
        cin >>a2;
        int Board2[4][4];
        for(int u = 0; u<4; u++){
            for (int v = 0; v<4; v++) cin >> Board2[u][v];
        };

        set<int> s2;
        for(int v =0; v<4; v++) s2.insert(Board2[a2-1][v]);

        //check:
        int ans;
        int ansCnt = 0;
        for(set<int>::iterator it = s1.begin(); it != s1.end(); ++it){
            if (s2.count(*it)){
                ans = *it;
                ansCnt++;
            };
        };

        //output:
        cout <<"Case #"<<i<<": ";

        if (ansCnt == 0){
            cout <<"Volunteer cheated!";
        }
        else{
            if (ansCnt > 1){
                cout <<"Bad magician!";
            }
            else cout <<ans;
        };
        cout <<endl;


/*
        cout <<" First answer: "<<a1<<endl;
        cout <<" First board:\n";
        for(int u = 0; u<4; u++){
            for(int v = 0; v<4; v++) cout <<Board1[u][v]<<" ";
            cout <<endl;
        };

        cout <<" Second answer: "<<a2<<endl;
        cout <<" Second board:\n";
        for(int u = 0; u<4; u++){
            for(int v = 0; v<4; v++) cout <<Board2[u][v]<<" ";
            cout <<endl;
        };
*/

    }// each test case
    return 0;
}
