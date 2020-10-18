class Solution
{
public:
   
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void helper(vector<vector<int>> &final, vector<int> &nums, int l, int h)
	{
		if (l == h) // Base condtion.
		{
			final.push_back(nums);
			return;
		}
		else
		{
			for (int i = l; i < h; i++)
			{
				swap(nums[i], nums[l]); // this actually does swapping for us.
				helper(final, nums, l + 1, h);
				swap(nums[i], nums[l]); // this actually help us to get back to where we before swapping.
			}
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		vector<vector<int>> final;
		helper(final, nums, 0, nums.size());
		return final;
	}
};