#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lc125 {

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }

    int left = 0, right = s.length() - 1;

    while (left < right) {
      while (left < right && !std::isalnum(s[left])) {
        left++;
      }

      while (left < right && !std::isalnum(s[right])) {
        right--;
      }

      if (tolower(s[left]) == tolower(s[right])) {
        left++;
        right--;
      } else {
        return false;
      }


    }

    return true;
  }
};
}

int main() {
  lc125::Solution solution;
  string s = "A man, a plan, a canal: Panama";
  cout << solution.isPalindrome(s) << endl;
}