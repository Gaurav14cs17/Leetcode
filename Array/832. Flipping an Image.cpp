
/*

https://leetcode.com/problems/flipping-an-image/
*/


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int n = image.size();
        vector<vector<int>>rev_temp;
        vector<vector<int>>ans;


        for(int i = 0  ; i<image.size() ; ++i ){
            int m = image[i].size();
            vector<int>temp;
            while(m)
                temp.push_back(image[i][--m]);
            rev_temp.push_back(temp);
        }

        for(int i = 0 ; i<rev_temp.size() ; ++i ){
            vector<int>v;
            for(int j = 0 ; j<rev_temp[i].size() ; ++j )
                v.push_back(rev_temp[i][j]^1);
            ans.push_back(v);
        }

        return ans;
    }
};