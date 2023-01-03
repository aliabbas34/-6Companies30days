class Solution {
public:
// the pattern of the problem is based on longest increasing subsequence (dp problem)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> arr=nums;//coz we don't want to modify the given array
        int n=arr.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> tmp;
        tmp.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            tmp.push_back(arr[lastIndex]);
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};