#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for i in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    num_strings = int(line.split()[0])
    string_set = []
    for j in range(num_strings):
        string_set.append( f.readline().strip() )
    short_strings = []
    count_strings = []
    for j in range(num_strings):
        short_string = [string_set[j][0]]
        last_short_string_character = string_set[j][0]
        current_count = 1
        count_string = []
        for k in range(1,len(string_set[j])):
            if string_set[j][k] != last_short_string_character:
                last_short_string_character = string_set[j][k]
                short_string.append( last_short_string_character )
                count_string.append( current_count )
                current_count = 1
            else:
                current_count += 1
        #if current_count:
        count_string.append( current_count )
        count_strings.append( count_string )
        short_string = ''.join(short_string)
        short_strings.append( short_string )
    #print short_strings, count_strings
    success = 1
    for option in short_strings:
        if short_string != option:
            success = 0
            break
    if success == 0:
        print "Case #" + str(i+1) + ":", "Fegla Won"
    else:
        answer = 0
        for j in range(len(short_string)):
            # First get the largest number in any string
            max = 0
            min = 1000000000
            for count_string in count_strings:
                if count_string[j] > max:
                    max = count_string[j]
                    #print "max was", max
                if count_string[j] < min:
                    min = count_string[j]
                    #print "min was", max
            minimum_amount = 10000000
            if max == min:
                minimum_amount = 0
            if max < min:
                print "PROBLEM!!!!!!!!"
            for k in range(min,max):
                current_amount = 0
                for count_string in count_strings:
                    current_amount += abs(k - count_string[j])
                if current_amount < minimum_amount:
                    minimum_amount = current_amount
                    #print "set minimum to", minimum_amount
            answer += minimum_amount
        print "Case #" + str(i+1) + ":", answer
        


            



