#pragma once
#include <vector>
#include <iostream>
#include "basic.h"

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

