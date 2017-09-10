#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int iCount = 0;
    if(s1.length() > s2.length())
    {
        while(s1.length() != s2.length())
        {
            if(s1[iCount] != s2[iCount])
            {
                s1.erase(iCount,1);
            }
            else
                iCount++;
        }
        if(s1.length() > s2.length())
        {
            int iSobra = s1.length() - s2.length();
            s1.erase(iCount, iSobra);
        }

        if(s1 == s2)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        while(s2.length() != s1.length())
        {
            if(s2[iCount] != s1[iCount])
            {
                s2.erase(iCount,1);
            }
            else
                iCount++;
        }

        if(s2.length() > s1.length())
        {
            int iSobra = s2.length() - s1.length();
            s2.erase(iCount, iSobra);
        }
        if(s1 == s2)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
