class Solution {
public:
    void b(vector<string>&res,vector<string>&sub,string s,unordered_set<string>words,int idx){
        if(idx==s.size()){
            string ans = "";
            for(int i=0;i<sub.size();i++){
                if(i==sub.size()-1){
                    ans += sub[i];
                }
                else{
                    ans += sub[i];
                    ans += " ";
                }
            }
            res.push_back(ans);
        }
        for(int i=idx;i<s.size();i++){
            string candidate = s.substr(idx,i-idx+1);
            if(words.find(candidate)!=words.end()){
                sub.push_back(candidate);
                b(res,sub,s,words,i+1);
                sub.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<string> sub;
        unordered_set<string> words;
        for(string w:wordDict){
            words.insert(w);
        }
        b(res,sub,s,words,0);
        return res;
    }
};
