//Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    stack<char> topo;
    
    void toposort(unordered_map<char,list<char>> &lexical,
    unordered_map<char,bool> &visited,
    char ch){
        visited[ch]=true;
        for(auto neighbour: lexical[ch]){
            if(!visited[neighbour]) toposort(lexical, visited, neighbour);
        }
        topo.push(ch);
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        //run a loop through the dictionary and compare why a word comes before another
        //if one letter comes before another, then in adjacency list push the latter v to former
        unordered_map<char,list<char>> lexical;
        unordered_map<char,bool> visited;
        int first=0;
        int second=1;
        while(second<N){
            string fw= dict[first];
            string sw= dict[second];
            
            int ind=0;
            
            int maxind= min(fw.size(), sw.size());
            
            while(ind<maxind){
                if(fw[ind] == sw[ind]){
                    ind++;
                }
                else{
                    lexical[fw[ind]].push_back(sw[ind]);
                    break;
                }
            }
            first++;
            second++;
        }
        
        for(char ch='a'; ch<'a'+K; ch++){
            if(!visited[ch]) toposort(lexical, visited, ch);
        }
        
        string ans="";
        while(!topo.empty()){
            ans+=topo.top();
            topo.pop();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends