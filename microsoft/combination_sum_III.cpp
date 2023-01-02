class Solution {
private:
    void combinations(int i,vector<int> &oneCombination,int sumOfCombination,int sizeOfCombination,vector<vector<int>>& ans,int n,int k){
        //base conditions
        if(sizeOfCombination==k){
            if(sumOfCombination==n) ans.push_back(oneCombination);
            return;
        }
        if(sumOfCombination>n) return;//edge case, when the sum exceeds n before reaching k digits
        if(i==10) return;//edge case, when i crosses 9

        //pick
        oneCombination.push_back(i);
        sumOfCombination+=i;
        sizeOfCombination++;
        combinations(i+1,oneCombination,sumOfCombination,sizeOfCombination,ans,n,k);

        //not pick
        oneCombination.pop_back();
        sumOfCombination-=i;
        sizeOfCombination--;
        combinations(i+1,oneCombination,sumOfCombination,sizeOfCombination,ans,n,k);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> oneCombination;
        combinations(1,oneCombination,0,0,ans,n,k);
        return ans;
    }
};