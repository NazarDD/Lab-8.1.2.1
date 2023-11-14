#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 5)
        return 0;

    if (i + 4 < strlen(str))
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    else
    {
        return 0;
    }
}

char* ChangeHelper(char* dest, const char* str, size_t i)
{
    if (str[i] != 0 && str[i + 4] != 0)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            strcat(dest, "***");
            return ChangeHelper(dest + 3, str + i + 5, 0);
        }
        else
        {
            *dest++ = str[i++];
            *dest = '\0';
            return ChangeHelper(dest, str, i);
        }
    }
    else
    {
        *dest++ = str[i++];
        *dest++ = str[i++];
        *dest = '\0';
        return dest;
    }
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 5)
        return str;

    char* tmp = new char[len * 4 / 3 + 1];
    tmp[0] = '\0';

    ChangeHelper(tmp, str, 0);

    strcpy_s(str, len * 4 / 3 + 1, tmp);
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " occurrences of 'while'" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string: " << dest << endl;

    return 0;
}
