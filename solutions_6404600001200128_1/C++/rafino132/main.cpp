//
//  main.cpp
//  GCJ quaternions
//
//  Created by Rafał Stempowski on 11.04.2015.
//  Copyright (c) 2015 Rafał Stempowski. All rights reserved.
//

#include <iostream>











int main(int argc, const char * argv[])
{
    FILE *pFile;
    pFile= fopen("/Users/rafal/Downloads/A-large.in","r");
    
    int t,x,tmp;
    int*tab;
    fscanf(pFile,"%d\n",&t);
    
    
    for(int h=0;h<t;h++)
    {
        int temp=0;
        long long count=0;
        long long _count=0;
        int rate=0;
        fscanf(pFile,"%d\n",&x);
        tab=new int[x];
        
        for(int g=0;g<x;g++)
        {
            fscanf(pFile,"%d",&tmp);
            tab[g]=tmp;
            if((temp-tmp)>0)
            {
                count+=(temp-tmp);
                if((temp-tmp)>rate)
                    rate=temp-tmp;
            }
            temp=tmp;
        }
        
        for(int g=0;g<x-1;g++)
        {
            if(tab[g]<rate)
                _count+=tab[g];
            else
                _count+=rate;
        }
       
        
        printf("\nCase #%d: %d %d",h+1,count,_count);
        
        
        
        
    }
    
    
    
    
    return 0;
}
