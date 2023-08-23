class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if((n%2==0 and mp[i]>n/2) or (n%2!=0 and mp[i]>(n+1)/2)){
                return "";
            }
        }
        string ans;
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<26;i++){
            if(mp[i]>0){
                pq.push(make_pair(mp[i],i));
            }
        }
        for(int i=0;i<n;i++){
            ans+=" ";
        }
        int j=0;
        int i=0;
        auto tp=pq.top();
        pq.pop();
        while(i<n){
            if(tp.first>0){
                ans[i]=tp.second+'a';
                tp.first--;
                i+=2;
            }
            else{
                tp=pq.top();
                pq.pop();
            }
        }  
        i=1;
        while(i<n){
            if(tp.first>0){
                ans[i]=tp.second+'a';
                tp.first--;
                i+=2;
            }
            else{
                tp=pq.top();
                pq.pop();
            }
        }  
        return ans;
        
    }
};
