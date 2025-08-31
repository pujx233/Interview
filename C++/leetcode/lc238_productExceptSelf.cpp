#include "iostream"
#include "vector"

using namespace std;

namespace lc238 {

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int left_product = 1;
    for (int i = 0; i < n; ++i) {
      result[i] *= left_product;
      left_product *= nums[i];
    }

    int right_product = 1;
    for (int i = n - 1; i >= 0; --i) {
      result[i] *= right_product;
      right_product *= nums[i];
    }

    return result;
  }
};

}

int main() {
  vector<int> nums = {1,2,3,4};
  vector<int> result = lc238::Solution().productExceptSelf(nums);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
}