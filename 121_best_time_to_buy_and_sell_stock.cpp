#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = 10000;
        int maxn = 0;
        for(int i = 0;i< prices.size();i++){
            maxn = max(maxn, prices[i] - minn);
            if(prices[i] < minn){
                minn = prices[i];
            }
        }
        return maxn;
    }
};
