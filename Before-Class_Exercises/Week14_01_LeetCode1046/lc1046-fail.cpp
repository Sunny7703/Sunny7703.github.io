class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());



        return pq.empty() ? 0 : pq.top();
    }
};
