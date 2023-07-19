//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};
    
    void solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, string temp,
    vector<vector<bool>>& visited, vector<int> di, vector<int> dj ) {
        
        if(i == n-1 && j == n-1) {
            ans.push_back(temp);
            return;
        }
        
        string dir = "DRUL";
        
        for(int idx = 0; idx < 4; idx++) {
            int x = i + di[idx];
            int y = j + dj[idx];
            
            if(x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && m[x][y] == 1) {
                
                visited[i][j] = true;
                solve(x, y, m, n, ans, temp + dir[idx], visited, di, dj);
                visited[i][j] = false;
                
            }
        }

    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
       
       vector<string> ans;
       string temp = "";
       
       vector<vector<bool>> visited(n, vector<bool>(n, false));
       
       if(m[0][0] == 1) {
           solve(0, 0, m, n, ans, temp, visited, di, dj);
       }
       
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends