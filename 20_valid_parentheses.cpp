#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') ss.push(s[i]);
            if(s[i] == ')') {
                if(ss.size() && ss.top() == '(') ss.pop();
                else return false;
            }
            if(s[i] == '}') {
                if(ss.size() && ss.top() == '{') ss.pop();
                else return false;
            }
            if(s[i] == ']') {
                if(ss.size() && ss.top() == '[') ss.pop();
                else return false;
            }
        }

        if(ss.size()) return false;
        return true;
    }
};
