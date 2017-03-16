#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct seq {
  char letter;
  int count;

  seq(char letter, int count):letter(letter),count(count){}
};

int abs(int a) {
  if(a>0) {
    return a;
  } else {
    return -a;
  }
}

vector<seq> parse(string s) {
  vector<seq> res;
  char last = ' ';
  int count = 0;
  for(int i=0;i<s.size();++i) {
    char c = s[i];
    if(c==last) {
      count++;
    } else {
      if(last!=' ') {
        res.push_back(seq(last, count));
      }
      last = c;
      count = 1;
    }
  }
  res.push_back(seq(last, count));
  return res;
}

int solve() {
  int n;
  cin>>n;
  vector<vector<seq> > data;

  for(int i=0;i<n;++i) {
    string s;
    cin>>s;
    vector<seq> line = parse(s);
    data.push_back(line);
  }

  // Sanity check
  for(int i=0;i<n;++i) {
    if(data[i].size() != data[0].size()) {
      //cerr<<"Wrong number of letters"<<endl;
      return -1;
    }
  }
  int cost = 0;
  for(int i=0;i<data[0].size();++i) {
    int mincount = 101;
    int maxcount = 1;
    for(int j=0;j<n;++j) {
      if(data[j][i].letter != data[0][i].letter) {
        //cerr<<"Wrong sequence of letters"<<endl;
        return -1;
      }
      mincount = min(mincount, data[j][i].count);
      maxcount = max(maxcount, data[j][i].count);
    }
    int mincost = 101*101;
    for(int k=mincount;k<=maxcount;++k) {
      int thecost = 0;
      for(int j=0;j<n;++j) {
        int w = abs(k-data[j][i].count);
        thecost += w;
      }
      mincost = min(mincost, thecost);
    }
    cost += mincost;
  }


  return cost;
}

int main(int argc, char** argv) {
  int ntc = 0;
  cin>>ntc;

  for(int n=1;n<=ntc;++n) {
    int r = solve();
    cout<<"Case #"<<n<<": ";
    if(r==-1) {
      cout<<"Fegla Won";
    } else {
      cout<<r;
    }
    cout<<endl;
  }
}
