"""Python2- and Python3-compatible. That's all."""
from time import clock
from sys import argv
#import math
#import itertools
#import numpy

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits (as strings) of an int
    return list(read(f))
    
def read_int(f, b=10):
    return int(read(f), b)
 
def read_float(f):
    return float(read(f))
 
def read_digits(f, b=10):
    return [int(n, b) for n in read_singles(f)]

#---------------------------------------------

def read_strs(f, s=" "):
    return read(f).split(s)
    
def read_ints(f, b=10, s=" "):
    return [int(n, b) for n in read_strs(f, s)]

def read_floats(f, s=" "):
    return [float(n) for n in read_strs(f, s)]
               
#---------------------------------------------

def read_lines(f, n, reader=read_ints, *args, **kwargs):
    ret = []
    for i in range(n):
        ret.append(reader(f, *args, **kwargs))
    return ret

#---------------------------------------------

def get_overlap(a1, a2):
    """Overlap of 0: No possibilities; volunteer cheated.
       Overlap of 1: That's the chosen number!
       Overlap of >2: Too many possibilities; bad magician."""
    overlap = []
    for i in a1:
        if i in a2:
            overlap.append(i)
    return overlap

def run(data):
    guesses, fields = data
    first_guess = guesses[0]
    second_guess = guesses[1]
    first_field = fields[0]
    second_field = fields[1]
    first_possible_nums = []
    second_possible_nums = []
    """get numbers the parcipitant could have chosen 
       - this refers to all numbers in the chosen row.
       '-1' is necessary because python's indices start at 0."""
    first_possible_nums = first_field[first_guess-1]
    second_possible_nums = second_field[second_guess-1]
    overlap = get_overlap(first_possible_nums, second_possible_nums)
    if len(overlap):
        if len(overlap) == 1:
            return str(overlap[0])
        else:
            return "Bad magician!"
    else:
        return "Volunteer cheated!"

#---------------------------------------------

def read_case(f):
    guesses = []
    fields = []
    guesses.append( read_int(f)                 )
    fields.append(  read_lines(f, 4, read_ints) )
    guesses.append( read_int(f)                 )
    fields.append(  read_lines(f, 4, read_ints) )
    return [guesses, fields]

def write_case(f, i, sol):
    f.writelines("Case #"+str(i+1)+": "+str(sol)+"\n")

#---------------------------------------------

def main():
    f = open(argv[1])
    f2 = open(argv[2], "wt")
    for i in range(read_int(f)):
        print("Init case "+str(i+1)+".")
        write_case(f2, i, run(read_case(f)))
        print("Finished in "+str(clock())+".")
    f.close()
    f2.close()

if __name__ == "__main__":
    main()
