#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int countMinimumMoves(vector<int> arr, int n, int k)
{
    int i;
    
    for (i = k - 1; i < n; i++)
        if (arr[i] != arr[k - 1])
            return -1;
            
    for (i = k - 1; i >= 0; i--)
        if (arr[i] != arr[k - 1])
            return i + 1;

    return 0;
}

int main(){
    fstream out("numbers.txt");
    int temp;
    vector<int> nums;
    while(out >> temp) nums.push_back(temp);
    out.close();

    temp = (int)nums.size();
    cout << countMinimumMoves(nums, temp, temp) << endl;

    return 0;
}