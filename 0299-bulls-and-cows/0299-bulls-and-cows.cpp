class Solution {
public:
    string getHint(string secret, string guess) {
        int f[10]={0};
        for(int i=0;i<secret.size();i++)
        {
            f[secret[i]-'0']++;
        }
    int cow=0;
    int bull=0;
    for(int i=0;i<guess.size();i++)
    {
        if(f[guess[i]-'0']>0){
            cow++;
            f[guess[i]-'0']--;
        }
    }
    for(int i=0;i<secret.size();i++)
    {
        if(guess[i]==secret[i])
        {
            bull++; cow--;
        }
    }
     return to_string(bull) + "A" + to_string(cow) +"B"; 
    }
};