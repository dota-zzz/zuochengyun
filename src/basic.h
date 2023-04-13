#pragma once
#include <vector>
#include <random>
#include <functional>


//左闭右开
static std::vector<std::vector<int>> random_vec_generator(int num, int vec_size = 50000, int min = -50000, int max = 50000)
{
	std::random_device seed;//硬件生成随机数种子
	std::ranlux48 engine(seed());//利用种子生成随机数引擎
	std::uniform_int_distribution<> sizedistrib(0, vec_size);//设置随机数范围，并为均匀分布
	std::uniform_int_distribution<> contentdistrib(min, max);//设置随机数范围，并为均匀分布

	std::vector<std::vector<int>> res(num);
	for (int i = 0; i < num; ++i)
	{
		int v_s = sizedistrib(engine);
		res[i] = std::vector<int>(v_s);
		for (int j = 0; j < v_s; ++j)
		{
			res[i][j] = contentdistrib(engine);
		}
	}
	return res;
}

static void print_vec(const std::vector<int>& vec)
{
	for (auto x : vec)
	{
		std::cout << x << " ";
	}
}

static void swap(std::vector<int>& vec, int i, int j)
{
	int c = vec[i];
	vec[i] = vec[j];
	vec[j] = c;
}