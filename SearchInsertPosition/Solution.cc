#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        int searchInsert(vector<int>& nums, int target) {
            int begin = 0; 
            int end = nums.size() - 1;
            int mid = 0;
            while (begin <= end) {
                mid = (begin + end) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    end = mid - 1;
                    continue;
                } else if (nums[mid] < target) {
                    begin = mid + 1;
                    continue;
                }
            }
            return mid == (end -1) ? mid : begin;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    int target = 2;
    Solution s;
    cout << s.searchInsert(nums, target); 
}
