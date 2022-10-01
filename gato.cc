#include <iostream>
#include <windows.h>


using namespace std;

char tablero[6][5] = {{' ', '|', ' ', '|', ' '},
                      {'_', '|', '_', '|', '_'},
                      {' ', '|', ' ', '|', ' '},
                      {'_', '|', '_', '|', '_'},
                      {' ', '|', ' ', '|', ' '},
                      {' ', '|', ' ', '|', ' '},};


char matriz_juego[3][3] = {{'7', '8', '9'},
                           {'4', '5', '6'},
                           {'1', '2', '3'},};

//Prototipos
void Menu();
void mostrarTablero();
void Movimiento(bool jugador);
void cambioJugador(bool *jugador);
bool verifica(bool jugador);
bool verificaHorizontal();
void ganador(bool jugador);
bool verificaVertical();
bool verificaDiagonal();
bool verificaDiagonalI();
void limpiaTablero();

int main(void)
{
        int control_menu;
        bool jugador = 0;
        bool var_ganador = false;

        while (true)
        {
            Menu();
            cin >> control_menu;

            switch (control_menu)
            {
            case 0:
                cout << "Gracias por jugar :)";
                return 0;
             break;

            case 1:
                limpiaTablero(); 
                while(true)
                {
                    mostrarTablero();
                    cambioJugador(&jugador);
                    Movimiento(jugador);
                    var_ganador = verifica(jugador);
                    if(var_ganador == true)
                    {
                        mostrarTablero();
                        ganador(jugador);
                        break;
                    }
                }      
                break;
            
                default:
                    cout << "ERROR: vuelve a intentarlo :(";
                    system("pause");
                break;
                }
        }
}

//Prototipos
void Menu()
{
    //Imprime el menu de opciones
    system("cls");
    cout << "\n--------------------------------------------------" << endl;
    cout << "\t\tJUEGO DEL GATO" << endl;
    cout << "1.- Jugar" << endl;
    cout << "0.- Salir" << endl << endl;
    cout << "Elija la opcion: ";
    cout << endl;

}

//Imprimir tablero
void mostrarTablero()
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 7);


    int ii = 0;
    int jj = 0;

    cout << endl;
    for (int i = 0; i < 6; i++)
    {
         cout << endl;
        for (int j = 0; j < 5; j++)
        {
            if (i%2 == 0 && j%2 ==0)
            {
                if(matriz_juego[ii][jj]=='x')
                {
                    SetConsoleTextAttribute(hConsole, 1);
                    cout << matriz_juego[ii][jj];
                }
                else if(matriz_juego[ii][jj]=='O')
                {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << matriz_juego[ii][jj];
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << matriz_juego[ii][jj];
                }
                
                    jj++;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 7);
                cout << tablero[i][j];
            }
               
        }
        if(i%2 == 0)
        {
            jj=0;
            ii++;
        }
    }
}

void Movimiento(bool jugador)
{
    int casilla;
    bool valido = false;
    char caracter;
    bool repetido = false;

    //Define caracter
    if(jugador == 0)
    {
        caracter = 'O';
    }
    else
        caracter = 'x';

    //valida numero y coloca caracter
    while(valido == false)
    {
        cout << endl;
        cout << "Jugador " << jugador << " realiza tu movimiento: " << endl;
        cin >> casilla;

        if((casilla<=9) && (casilla>0))
        {

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if(matriz_juego[i][j]==casilla+48)
                    {
                        matriz_juego[i][j]=caracter;
                        valido = true;
                    }
                }    
                if (valido == false)
                    {
                        repetido = true;
                    }     
            }
            if (repetido == true)
            {
                cout << "CASILLA OCUPADA";
            }
        }
        else
            cout << "\nERROR: casilla invalida.";

        
    }
}

void cambioJugador(bool *jugador)
{
    if (*jugador == 0)
        *jugador = 1;
    else
        *jugador = 0;
}

bool verifica(bool jugador) 
{
    bool tres_lineaH = false;
    bool tres_lineaV = false;
    bool tres_lineaD = false;
    bool tres_lineaDI = false;
    tres_lineaH = verificaHorizontal();
    tres_lineaV = verificaVertical();
    tres_lineaD = verificaDiagonal();
    tres_lineaDI = verificaDiagonalI();
    return tres_lineaDI;
}

bool verificaHorizontal()
{
    char linea[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            linea[j] = matriz_juego[i][j];
        }
        if(linea[0]==linea[1] && linea[1] == linea[2])
        {
            return true;
        }
        
    }
    return false;
}

bool verificaVertical()
{
    char linea[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            linea[j] = matriz_juego[j][i];
        }
        if(linea[0]==linea[1] && linea[1] == linea[2])
        {
            return true;
        }
        
    }
    return false;
}

bool verificaDiagonal()
{
    char linea[3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            linea[j] = matriz_juego[j][j];
        }
        if(linea[0]==linea[1] && linea[1] == linea[2])
        {
            return true;
        }
        
    }
    return false;
}

bool verificaDiagonalI()
{
    char linea[3];
    int m=2;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            linea[j] = matriz_juego[j][m];
            m = m-1;
        }
        if(linea[0]==linea[1] && linea[1] == linea[2])
        {
            return true;
        }
        
    }
    return false;
}

void ganador(bool jugador)
{
    cout << "\n\n";
    cout << "--------------------------------------------------" << endl;
    cout << "Felicidades jugador " << jugador << " eres el ganador" << endl;
    cout << "--------------------------------------------------" << endl;
    system("pause");
   
}

void limpiaTablero()
{
    int cont=1;

    for(int i = 2; i>=0; i--)
    {
        for(int j = 0; j<=2; j++)
        {
            matriz_juego[i][j]=cont+48;
            cont++;
        }
    }
}