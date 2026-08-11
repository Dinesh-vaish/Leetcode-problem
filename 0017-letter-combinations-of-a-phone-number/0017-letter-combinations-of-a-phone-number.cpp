class Solution {
public:
       vector<string> ans;

       string keypaid[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(string digits , int idx, string curr)
    {
        //base case
          if(idx==digits.size())
          {
            ans.push_back(curr);
            return;
          }
        string latters = keypaid[digits[idx]-'0'];
        for(char ch:latters)
        {
          //choose
        curr.push_back(ch);
        
        //Explore
        solve(digits,idx+1,curr);

        //backtriking
        curr.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};
        solve(digits,0,"");
        return ans;
    }
};