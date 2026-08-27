#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, int> mp1;
        map<int, int> mp2;

        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0) mp1[i] = 1, mp2[j] = 1;
            }
        }

        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(mp1[i] || mp2[j]) matrix[i][j] = 0;
            }
        }
    }
};
