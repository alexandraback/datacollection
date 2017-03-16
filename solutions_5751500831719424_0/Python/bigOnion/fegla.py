from functools import wraps
import time
import os

###############################
##      useful decorators
###############################

def memoize_it(inner_func):
    # a decorator for memoizing function outputs
    global __memoization_registry
    try:
        __memoization_registry
    except NameError:
        __memoization_registry = []
    cache = {}
    __memoization_registry.append(cache)
    @wraps(inner_func)
    def wrap(*args):
        if args not in cache:
            cache[args] = inner_func(*args)
        return cache[args]
    return wrap

def reset_memoization ():
    # clear all previous memoization. For use in the beginning of a new test-case
    global __memoization_registry
    try:
        for cache_d in __memoization_registry:
            cache_d.clear()
    except NameError:
        pass
        
def time_it(inner_func):
    # a decorator for adding printing of timing for a function
    @wraps(inner_func)
    def wrap(*args):
        print ('--> Start function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        starttime = time.time()
        res = inner_func(*args)
        endtime = time.time()
        print ('--> End   function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        print ('--> Elapsed time \'' + inner_func.__qualname__ + '\' : ', endtime-starttime)
        print()
        return res
    return wrap
    
def count_it (inner_func):
    # a decorator for counting the number of calls to the wrapped function
    global _CALL_FUNC_COUNTERS
    if '_CALL_FUNC_COUNTERS' not in globals():
        _CALL_FUNC_COUNTERS = {}
    assert type(_CALL_FUNC_COUNTERS) == dict
    assert inner_func.__qualname__ not in _CALL_FUNC_COUNTERS
    _CALL_FUNC_COUNTERS[inner_func.__qualname__] = 0
    @wraps(inner_func)
    def wrap(*args):
        global _CALL_FUNC_COUNTERS
        _CALL_FUNC_COUNTERS[inner_func.__qualname__] += 1
        return inner_func(*args)
    return wrap

def pre_process_it (inner_func):
    # a decorator for pre-processing the function and automatically save the result 
    import inspect
    import pickle
    a = inspect.getargspec(inner_func)
    if a.args or a.keywords or a.varargs or a.defaults:
        raise ValueError ('A pre process function must not have arguments')        
    
    @time_it
    @wraps(inner_func)
    def wrap (*args):
        filename = 'preprocess_' + inner_func.__qualname__ + '.pickle'
        if not filename in os.listdir():
            print ('--> Pre process started for function \'' + inner_func.__qualname__ + '\' ....')
            preProcessData = inner_func()
            print ('--> Pre process ended for function \'' + inner_func.__qualname__ + '\'')
            print ('--> Pickling started for function \'' + inner_func.__qualname__ + '\' ....')
            with open(filename, 'wb') as f_pp:
                pickle.dump(preProcessData, f_pp, pickle.HIGHEST_PROTOCOL)
            print ('--> Pickling ended for function \'' + inner_func.__qualname__ + '\'')
        print ('--> Unpickling pre-processed data of function \'' + inner_func.__qualname__ + '\' ...')
        with open(filename, 'rb') as f_pp:
            data = pickle.load(f_pp)
        print ('--> Unpickling ended')
        print()
        return data

    return wrap
 

        

###########################################
# write code here
###########################################

@time_it
def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        print('****************testcase ', testcase)
        f_out.write('Case #' + str(testcase) + ': ')
        N = int(f_in.readline())
        l = []
        for i in range(N):
            l.append(f_in.readline().replace('\n',''))
        l2 = [no_repeat(x) for x in l]
        if l2 != [l2[0]] * N:
            f_out.write('Fegla Won\n')
        else:
            unique_letters = l2[0]
            #print ('unique', unique_letters)
            n_unique = len(unique_letters)
            l3 = [count_reps(s, unique_letters) for s in l]
            #print ('l3',l3)
            moves = 0
            for j in range(n_unique):
                ttt = [x[j] for x in l3]
                #print ('ttt',ttt)
                med = median(ttt)
                #print('med', med)
                moves += sum([abs(t-med) for t in ttt])
                #print('moves', med)
            f_out.write(str(moves) + '\n') 
                

def median (lst):
    lst2 = list(sorted(lst))
    n = len(lst2)
    #print ('??????', lst2, n)
    if n %2 == 1:
        return lst2[(n-1)//2]
    else:
        return (lst2[n//2] + lst2[n//2-1])//2
    
def no_repeat(s):
    s2 = s[0]
    for i in range(1,len(s)):
        if s2[-1] != s[i]:
            s2 += s[i]
    return s2


def count_reps (s, unique_letters):
    l = []
    i = 0
    n = len(s)
    for c in unique_letters:
        rep = 0
        while i <n and s[i] == c:
            rep += 1
            i += 1
        l.append(rep)
    assert i == n
    return tuple(l)



###########################################
# automatic runner
###########################################

@time_it
def main_run():
    print ('Directory : ', os.getcwd())
    filenames = [x for x in os.listdir ()]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(x).st_mtime, x) for x in filenames]
    if not l1:
        raise ValueError('No input file found')
    chosen_filename =  sorted(l1)[-1][1][:-3]
    print ('Chosen Filename : ',chosen_filename)
    print()
    f_in = open(chosen_filename+'.in')
    f_out = open(chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()


main_run()
