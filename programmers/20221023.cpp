#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const auto& command : commands)
	{
		vector<int> sortedArray;
	
		sortedArray.assign(array.begin() + command[0] - 1, array.begin() + command[1]);

		sort(sortedArray.begin(), sortedArray.end());

		answer.emplace_back(sortedArray[command[2] - 1]);
	}

	return answer;
}

void main()
{
	vector<int> a;
	vector<vector<int>> b;
	vector<int> c;
	c.emplace_back(1);
	c.emplace_back(3);
	c.emplace_back(2);

	b.emplace_back(c);

	a.emplace_back(1);
	a.emplace_back(2);
	a.emplace_back(3);
	a.emplace_back(4);
	a.emplace_back(5);


	solution(a, b);
}