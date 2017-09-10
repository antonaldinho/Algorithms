#include <iostream>

using namespace std;

int main()
{
    short int iVeces;
    cin >> iVeces;
    short int iAnswers[10];
    for (short int i = 0; i < iVeces; i++)
        iAnswers[i]=0;
    for(short int i = 0; i < iVeces; i++)
    {
        int iCount = 0;
        short int iN, iK;
        cin >> iN >> iK;
        short int iArrTimes[1000];
        for(short int j = 0; j < iN; j++)
        {
            cin >> iArrTimes[j];
        }
        for(short int j = 0; j < iN; j++)
        {
            if(iArrTimes[j] > 0)
                iCount++;
            if(iCount > (iN-iK))
            {
                iAnswers[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < iVeces; i++)
    {
        if(iAnswers[i] == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
