#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    struct node {
        int st;
        int ed;
    } a[10005];

    static bool cmp(const node& a, const node& b) {
        if (a.st != b.st) {
            return a.st < b.st;
        }
        return a.ed < b.ed;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        for(int i = 0;i < intervals.size();i++){
            a[i].st = intervals[i][0];
            a[i].ed = intervals[i][1];
        }
        int n = (int)intervals.size();
        sort(a, a + n, cmp);
        int end = a[0].ed;
        int start = a[0].st;
        a[n].st = 1e5;
        a[n].ed = 1e5;
        for(int i =1;i <= intervals.size();i++){
            if(a[i].st <= end){
                end = max(end, a[i].ed);
            }else{
                ans.push_back({start, end});
                start = a[i].st;
                end = a[i].ed;
            }
        }
        return ans;
    }
};
