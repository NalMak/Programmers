#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector<int> arrDigit;

	sort(numbers.begin(), numbers.end(), [](int a, int b)
	{
		int digitA = to_string(a).length() - 1;
		int digitB = to_string(b).length() - 1;
		
		if (digitA == digitB)
			return a > b;

		while (digitA >= 0 && digitB >= 0)
		{
			int maxA = a;
			int maxB = b;

			if (digitA >= 0)
			{
				maxA = a / pow(10, digitA);
				a -= maxA * pow(10, digitA);
			}
			
			if (digitB >= 0)
			{
				maxB = b / pow(10, digitB);
				b -= maxA * pow(10, digitB);
			}

			if(maxA != maxB)
				return maxA > maxB;

			--digitA;
			--digitB;
		}
		return digitA < digitB;
	});

	for (int i = 0 ; i < numbers.size(); ++i)
	{
		answer += to_string(numbers[i]);
	}
	return answer;
}

void main()
{
	vector<int> a;
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(i);
	//a.emplace_back(9);
	//a.emplace_back(91);



	solution(a);
}