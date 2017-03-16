//
//  main.cpp
//  GCJ quaternions
//
//  Created by Rafał Stempowski on 11.04.2015.
//  Copyright (c) 2015 Rafał Stempowski. All rights reserved.
//

#include <iostream>
#define MAX 2000000000
struct bar{
    int podst;
    int por;
    int nr;
    bar()
    {
        podst=0;
        por=0;
        nr=0;
        
    }
    bar(int b,int c,int d)
    {
        podst=b;
        por=c;
        nr=d;
    }
};



class kopiec
{
    bar*lista;
    int ptr;
    int elem;
public:
    kopiec(int n)
    {
        lista=new bar[n];
        ptr=0;
        elem=n;
    }
    int pokaz()
    {
        return lista[0].por;
    }
    int pokanr()
    {
        return lista[0].nr;
    }
    int pokapodst()
    {
        return lista[0].podst;
    }
    void dodaj(int b,int c,int nr)
    {
        lista[ptr]=bar(b,c,nr);
        ptr++;
        przelicz(ptr-1);
    }
    void Swap(int a,int b)
    {
        bar tmp=lista[a];
        lista[a]=lista[b];
        lista[b]=tmp;
    }
    void przelicz(int n)
    {
        
            
            int i=n;
            while(i!=0)
            {
                if(lista[i].por<lista[(i-1)/2].por)
                {
                    Swap(i,(i-1)/2);
                    i=(i-1)/2;
                }
                else
                    break;
            }
            
        
    }
    int ChackHead()
    {
        int s=0;
        int k;
        
        while(1)
        {
            if((2*s+2)>=ptr)
            {
                if((2*s+1)>=ptr)
                    return s;
                else if(lista[s].por>lista[2*s+1].por)
                {
                    Swap(s,2*s+1);
                    s=2*s+1;
                    continue;
                }
                else
                    return s;
                
            }
            
            bar ja,lewy_syn,prawy_syn;
            ja=lista[s];
            lewy_syn=lista[2*s+1];
            prawy_syn=lista[2*s+2];
            
            
            
            if(ja.por>lewy_syn.por)
            {
                if(ja.por>prawy_syn.por)
                {
                    
                    if(lewy_syn.por==prawy_syn.por)
                    {
                        if(lewy_syn.podst==prawy_syn.podst)
                        {
                            k=(lewy_syn.nr<prawy_syn.nr ? 2*s+1 : 2*s+2);
                            Swap(s,k);
                            s=k;
                            continue;
                        }
                        k=(lewy_syn.podst>prawy_syn.podst ? 2*s+1 : 2*s+2);
                        Swap(s,k);
                        s=k;
                        continue;
                    }
                    else if(lewy_syn.por<prawy_syn.por)
                    {
                        Swap(s,2*s+1);
                        s=2*s+1;
                        continue;
                    }
                    else
                    {
                        Swap(s,2*s+2);
                        s=2*s+2;
                        continue;
                    }
                }
                Swap(s,2*s+1);
                s=2*s+1;
                continue;
            }
            else if(ja.por>prawy_syn.por)
            {
                Swap(s,2*s+2);
                s=2*s+2;
                continue;
            }
            else
                return s;
            
            
        }
        
        
        return s;
        
    }
    void Usunhead()
    {
        //Swap(0,ptr-1);
        lista[0]=bar(MAX,MAX,MAX);
        int s=ChackHead();
        Swap(s,ptr-1);
        ptr--;
        
    }

};


long long NWW(long a, long b)
{
    long long ab,t;
    ab = a * b;
    while(b)
    {
        t = b;
        b = a % b;
        a = t;
    }
    ab /= a;
    return ab;
}



int main(int argc, const char * argv[])
{
    FILE *pFile;
    pFile= fopen("/Users/rafal/Downloads/A-large.in","r");
    
    int t,x,tmp,podst,num;
    long long l;
    kopiec*heh;
    fscanf(pFile,"%d",&t);
    
    
    for(int h=0;h<t;h++)
    {
        
        fscanf(pFile,"%d %d",&x,&l);
        
        if(l<=x)
        {
            printf("\nCase #%d: %lld",h+1,l);
            for(int g=0;g<x;g++)
            {
                fscanf(pFile,"%d",&tmp);
            }
            continue;
        }
        long bylo_l=l;
        l-=x;
        long bylo=l;
        heh=new kopiec(x);
        long nww=1;
        
        for(int g=0;g<x;g++)
        {
            fscanf(pFile,"%d",&tmp);
            heh->dodaj(tmp, tmp,g+1);
            nww=NWW(nww,tmp);
        }
        
        int czas=0;
        
        while(l!=0)
        {

            
            while(heh->pokaz() == czas)
            {
                if(l==1)
                {
                    printf("\nCase #%d: %d",h+1,heh->pokanr());
                    l--;
                    break;
                }
                else
                {
                    l--;
                    podst=heh->pokapodst();
                    num=heh->pokanr();
                    heh->Usunhead();
                    heh->dodaj(podst, (podst+czas), num);
                }
            }
            
            
            if(czas==nww && l!=0)
            {
                long j=bylo-l;
                if(j==0)
                {
                    printf("\nCase #%d: %d",h+1,num);
                    break;
                }
                
                
                l=l%j;
                
                if(l==0)
                {
                    printf("\nCase #%d: %d",h+1,num);
                    break;
                }
                
                
            }
            
            czas++;
            
        }
       
        
        
        
        
        
    }
    
    
    
    
    return 0;
}
