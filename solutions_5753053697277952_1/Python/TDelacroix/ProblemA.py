import numpy as np


#f = open('A-sample.in','r')
#g = open('A-sample.ou','w')

#f = open('A-small-attempt1.in','r')
#g = open('A-small.ou','w')

f = open('A-large.in','r')
g = open('A-large.ou','w')


def inputToList(f):
    n = int(f.readline()[:-1])
    iL = []
    for k in range(n):
        n_k = int(f.readline()[:-1])
        l_k = f.readline()[:-1].split(' ')
        iL += [[]]
        for i in range(n_k):
            iL[k] += [int(l_k[i])]
    return iL


iL = inputToList(f)



def letter(num):
    return chr(num + ord('A'))


def solution(pat):
    S  = ''
    while np.max(pat) <> 0:
        if np.sum(pat) == 3 or np.sum(pat) == 1:
            i = np.argmax(pat)
            pat[i] -= 1
            S += letter(i)
            S += ' '
        else:
            i = np.argmax(pat)
            pat[i] -= 1
            j = np.argmax(pat)
            pat[j] -= 1
            S += letter(i)
            S += letter(j)
            S += ' '
    return S[:-1]



def outputList(iL):
    oL = []
    for k in range(len(iL)):
        oL += [solution(iL[k])]
	print k+1,'Done'
    return oL


oL = outputList(iL)


def outputListToString(oL):
    oS = ''
    for k in range(len(oL)):
        oS += 'Case #'+str(k+1)+': '+ oL[k]+'\n'
    return oS


oS = outputListToString(oL)


g.write(oS)


g.close()
