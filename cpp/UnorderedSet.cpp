#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> set = {1, 2, 3, 3, 4, 8};

    //this is essentially a foreach loop.
    for (int y : set)
    {
        //Note that the value 3 is only outputted once (no repating values allowed)
        cout << y << "\t";
    }
    return 0;


}
