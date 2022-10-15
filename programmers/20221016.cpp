#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void GetStringElement(vector<string>& outStvElement, const string& strInput, const char* baseChar)
{
	string _strInput = strInput;
	while (true)
	{
		size_t baseIdx = _strInput.find(baseChar);

		if (baseIdx == -1)
		{
			outStvElement.emplace_back(_strInput);
			break;
		}

		outStvElement.emplace_back(_strInput.substr(0, baseIdx));
		_strInput.erase(0, baseIdx + 1);
	}
}
int StringToInt(const string& s)
{
	return stoi(s.c_str());
}

string solution(string s) {

	vector<string> stvResult;

	typedef int ELEMENT_NUM;
	typedef int ELEMENT_INDEX;
	vector<pair<ELEMENT_NUM, ELEMENT_INDEX>> stvIntResult;

	GetStringElement(stvResult, s, " ");

	int index = 0;
	for (const auto& strResult : stvResult)
	{
		stvIntResult.emplace_back(pair<ELEMENT_NUM, ELEMENT_INDEX>(StringToInt(strResult),index));
		++index;
	}

	sort(stvIntResult.begin(), stvIntResult.end());
	
	string answer = "";
	answer += stvResult[stvIntResult.front().second];
	answer += " ";
	answer += stvResult[stvIntResult.back().second];

	return answer;
}


void main()
{
	string s = "-1 -4";
	solution(s);
}