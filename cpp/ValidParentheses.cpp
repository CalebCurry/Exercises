//https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
#include <vector>

using namespace std;

//no longer used
bool CheckIfCorrect(char a, char b)
{
    cout << "a: " << a << ". b: " << b << endl;
    if(
        (a == '{' && b == '}') ||
        (a == '[' && b == ']') ||
        (a == '(' & b == ')')
        )
        {
            return true;
        }
    return false;
}

bool IsStringValid(string input)
{
    //more elegant solution found here:
    //https://leetcode.com/problems/valid-parentheses/discuss/9178/Short-java-solution
    if (input.length() % 2 != 0) return false;
    vector<char> characters = {};
    for (char c : input)
    {
        
        //cout << c << endl;
        if (c == '{')
        {
            characters.push_back('}');
        } else if (c == '(')
        {
            characters.push_back(')');
        } else if (c == '[')
        {
            characters.push_back(']');
        } else
        {
            if(characters.size() == 0 ) return false;
            
            char popped_char = characters.back();
            characters.pop_back();

            if(popped_char != c)
            {
                return false;
            }
        }
    }
    return true;
}

//no longer used
bool IsStringValidOld(string input)
{
    vector<char> left = {};

    //empty string is valid
    if (input.length() == 0)
    {
        return true;
    }

    // if input is like "[]{"
    if (input.length() % 2 != 0)
    {
        return false;
    }
    for (int i = 0; i < input.length(); i++)
    {
        cout << input[i] << endl;
        if(input[i] == '{' || input[i] == '(' || input[i] == '[')
        {
            //add it to the stack
            left.push_back(input[i]);
        
        } else
        {
            //Grab the left side
            char popped_value = left.back();
            left.pop_back();

            //compare left side to see if it aligns with latest character
            return CheckIfCorrect(popped_value, input[i]);
        }
    }
    return false;
}

int main()
{
    bool result = IsStringValid("[]{");
    if(result)
    {
        cout << "valid" << endl;
    } else 
    {
        cout << "invalid" << endl;
    }

    return 0;
}
