from functools import reduce
from queue import PriorityQueue
from math import floor

data = open("inputB.txt")
output = open("outputB.txt", "w")
T = int(data.readline())
for t in range(T):
    num_barbers, place = [int(x) for x in data.readline().split()]
    barbers = [int(x) for x in data.readline().split()]
    fractions = [1/x for x in barbers]
    total = sum(fractions)
    percentages = [x/total for x in fractions]
    customers_processed = [floor(percentage * (max(place-1, place-100))) for percentage in percentages]


    pq = PriorityQueue()
    for i in range(len(barbers)):
        #(due_to_finish, id, time_they_take)
        pq.put((customers_processed[i]*barbers[i], i+1, barbers[i]))
    
    #Now simulate the rest
    current_place = sum(customers_processed) + 1
    result = 0
    while result == 0:
        #Take a barber
        next_barber = pq.get()
        dtf, id_, time = next_barber
        if current_place == place:
            result = id_
            break
        pq.put((dtf+time, id_, time))
        current_place += 1

    output.write("Case #%d: %d\n" % (t+1, result))
output.close()
