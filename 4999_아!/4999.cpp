#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() >= s2.length())
		cout << "go";
	else
		cout << "no";

	return 0;
}
