
# coding: utf-8

# In[57]:

cin = None
cout = None


# In[114]:

def read():
    global cin
    return cin.readline().strip().split()

def read_int():
    return [int(x) for x in read()]
    
def write(fmt, data=None):
    global cout
    cout.write(data is None and str(fmt) or fmt % data)
    
def write_line():
    write('\n')


# In[151]:

def solve():
    N = read_int()[0]
    strs = []
    for i in range(N):
        strs.extend(read())
    pc = None
    str = strs[0]
    scores = []
    fail = False
    for c in str:
        if c == pc:
            continue
        pc = c
        c_cnt = []
        for i in range(N):
            s = strs[i]
            j = 0
            while j < len(s) and s[j] == c:
                j += 1
            if j == 0:
                fail = True
                break
            c_cnt.append(j)
        if fail:
            break
        else:
            score = min([sum([abs(x - y) for y in c_cnt]) for x in c_cnt])
        scores.append(score)
        for i in range(N):
            new_str = strs[i][c_cnt[i]:]
            strs[i] = new_str
    for s in strs:
        if len(s) > 0:
            fail = True
            break
    if fail:
        write('Fegla Won')
    else:
        write(sum(scores))


# In[115]:

def work(id):
    global cin, cout
    case_num = 0
    cin = file('%s.in' % id, 'r')
    cout = file('%s.out' % id, 'w')
    case_num = read_int()[0]
    for i in range(case_num):
        write('Case #%d: ', i + 1)
        solve()
        write('\n')
    cin.close()
    cout.close()


# In[153]:

id = 'A'
work(id)
with open('%s.out' % id) as f:
    print f.read()


# In[37]:



