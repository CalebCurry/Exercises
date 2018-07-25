//https://www.youtube.com/watch?v=GJdiM-muYqc
//First recurring character in a string.
//uses hashset as this does not allow duplicates and the value is the key.
//hashset = unordered_set in C++

#include <iostream>
#include <unordered_set>

using namespace std;

char RecurringNumber(string input)
{
    unordered_set<int> seen;
    for(char x: input)
    {
        if(seen.count(x) == 0)
        {
            seen.insert(x);
        }
        else
        {
            //cout << "We found " << x << endl;
            return x;
        }
    }

    return 0;
}

int main()
{
    char x = RecurringNumber("ABCDA");
    if (x != 0)
    {
        cout << "We found " << x << endl;
    } else
    {
        cout << "No repeats." << endl;
    }
}

