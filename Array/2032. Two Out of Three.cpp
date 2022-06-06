/*
https://leetcode.com/problems/two-out-of-three/
*/


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();

        set<int>s;
        vector<int>ans;

        for(auto it : nums1)
            s.insert(it);

        for(auto it : nums2)
            s.insert(it);

        for(auto it : nums3)
            s.insert(it);

        for(auto it :  s ){
            int a = find(nums1.begin() , nums1.end(), it)  != nums1.end();
            int b = find(nums2.begin() , nums2.end() , it) != nums2.end();
            int c = find(nums3.begin() , nums3.end() , it) != nums3.end();

            if((a&&b) || (a&&c) || (b&&c))
                ans.push_back(it);
        }

        return ans;


    }
};