#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace lc152 {

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty()) {
      return 0; 
    }

    int max_so_far =  nums[0];
    int max_ending_here = nums[0];
    int min_ending_here = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        swap(max_ending_here, min_ending_here);
      }

      max_ending_here = max(nums[i], max_ending_here * nums[i]);
      min_ending_here = min(nums[i], min_ending_here * nums[i]);

      max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
  }
};


}

int main() {
  vector<int> nums = {2,3,-2,4};
  cout << lc152::Solution().maxProduct(nums) << endl;
}