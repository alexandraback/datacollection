#!/usr/bin/env python3
from bisect import bisect_left

class served_list:
    def __init__(self, N, barbers):
        self.barbers = barbers
        self. N = N
        self.upper_bound = None
        self.lower_bound = None

    def __len__(self):
        if not self.upper_bound:
            self.lower_bound, self.upper_bound = self.bounds()
        return self.upper_bound

    def bounds(self):
        old_time = 0
        time = 1
        while self[time] < self.N:
            old_time = time
            time *= 2
        return (old_time, time)

    def __getitem__(self, time):
        if (time < 0):
            return 0
        else:
            return sum([ time // barber + 1 for barber in self.barbers ])

class B:
    def __init__(self, N, barbers):
        self.N = N
        self.barbers = barbers
        self.served = served_list(N, barbers)

    def find_time_served(self):
        low, high = self.served.bounds()
        return bisect_left(self.served, self.N, low, high)

    def ready(self, time):
        return [time % barber == 0 for barber in self.barbers ]

    def solve(self):
        time = self.find_time_served()
        last_served = self.served[time-1]
        must_seat = self.N - last_served
        ready = self.ready(time)
        for i in range(len(ready)):
            if ready[i]:
                must_seat -= 1
                if must_seat == 0:
                    return i
        raise(Error("This shouldn't happen..."))

T = int(input())
for t in range(T):
    U, N = [int(x) for x in input().split(" ")]
    barbers = [int(x) for x in input().split(" ")]
    problem = B(N, barbers)
    print("Case #" + str(t+1) + ": " + str(problem.solve()+1))
