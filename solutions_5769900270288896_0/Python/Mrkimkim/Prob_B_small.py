def Remove(K):
       global Map, Cnt, N, M
       Sum = 0
       for i in xrange(N):
              for j in xrange(M):
                     R = 0
                     if Cnt == Empty: return Sum
                     elif Map[i][j] == False:
                            if i > 0 and Map[i-1][j] == False: R += 1
                            if j > 0 and Map[i][j-1] == False: R += 1
                            if i < N-1 and Map[i+1][j] == False: R += 1
                            if j < M-1 and Map[i][j+1] == False: R += 1

                            if R == K:
                                   Map[i][j] = True
                                   Sum += K
                                   Cnt += 1
       return Sum

def Remove_2(K):
       global N, M, Cnt
       Sum = 0
       for j in xrange(M):
              R = 0
              if Cnt == Empty: return Sum
              elif Map[0][j] == False:
                     if j > 0 and Map[0][j-1] == False: R += 1
                     if N > 1 and Map[1][j] == False: R += 1
                     if j < M-1 and Map[0][j+1] == False: R += 1

                     if R == K:
                            Map[0][j] = True
                            Sum += K
                            Cnt += 1
       return Sum

File = open("B-small-attempt3.in","r")
Out = open("output.txt","w")
T = int(File.readline().replace("\n",''))

for z in xrange(T):
       N, M, K = File.readline().replace("\n",'').split(' ')
       N, M, K = int(N), int(M), int(K)
       Empty = N*M - K
       Cnt = 0
       Total_Line = (N-1) * M + N * (M-1)
       Map = []
       Temp = Total_Line
       
       for i in xrange(N):
              Map.append([])
              for j in xrange(M): Map[i].append(False)      
       for i in range(0, 5): Temp -= Remove(4-i)

       Cnt = 0
       for i in xrange(N):
              for j in xrange(M): Map[i][j] = False

       Total_Line -= Remove_2(3)
       for i in range(0, 5): Total_Line -= Remove(4-i)
       Out.write("Case #" + str(z+1) + ": " + str(min(Temp, Total_Line)) + "\n")
File.close()
Out.close()
