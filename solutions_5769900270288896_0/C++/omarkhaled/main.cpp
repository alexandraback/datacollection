#include <bits/stdc++.h>

using namespace std;

bool arr[16 + 10][16 + 10];

int n, m, d;
int ans;
int b;

void dfs(int num, int i , int j, int g){

    if(i > n && j == 1 && d == g){
        if(ans > num){
            ans = num;
             b = ans;
        }


        return;
    }
    if(i > n || j > m) return;

    if(arr[i][j] == false){

        if(i >= 1 && i <= n && j >= 1 && j < m){
            arr[i][j] = true;
            int pu = 0;
            if(arr[i - 1][j] == true) pu++;
            if(arr[i][j - 1] == true) pu++;
            dfs(num + pu, i , j + 1, g + 1);

        } else if (i >= 1 && i <= n && j == m){
            arr[i][j] = true;
            int pu = 0;
            if(arr[i - 1][j] == true) pu++;
            if(arr[i][j - 1] == true) pu++;

            dfs(num + pu, i + 1, 1, g + 1);
        }

        if(i >= 1 && i <= n && j >= 1 && j < m){

            arr[i][j] = false;
            dfs(num , i , j + 1, g);

        }   else if (i >= 1 && i <= n && j == m){
            arr[i][j] = false;
            dfs(num , i  + 1, 1, g);
        }


    }
}


int main()
{

    freopen ("file_name.X","w",stdout);
    int k , t,sum = 0, tem1 , tem2;
    string s , c;

    cin >> t ;
    int i = 1;



    while(i <= t){


      for(int f = 0; f < 25; f++){
        for(int h = 0; h < 25; h++){
            arr[f][h] = false;
        }
      }


      cin >> n >> m >> d;

     ans = 1000000000;
      dfs(0, 1, 1, 0);
         cout << "Case #" << i <<": " << b << endl;
         b = 0;

        i++;
    }

    return 0;
}
