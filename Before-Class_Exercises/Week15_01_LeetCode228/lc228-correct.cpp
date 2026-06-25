class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            // extend while the next number is consecutive
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;
            if (nums[i] == start)
                res.push_back(to_string(start));          // single number
            else
                res.push_back(to_string(start) + "->" + to_string(nums[i])); // range
        }
        return res;
    }
};
