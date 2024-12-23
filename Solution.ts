
function minimumOperations(input: number[]): number {
    const RANGE_OF_VALUES: number[] = [1, 100];

    // If there are fewer than 3 elements, then all elements are removed.
    const NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION: number = 3;

    let minOperationsToMakeDistinctElements = 0;
    const visited: boolean[] = new Array(RANGE_OF_VALUES[1] + 1).fill(false);

    for (let i = input.length - 1; i >= 0; --i) {
        if (visited[input[i]]) {
            minOperationsToMakeDistinctElements
                = Math.ceil((i + 1) / NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION);
            break;
        }
        visited[input[i]] = true;
    }

    return minOperationsToMakeDistinctElements;
};
