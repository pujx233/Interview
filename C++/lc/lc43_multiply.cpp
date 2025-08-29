#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace lc43 {

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    int m = num1.length();
    int n = num2.length();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[j] - '0';
        int product = digit1 * digit2;

        int p1 = i + j;
        int p2 = i + j + 1;
        int sum = product + res[p2];

        res[p2] = sum % 10;
        res[p1] += sum / 10;
      }
    }

    string result_str;
    int start_index = 0;

    while (start_index < res.size() && res[start_index] == 0) {
      start_index++;
    }

    if (start_index == res.size()) {
      return "0";
    }

    for (int i = start_index; i < res.size(); ++i) {
      result_str += std::to_string(res[i]);
    }


    return result_str;
  }
};
}

int main() {
  lc43::Solution solution;
  string num1 = "123";
  string num2 = "45";
  cout << "Input: num1 = \"" << num1 << "\", num2 = \"" << num2 << "\"" << endl;
  cout << "Output: \"" << solution.multiply(num1, num2) << "\"" << endl;
}