#!/usr/bin/env python
import fileinput

def plan(line):
    base = ord('A')
    parties = line.split(" ")
    parties = [int(p) for p in parties]
    output = ""
    while not all(p == 0 for p in parties):
        # find the max value
        maxval = max(parties)
        maxParties = [i for i, j in enumerate(parties) if j == maxval]
        if len(maxParties) % 2 == 0:
            # remove two
            parties[maxParties[0]] -= 1
            parties[maxParties[1]] -= 1
            output += chr(base + maxParties[0])
            output += chr(base + maxParties[1])
        else:
            # remove one
            parties[maxParties[0]] -= 1
            output += chr(base + maxParties[0])
        output += " "
    return output.strip()

i = 0
for line in fileinput.input():
    if i == 0:
        i += 1
        continue
    if i % 2 == 0:
        line = line[0:-1]
        print("Case #" + str(i/2) + ": " + str(plan(line)))
    i += 1
