#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
	
	int a = 2;
	int b = 4 - brown;
	int c = 2 * yellow;
	int x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
	int y = yellow / x;

	x += 2;
	y += 2;

	return { x,y };
}

void main()
{
	solution(24, 24);
}