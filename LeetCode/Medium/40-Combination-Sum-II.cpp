class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // Move to i + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i], i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        backtrack(candidates, target, 0, current);

        return result;
    }
};
