#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    fstream out("numbers.txt");
    int temp;
    vector<int> nums;
    while(out >> temp) nums.push_back(temp);
    out.close();

    int n = nums.size(), steps = 0;
    sort(nums.begin(), nums.end());
    int median = nums[n/2];
    for(int i = 0; i < n; i++){
        steps += abs(nums[i] - median);
    }
    cout << steps << endl;

    return 0;
}
