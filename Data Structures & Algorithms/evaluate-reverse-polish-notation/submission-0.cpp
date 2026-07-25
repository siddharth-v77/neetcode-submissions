class Solution {
public:

     int operate(int a, int b , string token){
            if( token == "+") 
            return a+b ;

             if( token == "*") 
            return (long)a* (long)b ;

             if( token == "-") 
            return b-a;

             if( token == "/") 
            return b/a ;
            
            else return -1;
        }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
       
        for(int i=0; i<tokens.size();i++){
            
             if(tokens[i] == "+"||
                tokens[i] == "*"||
                tokens[i] == "-"||
                tokens[i] == "/"){
                 int a =st.top();
                 st.pop();

                 int b =st.top();
                 st.pop();

                 int ans = operate(a,b,tokens[i]);
                 st.push(ans);
                }

                else st.push(stoi(tokens[i]));
        }     
        return st.top();  
    }
};