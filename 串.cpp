class Solution {

private:
    queue<char>q;

public:

    Solution(){}

    string convert(string s, int numRows) {
        
        int i = 0;
        string x;
        for (char c : s) {
            if(c != ' '){
                  x+=c;
            }
        }
        return x;
    }
};