
# coding: utf-8

# In[3]:

from collections import Counter


# In[41]:

def solve(people):
    answer = []
    senators = Counter(dict(zip("ABCDEFGHIJKLMNOPQRSTUVWXYZ", people)))
    while senators:
        leaving = ""
        most_common, count = senators.most_common(1)[0]
        senators -= Counter(most_common)
        leaving += most_common
        if majority(senators):
            most_common, count = senators.most_common(1)[0]
            senators -= Counter(most_common)
            leaving += most_common
        answer.append(leaving)
    return " ".join(answer)


# In[39]:

def majority(senators):
    most_common, count = senators.most_common(1)[0]
    return count > sum(people for party, people in senators.items() if party != most_common)


# In[ ]:

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T+1):
        P = int(input())
        senators = [int(x) for x in input().split()]
        answer = solve(senators)
        print("Case #{}: {}".format(case, answer))

