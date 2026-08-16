class Solution {
public:
vector<vector<int>> result;
void backtrack(int start, vector<int>& candidates, vector<int>& current,int total,int target){
    if(total == target){
        result.push_back(current);
        return;
    }
    if(total > target){
        return;
    }
    for(int i=start; i<candidates.size(); i++){
        current.push_back(candidates[i]);
        backtrack(i, candidates, current, total + candidates[i],target);
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(0, candidates, current, 0, target);
        return result;
    }
};