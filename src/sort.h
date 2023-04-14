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
	void process(std::vector<int>& vec, int l, int r)
	{
		if (l == r)
		{
			return;
		}
		int mid = l + ((r - l) >> 1);
		process(vec, l, mid);
		process(vec, mid + 1, r);
		merge(vec, l, mid, r);
	}
	void mergesort(std::vector<int>& vec)
	{
		process(vec, 0, vec.size() - 1);
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

}
