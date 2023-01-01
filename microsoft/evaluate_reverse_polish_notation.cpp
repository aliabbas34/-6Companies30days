class Solution {
private:
    int conversionToInfixNotation(vector<string>& tokens){
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            //given that the string contains only integers or below mentioned four operators
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int rightOperand,leftOperand,evaluationOfTheEquation;
                string middleOperator;
                
                rightOperand=st.top();
                st.pop();
                leftOperand=st.top();
                st.pop();
                middleOperator=tokens[i];

                if(middleOperator=="+") evaluationOfTheEquation = leftOperand + rightOperand;
                if(middleOperator=="-") evaluationOfTheEquation = leftOperand - rightOperand;
                if(middleOperator=="*") evaluationOfTheEquation = leftOperand * rightOperand;
                if(middleOperator=="/") evaluationOfTheEquation = leftOperand / rightOperand;
                
                st.push(evaluationOfTheEquation);
            }
        }
        return st.top();
    }
public:
/*
the given string is postfix notation
so convert it into infix notation and solve it while converting
so at the end of conversion we will have the solved equation at the top of stack.
*/
    int evalRPN(vector<string>& tokens) {
        int ans=conversionToInfixNotation(tokens);
        return ans;
    }
};