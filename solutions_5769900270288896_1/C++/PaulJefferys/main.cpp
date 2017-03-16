#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");

int grid[36][36];

int solve(int r, int c, int n)
{
    memset(grid,0,sizeof(grid));
    int m = r*c;
    int i,j,k;
    
    int ans = 100*r*c;
    
    for(k=0; k<(1<<m); k++)
    {
        //cout << k << " " << ans << endl;
        int l = k;
        
        int x = 0;
        
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                grid[i][j] = l%2;
                x+=l%2;
                l/=2;
            }
        }
        
        if(x!=n)
            continue;
        x=0;
        
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                if(grid[i][j]==1)
                {
                    x+=grid[i+1][j]+grid[i][j+1];
                }
            }
        }
        
        //cout << x << " " << ans << " " << k << endl;
        
        if(x<ans)
            ans=x;
        
    }
    return ans;
    
    
}

int solve2(int r, int n)
{
    if(r==1)
        return 0;
    int vals[3];
    int i,j,k,p,q;
    int ans = 4*r;
    
    vals[0]=vals[1]=vals[2]=0;
    
    for(i=0; i<r; i++)
    {
        if(i%2==0)
            vals[0]++;
        else if(i==r-1)
            vals[1]++;
        else
            vals[2]++;
    }
    
    p=q=0;
    p=n;
    
    for(i=0; i<3; i++)
    {
        if(vals[i]<=p)
        {
            p-=vals[i];
            q+=vals[i]*i;
        }
        else{
            q+=p*i;
            p=0;
        }
    }
    
    if(q < ans)
        ans=q;
    
    vals[0]=vals[1]=vals[2]=0;
    
    for(i=0; i<r; i++)
    {
        if(i%2==1)
            vals[0]++;
        else if(i==0 || i==r-1)
            vals[1]++;
        else
            vals[2]++;
    }
    
    p=q=0;
    p=n;
    
    for(i=0; i<3; i++)
    {
        if(vals[i]<=p)
        {
            p-=vals[i];
            q+=vals[i]*i;
        }
        else{
            q+=p*i;
            p=0;
        }
    }
    
    if(q < ans)
        ans=q;
    return ans;
}

int solve1(int r, int c, int n)
{
    if(r==1)
        return solve2(c,n);
    else if(c==1)
        return solve2(r,n);
    int ans = n*100;
    
    int vals[5];
    vals[0]=vals[1]=vals[2]=vals[3]=vals[4]=0;
    
    int i,j,k;
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if((i+j)%2==0)
                vals[0]++;
            else
            {
                k = 0;
                if(i==0 || i==r-1)
                    k++;
                if(j==0 || j==c-1)
                    k++;
                vals[4-k]++;
            }
        }
    }
    int p,q;
    p=q=0;
    p=n;
    
    for(i=0; i<5; i++)
    {
        if(vals[i]<=p)
        {
            p-=vals[i];
            q+=vals[i]*i;
        }
        else{
            q+=p*i;
            p=0;
        }
    }
    
    if(q < ans)
        ans=q;
    
    vals[0]=vals[1]=vals[2]=vals[3]=vals[4]=0;
    
    
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if((i+j)%2==1)
                vals[0]++;
            else
            {
                k = 0;
                if(i==0 || i==r-1)
                    k++;
                if(j==0 || j==c-1)
                    k++;
                vals[4-k]++;
            }
        }
    }
   
    p=q=0;
    p=n;
    
    for(i=0; i<5; i++)
    {
        if(vals[i]<=p)
        {
            p-=vals[i];
            q+=vals[i]*i;
        }
        else{
            q+=p*i;
            p=0;
        }
    }
    
    if(q < ans)
        ans=q;
    
    return ans;
}


int main(void)
{
    int ttt;
    fin >> ttt;
    int ct = 0;
    string s;
    
    cout.precision(9);
    fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
    
    while(ttt>0)
    {
        ct++;
        ttt--;
        
        int r,c,n;
        
        int i,j,k;
        
        fin >> r >> c >> n;
        // cout << endl;
        
        
        int ans = solve1(r,c,n);
        
//        if(ans!=ans1)
//        {
//            cout << ans << " " << ans1 << " " << r << " " << c << " " << n << " ERROR " << endl;
//        }
        
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        
        
        cout << ans;
        fout << ans;
        
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

