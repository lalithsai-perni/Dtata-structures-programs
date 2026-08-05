class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>map;
        map[0]=1;

        int sum =0;
        int ans =0;
        int rem =0;

        for(int i =0 ;i <n;i++){
            sum+=nums[i];
            rem = sum%k;
            if(rem<0){
                rem +=k;
            }

            if(map.find(rem)!=map.end()){
                ans+=map[rem];
                map[rem]=map[rem]+1;
            }
            else{
                map[rem]=1;
            }
    
            
        }
        return ans;
        

    }
};