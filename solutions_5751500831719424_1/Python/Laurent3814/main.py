import collections

def compute_cost(a,choice):
    count = 0 
    for i in xrange(len(a)):
        if i<choice:
            count+=a[choice]-a[i]
        elif i == choice:
            continue
        else:
            count +=a[i]-a[choice]
    return count

ncases = int(raw_input())
for i in xrange(ncases):
    done = False
    n = int(raw_input())
    words = []
    for j in xrange(n):
        word = raw_input().strip()
        if len(word) == 1:
            word_seq = [(word[0],1)]
        else:
            current_letter = word[0]
            word_seq = []
            counter = 0
            for p,l in enumerate(word[1:]):
                counter+=1
                if l !=current_letter:
                    word_seq.append((current_letter,counter))
                    counter = 0
                    current_letter = l
                    if p == len(word)-2:
                        word_seq.append((current_letter,1))
                        break
                if p == len(word)-2:
                    word_seq.append((current_letter,counter+1))
                    break
        words.append(word_seq)
    # 0 is same than the others prove it all

    for g in range(len(words[0])):
        for u in words[1:]:
            if not len(u) == len(words[0]) or not u[g][0] == words[0][g][0]:
                print "Case #%d: Fegla won"%(i+1)
                done = True
                break
        if done: break
    if done: continue
    count = 0
    for g in range(len(words[0])):
        # Compute smallest_cost
        a = sorted([words[u][g][1] for u in range(len(words))])
        count +=min([compute_cost(a, x) for x in range(len(a))])
        #count +=max(words[0][g][1],words[1][g][1]) - min(words[0][g][1],words[1][g][1])
    print "Case #%d: %d"%(i+1, count)

    # Otherwise it is solvable let's compute moves
