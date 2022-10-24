#include <string>
#include <vector>

using namespace std;

int GetMax(const vector<int>& citations)
{
	int maxNum = -1;

	for (const auto& citation : citations)
	{
		if (maxNum < citation)
		{
			maxNum = citation;
		}
	}
	return maxNum;
}

void DividCitations(const vector<int>& citations, vector<int>& lessCitation, vector<int>& moreCitations, int h)
{
	for (const auto& citation : citations)
	{
		if (citation >= h)
			moreCitations.emplace_back(citation);
		else 
			lessCitation.emplace_back(citation);
	}
}

int solution(vector<int> citations) {
	int answer = 0;

	int iMax = GetMax(citations);

	for (int i = iMax; i >= 0; --i)
	{
		vector<int> lessCitation;
		vector<int> moreCitation;
		DividCitations(citations, lessCitation, moreCitation, i);

		if (moreCitation.size() >= i)
		{
			if (lessCitation.size() <= i)
			{
				answer = i;
				break;
			}
		}
	}


	return answer;
}

void main()
{
	vector<int> a;
	a.emplace_back(3);
	a.emplace_back(0);
	a.emplace_back(6);
	a.emplace_back(1);
	a.emplace_back(5);

	solution(a);
}