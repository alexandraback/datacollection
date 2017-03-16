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



def ProblemB(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
    Output = open('/CodeJam/' + 'R1BOut.txt','w');
    Start = 0;
    End = Data.find('\n');
    T = int(Data[Start:End]);
    Start = End + 1;
    t = 0;
    while (t < T):
        End = Data.find(' ',Start);
        B = int(Data[Start:End]);
        Start = End + 1;
        End = Data.find('\n',Start);
        N = int(Data[Start:End]);
        Start = End + 1;
        b = 0;
        Barbers = [];
        while (b < (B-1)):
            End = Data.find(' ',Start);
            Barbers.append(int(Data[Start:End]));
            b = b + 1;
            Start = End + 1;
        End = Data.find('\n',Start);
        Barbers.append(int(Data[Start:End]));
        b = b + 1;
        Start = End + 1;

        Product = 1;
        b = 0;
        while (b < B):
            Product = Product*Barbers[b];
            b = b + 1;
        b = 0;
        Modulus = 0;
        while (b < B):
            Modulus = Modulus + Product/Barbers[b];
            b = b + 1;
        N = int(N%Modulus);
        #print(N);

        Flip = Barbers.copy();
        Flip.reverse();
        Fastest = min(Flip);
        Last = B - Flip.index(Fastest) - 1;
        TimeLeft = [0]*B;
        while (N > 0):
            MinTime = min(TimeLeft);
            if (MinTime == 0):
                Last = TimeLeft.index(0);
                TimeLeft[Last] = Barbers[Last];
                N = N - 1;
            else:
                b = 0;
                while (b < B):
                    TimeLeft[b] = TimeLeft[b] - MinTime;
                    b = b + 1;
        
        MyBarber = Last + 1;
        # Report the output
        ThisCase = 'Case #' + str(t+1) + ': ' + str(MyBarber);
        print(ThisCase);
        Output.write(ThisCase + '\n');

        # Advance to the next case 
        t = t + 1;

    Output.close();
        