#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void GetCharToInt(vector<int>& outStvInt,const string& number)
{
	for (int i = 0; i < number.size(); ++i)
	{
		outStvInt.emplace_back(number[i] - 48);
	}
}

int GetMaxNumFromLeft(vector<int>& outStvInt,int iMinDigit, int iLeftSpace)
{
	int maxNumIndex = 0;
	int maxNum = 0;

	if (iLeftSpace > 0)
	{
		for (int i = 0; i < outStvInt.size() ; ++i)
		{
			if(i > outStvInt.size() - iMinDigit)
				break;

			if (maxNum < outStvInt[i])
			{
				maxNum = outStvInt[i];
				maxNumIndex = i;

				if (maxNum == 9)
					break;
			}
		}
		outStvInt.erase(outStvInt.begin(), outStvInt.begin() + maxNumIndex + 1);
	}
	else
	{
		maxNum = outStvInt.front();
		outStvInt.erase(outStvInt.begin());
	}
	
	return maxNum;
}

string solution(string number, int k) {

	vector<int> stvNum;
	int maxNum = 0;
	GetCharToInt(stvNum, number);

	vector<int> debug;
	int copyK = k;
	int iDigit = stvNum.size() - k;
	int iMaxDigit = iDigit;
	for (int i = 0; i < iMaxDigit; ++i)
	{

		if (copyK == 0)
		{
			for (const auto& num : stvNum)
			{
				debug.emplace_back(num);
			}
			break;
		}
		else
		{
			debug.emplace_back(GetMaxNumFromLeft(stvNum, iDigit, copyK));

		}
		if(copyK > 0)
			--copyK;
		--iDigit;
	}

	maxNum = debug.size();
	string answer;
	for(int i = 0 ; i < maxNum; ++i)
	{
		answer += debug[i] + '0';
	}
	return answer;
}

void main()
{
	solution("654321",1);
}

//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//void GetCharToInt(vector<int>& outStvInt, const string& number)
//{
//	for (int i = 0; i < number.size(); ++i)
//	{
//		outStvInt.emplace_back(number[i] - 48);
//	}
//}
//
//int GetMaxNumFromLeft(vector<int>& outStvInt, int iMinDigit, int iLeftSpace)
//{
//	int maxNumIndex = 0;
//	int maxNum = 0;
//
//	for (int i = 0; i < outStvInt.size(); ++i)
//	{
//		if (i > outStvInt.size() - iMinDigit)
//			break;
//
//		if (maxNum < outStvInt[i])
//		{
//			maxNum = outStvInt[i];
//			maxNumIndex = i;
//
//			if (maxNum == 9)
//				break;
//		}
//	}
//
//	outStvInt.erase(outStvInt.begin(), outStvInt.begin() + maxNumIndex + 1);
//
//	return maxNum;
//}
//
//string solution(string number, int k) {
//
//	vector<int> stvNum;
//	int maxNum = 0;
//	GetCharToInt(stvNum, number);
//
//	vector<int> debug;
//	int copyK = k;
//	int iDigit = stvNum.size() - k;
//	int iMaxDigit = iDigit;
//	for (int i = 0; i < iMaxDigit; ++i)
//	{
//		if (copyK > 0)
//		{
//			debug.emplace_back(GetMaxNumFromLeft(stvNum, iDigit, copyK));
//			--copyK;
//			--iDigit;
//		}
//		else
//		{
//			for (const auto& num : stvNum)
//			{
//				debug.emplace_back(num);
//			}
//			break;
//		}
//
//	}
//
//	maxNum = debug.size();
//	string answer;
//	for (int i = 0; i < maxNum; ++i)
//	{
//		answer += debug[i] + '0';
//	}
//	return answer;
//}
//
//void main()
//{
//	solution("1034599000", 6);
//}