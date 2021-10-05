/*
    Find out the number of ways of decoding the message.
    Input-"226" 
    Output-3
     "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
#include<bits/stdc++.h>
using namespace std;
//Dp solution
int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') dp[i]=0; //0 can't be encoded
            else {
                dp[i] = dp[i+1]; 
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
            }
        }
        return s.empty()? 0 : dp[0];   
    }