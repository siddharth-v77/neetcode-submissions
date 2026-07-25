class Solution {
public:

    //  int operate(int a, int b , string token){
    //         if( token == "+") 
    //         return a+b ;

    //          if( token == "*") 
    //         return (long)a* (long)b ;

    //          if( token == "-") 
    //         return b-a;

    //          if( token == "/") 
    //         return b/a ;
            
    //         else return -1;
    //     }

    unordered_map<string ,function<int (int,int)>> mp ={
        {"+", [](int a, int b){return a+b;}},
        {"-" ,[](int a, int b) {return b-a;}},
        {"*",[](int a, int b) {return (long)a*(long)b;}},
        {"/",[](int a,int b) {return b/a;}},

    };

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

                 int ans = mp[tokens[i]](a,b);
                 st.push(ans);
                }

                else st.push(stoi(tokens[i]));
        }     
        return st.top();  
    }
};