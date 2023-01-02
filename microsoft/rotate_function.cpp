class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /*
        solution description
        f(0)=0*a[0]+1*a[1]+2*a[2]+.....+(n-1)*a[n-1]
        f(1)=0*a[n-1]+1*a[0]+2*a[1]+3*a[2]+.....+(n-1)*a[n-2]
        since, 2*a[1]-1*a[1]=a[1]
        hence,
        f(1)-f(0)=(a[0]+a[1]+a[2]+.....+a[n-2])-(n-1)a[n-1]
        f(1)-f(0)=(a[0]+a[1]+a[2]+.....+a[n-2])-(n*a[n-1]-1*a[n-1])
        f(1)-f(0)=(a[0]+a[1]+a[2]+.....+a[n-2])-n*a[n-1]+a[n-1]
        f(1)-f(0)=(a[0]+a[1]+a[2]+.....+a[n-2]+a[n-1])-n*a[n-1]
        let sum of all elements of nums equals to S, S=a[0]+a[1]+a[2]+.....+a[n-2]+a[n-1]
        f(1)-f(0)=S-n*a[n-1]
        f(1)=f(0)+S-n*a[n-1]

        hence we can say that,
        for f(i),

        "f(i)=f(i-1)+S+n*a[n-i]" 
        
        The brute force solution's time complexity would be O(n^2) hence the above given approach is used
        It has time complexity of O(n).
        */
        int n=nums.size();
        int sumOfNums=0;
        int F=0;
        for(int i=0;i<n;i++){
            F+=i*nums[i];//calculating f(0)
            sumOfNums+=nums[i];//calculating S(sum of all elements of nums)
        }
        int ans=F;
        for(int i=1;i<n;i++){
            F=F+(sumOfNums-(n*nums[n-i]));//f(i)=f(i-1)+S+n*a[n-i]
            ans=max(ans,F);//calculating max among all f(0),f(1),.....,f(n-1)
        }
        return ans;
    }
};