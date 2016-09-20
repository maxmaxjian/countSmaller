#include <iostream>
#include <vector>

using namespace std;

class solution {
  public:
    vector<size_t> countSmaller(const vector<int> & nums) {
        vector<size_t> counts;
        vector<int> sorted;

        for (size_t i = nums.size()-1; i < nums.size(); --i) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            counts.insert(counts.begin(), distance(sorted.begin(), it));
            sorted.insert(sorted.begin()+counts.front(), nums[i]);
        }

        return counts;
    }
};

int main() {
    vector<int> nums{5,2,6,1};

    solution soln;
    auto counts = soln.countSmaller(nums);

    for (size_t i = 0; i < nums.size(); ++i)
        cout << "To the right of " << nums[i] << " there are " << counts[i] << " smaller elements." << endl;

    return 0;
}
