#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

namespace lc3 {
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0;
    int max_size = 0;
    for (int right = 0; right < s.size(); right++) {
      while (window.find(s.at(right)) != window.end()) {
        window.erase(s.at(left));
        left++;
      }
      window.insert(s.at(right));
      max_size = max(max_size, right - left + 1);
    }
  
    return max_size;
  }
};
} // namespace lc3

int main() {
  lc3::Solution solution;
  string s = "abcabcbb";
  cout << solution.lengthOfLongestSubstring(s) << endl;
}