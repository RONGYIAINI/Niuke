#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;


class Solution {
	map<string, int> m;
	
	
public:
	class Compear {
	public:
		bool operator ()(const int &a, const int &b)
		{
			return a > b;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k) {
		for (int i = 0; i < words.size(); i++)
		{
			(m[words[i]])++;
		}
		multimap<int, string, Compear> v;
		for (auto &i : m)
		{
			v.insert(pair<int, string>(i.second, i.first));
		}
		vector<string> topwords;
		
		for (auto &e : v)
		{
			topwords.push_back(e.second);
			if (topwords.size() == k)
				return topwords;
		}
		
	}
};
int main()
{
	Solution A;
	vector<string> a{ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	vector<string> b;
	b = A.topKFrequent(a, 4);
	return 0;
}