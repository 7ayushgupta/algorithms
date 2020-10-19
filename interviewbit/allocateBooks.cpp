bool isPossible(vector<int> &A,long long int X,int B){
    int n=A.size();
    long long int sum=X;
    int stdcnt=1,i=0;
    while(i<n){
        if(sum-A[i]<0){
            stdcnt++;
            sum=X;
        }
        else {
            sum-=A[i];
            i++;
        }
        
        if(stdcnt>B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    if(n<B) return -1;
    long long int pages=0;
    for(int i=0;i<n;i++)
     pages+=A[i];
    long long int low=0,high=pages;
    long long int mid,ans=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(isPossible(A,mid,B)){
         ans=mid;
         high=mid-1;
        }
        else
         low=mid+1;
    }
    return ans;
}