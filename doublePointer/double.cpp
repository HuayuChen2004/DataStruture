#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = nums[0];
        int minLen = nums.size()+1;
        while (right < nums.size()) {
            // cout << "left: " << left << " right: " << right << " sum: " << sum << endl;
            if (sum == target) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                }
                right++;
                left++;
                if (right >= nums.size()) break;
                sum += nums[right];
                sum -= nums[left-1];
            }
            else if (sum < target) {
                right++;
                if (right >= nums.size()) break;
                sum += nums[right];
            }
            else {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                }
                left++;
                sum -= nums[left-1];
            }
        }
        if (minLen == nums.size()+1) return 0;
        return minLen;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    Solution sol;
    int res = sol.minSubArrayLen(target, nums);
    cout << res << endl;
    return 0;
}
