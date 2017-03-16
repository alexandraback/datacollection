#include <bits/stdc++.h>

int sz[27];

void test(int k){
    for(int i=0; i<27; ++i) sz[i] = 0;
    
    int N; 
    std::cin >> N;
    for(int i=0; i<N; ++i){
        std:: cin >> sz[i];
    }
    
    std::vector<std::string> ans;
    while(true){
        int pcnt = 0;
        std::vector<std::pair<int, int> > vc;
        
        for(int i=0; i<N; ++i){
            vc.push_back(std::make_pair(sz[i], i));
            assert(sz[i] >= 0);
            if(sz[i]) ++pcnt;
        }
        std::sort(vc.begin(), vc.end(), std::greater<std::pair<int, int> >());
        if(pcnt == 0) break;
                
        std::string s = "";
        if(pcnt == 2){       
            s += static_cast<char>('A'+vc[0].second);
            s += static_cast<char>('A'+vc[1].second);
            
            sz[vc[0].second]--;
            sz[vc[1].second]--;
            
            assert(sz[vc[0].second] >= 0);
            assert(sz[vc[1].second] >= 0);
            
            ans.push_back(s);
        }else{
            s += static_cast<char>('A'+vc[0].second);

            sz[vc[0].second]--;
            
            assert(sz[vc[0].second] >= 0);
            
            ans.push_back(s);
        }
    }
    
    if(ans.size() == 0){
        std::cout << "Case #" << k << std::endl;
    }else{
        std::cout << "Case #" << k << ": " << ans[0];
        for(size_t i=1; i<ans.size(); ++i){
            std::cout << " " << ans[i];
        }
        std::cout << std::endl;
    }
}

int main(){
    int T;
    std::cin >> T;
    for(int i=1; i<=T; ++i){
        test(i);
    }
}
