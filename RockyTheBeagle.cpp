#include <iostream>
#include <limits.h>

using namespace std;

int W[20][20];
int iVeces, iNumCuartos, iNumConexiones, iIndex = 0;

char conversion2(int iNum)
{
    if(iNum == 0)
        return 'A';
    else if (iNum == 1)
        return 'B';
    else if (iNum == 2)
        return 'C';
    else if (iNum == 3)
        return 'D';
    else if (iNum == 4)
        return 'E';
    else if (iNum == 5)
        return 'F';
    else if (iNum == 6)
        return 'G';
    else if (iNum == 7)
        return 'H';
    else if (iNum == 8)
        return 'I';
    else if (iNum == 9)
        return 'J';
    else if (iNum == 10)
        return 'K';
    else if (iNum == 11)
        return 'L';
    else if (iNum == 12)
        return 'M';
    else if (iNum == 13)
        return 'N';
    else if (iNum == 14)
        return 'O';
    else if (iNum == 15)
        return 'P';
    else if (iNum == 16)
        return 'Q';
    else if (iNum == 17)
        return 'R';
    else if (iNum == 18)
        return 'S';
    else
        return 'T';
}

int distanciaMinima(int distance[], bool bset[])
{
    int iMin = INT_MAX;
    int indexMin = 0;

    for (int vertex = 0; vertex < iNumCuartos; vertex++)
    {
        if (bset[vertex] == false && distance[vertex] <= iMin)
        {
            iMin = distance[vertex];
            indexMin = vertex;
        }
    }
    return indexMin;
}

int conversion(char iC)
{
    if(iC == 'A')
        return 0;
    else if (iC == 'B')
        return 1;
    else if (iC == 'C')
        return 2;
    else if (iC == 'D')
        return 3;
    else if (iC == 'E')
        return 4;
    else if (iC == 'F')
        return 5;
    else if (iC == 'G')
        return 6;
    else if (iC == 'H')
        return 7;
    else if (iC == 'I')
        return 8;
    else if (iC == 'J')
        return 9;
    else if (iC == 'K')
        return 10;
    else if (iC == 'L')
        return 11;
    else if (iC == 'M')
        return 12;
    else if (iC == 'N')
        return 13;
    else if (iC == 'O')
        return 14;
    else if (iC == 'P')
        return 15;
    else if (iC == 'Q')
        return 16;
    else if (iC == 'R')
        return 17;
    else if (iC == 'S')
        return 18;
    else
        return 19;
}

void dijkstra(int zero)
{
    int N[iNumCuartos];
    bool bset[iNumCuartos];
    for (int i = 0; i < iNumCuartos; i++)
    {
        N[i] = INT_MAX;
        bset[i] = false;
    }

    N[zero] = 0;
    for (int y = 0; y < iNumCuartos-1; y++)
    {
        int m = distanciaMinima(N, bset);
        bset[m] = true;

        for (int v = 0; v < iNumCuartos; v++)
        {
            if (!bset[v] && W[m][v] && N[m] != INT_MAX && N[m]+W[m][v] < N[v])
                N[v] = N[m] + W[m][v];
        }
    }

    int iMax = N[0];
    for (int i = 1;  i < iNumCuartos; i++)
    {
        if (N[i] > iMax)
        {
            iMax = N[i];
            iIndex = i ;
        }
    }
}
int main()
{
    cin >> iVeces;
    for(int i = 0; i < iVeces; i++)
    {
        cin >> iNumCuartos >> iNumConexiones;
        for(int x = 0; x < iNumConexiones; x++)
        {
            char cX, cY;
            int iDistancia, iX, iY;
            cin >> cX >> cY >> iDistancia;
            iX = conversion(cX);
            iY = conversion(cY);
            W[iX][iY] = iDistancia;
            W[iY][iX] = iDistancia;
        }
        dijkstra(0);
        char cSolucion = conversion2(iIndex);
        cout << iIndex << endl;
        cout << "Case " << i+1 << ": "<< cSolucion <<endl;

        for(int x = 0; x < iNumConexiones; x++)
            for(int y = 0; y < iNumConexiones; y++)
                W[x][y] = 0;
    }
    return 0;
}
