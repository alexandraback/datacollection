#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int T, N, total;

int main(void)
{
     freopen("A-small-attempt0.in","r",stdin);
     freopen("A-small-attempt0.out","w",stdout);
     
     cin >> T;
     for (int cases = 1; cases <= T; cases++) {
         cin >> N;
         
         priority_queue<pair<int, char> > pq;
         total = 0;
         
         for (int i = 0; i < N; i++) {
             int temp;
             cin >> temp;
             
             pq.push(make_pair(temp, (char) (i + 'A')));
             total += temp;
         }
         
         cout << "Case #" << cases << ":";
         
         while (!pq.empty()) {
             pair<int, char> first = pq.top(); pq.pop();
             
             if (pq.empty()) {
                cout << " ";             
                for (int i = 0; i < first.first; i++)
                    cout << first.second;                    
             } else {
                pair<int, char> second = pq.top(); pq.pop();    
                
                if (max(first.first - 1, second.first) * 2 <= total - 1) {
                   //bisa ambil 1
                   cout << " " << first.second;
                   total--;
                   
                   if (first.first > 1) 
                      pq.push(make_pair(first.first - 1, first.second));
                   pq.push(second);              
                } else
                if (first.first >= 2 && max(first.first - 2, second.first) * 2 <= total - 2) {
                   //bisa ambil 2 yang sama
                   cout << " " << first.second << first.second;
                   total -= 2;
                   
                   if (first.first > 2)
                      pq.push(make_pair(first.first - 2, first.second));
                   pq.push(second);
                } else {
                   //bisa ambil 2 beda
                   cout << " " << first.second << second.second;
                   total -= 2;
                   
                   if (first.first > 1)
                      pq.push(make_pair(first.first - 1, first.second));
                   if (second.first > 1)
                      pq.push(make_pair(second.first - 1, second.second));       
                }
             }             
         }
         
         cout << endl;
     }
     


}
