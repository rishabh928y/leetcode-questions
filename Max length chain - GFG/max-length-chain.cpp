//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    static bool comp(val a, val b) {
        return a.second < b.second;
    }
    
    int maxChainLen(struct val p[],int n){
        sort(p, p+n, comp);
        int currend = p[0].second;
        int count = 1;
        
        for(int i=1; i<n; i++) {
            if(p[i].first > currend) {
                currend = p[i].second;
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends