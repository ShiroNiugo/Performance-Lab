#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cout << "n and m: ";
	cin >> n >> m;

    queue<int> st;
	int digit = 1;
	while (digit <= n) st.push(digit++);

	string result = "";
	int temp = st.front();
	do{
		result += to_string(st.front());
		int count = m;
		while(--count){
			st.push(st.front());
			st.pop();
		}
	}while (temp != st.front());
	
	cout << result << endl;

	return 0;
}