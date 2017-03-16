#!/usr/bin/python
import math
import sys

def main():
        count = int(input());
        for i in range(0, count):
                sys.stdout.write ("Case #" + str(i+1) + ": ")

                num1 = int(input()) - 1
                grid1 = [];

                for j in range(0,4):
                    grid1.append(set(input().split(' ')))

                    
                num2 = int(input()) - 1
                grid2 = [];

                for j in range(0,4):
                    grid2.append(set(input().split(' ')))

                resultSet = grid1[num1].intersection(grid2[num2]);

                if(len(resultSet) == 0):
                    print("Volunteer cheated!");
                elif(len(resultSet) > 1):
                    print("Bad magician!");
                else:
                    print(resultSet.pop())


if __name__ == "__main__":
        main()
