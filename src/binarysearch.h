#pragma once
#include <vector>


namespace b_s
{
	//有序数组，找>=某个数最左侧的位置
	int process1(const std::vector<int>& vec, int num, int l, int r)
	{
		if (l == r)
		{
			return vec[l] >= num ? l : INT32_MAX;
		}
		int mid = l + (r - l) / 2;
		if (vec[mid] < num)
		{
			return process1(vec, num, mid + 1, r);
		}
		else
		{
			return std::min(process1(vec, num, mid + 1, r), process1(vec, num, l, mid));
		}
	}
	int f_n_ml(const std::vector<int>& vec, int num)
	{
		return process1(vec, num, 0, vec.size() - 1);
	}

	//无序数组，任意相邻两个数一定不等，只需求任意一个局部最小值
	bool is_pm(const std::vector<int>& vec, int p)
	{
		if (p == 0)
		{
			return vec[0] < vec[1];
		}
		else if (p == vec.size() - 1)
		{
			return vec[p] < vec[p - 1];
		}
		else
		{
			return vec[p] < vec[p - 1] && vec[p] < vec[p + 1];
		}
	}
	int process2(const std::vector<int>& vec, int l, int r)
	{
		if (l == r)
		{
			return is_pm(vec, l) ? l : -1;
		}
		int mid = l + (r - l) / 2;
		int v_m = vec[mid];
		if (is_pm(vec, mid))
		{
			return mid;
		}
		else if (vec[l] <= vec[mid])
		{
			return process2(vec, l, mid);
		}
		else if (vec[r] <= vec[mid])
		{
			return process2(vec, mid + 1, r);
		}
		else
		{
			int p1 = process2(vec, l, mid);
			int p2 = process2(vec, mid + 1, r);
			return p1 == -1 ? (p2 == -1 ? -1 : p2) : p1;
		}
	}
	int f_p_m(const std::vector<int>& vec)
	{
		return process2(vec, 0, vec.size() - 1);
	}
}