from fractions import gcd
import heapq

def lcm(a, b):
    return (a * b) // gcd(a, b)

def solve_simulate(N, barber_times):
    last_barber_cut_index = 0
    available_barbers = [(index, value) for index, value in enumerate(barber_times)]
    heapq.heapify(available_barbers)
    unavailable_barbers = []
    for i in range(N + 1):
        if len(available_barbers) > 0:
            barber_index_time = heapq.heappop(available_barbers)
            heapq.heappush(unavailable_barbers, (barber_index_time[1], barber_index_time[0]))
            last_barber_cut_index = barber_index_time[0]
        else:
            min_time = unavailable_barbers[0][0]
            while len(unavailable_barbers) > 0 and unavailable_barbers[0][0] == min_time:
                now_available = heapq.heappop(unavailable_barbers)
                barber_index = now_available[1]
                heapq.heappush(available_barbers, (barber_index, barber_times[barber_index]))
            for i in range(len(unavailable_barbers)):
                unavailable_barbers[i] = (unavailable_barbers[i][0] - min_time, unavailable_barbers[i][1])
            heapq.heapify(unavailable_barbers)
            barber_index_time = heapq.heappop(available_barbers)
            heapq.heappush(unavailable_barbers, (barber_index_time[1], barber_index_time[0]))
            last_barber_cut_index = barber_index_time[0]
    return last_barber_cut_index

def solve_small(N, barber_times):
    max_lcm = 1
    for barber_time in barber_times:
        max_lcm = lcm(max_lcm, barber_time)
    cycle_length = 0
    for barber_time in barber_times:
        cycle_length += (max_lcm // barber_time)
    new_N = (N % cycle_length)
    return solve_simulate(new_N, barber_times) + 1

if __name__ == "__main__":
    with open("input.txt", "r") as input, open("output.txt", "w") as output:
        T = int(input.readline())
        for t in range(1, T + 1):
            B_N_tokens = input.readline().split(" ")
            B = int(B_N_tokens[0])
            N = int(B_N_tokens[1]) - 1
            Mk_tokens = input.readline().split(" ")
            barber_times = list(map(int, Mk_tokens))
            small_answer = solve_small(N, barber_times)
            print("Case #{0}: {1}".format(t, small_answer), file=output)