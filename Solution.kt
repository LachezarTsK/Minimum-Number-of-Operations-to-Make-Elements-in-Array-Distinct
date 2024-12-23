
import kotlin.math.ceil

class Solution {

    private companion object {
        val RANGE_OF_VALUES = intArrayOf(1, 100)

        // If there are fewer than 3 elements, then all elements are removed.
        const val NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION = 3
    }

    fun minimumOperations(input: IntArray): Int {
        var minOperationsToMakeDistinctElements = 0
        val visited = BooleanArray(RANGE_OF_VALUES[1] + 1)

        for (i in input.size - 1 downTo 0) {
            if (visited[input[i]]) {
                minOperationsToMakeDistinctElements =
                    ceil((i + 1).toDouble() / NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION).toInt()
                break
            }
            visited[input[i]] = true
        }

        return minOperationsToMakeDistinctElements
    }
}
