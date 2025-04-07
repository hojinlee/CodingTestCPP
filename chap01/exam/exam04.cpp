#include <iostream>
#include <vector>

using namespace std;

vector<int> combine_vectors(const vector<int>& v1, const vector<int>& v2) 
{
    vector<int> result(v1.size() + v2.size());
    int i = 0;
    for (const int& element : v1) 
    {
        result[i++] = element;
    }
    for (const int& element : v2) 
    {
        result[i++] = element;
    }
    return result;
}

int main()
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    vector<int> result = combine_vectors(v1, v2);
    for (const int& element : result) 
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}





