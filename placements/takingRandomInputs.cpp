#include <bits/stdc++.h>
using namespace std;

int main() {
	int i;
	cin>>i;
	cin.ignore();
	cout<<i<<endl;
// 	getline(cin, clearer_temp);
	string flights;
	getline(cin, flights);
    // getline(cin, clearer_temp);
	cout<<flights<<endl;
	string o;
	stringstream s1(flights);
	while(getline(s1, o, ']'))
	{
	    int left=0, right = o.size();
	    while(o[left]==',' || o[left]=='[')
	        left++;
	    while(o[right]==',' || o[right]==']')
	       {
	        cout<<o.substr(left, right-left+1)<<endl;
	        right--;
	       }
	    string ot = o.substr(left, right-left+1);
	    cout<<ot<<endl;
	    string temp;
	    stringstream s2(o);
	    int arr[3], t = 0;
	    while(getline(s2, temp, ','))
	        arr[t++]=stoi(temp);
	    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
	}
	int p, q;
	cin>>p>>q;
	cout<<p<<" "<<q;
	return 0;
}