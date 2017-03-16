# Encoding: utf-8
'''
Created on 12.04.2014

@author: Los

@version: 0.0.1
'''
import sys

def main(argv=None):
    if argv is None:
        argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')
    
    T = int(input())
     
    for i in range(T):
        aa=int(input())
        la=[0]*16
        la[0],la[1],la[2],la[3] = map(int, tuple(input().split()))
        la[4],la[5],la[6],la[7] = map(int, tuple(input().split()))
        la[8],la[9],la[10],la[11] = map(int, tuple(input().split()))
        la[12],la[13],la[14],la[15] = map(int, tuple(input().split()))
        
        sa=set(la[(aa-1)*4:aa*4])

        ab=int(input())
        lb=[0]*16
        lb[0],lb[1],lb[2],lb[3] = map(int, tuple(input().split()))
        lb[4],lb[5],lb[6],lb[7] = map(int, tuple(input().split()))
        lb[8],lb[9],lb[10],lb[11] = map(int, tuple(input().split()))
        lb[12],lb[13],lb[14],lb[15] = map(int, tuple(input().split()))
        
        sb=set(lb[(ab-1)*4:ab*4])
        
        #print(sa, sb)
        
        sr = sa.intersection(sb)
        
        if len(sr)==0:
            case='Case #{0}: {1}'.format(i+1,'Volunteer cheated!')
        elif len(sr)==1 :
            case='Case #{0}: {1}'.format(i+1,list(sr)[0])
        elif len(sr)>1:
            case='Case #{0}: {1}'.format(i+1,'Bad magician!')
        
        print(case)
            

if __name__ == '__main__':
    main()
