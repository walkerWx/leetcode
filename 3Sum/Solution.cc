#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> result;
            std::vector<int> v;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (binary_search(-(nums[i]+nums[j]), j+1, nums.size()-1, nums)) {
                        v.clear();
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(-(nums[i]+nums[j]));
                        result.push_back(v);
                    }
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                        ++j; 
                    }         
                }

                while ( i + 1 < nums.size() && nums[i] == nums[i+1] ) {
                    ++i;   
                } 
            }
            return result;
       }

        bool binary_search(int target, int begin, int end, std::vector<int>& nums) {
            if (begin > end) {
                return false; 
            }

            int mid = (begin + end) / 2; 
            if (nums[mid] == target) {
                return true; 
            } else if (nums[mid] < target) {
                return binary_search(target, mid + 1, end, nums);     
            } else {
                return binary_search(target, begin, mid - 1, nums); 
            }
        }
};

int main() {
    std::vector<int> nums = {-1, -1,0,0, 0, 1, 2};
    Solution s;
    for (auto v : s.threeSum(nums)) {
        for (auto i : v) {
            std::cout << i << "\t"; 
        } 
        std::cout << std::endl;
    }
}
