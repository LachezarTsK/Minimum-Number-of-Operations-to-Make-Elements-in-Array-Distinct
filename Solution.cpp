
#include <array>
#include <vector>
using namespace std;

class Solution {

    static constexpr array<int, 2> RANGE_OF_VALUES = { 1, 100 };

    // If there are fewer than 3 elements, then all elements are removed.
    static const int NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION = 3;

public:
    int minimumOperations(const vector<int>& input) const {
        int minOperationsToMakeDistinctElements = 0;
        array<bool, RANGE_OF_VALUES[1] + 1> visited{};

        for (size_t i = input.size() - 1; i != variant_npos; --i) {
            if (visited[input[i]]) {
                minOperationsToMakeDistinctElements
                        = ceil(static_cast<double>(i + 1) / NUMBER_OF_ELEMENTS_TO_REMOVE_FROM_FRONT_PER_OPERATION);
                break;
            }
            visited[input[i]] = true;
        }

        return minOperationsToMakeDistinctElements;
    }
};
