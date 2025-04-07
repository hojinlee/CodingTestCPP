#include <iostream>
#include <vector>
using namespace std;

void print_dual(vector<int>& arr)
{
    for(int& i: arr)
    {
        for(int j = 0; j < i; j++ )
        {
            cout << i << j << endl;
        }

        for(int j = i; j < arr.size(); j++ )
        {
            cout << i << j << endl;            
        }
    }
}

int main()
{
    vector<int> data = { 1,2,3 };
    print_dual(data);

    return 0;
}
