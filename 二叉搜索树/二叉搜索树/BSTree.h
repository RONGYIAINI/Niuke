#pragma once

template<class T>
class TreeNode {
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
public:
	TreeNode(const T & val) :
		m_data(val),
		m_left(nullptr),
		m_right(nullptr)
	{}

	template <class T>
	friend class BinarySortTree;
};

template <class T>
class BinarySortTree {
	TreeNode<T> * m_root;
	
public:
	BinarySortTree() : //构造函数
		m_root(nullptr)
	{}
	bool insert(const T &val) //添加函数
	{
		if (m_root == nullptr) {  //如果根节点位空节点,直接创建一个新的节点,让它的data为val;替换根节点;
			m_root = new TreeNode<T>(val);
			return true;
		}
		//创建两个节点来寻找和保存节点
		TreeNode<T> * tmp = m_root;   //令其等于根节点
		TreeNode<T> * cmp = nullptr;  //用来保存val的添加位置的节点
		while (tmp) //当tmp为空节点时跳出
		{
			if (val == tmp->m_data) { //如果val 和其中的一个节点的值相等,表示树中已经有这个元素,添加失败
				return false;
			}
			else if (val > tmp->m_data) { //如果val大于此节点的data;则进入它的右节点
				cmp = tmp;
				tmp = tmp->m_right;
			}
			else { //如果val小于此节点的data,进入左节点
				cmp = tmp;
				tmp = tmp->m_left;
			}
		}
		tmp = new TreeNode<T>(val); //创建一个新的节点,令他的data等于val
		if (val > cmp->m_data) { //如果val大于添加位置的data,则将tmp添加到右节点上
			cmp->m_right = tmp;
			return true;
		}
		else {					 //如果val小于添加位置的data,则将tmp添加到左节点上
			cmp->m_left = tmp;
			return true;
		}
	}
	bool erase(const T& val)
	{
		if (m_root == nullptr) //如果这是一个空树,直接退出
			return false;
		//创建两个节点来寻找和保存节点
		TreeNode<T> * tmp = m_root;   //用来保存要删除的节点
		TreeNode<T> * cmp = nullptr;  //用来保存要要删除的节点的父节点
		//如果删除的是根节点,找到根的右节点中最小的节点,也就是第一个没有左节点的节点,将根的左节点保存到其左节点上
		if (val == m_root->m_data) {
			if (tmp->m_left && tmp->m_right) {
				cmp = m_root->m_left;
				tmp = m_root->m_right;
				TreeNode<T> * tmp5 = tmp;
				while (tmp5->m_left)
				{
					tmp5 = tmp5->m_left;
				}
				tmp5->m_left = cmp;
				delete m_root;
				m_root = tmp;
				return true;
			}
			else if (tmp->m_left){
				delete m_root;
				m_root = tmp->m_left;
				return true;
			}
			else {
				delete m_root;
				m_root = tmp->m_right;
			}
		}
			
		while (tmp) //寻找到要删除的节点,用tmp保存要删除的节点,并用cmp保存它的上一个节点;
		{
			if (val == tmp->m_data) { //如果val 和其中的一个节点的值相等,表示已经找到要删除的节点
				break;
			}
			else if (val > tmp->m_data) { //如果val大于此节点的data;则进入它的右节点
				cmp = tmp;
				tmp = tmp->m_right;
			}
			else { //如果val小于此节点的data,进入左节点
				cmp = tmp;
				tmp = tmp->m_left;
			}
		}
		if (tmp == nullptr)
		{
			return false;
		}
		TreeNode<T> * tmp2 = tmp;
		TreeNode<T> * cmp2 = nullptr;
		if (tmp2->m_left && tmp2->m_right) { //当它的左右节点都存在
			cmp2 = tmp2->m_right; //用cmp2保存它的右节点
			tmp2 = tmp2->m_left;  //用tmp2保存它的左节点
			 
			if (tmp2->m_right == nullptr){//当tmp2的右节点为空时,将它与要删除节点的父节点相连
				//如果要删除的节点是它父节点的右节点,就将tmp2保存到它父节点的右节点;并将要删除节点的右节点保存到tmp2的右节点上
				if (val > cmp->m_data) { 
					cmp->m_right = tmp2; 
					tmp2->m_right = cmp2;
					delete tmp;
					return true;
				}
				//如果要删除的节点是它父节点的左节点,就将tmp2保存到它父节点的左节点;并将要删除节点的右节点保存到tmp2的右节点上
				else {					
					cmp->m_left = tmp2;
					tmp2->m_right = cmp2;
					delete tmp;
					return true;
				}
			}
			//当它的右节点不为空时,找到data与要删除节点data最接近的一个节点,用它来替代删除节点的位置
			else { 
				
				TreeNode<T> * tmp3 = tmp2;  //用来保存替代的节点
				TreeNode<T> * cmp3 = nullptr; //用来保存替代的节点的父节点
				while (tmp3->m_right) //找到替代的节点,替代的节点为第一个没有右节点的节点
				{
					cmp3 = tmp3; //cmp3用来保存替代节点的父节点
					tmp3 = tmp3->m_right; //tmp3用来保存替代节点
				}
				


				tmp3->m_right = cmp2;	 //将要删除节点的右节点保存到tmp3的右节点上
				cmp3->m_right = nullptr; //将替代节点的父节点的右节点置空
				if (tmp3->m_left) {		 //如果替代节点右左节点,找到其最小的节点,将要删除节点的左节点保存在其上
					TreeNode<T> * tmp4 = tmp3->m_left; //用来保存最小节点
					while (tmp4->m_left) //寻找最小节点,最小节点为第一个没有左节点的节点
					{
						tmp4 = tmp4->m_left;
					}
					tmp4->m_left = tmp2; //找到之后将要删除节点的左节点保存在其左节点上
				}
				else { //如果它没有左节点,直接将要删除节点的左节点保存在其左节点上
					tmp3->m_left = tmp2;
				}
				//这时,已经完成替换
				delete tmp;


				//如果要删除的节点是它父节点的右节点
				if (val > cmp->m_data) { 
					cmp->m_right = tmp3;	 //将tmp3保存到它父节点的右节点上
				}
				//如果要删除的节点是它父节点的左节点
				else {
					cmp->m_left = tmp3;	 //将tmp3保存到它父节点的左节点上
				}
			}
		}

		else if (tmp2->m_left) { // 当它只有左节点时,用cmp2保存它的左节点,
			cmp2 = tmp2->m_left;
			if (val > cmp->m_data) { //如果要删除的节点是它父节点的右节点,就将cmp2保存到它父节点的右节点;
				cmp->m_right = cmp2;
				delete tmp;
				return true;
			}
			else {					 //如果要删除的节点是它父节点的左节点,就将cmp2保存到它父节点的左节点;
				cmp->m_left = cmp2;
				delete tmp;
				return true;
			}
		}

		else if (tmp2->m_right) { //当它只有右节点时,用cmp2保存它的右节点,
			cmp2 = tmp2->m_right;
			if (val > cmp->m_data) { //如果要删除的节点是它父节点的右节点,就将cmp2保存到它父节点的右节点;
				cmp->m_right = cmp2;
				delete tmp;
				return true;
			}
			else {					//如果要删除的节点是它父节点的左节点,就将cmp2保存到它父节点的左节点;
				cmp->m_left = cmp2;
				delete tmp;
				return true;
			}
		}

		else { //当它没有左右节点时,直接删除该节点
			if (val > cmp->m_data) {
				cmp->m_right = nullptr;
				delete tmp;
			}
			else {
				cmp->m_left = nullptr;
				delete tmp;
			}
		}
	}
};