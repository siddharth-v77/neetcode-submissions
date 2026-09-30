class Solution {
public:

vector<string> getngbr(string word , unordered_set<string> &st){
    vector<string> ngbr;

    for(int i = 0 ; i < word.size() ; i++){
        for ( char ch = 'a' ; ch <= 'z' ; ch++){

            if(ch == word[i]){
                continue;
            }
            string newword = word.substr(0,i) + ch + word.substr(i+1);

            if(st.count(newword)) ngbr.push_back(newword);
        }
    }
    return ngbr;
}

    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        unordered_set<string> st(wordlist.begin() , wordlist.end());

        if(!st.count(endword)){
            return 0;
        }

        queue<string> q;

        q.push(beginword);
        if(st.count(beginword)){
            st.erase(beginword);
        }
int level = 0 ;
        while(!q.empty()){
            int currlevel = q.size();

            for(int i = 0 ; i < currlevel ; i++){

                string node = q.front();
                q.pop();
                
                if(node == endword){
                    return level+1;
                }

                vector<string> ngbr = getngbr(node, st);

                for( auto word : ngbr){
                    if(st.count(word)){
                        q.push(word);

                        st.erase(word);
                    }
                }
            }
            level++;
        }
        return 0 ;
    }
};