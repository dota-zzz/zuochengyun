#include "sort/bubblesort.h"
#include "sort/selectionsort.h"
#include "XOR/xor.h"

int main()
{
	//测试排序
	/*auto vecs = random_vec_generator(10000, 100, -1000, 1000);
	for (const auto& vec : vecs)
	{
		auto v1 = vec;
		auto v2 = vec;
		bubblesort(v1);
		std::sort(v2.begin(), v2.end());
		if (v1 != v2)
		{
			std::cout << "g";
			print_vec(vec);
		}
	}*/

	std::vector<int> x{ 1,1,1,2,2,3,3,120,120,0,0,0,0,99,99,-100,-100,-26,-26 };
	int res = f_o_n(x);
	std::vector<int> x1{ 1,1,1,2,2,3,3,120,120,0,0,0,0,99,99,-100,-100,-26,-26,-26 };
	auto res1 = f_o_ns(x1);
	return 0;
}
