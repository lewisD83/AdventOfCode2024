#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    std::string input1 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input1.txt";
    std::string input2 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input2.txt";
    // Build a read-Stream
    std::ifstream source;

    // Open the sample problem
    source.open(input1, std::ios_base::in);

    // Check if there was a problem opening the file
    if (!source)
    {
        std::cout << "Can't open file!";
        return 0;
    }

    // Vectors to hold all our numbers from each list
    std::vector<int> listOne;
    std::vector<int> listTwo;

    // Read in our puzzle input line by line
    for (std::string line; std::getline(source, line);)
    {
        // Make a stream for the line itself
        std::istringstream in(line);

        int firstNumber = 0;
        int secondNumber = 0;

        // Place the values from the list into our variables
        in >> firstNumber;
        in >> secondNumber;

        // Add out numbers to their respective list
        listOne.push_back(firstNumber);
        listTwo.push_back(secondNumber);
    }

    // Sort both lists into ascending order
    std::sort(listOne.begin(), listOne.end());
    std::sort(listTwo.begin(), listTwo.end());

    // Part 1
    {
        int answer = 0;

        // We can loop like this cause both lists are the same size (this would break if they weren't)
        for (int i = 0; i < listOne.size(); i++)
        {
            // Compare each pair and calculate their absolute difference (we don't care about negative distances)
            int difference = std::abs(listOne[i] - listTwo[i]);

            // And difference to our answer
            answer += difference;
        }
        
        printf("Answer: %d\n", answer);
    }

    // Part 2
    {
        int answer = 0;
        
        for (auto& i : listOne)
        {
            int val = i;
            int occurence = 0;
            
            for (auto & j : listTwo)
            {
                // If the number i from list one is the same as number j from list two then increment count
                if (i == j)
                {
                    occurence++;
                }
            }
            
            printf("%d occurs %d times.\n", val, occurence);
            answer += val * occurence;
        }

        printf("Answer: %d", answer);
    }
}
