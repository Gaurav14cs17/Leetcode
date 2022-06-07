

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int>ans = prices;
        stack<int>s;

        int n = prices.size();
        for(int i = 0  ; i<n ; ++i ){

            if(s.empty() || prices[i] > prices[s.top()] ){
                s.push(i);
            }
            else{

                while(not s.empty() and  prices[i] <= prices[s.top()]){
                    int cur_idx = s.top();
                    ans[cur_idx] = (prices[cur_idx] - prices[i]);
                    s.pop();
                }
                s.push(i);
            }
        }

       return ans;
    }
};