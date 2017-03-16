import string
from operator import itemgetter



def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "FAIL"
    outputLine = casestr+status
    print outputLine


def main():
    T = int( raw_input() )

    alph = string.ascii_uppercase

    for t in xrange(T):    
        N = int(raw_input())
        P = map(int, raw_input().split())

        S = [[alph[i], P[i]] for i in xrange(N)]
        S.sort(key = itemgetter(1), reverse = True)
        evac = []
        while S[0][1] > 0:
            diff = S[0][1] - S[1][1]
            if diff >= 2:
                pairs = diff / 2
                for i in xrange(pairs):
                    evac.append(S[0][0]*2)
                    S[0][1] -= 2
            elif diff == 1:
                 evac.append(S[0][0])
                 S[0][1] -= 1
            else:
                if N >= 3:
                    if S[2][1] == S[0][1]:
                        evac.append(S[0][0])       
                        S[0][1] -= 1
                    else:
                        evac.append(S[0][0] + S[1][0])
                        S[0][1] -= 1
                        S[1][1] -= 1                        
                else:       
                    evac.append(S[0][0] + S[1][0])
                    S[0][1] -= 1
                    S[1][1] -= 1
            S.sort(key = itemgetter(1), reverse = True)
        output(t, ' '.join(evac))



if __name__ == "__main__":
   main()