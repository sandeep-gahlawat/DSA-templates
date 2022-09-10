#include<bits/stdc++.h>
using namespace std;
//trick lcs of given string ,reverse of given string
class Solution {
public:
    int lcs( string X, string Y )
{
        int m = X.size(),n = Y.size();
int L[m+1][n+1];
int i, j;
 
/* Following steps build L[m+1][n+1] in bottom up fashion. Note
    that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (i=0; i<=m; i++)
{
    for (j=0; j<=n; j++)
    {
    if (i == 0 || j == 0)
        L[i][j] = 0;
 
    else if (X[i-1] == Y[j-1])
        L[i][j] = L[i-1][j-1] + 1;
 
    else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
}
     
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
}
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        return lcs(s1,s2);
    }
};