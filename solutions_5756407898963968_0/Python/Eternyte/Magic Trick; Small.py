def main():
    fileName = "A-small-attempt0.in"
    file = open(fileName)

    # Loop for the number of tests there are.
    for case in range(1, int(file.readline()) + 1):
        # Read in the answer to the first question.
        rowDesired = int(file.readline())

        # Read in the row of the board into a list.
        answersOne = []
        for row in range(1, 5):
            if (row == rowDesired):
                rowOfCardsOne = file.readline()
                answersOne = rowOfCardsOne.split()
            else:
                file.readline()

        # Read in the answer for the second question.
        rowDesired = int(file.readline())
        
        # Read in the row of the board into a list.
        answersTwo = []
        for row in range(1, 5):
            if (row == rowDesired):
                rowOfCardsTwo = file.readline()
                answersTwo = rowOfCardsTwo.split()
            else:
                file.readline()

        # Cross check both set of answers.
        answers = set(answersOne) & set(answersTwo)

        # Return the results.
        print("Case #" + str(case) + ": ", end="")
        # If there are no answers, volunteer cheated.
        if (len(answers) == 0):
            print("Volunteer cheated!")
            
        # If there are more than one answer, the magician sucks.
        if (len(answers) > 1):
            print("Bad magician!")
            
        # If there is only one answer, print the answer.
        if (len(answers) == 1):
            for answer in answers:
                print(answer)

if __name__ == "__main__":
    main()
