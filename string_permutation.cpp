#include <iostream>
#include <cstring>
#include<algorithm>

using namespace std;

int n=0;

void permute(char *s,int left, int right);

void permute(char *s,int left, int right)
{
	if(left==right){
       n++;
		cout<<s<<endl;
	}


	else
		for(int i=left;i<=right;i++)
		{
			swap(s[0+left],s[0+i]);
			permute(s,left+1,right);
			swap(s[0+left],s[0+i]);
		}
}

int main()
{
	char s[100];
	cin>>s;

    permute(s,0,int(strlen(s)-1));

    cout<<n<<endl;
}

