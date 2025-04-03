#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int LCS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = 0;
        
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int streak = 1;
                
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    streak++;
                }
                
                ans = max(ans, streak);
            }
        }
        
        return ans;
    }
};
