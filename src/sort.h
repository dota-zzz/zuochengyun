#pragma once
#include <vector>
#include <iostream>
#include "basic.h"


namespace sort {

	//冒泡排序
	void bubblesort(std::vector<int>& vec)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = 0; j < vec.size() - i - 1; ++j)
			{
				if (vec[j] > vec[j + 1])
				{
					swap(vec, j, j + 1);
				}
			}
		}
	}

	//选择排序
	void selectionsort(std::vector<int>& vec)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			int min_index = i;
			for (int j = i + 1; j < vec.size(); ++j)
			{
				if (vec[j] < vec[min_index])
				{
					min_index = j;
				}
			}
			swap(vec, i, min_index);
		}
	}


	//归并排序
	void merge(std::vector<int>& vec, int l, int mid, int r)
	{
		std::vector<int> c;
		int l1 = l;
		int l2 = mid + 1;
		while (l1 <= mid && l2 <= r)
		{
			if (vec[l1] <= vec[l2])
			{
				c.push_back(vec[l1]);
				++l1;
			}
			else
			{
				c.push_back(vec[l2]);
				++l2;
			}
		}
		if (l1 > mid)
		{
			for (; l2 <= r; ++l2)
			{
				c.push_back(vec[l2]);
			}
		}
		else
		{
			for (; l1 <= mid; ++l1)
			{
				c.push_back(vec[l1]);
			}
		}
		std::copy(c.begin(), c.end(), vec.begin() + l);
	}
	void m_process(std::vector<int>& vec, int l, int r)
	{
		if (l == r)
		{
			return;
		}
		int mid = l + ((r - l) >> 1);
		m_process(vec, l, mid);
		m_process(vec, mid + 1, r);
		merge(vec, l, mid, r);
	}
	void mergesort(std::vector<int>& vec)
	{
		m_process(vec, 0, vec.size() - 1);
	}

	//求小和问题
	//在一个数组中，每一个数左边比该数小的数累加起来，叫做这个数组的小和，求一个数组的小和
	void merge1(std::vector<int>& vec, int l, int mid, int r, int& s_m)
	{
		std::vector<int> c;
		int l1 = l;
		int l2 = mid + 1;
		while (l1 <= mid && l2 <= r)
		{
			if (vec[l1] < vec[l2])
			{
				c.push_back(vec[l1]);
				++l1;
			}
			else
			{
				c.push_back(vec[l2]);
				for (int i = l; i < l1; ++i)
				{
					s_m += vec[i];
				}
				++l2;
			}
		}
		if (l1 > mid)
		{
			for (; l2 <= r; ++l2)
			{
				c.push_back(vec[l2]);
				for (int i = l; i < l1; ++i)
				{
					s_m += vec[i];
				}
			}
		}
		else
		{
			for (; l1 <= mid; ++l1)
			{
				c.push_back(vec[l1]);
			}
		}
		std::copy(c.begin(), c.end(), vec.begin() + l);
	}
	void process1(std::vector<int>& vec, int l, int r, int& s_m)
	{
		if (l == r)
		{
			return;
		}
		int mid = l + ((r - l) >> 1);
		process1(vec, l, mid, s_m);
		process1(vec, mid + 1, r, s_m);
		merge1(vec, l, mid, r, s_m);
	}
	int f_s_s(const std::vector<int>& vec)
	{
		int res = 0;
		auto v = vec;
		process1(v, 0, vec.size() - 1, res);
		return res;
	}

	//逆序对问题
	//在一个数组中，左边的数如果比右边的数大，则折两个数构成一个逆序对，请打印所有逆序对
	void f_r_ps_merge(std::vector<int>& vec, int l, int mid, int r, std::vector<std::pair<int, int>>& p_v)
	{
		std::vector<int> c;
		int l1 = l;
		int l2 = mid + 1;
		while (l1 <= mid && l2 <= r)
		{
			if (vec[l1] <= vec[l2])
			{
				c.push_back(vec[l1]);
				++l1;
			}
			else
			{
				c.push_back(vec[l2]);
				for (int i = l1; i <= mid; ++i)
				{
					p_v.push_back(std::pair<int, int>(vec[l2], vec[i]));
				}
				++l2;
			}
		}
		if (l1 > mid)
		{
			for (; l2 <= r; ++l2)
			{
				c.push_back(vec[l2]);
			}
		}
		else
		{
			for (; l1 <= mid; ++l1)
			{
				c.push_back(vec[l1]);
			}
		}
		std::copy(c.begin(), c.end(), vec.begin() + l);
	}
	void f_r_ps_process(std::vector<int>& vec, int l, int r, std::vector<std::pair<int, int>>& p_v)
	{
		if (l == r)
		{
			return;
		}
		int mid = l + ((r - l) >> 1);
		f_r_ps_process(vec, l, mid, p_v);
		f_r_ps_process(vec, mid + 1, r, p_v);
		f_r_ps_merge(vec, l, mid, r, p_v);
	}
	void f_r_ps(const std::vector<int>& vec)
	{
		std::vector<int> vec_ = vec;
		std::vector<std::pair<int, int>> v;
		f_r_ps_process(vec_, 0, vec.size() - 1, v);
		for (auto& x : v)
		{
			std::cout << "(" << x.first << "," << x.second << ")" << std::endl;
		}
	}

	//堆排序
	//i位置左孩子2*i+1,右孩子2*i+2,父(i-1)/2
	void heap_insert(std::vector<int>& vec, int index)
	{
		while (index > 0)
		{
			int father = (index - 1) >> 1;
			if (vec[father] < vec[index])
			{
				swap(vec, index, father);
				index = father;
			}
			else
			{
				break;
			}
		}
	}
	void heapify(std::vector<int>& vec, int index, int heapsize)
	{
		int lc = 2 * index + 1;
		while (lc < heapsize)
		{
			int rc = lc + 1;
			int large_index = lc;
			if (rc < heapsize)
			{
				large_index = vec[rc] > vec[lc] ? rc : lc;
			}
			if (vec[index] < vec[large_index])
			{
				swap(vec, large_index, index);
				index = large_index;
				lc = 2 * index + 1;
			}
			else
			{
				break;
			}
		}
	}
	void heap_sort(std::vector<int>& vec)
	{
		int vsize = vec.size();
		std::vector<int> v(vsize);
		for (int i = 0; i < vsize; ++i)
		{
			v[i] = vec[i];
			heap_insert(v, i);
		}
		int heapsize = vsize;
		while (heapsize > 0)
		{
			vec[heapsize - 1] = v[0];
			swap(v, 0, heapsize - 1);
			--heapsize;
			heapify(v, 0, heapsize);
		}

	}

	//快速排序
	//version1 选最后一个值为划分值，且分为两部分（<=,>）
	int dutch_flag(std::vector<int>& vec, int l, int r, int num)
	{
		int i = l;
		int res = l - 1;
		while (i <= r)
		{
			if (vec[i] <= num)
			{
				swap(vec, i, res + 1);
				++res;
			}
			++i;
		}
		return res;
	}
	void q_process(std::vector<int>& vec, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int lo = dutch_flag(vec, l, r - 1, vec[r]);
		swap(vec, r, lo + 1);
		q_process(vec, l, lo);
		q_process(vec, lo + 2, r);
	}
	void quick_sort(std::vector<int>& vec)
	{
		q_process(vec, 0, vec.size() - 1);
	}

	//version2 选最后一个为划分值，且分为三部分(<,=,>)
	std::pair<int, int> dutch_flag_t(std::vector<int>& vec, int l, int r, int num)
	{
		int i = l;
		auto res = std::pair<int, int>{ l - 1,r + 1 };
		while (i <= r && res.first + 1 < res.second)
		{
			if (vec[i] < num)
			{
				swap(vec, res.first + 1, i);
				res.first = res.first + 1;
				++i;
			}
			else if (vec[i] == num)
			{
				++i;
			}
			else
			{
				swap(vec, res.second - 1, i);
				res.second = res.second - 1;
			}
		}
		return res;
	}
	void q_process_v2(std::vector<int>& vec, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		auto lo = dutch_flag_t(vec, l, r - 1, vec[r]);
		swap(vec, r, lo.second);
		q_process(vec, l, lo.first);
		q_process(vec, lo.second + 1, r);
	}
	void quick_sort_v2(std::vector<int>& vec)
	{
		q_process_v2(vec, 0, vec.size() - 1);
	}

	//version3 随机选取划分值，且分为三部分(<,=,>)
	void q_process_v3(std::vector<int>& vec, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int num = random_int(l, r);
		swap(vec, num, r);
		auto lo = dutch_flag_t(vec, l, r - 1, vec[r]);
		swap(vec, r, lo.second);
		q_process(vec, l, lo.first);
		q_process(vec, lo.second + 1, r);
	}
	void quick_sort_v3(std::vector<int>& vec)
	{
		q_process_v3(vec, 0, vec.size() - 1);
	}

	//计数排序
	void counting_sort(std::vector<int>& vec)
	{
		int min = INT_MAX;
		int max = INT_MIN;
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] < min)
			{
				min = vec[i];
			}
			if (vec[i] > max)
			{
				max = vec[i];
			}
		}
		std::vector<int> counting_vec(max - min + 1);
		for (int i = 0; i < vec.size(); ++i)
		{
			++counting_vec[vec[i] - min];
		}
		vec.clear();
		for (int i = 0; i < counting_vec.size(); ++i)
		{
			for (int j = 0; j < counting_vec[i]; ++j)
			{
				vec.push_back(min + i);
			}
		}
	}

	//基数排序
	void radix_sort(std::vector<int>& vec)
	{
		int max = INT_MIN;
		for (auto x : vec)
		{
			if (x > max)
			{
				max = x;
			}
		}
		int max_bit = 0;
		while (max != 0)
		{
			max /= 10;
			++max_bit;
		}
		std::vector<int> cache(vec);
		for (int i = 0; i < max_bit; ++i)
		{
			std::vector<int> count(10);
			for (int j = 0; j < vec.size(); ++j)
			{
				int cur = (vec[j] / int(pow(10, i))) % 10;
				count[cur]++;
			}
			for (int k = 1; k < count.size(); ++k)
			{
				count[k] = count[k] + count[k - 1];
			}
			for (int l = vec.size() - 1; l >= 0; --l)
			{
				int cur = (vec[l] / int(pow(10, i))) % 10;
				cache[count[cur] - 1] = vec[l];
				count[cur]--;
			}
			vec = cache;
		}

	}
}
