/*
https://leetcode.com/problems/clumsy-factorial/
*/

class Solution {
public:
    int clumsy(int n) {

        stack<pair<int,string>>st;
        const char *s[4]  = {"*" , "/" , "+" , "-" };
        st.push({n," "});
        int cnt = 0;

        for( int i = n-1 ; i>0 ; --i ){

            if(s[cnt]=="*"){
                auto x = st.top();
                st.pop();
                st.push({ x.first*i , x.second});
                cnt = cnt+1;
                cnt = cnt%4;
            }
            else if(s[cnt]=="/"){
                auto x = st.top();
                st.pop();
                st.push({x.first/i ,x.second});

                cnt = cnt+1;
                cnt = cnt%4;
            }
            else if(s[cnt]=="+"){
                st.push({i ,"+"});
                cnt = cnt+1;
                cnt = cnt%4;
            }
            else if(s[cnt]=="-"){
                st.push({i,"-"});
                cnt = cnt+1;
                cnt = cnt%4;

            }

        }
        stack<pair<int , string>>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        int ans = st2.top().first ;
        st2.pop();

        while(!st2.empty()){
            if(st2.top().second == "-"){
                ans = ans - st2.top().first;
                st2.pop();
            }
            else if(st2.top().second == "+"){
                ans = ans + st2.top().first;
                st2.pop();
            }
        }



        return ans ;

    }
};