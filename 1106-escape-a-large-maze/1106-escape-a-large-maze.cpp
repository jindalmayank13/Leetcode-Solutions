//Use unordered_set over pair with own Hash & DFS w.r.t Manhattan distance
class Solution {
public:
    struct MyHash
    {
        size_t operator()(const pair<int, int>& x) const
        {
            hash<int> f;
            size_t digest=f((x.first<<3)^(x.second));
            return digest; 
        }
    };
    unordered_set<pair<int, int>, MyHash> Blocked, Visit;
    bool dfs(int i, int j, int i0, int j0, int t_i, int t_j ){
        if (i==t_i && j==t_j) return true;
        int d=abs(i-i0)+abs(j-j0);
    //    cout<<"("<<i<<","<<j<<") d="<<d<<endl;
        if (d>=200) return true;
        Visit.insert({i, j});
        vector<pair<int, int>> adj={{i+1,j},{i, j+1},{i-1,j}, {i, j-1}};  
        for(auto& [a, b]: adj){
            if (a>=0 && a<1e6 && b>=0 && b<1e6 &&
            Visit.count({a, b})==0 && Blocked.count({a, b})==0)
            {
                if (dfs(a, b, i0, j0, t_i, t_j)) return true;
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
    {
        for (vector<int>& B: blocked){
            Blocked.insert({B[0], B[1]});
        }
        bool a=dfs(source[0], source[1], source[0], source[1],target[0], target[1]);
     //   cout<<"========\n";
        Visit.clear();
        bool b=dfs(target[0], target[1], target[0], target[1], source[0], source[1]);
        return a && b;
    }
};