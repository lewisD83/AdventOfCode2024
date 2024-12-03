listOne, listTwo = [], []

input1 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input1.txt"
input2 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input2.txt"

## Open the puzzle input in read mode
with (open(input2, "r") as lines):

    ## For each line in the puzzle input
    for line in lines:

        ## Each line has two numbers so we can split to extract each number
        nums = line.split()

        ## Store each number as an int
        firstNumber = int(nums[0])
        secondNumber = int(nums[1])

        ## Add our numbers to their respective lists
        listOne.append(firstNumber)
        listTwo.append(secondNumber)

## Sort our lists in ascending order
listOne.sort()
listTwo.sort()
n = len(listOne)

## Part 1 #############################################
answer1 = 0

## We can loop like this cause both lists are the same size (this would break if they weren't)
for i in range(n):

    ## Compare each pair and calculate their absolute difference (we don't care about negative distances)
    difference = abs(listOne[i] - listTwo[i])
    answer1 += difference

print(answer1)

## Part 2 #############################################
answer2 = 0

## Loop over both lists and check how many times the numbers in listOne appear in listTwo
for i in listOne:
    occurrence = 0

    for j in listTwo:
        if i == j:
           occurrence += 1

    print(i, "occurs", occurrence, "times")
    answer2 += i * occurrence

print(answer2)
