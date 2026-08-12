class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = nums[0]+nums[1]+nums[2];
        for(int i =0;i<n-2;i++){
            int l = i+1;
            int r = n-1;

            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(sum - target)<abs(ans - target)){
                    ans = sum;
                }
                if(sum<target){
                    l++;
                }
                else if (sum>target){
                    r--;
                }
                else{
                    return sum;
                }
            }
        }
        return ans;
        
    }
};