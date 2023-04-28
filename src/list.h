#include <stack>


namespace list
{
	struct list_node
	{
		int val;
		list_node* next;
		//list_node() :val(0), next(nullptr) {}
		list_node(int val_ = 0, list_node* next_ = nullptr) :val(val_), next(next_) {}
	};

	struct blist_node :public list_node
	{
		int val;
		blist_node* next;
		blist_node* pre;
		blist_node(int val_ = 0, blist_node* next_ = nullptr, blist_node* pre_ = nullptr) :val(val_), next(next_), pre(pre_) {}
	};

	list_node* make_list(const std::initializer_list<int>& l)
	{
		list_node* res = nullptr;
		list_node* pre = nullptr;
		for (auto i = l.begin(); i < l.end(); ++i)
		{
			if (res == nullptr)
			{
				res = new list_node(*i);
				pre = res;
				continue;
			}
			list_node* cur = new list_node(*i);
			pre->next = cur;
			pre = cur;
		}
		return res;
	}

	//反转单向链表
	list_node* reverse_list(list_node* list)
	{
		if (list == nullptr || list->next == nullptr)
		{
			return list;
		}
		list_node* pre = nullptr;
		list_node* cur = list;
		list_node* nex = nullptr;
		while (cur != nullptr)
		{
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}

	//反转双向链表
	blist_node* reverse_blist(blist_node* blist)
	{
		if (blist == nullptr || blist->next == nullptr)
		{
			return blist;
		}
		blist_node* pr = nullptr;
		blist_node* cur = blist;
		blist_node* nex = nullptr;
		while (cur != nullptr)
		{
			nex = cur->next;
			cur->next = pr;
			cur->pre = nex;
			pr = cur;
			cur = nex;
		}
		return pr;
	}

	//打印两个链表公共部分 
	std::pair<int, list_node*> inbound_node(list_node* list)
	{
		list_node* fast = list;
		list_node* slow = list;
		int length = 0;
		while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			++length;
			if (fast == slow)
			{
				break;
			}
		}
		if (fast == nullptr)
		{
			return std::pair<int, list_node* >{0, nullptr};
		}
		else if (fast->next == nullptr)
		{
			return std::pair<int, list_node* >{2 * length + 1, nullptr};
		}
		else if (fast->next->next == nullptr)
		{
			return std::pair<int, list_node* >{2 * length + 2, nullptr};
		}
		list_node* res = list;
		while (res != slow)
		{
			res = res->next;
			slow = slow->next;
			++length;
		}
		return std::pair<int, list_node* >{length, res};
	}
	list_node* find_common_list(list_node* list1, list_node* list2)
	{
		auto m1 = inbound_node(list1);
		auto m2 = inbound_node(list2);
		list_node* p1 = m1.second;
		list_node* p2 = m2.second;
		int length1 = m1.first;
		int length2 = m2.first;
		if (p1 == nullptr && p2 == nullptr)
		{
			list_node* b = nullptr;
			list_node* s = nullptr;
			int d = 0;
			if (length1 > length2)
			{
				b = list1;
				s = list2;
				d = length1 - length2;
			}
			else
			{
				b = list2;
				s = list1;
				d = length2 - length1;
			}
			while (d != 0)
			{
				b = b->next;
				d--;
			}
			while (b != nullptr && s != nullptr)
			{
				if (b == s)
				{
					return b;
				}
				b = b->next;
				s = s->next;
			}
			return nullptr;

		}
		else if (p1 == nullptr ^ p2 == nullptr)
		{
			return nullptr;
		}
		else if (p1 != nullptr && p2 != nullptr)
		{
			if (p1 == p2)
			{
				return p1;
			}
			else
			{
				list_node* f = p1;
				while (f->next = nullptr)
				{
					f = f->next;
					if (f == p2)
					{
						return f;
					}
				}
				return nullptr;
			}
		}
	}

	//判断一个链表是否是回文结构
	bool is_symmetry_list(list_node* list)
	{
		std::stack<int> stk;
		auto l = list;
		while (l != nullptr)
		{
			stk.push(l->val);
			l = l->next;
		}
		int sl = stk.size();
		for (int i = 0; i < sl / 2; ++i)
		{
			if (stk.top() != list->val)
			{
				return false;
			}
			stk.pop();
			list = list->next;
		}
		return true;
	}
}
