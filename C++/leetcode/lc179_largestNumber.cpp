#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

namespace lc179 {
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> strs;
    for (int num : nums) {
      strs.push_back(to_string(num));
    }

    sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
      return a + b > b + a;
    });

    if (strs[0] == "0") {
      return "0";
    }
    string result;
    for (const string &s : strs) {
      result += s;
    }
    return result;
  }
};
}

int main() {
  vector<int> nums = {3,30,34,5,9};
  cout << lc179::Solution().largestNumber(nums) << endl;
}