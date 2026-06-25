class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        // simulate the reveal process in reverse
        deque<int> dq;
        for (int i = n - 1; i >= 0; i--) {
            if (!dq.empty()) {
                dq.push_front(dq.back()); // undo the "move bottom to top"
                dq.pop_back();
            }
            dq.push_front(deck[i]); // place the next largest card on top
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
