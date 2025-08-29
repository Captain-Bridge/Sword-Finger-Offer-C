#include <stack>
#include <string>
class Solution {
public:
    string ReverseSentence(string str) {
        stack<string> st;
        string word = "";
        for(char i : str){
            if(i!=' '){
                word+=i;
            }else{
                st.push(word);
                st.push(" ");
                word = "";
            }
        }
        st.push(word);
        string ans = "";
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};