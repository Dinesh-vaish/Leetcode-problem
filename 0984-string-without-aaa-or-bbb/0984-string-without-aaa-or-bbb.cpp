class Solution {
public:
   string strWithout3a3b(int a, int b) { 
    string result = ""; 
    while (a > 0 || b > 0) { 
        bool writeA = false;
        int n = result.size();
                if (n >= 2 && result[n-1] == result[n-2]) { 
            if (result[n-1] == 'b') {
                writeA = true; 
            }
        } 
        else { 
            if (a > b) {
                writeA = true;
            }
        } 
        if (writeA) { 
            result += 'a'; 
            a--; 
        } else { 
            result += 'b'; 
            b--; 
        } 
    } 
    return result; 
}
};