#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    float x, y;
    float radius;
    ifstream out("circle.txt");
    if (out.is_open()){
        out >> x >> y >> radius;
    }
    out.close();

    vector<float> vec;
    out.open("dot.txt");
    if (out.is_open()){
        float temp;
        while(out >> temp){
            if(vec.size() <= 100)
            vec.push_back(temp);
        }
    }
    out.close();

    float R = radius*radius;
    for (auto it = vec.begin(); it < vec.end(); it+=2){
        //r^2 = (a-x)^2 + (b-y)^2
        float a = *it-x, b = *(it+1)-y;
        float dot = (a * a) + (b * b);
        if (dot < R) cout << 1 << endl;
        else if (dot == R) cout << 0 << endl;
        else cout << 2 << endl;;
    }

	return 0;
}