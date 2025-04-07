#include <iostream>
#include <vector>
using namespace std;

void print_triple(vector<int>& arr)
{
    for(int& i: arr)
        for(int& j: arr)
            for(int& k: arr)
                cout << i << j << k << endl;
}

int main()
{
    vector<int> data = { 1,2,3 };
    print_triple(data);

    return 0;
}
