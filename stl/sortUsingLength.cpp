bool compare(string &a, string &b){
    return a.size()>b.size();
}

class Solution {
public:
    
  
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        
        for(int i = 0; i<words.size(); i++)
            cout<<words[i]<<" ";
        cout<<endl;
        return 0;
    }
};