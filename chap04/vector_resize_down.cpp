#include <iostream>
#include <vector>
using namespace std;
 
int main() 
{
    vector<int> v1 = {1,2,3};
 
    v1.resize(2);
    for(auto i: v1)
        cout << i << " ";
 
    return 0;
}