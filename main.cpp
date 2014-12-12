#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string mapa[5][5] = {{"-","-","-","-","-"},
                     {"-","-","-","-","-"},
                     {"-","-","-","-","-"},
                     {"-","-","-","-","-"},
                     {"-","-","-","-","-"}};

string minas[5][5] = {{"X","X","X","X","X"},
                      {"X","X","X","X","X"},
                      {"X","X","X","X","X"},
                      {"X","X","X","X","X"},
                      {"X","X","X","X","X"}};

int cord_x = 0; int cord_y = 0;int cont = 19;
bool juego_terminado = false;
bool juego_ganado = false;

void iniciar()
{
    int num_x; int num_y;
    srand(time(NULL));
     for (int x = 0 ; x < 5; x++ )
        for(int y = 0; y < 5 ; y++)
            mapa[x][y] = "-";

    for(int x = 0 ; x < 5; x++ )
        {
            num_x = rand() % 5;
            num_y = rand() % 5;
            while(minas[num_x ][num_y] == "*")
            {
            num_x = rand() % 5;
            num_y = rand() % 5;
            }
            minas[num_x ][num_y] = "*";
       }
}

void imprimirMapa()
{
    for (int y = 0 ; y < 5; y++ )
    {
            cout<<"|";
            for(int x = 0 ; x < 5; x++ )
            {
                cout<<mapa[x][y];
                cout<<"|";
            }
            cout<<endl;
    }
    cout<<endl;
}

bool validar(int cord_x, int cord_y)
{
    if(cord_x <= 5 && cord_x > 0)
        if(cord_y <= 5 && cord_y > 0)
            return true;
    return false;
}

void minasAdyacentes(int cord_x,int cord_y)
{
    int cont = 0;

    if(cord_x == 0 && cord_y == 0)//Esquina Superior Izquierda
    {
        if(minas[cord_x + 1][cord_y] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y + 1] == "*")
            cont++;
    }
    if(cord_y == 0 && cord_x > 0 && cord_x < 4)//Parte Superior
    {
        if(minas[cord_x + 1][cord_y] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
    }
    if(cord_x == 4 && cord_y ==  0)//Esquina Superior Derecha
    {
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y + 1] == "*")
            cont++;
    }
    if(cord_x == 0 && cord_y > 0 && cord_y < 4)//Parte Izquierda
    {
        if(minas[cord_x + 1][cord_y] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x][cord_y - 1] == "*")
            cont++;
    }
    if(cord_x > 0 && cord_y > 0 && cord_x < 4 && cord_y < 4)//Lo Demas
    {
        if(minas[cord_x + 1][cord_y] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y - 1] == "*")
            cont++;
    }
    if(cord_x == 4 && cord_y > 0 && cord_y < 4)//Parte Derecha
    {
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x][cord_y - 1] == "*")
            cont++;
    }
    if(cord_x == 0 && cord_y ==  4)//Esquina Inferior Izquierda
    {
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x][cord_y + 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y + 1] == "*")
            cont++;
    }
    if(cord_y == 4 && cord_x > 0 && cord_x < 4)//Parte Inferior
    {
        if(minas[cord_x + 1][cord_y] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x + 1][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x][cord_y - 1] == "*")
            cont++;
    }
    if(cord_x == 4 && cord_y ==  4)//Esquina Inferior Derecha
    {
        if(minas[cord_x - 1][cord_y] == "*")
            cont++;
        if(minas[cord_x][cord_y - 1] == "*")
            cont++;
        if(minas[cord_x - 1][cord_y - 1] == "*")
            cont++;
    }

    if(cont > 0)
        cout<<"Hay "<<cont<<" minas alrededor"<<endl;
    else
        cout<<"No hay minas alrededor"<<endl;
}

void juego()
{
    while(true)
    {
        cout<<"Ingrese coordenadas para despejar una casilla"<<endl<<"X: ";
        cin>>cord_x;
        cout<<"Y: ";
        cin>>cord_y;
        cout<<endl;

            if(validar(cord_x,cord_y))
            {
                if(mapa[cord_x - 1][cord_y - 1] == "X")
                {
                    cout<<"Ya eligio este especio"<<endl;
                    imprimirMapa();
                    continue;
                }

                mapa[cord_x - 1][cord_y - 1] = minas[cord_x - 1][cord_y - 1];
                if(mapa[cord_x - 1][cord_y - 1] == "*")
                {
                    juego_terminado = true;
                    break;
                }
                if(cont == 0)
                {
                    juego_ganado = true;
                    break;
                }
                cont--;
                minasAdyacentes(cord_x - 1,cord_y- 1);
            }
            else
            {
                cout<<"Ingrese coordenadas dentro de los parametros establecidos"<<endl;
            }
        imprimirMapa();
    }

    if(juego_terminado == true)
    {
        imprimirMapa();
        cout<<"HAS PERDIDO"<<endl;
    }
    else
    {
        imprimirMapa();
        cout<<"HAS GANADO"<<endl;
    }
}

int main()
{
    iniciar();
    int opcion;
    do{
    cout<<"-------------Menu------------------"<<endl<<endl;
    cout<<"1)Jugar"<<endl<<"2)Salir"<<endl<<endl<<"Opcion: ";
    cin>>opcion;
    cout<<"-----------------------------------"<<endl;

        switch(opcion)
        {
        case 1 :
            imprimirMapa();
            juego();
            iniciar();
            break;
        case 2 :
            exit(0);
        default:
            cout<<"Este Comando no Existe"<<endl;
            break;
        }
    }while(true);
    return 0;
}
