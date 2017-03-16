__author__ = 'Ben'

from string import Template

def main():
    number_of_instances = int(input())
    result = ""
    result_line = Template('Case #$n: $res\n')

    for instance in range(1, number_of_instances + 1):
        row1 = int(input())
        for r1 in range(1, 5):
            temp = input()
            if row1 == r1:
                row1_content = set(temp.split())

        row2 = int(input())
        for r2 in range(1, 5):
            temp = input()
            if row2 == r2:
                row2_content = set(temp.split())

        intersection_set = row1_content.intersection(row2_content)
        if len(intersection_set) == 0:
            result += result_line.substitute(n=instance, res='Volunteer cheated!')
        elif len(intersection_set) > 1:
            result += result_line.substitute(n=instance, res='Bad magician!')
        else:
            result += result_line.substitute(n=instance, res=intersection_set.pop())

    print(result)

if __name__ == "__main__":
    main()