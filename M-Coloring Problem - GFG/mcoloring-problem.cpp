//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool issafe(int idx, bool graph[101][101], int color[], int c, int n) {
         
         for(int i=0; i<n; i++) {
             if(graph[i][idx] && c == color[i]) {
                 return false;
             }
         }
         
         return true;
    }
    
    
    bool solve(bool graph[101][101], int m, int color[], int n, int idx) {
          
         if(idx == n) {
             return true;
         } 
         
         for(int c=1; c<=m; c++) {
             if(issafe(idx, graph, color, c, n)) {
                 color[idx] = c;
             
                 if(solve(graph, m, color, n, idx+1)) {
                     return true;
                 }
                 
                 
                 color[idx] = 0;
             }
         }
         
         return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
         int color[n];
         
         for(int i=0; i<n; i++) {
             color[i] = 0;
         }
         
         if(solve(graph, m, color, n, 0)) {
             return true;
         }
         else {
             return false;
         }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends