#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // 边界判断
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows); // 存储每一行，下标0开始
        int cr = 0; // 当前行（从0开始）
        int step = 1;    // 方向：1向下，-1向上

        for (char c : s) {
            rows[cr] += c;   // 字符放入当前行
            cr += step;      // 移动行号
            
            // 触顶/触底，反转方向
            if (cr == 0) {
                step = 1;
            } else if (cr == numRows - 1) {
                step = -1;
            }
        }

        // 拼接所有行
        string res;
        for (string& row : rows) {
            res += row;
        }
        return res;
    }
};
//Z字形变换是行1 2 3 2 1 2 3输入的