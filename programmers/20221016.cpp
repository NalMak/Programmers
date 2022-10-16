#include <iostream>
#include <vector>
using namespace std;

int GetTornermentCount(int n)
{
	int TornermentIdx = 0;
	while (true)
	{
		n = n / 2;
		++TornermentIdx;

		if (n <= 1)
			break;
	}
	return TornermentIdx;
}

void GetTornermentIdxList(vector<int>& outTornermentList, int totalTornermentIdx, int curTornermentIdx)
{
	outTornermentList.clear();

	for (int i = 0; i < totalTornermentIdx; ++i)
	{
		if (curTornermentIdx <= 1)
		{
			outTornermentList.emplace_back(curTornermentIdx);
			continue;
		}

		if (curTornermentIdx % 2 == 0)
		{
			curTornermentIdx = curTornermentIdx / 2;
		}
		else
		{
			curTornermentIdx = curTornermentIdx / 2 + 1;
		}

		outTornermentList.emplace_back(curTornermentIdx);
	}
}

int solution(int n, int a, int b)
{
	int answer = 0;

	int tornermentIdx = GetTornermentCount(n);

	vector<int> userA_tornermentList;
	vector<int> userB_tornermentList;

	GetTornermentIdxList(userA_tornermentList, tornermentIdx, a);
	GetTornermentIdxList(userB_tornermentList, tornermentIdx, b);

	for (int i = 0; i < userA_tornermentList.size(); ++i)
	{
		if (userA_tornermentList[i] == userB_tornermentList[i])
		{
			return i + 1;
		}
	}

	return 0;
}



void main()
{
	solution(8, 4, 7);
}