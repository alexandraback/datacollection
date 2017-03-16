import numpy as np

f = open("A.in")
num = int(f.readline())
output = ""
for n in range(num):
    N, = [int(x) for x in f.readline().strip().split(" ")]
    
    def make_tuple(string):
        stack = []
        on_idx = None
        for c in string:
            if c == on_idx:
                stack[-1] = (c, stack[-1][1] + 1)
            else:
                stack.append((c, 1))
                on_idx = c
        return stack


    def does_char_match(states):
        num_states = len(states[0])
        for k in states:
            if len(k) != num_states:
                return False
        for k in range(num_states):
            char = states[0][k][0]
            for state in states:
                if char != state[k][0]:
                    return False
        return True

    inits = []
    for k in range(N):
        data = f.readline().strip()
        inits.append(make_tuple(data))

    def calc_dist(spots, t):
        spots = np.array(spots)
        return np.sum(np.abs(spots-t))

    def min_dist(spots):
        min_s = min(spots)
        max_s = max(spots)
        dists = [calc_dist(spots, x) for x in range(min_s, max_s+1)]
        #print dists
        #print spots, "spots"
        #print calc_dist(spots, 1)
        return calc_dist(spots, np.argmin(dists) + min_s)
        
    def solve(states):
        if not does_char_match(inits):
            return "Fegla Won"
        
        #flatten inits
        
        slices = []
        for k in range(len(states[0])):
            states_slice = [x[k][1] for x in states]
            slices.append(states_slice)
        
        dists = []
        for i, sli in enumerate(slices):
            #print states[0][i][0]
            dists.append(min_dist(sli))
        return sum(dists)
    output_val = solve(inits)
    output+="Case #"+str(n+1)+": "+str(output_val)+"\n"

f = open ("A.out", "w+")
f.write(output)
f.close()



