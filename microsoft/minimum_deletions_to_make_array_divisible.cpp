class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans = -1;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int gcdd = *max_element(numsDivide.begin() , numsDivide.end());
        for(auto i:numsDivide)
        {
            gcdd = __gcd(gcdd , i);
        }
        cout<<gcdd<<"\n";
        for(int i=0;i<n;++i)
        {
            if(gcdd%nums[i] == 0)
            {
               ans = i;
                break;
            } 
        }
        return ans;
    }
};