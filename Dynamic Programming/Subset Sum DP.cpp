//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        //sort(arr.begin(), arr.end());
        vector <bool> dp(sum+1),prev(sum+1), cur(sum+1);
        dp[0] = prev[0] = 1;
        for(int j = 1; j <= sum; j++) prev[j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(arr[i-1] > j) cur[j] = prev[j];
                else cur[j] = prev[j] || prev[j - arr[i-1]];
            }
            prev = cur;
        }
        return cur[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends