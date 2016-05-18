#include <iostream>

bool isBadVersion(int version) {
    return version >= 1702766719;
}

class Solution {
    public:
        int firstBadVersion(int n) {
            int low = 1;
            int high = n;
            int mid;
            while (low <= high) {
                mid = low + (high - low) / 2 ;
                if (isBadVersion(mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low == mid + 1? low : mid;
        }
};

int main() {
    int n = 2126753390;
    std::cout << (n + 1) / 2;
    Solution s;
    std::cout << s.firstBadVersion(n);
}
