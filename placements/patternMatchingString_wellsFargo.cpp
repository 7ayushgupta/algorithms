//O(M+N) complexity for substring matching
#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string pat)
{
	int M = pat.size();
	int len = 0;
	int i = 1;
	vector<int> lps(M,0);

	while(i<M)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else{
				lps[i] = len;
				i++;
			}
		}
	}
	return lps;
}

int KMPSearch(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();
	vector<int> lps = computeLPSArray(pat);
	int i = 0, j =0;
	int res = 0;
	int next_i = 0;

	while(i<N)
	{
		if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
             
            // When we find pattern first time,
            // we iterate again to check if there
            // exists more pattern
            j = lps[j - 1];
            res++;
 
            // We start i to check for more than once
            // appearance of pattern, we will reset i
            // to previous start+1
            if (lps[j] != 0)
                i = ++next_i;
            j = 0;
        }
 
        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
             
            // Do not match lps[0..lps[j-1]] 
            // characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
	}
	return res;
}


int main(){
	string txt = "eekseeksgeeekseksforgeekseeeeeeekseeksekeeeeksks";
	string pat = "eeks";
	int ans = KMPSearch(pat, txt);	 
	cout << ans <<endl;
    return 0;
}