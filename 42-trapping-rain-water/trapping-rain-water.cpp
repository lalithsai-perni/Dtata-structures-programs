class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int lmax,rmax,total,l=0,r;
        lmax=rmax=total=l=0;
        r=n-1;
        while(l<r){
            if(nums[l]<=nums[r]){
                if(lmax>=nums[l]){
                    total+=(lmax-nums[l]);
                }
                else{
                    lmax=nums[l];

                }

                l++;
            }
                else{
                    if(rmax>=nums[r]){
                        total+=(rmax-nums[r]);
                    }
                    else{
                        rmax=nums[r];
                    }
                    r--;
                }
            
        }
        return total;
    }
};