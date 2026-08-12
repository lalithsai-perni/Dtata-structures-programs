class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int l =0;
        int ans =0;
        for(int i =0 ; i<n;i++){
            mp[nums[i]]++;

            while(mp[nums[i]]>k){
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans , i-l+1);

        }
        return ans;

        
    }
};