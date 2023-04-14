#include "sort.h"
#include "xor.h"
#include "binarysearch.h"

int main()
{
	//测试排序
	auto vecs = random_vec_generator(1000, 1000, -5000, 5000);
	for (const auto& vec : vecs)
	{
		auto v1 = vec;
		auto v2 = vec;
		sort::heap_sort(v1);
		std::sort(v2.begin(), v2.end());
		if (v1 != v2)
		{
			std::cout << "g";
			print_vec(vec);
		}
	}

	//测试xor
	/*std::vector<int> x{ 1,1,1,2,2,3,3,120,120,0,0,0,0,99,99,-100,-100,-26,-26 };
	int res = f_o_n(x);
	std::vector<int> x1{ 1,1,1,2,2,3,3,120,120,0,0,0,0,99,99,-100,-100,-26,-26,-26 };
	auto res1 = f_o_ns(x1);*/

	//测试二分查找
	//std::vector<int> x{ 1,1,1,2,2,2,50,50,310,310,516541,23156314,1321565112 };
	//int p = b_s::f_n_ml(x, 1321565113);
	//std::vector<int> x{ 1,2,3,4,5,6,7,8,9,10 };
	//auto r = b_s::f_p_m(x);
	//测试小和,逆序对
	//std::vector<int> x{ 1,100,5,2,3 };
	//sort::f_r_ps(x);


	return 0;
}
