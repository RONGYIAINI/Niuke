#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
˼·:	����,Ҫд���ֵ�����ͳ���������㷨,Ȼ���ַ��������ж�,
		��������bool���͵ı��������б��,������ֵ�����,f_lex = true;
		��������ֵ�����f_lex = false;ͬ��,����ǳ�������,f_len = true;
		�������ж����������;
*/
bool lex(string str1, string str2) //�ֵ�����
{
	int i = 0;
	while (i < str1.size() && i < str2.size())
	{
		if (str1[i] - 'a' > str2[i] - 'a')  //��Ϊ�ַ��޷�ֱ�ӱȽϴ�С,����-'a'�����бȽ�
			return false;
		else if (str1[i] - 'a' < str2[i] - 'a')
			return true;
		else
			i++;
	}
	if (i >= str1.size() || i >= str2.size()) //�����Ϊi��������һ���ַ�����size���˳�ѭ��,˵�������ַ���ǰ����ͬ,���ж����ַ�����
		return (str1.size() < str2.size()); //���ǰ��ĳ���С�ں����,�����ֵ�����,�������ֵ�����
}
bool len(string str1, string str2) //��������
{
	if (str1.size() <= str2.size()) //�ж�ǰ��ĳ����Ƿ�С�ڵ��ں���ĳ��Ⱦ���
		return true;
	else
		return false;
}
int main()
{
	bool f_lex = true, f_len = true; //�������б�ǵ�bool���ͱ���,��ֵ�����true
	vector<string> str;
	string s;
	int n;
	cin >> n;
	while (str.size() < n)
	{
		cin >> s;
		str.push_back(s);
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (!(lex(str[i], str[i + 1]))) //��������ֵ�����f_lex��ֵ���false;
			f_lex = false;
		if (!(len(str[i], str[i + 1]))) //������ǳ�������f_len��ֵ���false;
			f_len = false;
	}
	if (f_lex && !f_len) //��������ֵ�����
		cout << "lexicographically";
	else if (f_len && !f_lex) //������ǳ�������
		cout << "lengths";
	else if (f_len && f_lex) //�����������
		cout << "both";
	else if (!f_lex && !f_len) //�������������
		cout << "none";
	return 0;
}