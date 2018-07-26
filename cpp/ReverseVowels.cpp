//https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <iostream>

using namespace std;

bool IsVowel(char c)
{
    if(
        c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U')
    {
        return true;
    }
    return false;
}

string ReverseVowels(string input)
{
    //the way this works is moving from outside in on both the left (first loop)
    //and the right (second for loop)

    //for the inner for loop.  We want j to be defined at a larger scope
    //this way we can maintain our location in the string
    int j = input.length() - 1;

    for (int i = 0; i < input.length(); i++)
    {
        if ( IsVowel(input[i]))
        {

            //make this j >= i because once we get halfway we can stop.
            //If i becomes equal to j or greater, we have either hit the middle
            //or the two passed one another
            for (; j >= i; j--)
            {
                
                if ( IsVowel(input[j]) )
                {
                    char temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                }
            }
        }
    }
    return input;
}

int main()
{
    string reverse = ReverseVowels("Caleb");
    cout << "reverse: " << reverse << endl;
}
