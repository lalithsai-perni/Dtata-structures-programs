class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l =0;
        int r = n-1;
        int ans = 0;
        while (l<r){
            int area = (r-l)*min(height[l],height[r]);
            ans = max (ans , area);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
        
        
        
    }
};