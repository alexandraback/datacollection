#!/usr/bin/env python3
import sys
import argparse

def get_case_1(number_of_values, number_of_mushrooms):
    val = 0
    for i in range(number_of_values - 1):
        if number_of_mushrooms[i] > number_of_mushrooms[i+1]:
            val += number_of_mushrooms[i] - number_of_mushrooms[i+1]
    return val

def get_case_2(number_of_values, number_of_mushrooms):
    min_rate = 0
    for i in range(number_of_values - 1):
        val = number_of_mushrooms[i] - number_of_mushrooms[i+1]
        if val > min_rate:
            min_rate = val

    val = 0
    for i in range(number_of_values - 1):
        eaten = min(min_rate, number_of_mushrooms[i])
        val += eaten
    return val

def process_instance(instance):
    number_of_values = instance['number_of_values']
    number_of_mushrooms = instance['number_of_mushrooms']
    x1 = get_case_1(number_of_values, number_of_mushrooms)
    x2 = get_case_2(number_of_values, number_of_mushrooms)
    return '{} {}'.format(x1, x2)

def parse_instance(number_of_values, number_of_mushrooms):
    number_of_values = int(number_of_values.strip())
    number_of_mushrooms = [int(x) for x in number_of_mushrooms.strip().split()]

    instance = {}
    instance['number_of_values'] = number_of_values
    instance['number_of_mushrooms'] = number_of_mushrooms

    list_of_values_length = len(number_of_mushrooms)
    if number_of_values != list_of_values_length:
        error = 'Expected {} values | {} values parsed'
        error = error.format(number_of_values, list_of_values_length)
        raise Exception(error)
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
