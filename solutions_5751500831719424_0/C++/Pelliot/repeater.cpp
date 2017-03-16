#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

int abs(int a, int b) {

  if (a<b)
    return b-a;
  return a-b;
}

int main() {
  int n_testcase;
  int i,j,t;
  int n_string;
  vector <string> str;
  vector <int> pointer;
  vector <int> nb_lettres;
  int tot;
  int temp_sum;
  char lettre;
  int flag=0;
  cin >> n_testcase;
  for(t=0;t<n_testcase;t++) {
    flag=0;
    tot=0;
    cin >> n_string;
    str.resize(n_string);
    nb_lettres.resize(n_string);
    pointer.resize(n_string);
    for(i=0;i<n_string;i++) {
      cin >> str[i];
      pointer[i]=0;
      nb_lettres[i]=0;
    }
    while(pointer[0]<str[0].size()) {
      lettre=str[0][pointer[0]];
      //	for(j=0;j<n_string;j++)
      //	  nb_lettres[j]=0;
      for(i=0;i<n_string;i++) {
	nb_lettres[i]=0;
	while(pointer[i]<str[i].length() && str[i][pointer[i]]==lettre) {
	  pointer[i]++;
	  nb_lettres[i]++;
	}
      }
      for(i=0;i<n_string;i++)
	if(nb_lettres[i]==0)
	  flag=1;
      if(flag==1) 
	break;
	//	
      else {
	//	temp_sum=0;
	//	for(i=0;i<n_string;i++) {
	//	  temp_sum+=nb_lettre[i];
	//	}
	sort(nb_lettres.begin(),nb_lettres.end());
	temp_sum=0;
	for(i=0;i<n_string;i++) {
	  tot+=abs(nb_lettres[nb_lettres.size()/2],nb_lettres[i]);
	}
      }
    }
    for(i=0;i<n_string;i++) 
      if(pointer[i]<str[i].size()) 
	flag=1;
    if(flag==1) 
      cout << "Case #" << t+1 << ": Fegla Won" << endl;
    else
      cout << "Case #" << t+1 << ": " << tot << endl;
  }
  return 0;
}
