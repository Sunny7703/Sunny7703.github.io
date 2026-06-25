class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max-heap: always smash the two heaviest
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) pq.push(a - b); // leftover goes back
        }
        return pq.empty() ? 0 : pq.top();
    }
};
