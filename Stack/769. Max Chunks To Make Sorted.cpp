
/*




https://leetcode.com/problems/max-chunks-to-make-sorted/



*/


class Solution {
public:

    vector<int>br;
    int ans = 1;

    bool check(vector<int> temp,int p){
        sort(temp.begin(),temp.end());
        int i=p,j=0;
        while(i<br.size() && j<temp.size()){
            if(br[i]!=temp[j]) return false;
            ++i;
            ++j;
        }
        return true;
    }

    void Solve( vector<int>&arr , int start_idx ,int count, vector<int>temp ,int p_arry_idx  ){
        if(start_idx >= arr.size()){
            ans = max(ans , count);
            return;
        }

        for( int i = start_idx ; i < arr.size() ; ++i ){
             temp.push_back(arr[i]);
             if(check(temp , p_arry_idx )){
                 vector<int>v;
                 Solve(arr , i+1,count + 1 , v ,  p_arry_idx + temp.size() );
             }
        }
    }

    int maxChunksToSorted(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) br.push_back(i);
        vector<int> temp;
        Solve(arr,0,0,temp,0);
        return ans;
    }
};