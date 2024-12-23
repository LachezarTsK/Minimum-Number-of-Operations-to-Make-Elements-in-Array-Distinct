
using System;

public class Solution
{
    private static readonly int[] RANGE_OF_VALUES = { 1, 100 };

    // If there are fewer than 3 elements, then all elements are removed.
    private static readonly int NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION = 3;

    public int MinimumOperations(int[] input)
    {
        int minOperationsToMakeDistinctElements = 0;
        bool[] visited = new bool[RANGE_OF_VALUES[1] + 1];

        for (int i = input.Length - 1; i >= 0; --i)
        {
            if (visited[input[i]])
            {
                minOperationsToMakeDistinctElements
                        = (int)Math.Ceiling((double)(i + 1) / NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION);
                break;
            }
            visited[input[i]] = true;
        }

        return minOperationsToMakeDistinctElements;
    }
}
