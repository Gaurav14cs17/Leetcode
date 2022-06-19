/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

/*
int x = 0;
x = atoi(it.c_str());
*/

class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<string>st;
        for(int i = 0  ; i<s.size() ;  ++i ){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=="+"){
                    int x = atoi(st.top().c_str());
                    st.pop();

                    int y = atoi(st.top().c_str());
                    st.pop();

                    st.push(to_string(x + y));
                }
                else if(s[i]=="-"){
                    int x = atoi(st.top().c_str());
                    st.pop();

                    int y = atoi(st.top().c_str());
                    st.pop();

                    st.push(to_string(y - x ));
                }
                else if(s[i]=="*"){
                    int x = atoi(st.top().c_str());
                    st.pop();

                    int y = atoi(st.top().c_str());
                    st.pop();

                    st.push(to_string(x * y));
                }
                 else if(s[i]=="/"){
                    int x = atoi(st.top().c_str());
                    st.pop();

                    int y = atoi(st.top().c_str());
                    st.pop();

                    st.push(to_string(y/x));
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        int x = atoi(st.top().c_str());
        return x;
    }
};