class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore majority vote: O(n) time, O(1) space
        int cand = 0, count = 0;
        for (int x : nums) {
            if (count == 0) { cand = x; count = 1; }
            else if (x == cand) count++;
            else                count--;
        }
        return cand;
    }
};
