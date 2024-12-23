
package main

import (
    "fmt"
    "math"
)

var RANGE_OF_VALUES = [2]int{1, 100}

// If there are fewer than 3 elements, then all elements are removed.
const NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION = 3

func minimumOperations(input []int) int {
    minOperationsToMakeDistinctElements := 0
    visited := make([]bool, RANGE_OF_VALUES[1] + 1)

    for i := len(input) - 1; i >= 0; i-- {
        if visited[input[i]] {
            minOperationsToMakeDistinctElements =
                    int(math.Ceil(float64(i + 1) / NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION))
            break
        }
        visited[input[i]] = true
    }

    return minOperationsToMakeDistinctElements
}
