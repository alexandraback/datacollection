# -*- coding: utf-8 -*-
"""
Created on Sat Apr 09 07:55:19 2016

@author: BCLAES
"""

def handle_case(N):
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    partiesS = N.split()
    parties = []
    for p in partiesS:
        parties.append(int(p))
    total = sum(parties)
    output = ""
    while total > 2:
        mx = max(parties)
        indexof = parties.index(mx)
        letter = letters[indexof]
        output += letter
        parties[indexof] -= 1
        total = sum(parties)
        #check for absolute majority
        mx2 = max(parties)
        if not (mx2 > total/2):
            output += " "
        
    #total is now 2, should be with the same party
    for i in xrange(0,2):
        mx = max(parties)
        indexof = parties.index(mx)
        output += letters[indexof]
        parties[indexof] -= 1
        
   
    return output


#print handle_case("2 2")
#print handle_case("3 2 2")
#print handle_case("1 1 2")
#print handle_case("1 1 1 1 1 1 1 7")

        
solutions = []
with open("A-small.in") as f:
#with open("A-large.in") as f:
    test_cases = int(f.readline())
    for i in xrange(0,test_cases):
        #DONT FORGET STRIP
        a = f.readline() #forget the count
        m = f.readline().strip()
        x = handle_case(m)
        strout = str.format("Case #{}: {}\n", i+1, x)
        solutions.append(strout)
with open("output-large.txt", "w") as out:
        out.writelines(solutions)