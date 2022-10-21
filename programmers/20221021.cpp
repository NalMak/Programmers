#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
	vector<char> stvLeft;
	vector<char> stvRight;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			stvLeft.emplace_back('(');
		else
		{
			stvRight.emplace_back(')');
			if (stvLeft.size() < stvRight.size())
				return false;
		}
	}

	return stvLeft.size() == stvRight.size();
}

void main()
{
	string s = "{}{{}}";
	solution(s);
}