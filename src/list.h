
namespace list
{
	struct list_node
	{
		int val;
		list_node* next;
		//list_node() :val(0), next(nullptr) {}
		list_node(int val_ = 0, list_node* next_ = nullptr) :val(val_), next(next_) {}
	};

	struct blist_node
	{
		int val;
		blist_node* next;
		blist_node* pre;
		blist_node(int val_ = 0, blist_node* next_ = nullptr, blist_node* pre_ = nullptr) :val(val_), next(next_), pre(pre_) {}
	};


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
}