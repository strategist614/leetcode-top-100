#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        int a[35][35] = {};
        a[1][1] = 1;
        a[2][1] = 1;
        a[2][2] = 1;
        vector<vector<int>> ans;
        if(numRows >= 1)
        ans.push_back({1});
        if(numRows >= 2)
        ans.push_back({1,1});
        for(int i = 3;i <= numRows;i++){
            vector<int> _;
            for(int j = 1;j <= i;j++){
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                _.push_back(a[i][j]);
            }
            ans.push_back(_);
        }
        return ans;
    }
};
