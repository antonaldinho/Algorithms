#include <iostream>
#include <math.h>

using namespace std;

bool esPrimo(int iN)
{
    bool isPrime = true;
    for(int i = 2; i <= iN / 2; i++)
    {
      if(iN % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime == true)
        return true;
    else
        return false;
}
int buscarMenor(int iNumber)
{
    int iResult;
    bool bPar = false;
    if(iNumber%2 == 0)
        bPar = true;
    if(bPar == true)
    {
        for(int i=iNumber-1; i>=2; i-=2)
            if(esPrimo(i) == true)
            {
                iResult = i;
                break;
            }
    }
    else
    {
        for(int i=iNumber; i>=2; i-=2)
            if(esPrimo(i) == true)
            {
                iResult = i;
                break;
            }
    }
    return iResult;
}
int buscarMayor(int iNumber)
{
    int iResult;
    bool bPar = false;
    if(iNumber%2 == 0)
        bPar = true;
    if(bPar == true)
    {
        for(int i=iNumber+1; i<= pow(iNumber,6); i+=2)
            if(esPrimo(i) == true)
            {
                iResult = i;
                break;
            }
    }
    else
    {
        for(int i=iNumber; i<=pow(iNumber,6); i+=2)
            if(esPrimo(i) == true)
            {
                iResult=i;
                break;
            }
    }
    return iResult;
}

int main()
{
    int iVeces;
    int iPrueba[100];
    cin >> iVeces;
    for(int i=0; i<iVeces; i++)
        cin >> iPrueba[i];
    for(int i=0; i<iVeces; i++)
    {
        if(iPrueba[i] == 2 || iPrueba[i] == 3 || iPrueba[i] == 5 || iPrueba[i] == 7)
            cout << iPrueba[i] << " " << iPrueba[i] << endl;
        else
            cout << buscarMenor(iPrueba[i]) << " " << buscarMayor(iPrueba[i]) << endl;
    }
    return 0;
}
