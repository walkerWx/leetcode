#include <vector>

class Solution {
    public:
        int majorityElement (vector<int>& nums) {
            int candidate = 0;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (count == 0) {
                    ++count;
                    candidate = nums[i];
                } else if (candidate == nums[i]) {
                    ++count; 
                } else {
                    --count; 
                }
            }
            return candidate;
        }
};
