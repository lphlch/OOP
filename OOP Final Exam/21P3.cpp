#include <iostream>
using namespace std;
int main(){
	int n,s,e;
	cin>>n>>s>>e;
	int sum=0;

	int si[10000],ei[10000],ci[10000];
	bool time[10000]={false};
	for (int i = 0; i < n; i++)
	{
		cin>>si[i]>>ei[i]>>ci[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = si[i]; j < ei[i]; j++)
		{
			time[j]=true;
		}

		for (int j = s; j < e; j++)
		{
			if(time[j]==false)
			{
				break;
			}
		}

		sum+=ci[i];
	}


	cout<<sum;

}