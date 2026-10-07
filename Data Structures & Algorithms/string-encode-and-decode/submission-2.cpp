class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(auto x : strs){
            ans+= to_string(x.size()) + '#' + x ;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0,n= s.size();

        while(i<n){
            int j = i;
            while(s[j]!= '#') j++ ;
            int len = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+1+len;
        }
        return ans;
    }
};
