#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    public:
        NumArray(vector<int> &nums) {
            if (nums.size() == 0) return;
            nums_sum.push_back(nums[0]);
            for (int i = 1; i < nums.size(); ++i) {
                nums_sum.push_back(nums_sum.back() + nums[i]);
            }
        }

        int sumRange(int i, int j) {
            if (i == 0) return nums_sum[j]; 
            return nums_sum[j] - nums_sum[i-1];
        }

    private:
        vector<int> nums_sum;
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    NumArray na(v);
    cout << na.sumRange(1,6);
}
