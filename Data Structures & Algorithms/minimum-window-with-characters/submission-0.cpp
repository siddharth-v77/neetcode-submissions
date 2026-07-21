class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return "";
        }
        vector<int> vec(128,0);
        for (int i=0; i<t.length();i++){
            vec[t[i]]++; }

            int rem = t.length();
            int minlen = INT_MAX;
            int l=0 , r=0;
            int minleft=0;

            while(r < s.length()){
                if(--vec[s[r]]>=0){
                    rem--;
                }
                r++;
                while(rem == 0){
                    if(r-l<minlen){
                        minlen = r-l;
                        minleft = l;
                        if(minlen == t.length()){
                            return s.substr(minleft,minlen);
                        }
                    }
                    if(++vec[s[l]]>0) rem++; l++;
                }
            }
            return  (minlen == INT_MAX) ? "" : s.substr(minleft,minlen);
       
        
    }
}; 