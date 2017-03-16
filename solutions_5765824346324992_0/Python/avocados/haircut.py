#!/usr/bin/env python3
import sys
import argparse

def lcm_list(list_value):
    val = 1
    for x in list_value:
        val = lcm(val, x)
    return int(val)

def lcm(a, b):
    return (a * b) / gcd(a, b)

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def process_instance(instance):
    number_of_barbers = instance['number_of_barbers']
    place_in_line = instance['place_in_line']
    barber_speed_list = instance['barber_speed_list']

    times_to_run = lcm_list(barber_speed_list)

    order = []
    time = 0
    free_barbers = set(range(number_of_barbers))
    for i in range(place_in_line):
        # takes lowest non taken barber
        if len(free_barbers) > 0:
            barber = min(free_barbers)
            free_barbers.remove(barber)
        else:
            # calculate time to free up a barber
            mod_times = [x - time % x for x in barber_speed_list]
            elapsed_time = min(mod_times)
            time += elapsed_time
            barbers_to_free_up = [i for i, x in enumerate(barber_speed_list)
                                  if time % x == 0]
            free_barbers |= set(barbers_to_free_up)

            barber = min(free_barbers)
            free_barbers.remove(barber)
        if time >= times_to_run:
            break
        order.append(barber)

    #print('place in line {}'.format(place_in_line))
    #print('lcm {}'.format(times_to_run))
    #input(order)
    arg = order[(place_in_line - 1)% len(order)]
    return arg + 1

def parse_instance(metadata, line):
    number_of_barbers, place_in_line = [int(x)
                                        for x in metadata.strip().split()]
    barber_speed_list = [int(x) for x in line.strip().split()]
    instance = {
                'number_of_barbers' : number_of_barbers,
                'place_in_line' : place_in_line,
                'barber_speed_list' : barber_speed_list,
                }
    return instance

def parse_file(file_name):
    with open(file_name, mode = 'r', encoding='utf-8') as file_:
        number_of_instances = int(file_.readline())
        lines = [line for line in file_]

        # Allows for cases where one instances can span multiple lines
        instances = [parse_instance(lines[2*i], lines[2*i+1])
                     for i in range(number_of_instances)]
    return (number_of_instances, instances)

def clean_solution(i, solution):
    solution = 'Case #{}: {}'.format(i, solution)
    print(solution)
    return solution

def get_output_from_solutions(file_name, solutions):
    lines = [clean_solution(i+1, solution) + '\n'
             if i != len(solutions) - 1
             else
             clean_solution(i+1, solution)
             for i, solution in enumerate(solutions)
            ]
    with open(file_name, 'w', encoding='utf-8') as file_:
        file_.writelines(lines)

def print_status(i, total):
    print_string = '\rProcessing {}/{} instances '.format(i+1, total)
    sys.stdout.write(print_string)
    sys.stdout.flush()

if __name__ == '__main__':
    description='Process Problem Name'
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('input_file_name', type=str, help='File to process')
    parser.add_argument('--output_file_name', type=str,
                        help='File to output', default='output')
    args = parser.parse_args()

    number_of_instances, instances = parse_file(args.input_file_name)

    if number_of_instances != len(instances):
        error = 'Expected {} instances | parsed {} instances'
        error = error.format(number_of_instances, len(instances))
        raise Exception(error)

    solutions = []
    for i, instance in enumerate(instances):
        print_status(i, number_of_instances)
        solution = process_instance(instance)
        solutions.append(solution)
    print('\nFinished Processing!')

    get_output_from_solutions(args.output_file_name, solutions)

    print('Done!')
