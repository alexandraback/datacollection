from threading import currentThread

class TailRecursiveCall(Exception):
    pass

class Rec_f(object):
    def __init__(self, func):
        self.tr_d = {}
        self.func = func

    def __call__(self, *args, **kw):
        self.args = args
        self.kw = kw
        thread = currentThread()
        if thread not in self.tr_d:
            self.tr_d[thread] = {}
            self.tr_d[thread]["depth"] = 0
        self.tr_d[thread]["depth"] += 1
        # Record the arguments passed to function on this thread
        self.tr_d[thread]["args"] = args
        self.tr_d[thread]["kw"] = kw
        depth =  self.tr_d[thread]["depth"]
        # If we are re-entering the same function on the same thread:
        if depth > 1:
            # Effectively detours execution to the "Landing Point",
            # but two execution frames above the current one:
            raise TailRecursiveCall
        over = False
        while not over:
            over = True
            args = self.tr_d[thread]["args"]
            kw = self.tr_d[thread]["kw"]
            try:
                # Execute the function with the latest arguments for this thread.
                result = self.func(*args, **kw)
            except TailRecursiveCall:
                # Landing point if the function tried to recurse itself.
                # Two execution frames above.
                self.tr_d[thread]["depth"] -= 1
                over = False
        self.tr_d[thread]["depth"] -= 1
        return result

def tailrecursive(func):
    return Rec_f(func)



import itertools


fn = 'treasure.in'
fn = '/Users/vivanov/Downloads/A-small-attempt0.in'
#fn = '/home/vivanov/Downloads/D-large-practice.in'

with open(fn) as f:
    lines = f.read().splitlines()[1:]
    l = []

    i = 0
    while i < len(lines):
        p = []

        num = [int(k) for k in lines[i].split(' ')][0]
        i += 1
        for j in range(num):
            p.append([(k) for k in lines[i]])
            i += 1
        l.append({'lines' : p})


import copy

pass

def remove_all_pairs(state):
    new_lines = []
    for line in state['lines']:
        new_line = []
        last_unique = line[0]
        new_line.append(last_unique)
        for i in range(1,len(line)):
            if line[i] != last_unique:
                last_unique = line[i]
                new_line.append(last_unique)
        new_lines.append(new_line)
    return {'lines' : new_lines}

def solvable(state):
    lines = state['lines']
    return all(lines[i] == lines[0] for i in range(len(lines)) )

def calc_coordinates(state):
    all_coordinates = []
    for line in state['lines']:
        last_unique = line[0]
        counter = 1
        coordinates = []
        for i in range(1,len(line)):
            if line[i] != last_unique:
                last_unique = line[i]
                coordinates.append(counter)
                counter = 1
            else :
                counter += 1
        coordinates.append(counter)
        all_coordinates.append(coordinates)
    return all_coordinates


def calc_distance(coordinates1, coordinates2):
    counter = 0
    for i in range(len(coordinates1)):
        counter += abs(coordinates1[i] - coordinates2[i])
    return counter

def calc_moves(state):
    all_coordinates = calc_coordinates(state)
    median_coordinates = []
    for i in range(len(all_coordinates[0])):
        median = list(sorted([j[i] for j in all_coordinates]))[len(all_coordinates) // 2]
        median_coordinates.append(median)
    moves = 0
    for i in all_coordinates:
        moves += calc_distance(median_coordinates, i)
    return moves

def search(state):
    if solvable(remove_all_pairs(state)):
        diffs = []
        return calc_moves(state)

#r = remove_all_pairs(l[1])
#res = solvable(r)
#c = calc_coordinates(l[2])
#ans = search(l[4])


pass


with open('treasure.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        res = search(l[i])
        to_write.append('Case #%s: %s \n' %((i+1), res if res is not None else 'Fegla Won'))
    f.writelines(to_write)

