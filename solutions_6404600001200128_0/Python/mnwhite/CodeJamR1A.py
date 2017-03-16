def ProblemA(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
    Output = open('/CodeJam/' + 'R1AOut.txt','w');
    Start = 0;
    End = Data.find('\n');
    T = int(Data[Start:End]);
    Start = End + 1;
    t = 0;
    while (t < T):
        End = Data.find('\n',Start);
        N = int(Data[Start:End]);
        Start = End + 1;
        n = 0;
        MushList = [];
        while (n < (N-1)):
            End = Data.find(' ',Start);
            MushList.append(int(Data[Start:End]));
            #print(MushList);
            Start = End + 1;
            n = n + 1;
        End = Data.find('\n',Start);
        MushList.append(int(Data[Start:End]));
        Start = End + 1;
        MethodA = 0;
        OnPlate = MushList[0];
        n = 1;
        while (n < N):
            Next = MushList[n];
            MethodA = MethodA + max(OnPlate - Next,0);
            OnPlate = Next;
            n = n + 1;
        MaxRate = 0;
        n = 1;
        OnPlate = MushList[0];
        while (n < N):
            Next = MushList[n];
            Eaten = max(OnPlate - Next,0);
            #print(Eaten);
            MaxRate = max(MaxRate,Eaten);
            OnPlate = Next;
            n = n + 1;
        #print(MaxRate);
        n = 1;
        OnPlate = MushList[0];
        MethodB = 0;
        while (n < N):
            Next = MushList[n];
            Eaten = min(MaxRate,OnPlate);
            MethodB = MethodB + Eaten;
            OnPlate = Next;
            n = n + 1;
        
        # Report the output
        ThisCase = 'Case #' + str(t+1) + ': ' + str(MethodA) + ' ' + str(MethodB);
        print(ThisCase);
        Output.write(ThisCase + '\n');

        # Advance to the next case 
        t = t + 1;

    Output.close();