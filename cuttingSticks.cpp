//José Antonio Alemán Salazar
//A01196565
//Creado el lunes 6 de marzo de 2017
//Análisis y diseño de algoritmos
//Tarea 10: Cutting Sticks
//El programa calcula la manera menos costosa de cortar los palos de acuerdo a los cortes indicados
#include <iostream>

using namespace std;

int main()
{
    int iLength;
    cin >> iLength;
    while(iLength != 0)
    {
        int iMatrix[50][50];
        int iCuts[50];
        int iC;
        int iMin;
        cin >> iC;
        iCuts[0] = 0;
        iCuts[iC+1] = iLength;
        for(int i = 1; i <= iC; i++)
            cin >> iCuts[i];
        for(int i = 0; i <= iC+1; i++)
            iMatrix[i][i+1] = 0;

        for(int j = 2; j<=iC+1; j++)
        {
            for(int i = j-2; i >= 0; i--)
                {
                    iMin = INT_MAX;
                    for(int k=i+1; k<j; k++)
                        iMin = min(iMin, iMatrix[i][k] +iMatrix[k][j] + iCuts[j] -iCuts[i]);
                    iMatrix[i][j]=iMin;
                }
        }

        cout << "The minimum cutting is " << iMatrix[0][iC+1] << endl;
        cin >> iLength;
    }
    return 0;
}
