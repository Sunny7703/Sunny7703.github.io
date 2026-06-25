class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // count how many want 0 and how many want 1
        int count[2] = {0, 0};
        for (int s : students) count[s]++;
        // go through the sandwich stack top to bottom
        for (int i = 0; i < (int)sandwiches.size(); i++) {
            if (count[sandwiches[i]] == 0) return (int)sandwiches.size() - i;
            count[sandwiches[i]]--;
        }
        return 0;
    }
};
