#!/usr/bin/python
# -*- coding: utf-8 -*-



nbcases = int(raw_input())

for case in xrange(1,nbcases+1):
    n = int(raw_input())
    chaines = []
    for i in xrange(0,n):
        chaines.append(raw_input())
    lettres = [chaines[0][0]]
    nombres = [[1]]
    for c in chaines[0][1:]:
        if (c == lettres[-1]):
            nombres[0][-1] += 1
        else:
            lettres.append(c)
            nombres[0].append(1)
    ok = True
    for chaine in chaines[1:]:
        lc = [chaine[0]]
        nombres.append([1])
        for c in chaine[1:]:
            if (c == lc[-1]):
                nombres[-1][-1] += 1
            else:
                lc.append(c)
                nombres[-1].append(1)
        if (lc <> lettres):
            ok = False
    if not ok:
        print "Case #%d: Fegla Won" % case
        continue
    else:
        nbmodifs = 0
        for i in xrange(0,len(nombres[0])):
            nbmini = 99999999
            best = -1
            for essai in xrange(0,101):
                modifs = 0
                for nombre in nombres:
                    modifs += abs(essai-nombre[i])
                if modifs < nbmini:
                    best = essai
                    nbmini = modifs
            nbmodifs += nbmini
        print "Case #%d: %d" % (case,nbmodifs)
