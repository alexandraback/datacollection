#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;

#define x first
#define y second

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;

        priority_queue<PII> pq;
        for(int i=0;i<N;i++){
            int P;
            cin >> P;
            pq.push(PII(P, i));
        }

        cout << "Case #" << t << ":";

        while(!pq.empty()){
            cout << " ";

            PII p1 = pq.top();
            pq.pop();

            if(p1.first == 1){
                if(pq.size() == 0){
                    cout << (char)(p1.second + 'A');
                    p1.first--;
                    if(p1.first > 0) pq.push(p1);
                    continue;
                } else if(pq.size() == 1){

                } else if(pq.size() >= 2){
                    cout << (char)(p1.second + 'A');
                    p1.first--;
                    if(p1.first > 0) pq.push(p1);
                    continue;
                }
            }

            cout << (char)(p1.second + 'A');

            if(!pq.empty()){
                PII p2 = pq.top();
                pq.pop();
                if(p2.first == p1.first){
                    cout << (char)(p2.second + 'A');
                    p2.first--;
                }
                if(p2.first > 0){
                    pq.push(p2);
                }
            }

            p1.first--;
            if(p1.first > 0){
                pq.push(p1);
            }
        }
        cout << endl;


    }
}





