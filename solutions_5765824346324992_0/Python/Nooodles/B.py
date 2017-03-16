### Google code jam 2015
### Round 1A
### Problem A: Barbers

def Customers(T, times):
    ret = 0;
    for barberTime in times:
        ret += (T-1)/barberTime + 1;
    return ret;


def Solve(Nvalue, times):
    tLow = 0;
    tHigh = min(times) * N;

    while (tHigh - tLow >= 2):
#        print (tLow, tHigh)
        tMid = (tHigh + tLow)/2;
        Eval = Customers(tMid, times);
        if (Eval <= N-1):
            tLow = tMid;
        else:
            tHigh = tMid;

    BarberNumber = 0;
    # 
    if Customers(tLow, times) <= N:      # I sit down at tLow;
        T0 = tLow;
        BarberNumber = N - Customers(tLow, times);
    else:
        T0 = tHigh;
        BarberNumber = N - Customers(tLow, times);

#    print [T0, BarberNumber]
                 
    barberFree = 0;
    for i in range(len(times)):
        if (T0)%times[i] == 0:
            barberFree += 1;
            if barberFree == BarberNumber:
                print i+1;
                break;
    
Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    [B, N] = map(int, raw_input().split());
    Mval = map(int, raw_input().split());

    if (N <= B):
        print N;
    else:
        Solve(N, Mval);

