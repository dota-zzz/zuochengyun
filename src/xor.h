#pragma once
#include <vector>

namespace xor {

	//交换
	void swap(std::vector<int>& vec, int i, int j)
	{
		if (vec[i] != vec[j])
		{
			vec[i] = vec[i] ^ vec[j];
			vec[j] = vec[i] ^ vec[j];
			vec[i] = vec[i] ^ vec[j];
		}
	}

	//数组中只有一个出现奇数次的数，求该数
	int f_o_n(const std::vector<int>& vec)
	{
		int odd_num = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			odd_num ^= vec[i];
		}
		return odd_num;
	}

	//数组中有两个出现奇数次的数，且不相同，求这两个数
	int get_right_one(int num)
	{
		return num & (~num + 1);
	}
	std::pair<int, int> f_o_ns(const std::vector<int>& vec)
	{
		int a = 0;
		int b = 0;
		int axorb = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			axorb ^= vec[i];
		}
		int r_o = get_right_one(axorb);
		for (int i = 0; i < vec.size(); ++i)
		{
			if ((r_o & vec[i]) != 0)
			{
				a ^= vec[i];
			}
		}
		b = axorb ^ a;
		return std::pair<int, int>(a, b);
	}
}
