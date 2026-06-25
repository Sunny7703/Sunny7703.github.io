class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // difference array: mark +seats at start, -seats after end
        vector<int> diff(n + 1, 0);
        for (auto& b : bookings) {
            diff[b[0] - 1] += b[2]; // flight b[0] gets +seats
            if (b[1] < n) diff[b[1]] -= b[2]; // flight b[1]+1 gets -seats
        }
        // prefix sum to get actual totals
        vector<int> ans(n);
        ans[0] = diff[0];
        for (int i = 1; i < n; i++) ans[i] = ans[i-1] + diff[i];
        return ans;
    }
};
