using System;
using System.IO;
using System.Numerics;

class Day1
{
    public static void Main(String[] args)
    {
        var input1 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input1.txt";
        var input2 = "D:\\Projects\\AdventOfCode\\2024\\AdventOfCode2024\\Day01\\Input2.txt";
        
        var lines = File.ReadAllLines(input1);

        // List to hold all our numbers from each list
        var listOne = new List<int>();
        var listTwo = new List<int>();
        
        // Read in our puzzle input line by line
        foreach (var line in lines) 
        {
            // Each number is serparated by 3 spaces (no idea) so we can splut on spaces to extract each number
            var nums = line.Split("   ");
            
            // Convert the extracted numbers (which are strings atm) to ints
            var firstNumber = int.Parse(nums[0]);
            var secondNumber = int.Parse(nums[1]);
                
            // Add our numbers to their respective list
            listOne.Add(firstNumber);
            listTwo.Add(secondNumber);
        }
        
        // Sort both lists in ascending order
        listOne.Sort();
        listTwo.Sort();
        
        // Part 1
        {
            int answer = 0;
            
            // We can loop like this cause both lists are the same size (this would break if they weren't)
            for (int i = 0; i < listOne.Count(); i++)
            {
                // Compare each pair and calculate their absolute difference (we don't care about negative distances)
                int difference = Math.Abs(listOne[i] - listTwo[i]);

                // And difference to our answer
                answer += difference;
            }
        
            Console.WriteLine("Answer: {0}", answer);
        }
        
        // Part 2
        {
            int answer = 0;

            foreach (var i in listOne)
            {
                int val = i;
                int occurence = 0;
            
                foreach (var j in listTwo)
                {
                    // If the number i from list one is the same as number j from list two then increment count
                    if (i == j)
                    {
                        occurence++;
                    }
                }
            
                Console.WriteLine("{0} occurs {1} times.", val, occurence);
                answer += val * occurence;
            }

            Console.WriteLine("Answer: {0}", answer);
        }
    }
}