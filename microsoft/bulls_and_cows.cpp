class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;//number of bulls
        unordered_map<char,int> hashCountChar;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                x++;//counting bulls
                //modifying given value because they are passed by value so we have a copy of original strings here.
                secret[i]='x';
                guess[i]='y';
            }
            //hashing the guess string characters with frequency count.
            if(hashCountChar.find(guess[i])==hashCountChar.end()) hashCountChar[guess[i]]=1;
            else hashCountChar[guess[i]]++;
        }
        int y=0;//number of cows.
        for(int i=0;i<guess.length();i++){
            if(hashCountChar.find(secret[i])!=hashCountChar.end()){
                if(hashCountChar[secret[i]]>0){
                    y++;//counting cows
                    hashCountChar[secret[i]]--;//removing the already counted cow from the map
                }
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};