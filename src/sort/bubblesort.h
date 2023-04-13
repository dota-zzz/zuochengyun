#pragma once
#include <vector>
#include <iostream>
#include "basic.h"

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

