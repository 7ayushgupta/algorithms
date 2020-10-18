#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int test_case(int n)
{
	    int flag=1;
	    if(floor(log2(n))==ceil(log2(n)))
		    flag=-1;
	    long long int sol[n]={0};
	    if(flag)
	    {
	        if(n==1)
	        sol[0]=1;
	        else if(n==3)
	        {
	            sol[0]=2;
	            sol[1]=3;
	            sol[2]=1;
	        }
	        else if(n>3)
	        {
	            sol[0]=2;
	            sol[1]=3;
	            sol[2]=1;
	            for(long long int i=3;i<n;i++)
	            {
	                if(floor(log2(i))==ceil(log2(i)))
	                sol[i]=i;
	                else if((floor(log2(i+1))==ceil(log2(i+1))))
	                sol[i]=i+2;
	                else
	                sol[i]=i+1;
	            }
	        }
	    }
	    if(flag==-1)
	    {
		    cout<<-1<<endl;
		    return -1;
	    }
	    // else
	    // {
	    //     for(int i=0;i<n;i++)
	    //     {
	    //         cout<<sol[i]<<" ";
	    //     }
	    //     cout<<endl;
	    // }
	    flag=1;
		for(int i = 0; i<n-1 && flag==1; i++)
		    if((sol[i]&sol[i+1])<=0)
		        flag=0;
	    return flag;
}

int main() {
   int N_limit=100000;
   for(int i = 1; i<=N_limit; i++)
   {
        int answer = test_case(i);
        if(answer==-1)
            cout<<i<<" "<<"is a 2s power"<<endl;
        else if(answer==0)
            cout<<i<<" "<<"is a wrong answer"<<endl;
   }
}