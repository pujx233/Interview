#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lc11 {

class Solution {
public:
  int maxArea(vector<int>& height) {
    if (height.size() < 2) {
      return 0;
    }
    int left = 0, right = height.size() - 1;
    int area = 0;
    while (left < right) {
      int high =  min(height[right], height[left]);
      area = max(area, high * (right - left));
      if (height[left] < height[right]) {
        left ++;
      } else {
        right --;
      }
    }
    return area;
  }
};


}

int main() {
  lc11::Solution solution;
  vector<int> nums{1,8,6,2,5,4,8,3,7};
  cout <<  solution.maxArea(nums) << endl;
}