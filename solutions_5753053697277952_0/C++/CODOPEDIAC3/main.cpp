#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for(int t = 1;t <= tc;++t){
        int N;
        cin >> N;
        vector<pair<int, int> > heap;
        int sum = 0;
        for(int i = 0;i < N;++i){
            int x;
            cin >> x;
            heap.push_back(make_pair(x, i));
            push_heap(heap.begin(), heap.end());
            sum += x;
        }
        string ans = "";
        while(!heap.empty()){
            if(ans != "")
                ans += " ";
            int a1 = heap[0].second;
            int cnt1 = heap[0].first;

            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
            if(cnt1 > 1){
                heap.push_back(make_pair(cnt1 - 1, a1));
                push_heap(heap.begin(), heap.end());
            }
            ans += a1 + 'A';
            --sum;
            if(heap[0].first > sum/2){
                int a1 = heap[0].second;
                int cnt1 = heap[0].first;

                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
                if(cnt1 > 1){
                    heap.push_back(make_pair(cnt1 - 1, a1));
                    push_heap(heap.begin(), heap.end());
                }
                ans += a1 + 'A';
                --sum;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
