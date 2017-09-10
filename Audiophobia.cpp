#include <iostream>
#include <limits>

using namespace std;

int iMat[100][100];
int way[100][100];

int menor(int a, int b){
    if(a > b)
        return b;
    return a;
}

void camino(int inicio, int fin){
    if(way[inicio][fin] != 0){
        camino(inicio, iMat[inicio][fin]);
        cout<<way[inicio][fin]+1 << "-";
        camino(iMat[inicio][fin], inicio);
    }
}

int main(){
    int n, m, q;
    cin >> n >> m;
    int iMatrizAlt[100][100];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            iMat[i][j] = 99999;
    //Llenar la matriz
    for(int j = 0; j < m; j++){
        int iA, iB, iC;
        cin >> iA >> iB >> iC;
        iMat[iA-1][iB-1] = iMat[iB-1][iA-1] = iC;
        iMat[j][j] = 0;
    }
    for(int x = 0; x < n; x++)
        for(int z =0; z < n; z++){
            iMatrizAlt[x][z] = iMat[x][z];
        }
    //Floyd
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                iMat[i][j] = menor(iMat[i][j], iMat[i][k] + iMat[k][j]);
                if(iMatrizAlt[i][k] + iMatrizAlt[k][j] < iMatrizAlt[i][j])
                {
                    way[i][j] = k;
                    iMatrizAlt[i][j] = iMatrizAlt[i][k] + iMatrizAlt[k][j];
                }
            }
    cin >> q;
    //Desplegar Costos
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if(iMat[x-1][y-1] == 99999)
            cout << "no path" << endl;
        else{
            cout << iMat[x-1][y-1] << " " << x<<"-";
            camino(x-1,y-1);
            cout << y << endl;
        }

    }
    return 0;
}
