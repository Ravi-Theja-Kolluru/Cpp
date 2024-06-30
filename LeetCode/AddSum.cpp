
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans;

        if (size < 3) {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }

        for (int i = 0; i < size; i++) {
            int val1 = nums[i];
            int val2 = target - val1;

            auto val2It = find(nums.begin(), nums.end(), val2);
            int val2Index = val2It - nums.begin();

            if ((val2Index != -1) && (i != val2Index)) {
                ans.push_back(i);
                ans.push_back(val2Index);
                return ans;
            }
        }

        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};


