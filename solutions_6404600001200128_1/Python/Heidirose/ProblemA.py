data = open("inputA.txt")
output = open("outputA.txt", "w")
T = int(data.readline())
for t in range(T):
    n = int(data.readline())
    counts = [int(x) for x in data.readline().split()]
    
    eaten_calc_1 = 0
    eaten_calc_2 = 0
    biggest_difference = 0

    #Do calculation 1
    for i in range(n - 1):
        before = counts[i]
        after = counts[i+1]
        #Assume that if before is less than after, mushrooms were added and none were eaten
        if before > after:
            eaten_calc_1 += (before - after)
        #Also do some preprocessing for the next calculation
        if (before - after) > biggest_difference:
            biggest_difference = before - after


    #Do calculation 2
    #We know that biggest_difference is the speed she can eat in 10 seconds. She will eat all of these if they are there!
    for i in range(n-1):
        before = counts[i]
        after = counts[i+1]
        eaten_calc_2 += min(biggest_difference, before)

   
    output.write("Case #%d: %d %d\n" % (t+1, eaten_calc_1, eaten_calc_2))
output.close()
