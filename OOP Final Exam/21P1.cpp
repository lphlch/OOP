#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    /**
    * 你的代码请写在这儿
    */
	vector<vector<int>> result;
	int len=nums.size();
	int flags[16]={0};	

	if(len==1)
	{
				vector<int> singleResult;
				singleResult.push_back(nums[0]);
				result.push_back(singleResult);
				return result;
	}

	/* 遍历置1 */
	for (int i = 0; i < pow(2,len); i++)
	{
		vector<int> singleResult;
		flags[0]++;
		for (int j = 0; j < 15; j++)
		{
			if(flags[j]>1)
			{
				flags[j]=0;
				flags[j+1]++;
			}
		}


		for (int i = 0; i < 16; i++)
		{
			//cout<<flags[i];
			if(flags[i]==1 && i<len)
			{
				singleResult.push_back(nums[i]);
			}
		}
		//cout<<endl;
		result.push_back(singleResult);
	}

	return result;
}

int main(){
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }
    auto result = subsets(nums);
    for (auto i = result.begin(); i < result.end(); i++){
        sort(i->begin(), i->end());
    }
    sort(result.begin(), result.end());
    for (auto result_it = result.cbegin(); result_it < result.cend(); result_it++){
        for (auto i_it = result_it->cbegin(); i_it < result_it->cend(); i_it++){
            cout << *i_it << " ";
        }
        cout << endl;
    }
	//getchar();
	//getchar();
}