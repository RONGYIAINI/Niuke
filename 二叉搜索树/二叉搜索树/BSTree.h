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
	BinarySortTree() : //���캯��
		m_root(nullptr)
	{}
	bool insert(const T &val) //��Ӻ���
	{
		if (m_root == nullptr) {  //������ڵ�λ�սڵ�,ֱ�Ӵ���һ���µĽڵ�,������dataΪval;�滻���ڵ�;
			m_root = new TreeNode<T>(val);
			return true;
		}
		//���������ڵ���Ѱ�Һͱ���ڵ�
		TreeNode<T> * tmp = m_root;   //������ڸ��ڵ�
		TreeNode<T> * cmp = nullptr;  //��������val�����λ�õĽڵ�
		while (tmp) //��tmpΪ�սڵ�ʱ����
		{
			if (val == tmp->m_data) { //���val �����е�һ���ڵ��ֵ���,��ʾ�����Ѿ������Ԫ��,���ʧ��
				return false;
			}
			else if (val > tmp->m_data) { //���val���ڴ˽ڵ��data;����������ҽڵ�
				cmp = tmp;
				tmp = tmp->m_right;
			}
			else { //���valС�ڴ˽ڵ��data,������ڵ�
				cmp = tmp;
				tmp = tmp->m_left;
			}
		}
		tmp = new TreeNode<T>(val); //����һ���µĽڵ�,������data����val
		if (val > cmp->m_data) { //���val�������λ�õ�data,��tmp��ӵ��ҽڵ���
			cmp->m_right = tmp;
			return true;
		}
		else {					 //���valС�����λ�õ�data,��tmp��ӵ���ڵ���
			cmp->m_left = tmp;
			return true;
		}
	}
	bool erase(const T& val)
	{
		if (m_root == nullptr) //�������һ������,ֱ���˳�
			return false;
		//���������ڵ���Ѱ�Һͱ���ڵ�
		TreeNode<T> * tmp = m_root;   //��������Ҫɾ���Ľڵ�
		TreeNode<T> * cmp = nullptr;  //��������ҪҪɾ���Ľڵ�ĸ��ڵ�
		//���ɾ�����Ǹ��ڵ�,�ҵ������ҽڵ�����С�Ľڵ�,Ҳ���ǵ�һ��û����ڵ�Ľڵ�,��������ڵ㱣�浽����ڵ���
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
			
		while (tmp) //Ѱ�ҵ�Ҫɾ���Ľڵ�,��tmp����Ҫɾ���Ľڵ�,����cmp����������һ���ڵ�;
		{
			if (val == tmp->m_data) { //���val �����е�һ���ڵ��ֵ���,��ʾ�Ѿ��ҵ�Ҫɾ���Ľڵ�
				break;
			}
			else if (val > tmp->m_data) { //���val���ڴ˽ڵ��data;����������ҽڵ�
				cmp = tmp;
				tmp = tmp->m_right;
			}
			else { //���valС�ڴ˽ڵ��data,������ڵ�
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
		if (tmp2->m_left && tmp2->m_right) { //���������ҽڵ㶼����
			cmp2 = tmp2->m_right; //��cmp2���������ҽڵ�
			tmp2 = tmp2->m_left;  //��tmp2����������ڵ�
			 
			if (tmp2->m_right == nullptr){//��tmp2���ҽڵ�Ϊ��ʱ,������Ҫɾ���ڵ�ĸ��ڵ�����
				//���Ҫɾ���Ľڵ��������ڵ���ҽڵ�,�ͽ�tmp2���浽�����ڵ���ҽڵ�;����Ҫɾ���ڵ���ҽڵ㱣�浽tmp2���ҽڵ���
				if (val > cmp->m_data) { 
					cmp->m_right = tmp2; 
					tmp2->m_right = cmp2;
					delete tmp;
					return true;
				}
				//���Ҫɾ���Ľڵ��������ڵ����ڵ�,�ͽ�tmp2���浽�����ڵ����ڵ�;����Ҫɾ���ڵ���ҽڵ㱣�浽tmp2���ҽڵ���
				else {					
					cmp->m_left = tmp2;
					tmp2->m_right = cmp2;
					delete tmp;
					return true;
				}
			}
			//�������ҽڵ㲻Ϊ��ʱ,�ҵ�data��Ҫɾ���ڵ�data��ӽ���һ���ڵ�,���������ɾ���ڵ��λ��
			else { 
				
				TreeNode<T> * tmp3 = tmp2;  //������������Ľڵ�
				TreeNode<T> * cmp3 = nullptr; //������������Ľڵ�ĸ��ڵ�
				while (tmp3->m_right) //�ҵ�����Ľڵ�,����Ľڵ�Ϊ��һ��û���ҽڵ�Ľڵ�
				{
					cmp3 = tmp3; //cmp3������������ڵ�ĸ��ڵ�
					tmp3 = tmp3->m_right; //tmp3������������ڵ�
				}
				


				tmp3->m_right = cmp2;	 //��Ҫɾ���ڵ���ҽڵ㱣�浽tmp3���ҽڵ���
				cmp3->m_right = nullptr; //������ڵ�ĸ��ڵ���ҽڵ��ÿ�
				if (tmp3->m_left) {		 //�������ڵ�����ڵ�,�ҵ�����С�Ľڵ�,��Ҫɾ���ڵ����ڵ㱣��������
					TreeNode<T> * tmp4 = tmp3->m_left; //����������С�ڵ�
					while (tmp4->m_left) //Ѱ����С�ڵ�,��С�ڵ�Ϊ��һ��û����ڵ�Ľڵ�
					{
						tmp4 = tmp4->m_left;
					}
					tmp4->m_left = tmp2; //�ҵ�֮��Ҫɾ���ڵ����ڵ㱣��������ڵ���
				}
				else { //�����û����ڵ�,ֱ�ӽ�Ҫɾ���ڵ����ڵ㱣��������ڵ���
					tmp3->m_left = tmp2;
				}
				//��ʱ,�Ѿ�����滻
				delete tmp;


				//���Ҫɾ���Ľڵ��������ڵ���ҽڵ�
				if (val > cmp->m_data) { 
					cmp->m_right = tmp3;	 //��tmp3���浽�����ڵ���ҽڵ���
				}
				//���Ҫɾ���Ľڵ��������ڵ����ڵ�
				else {
					cmp->m_left = tmp3;	 //��tmp3���浽�����ڵ����ڵ���
				}
			}
		}

		else if (tmp2->m_left) { // ����ֻ����ڵ�ʱ,��cmp2����������ڵ�,
			cmp2 = tmp2->m_left;
			if (val > cmp->m_data) { //���Ҫɾ���Ľڵ��������ڵ���ҽڵ�,�ͽ�cmp2���浽�����ڵ���ҽڵ�;
				cmp->m_right = cmp2;
				delete tmp;
				return true;
			}
			else {					 //���Ҫɾ���Ľڵ��������ڵ����ڵ�,�ͽ�cmp2���浽�����ڵ����ڵ�;
				cmp->m_left = cmp2;
				delete tmp;
				return true;
			}
		}

		else if (tmp2->m_right) { //����ֻ���ҽڵ�ʱ,��cmp2���������ҽڵ�,
			cmp2 = tmp2->m_right;
			if (val > cmp->m_data) { //���Ҫɾ���Ľڵ��������ڵ���ҽڵ�,�ͽ�cmp2���浽�����ڵ���ҽڵ�;
				cmp->m_right = cmp2;
				delete tmp;
				return true;
			}
			else {					//���Ҫɾ���Ľڵ��������ڵ����ڵ�,�ͽ�cmp2���浽�����ڵ����ڵ�;
				cmp->m_left = cmp2;
				delete tmp;
				return true;
			}
		}

		else { //����û�����ҽڵ�ʱ,ֱ��ɾ���ýڵ�
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