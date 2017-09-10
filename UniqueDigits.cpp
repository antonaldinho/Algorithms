#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n)
{
    if(n == 0)
        return 1;
    if(n== 1)
        return 10;
    int iArrSol[n];
    iArrSol[0] = 10;
    int iCount = 9;
    int iArrFactores[n];
    iArrFactores[0] = 9;
    //usando hint f(k)
    //Almacenamos las soluciones para cada n en iArrSol para luego sumarlas al factor
    //El factor de 9*9*8...(9-k+2) se va guardando periodicamente en iArrFactores
    for(int i = 1; i < n; i++)
    {
        iArrSol[i] = iArrSol[i-1] + iCount*iArrFactores[i-1];
        iArrFactores[i] = iArrFactores[i-1]*iCount;
        iCount--;
    }
    return iArrSol[n-1];
}
int main()
{
    int iN;
    cin >> iN;
    cout << countNumbersWithUniqueDigits(iN) << endl;
    return 0;
}
