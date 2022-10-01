#include <iostream>
#include <string.h>
 
#define TAM 100
 
using namespace std;
 
//Prototipos
void Menu();
void dibujaAhorcado(int intentos);
int ini_palabra_misterio(char palabra_misterio[TAM]);
void ini_palabra_adivinar(int num_letras, char palabra_adivinar[TAM]);
void imprimir_palabra(int num_letras, char palabra_adivinar[TAM]);
void adivinaLetra(int num_letras, char palabra_misterio[TAM], char palabra_adivinar[TAM]);
 
int main(void)
{
    int control_menu;
    char palabra_misterio[TAM];
    char palabra_adivinar[TAM];
    int num_letras;
 
    while(true)
    {
        Menu();
        cin >> control_menu;
       
        switch(control_menu)
        {
        case 0:
            cout << "Gracias por jugar, vuelve pronto :D";
            return 0;
        break;
       
        case 1:
            num_letras = ini_palabra_misterio(palabra_misterio);
 
            ini_palabra_adivinar(num_letras, palabra_adivinar);
 
            dibujaAhorcado(7);
 
            imprimir_palabra(num_letras, palabra_adivinar);
 
            system("pause");
        break;
 
        default:
            cout << "Opcion incorrecta, vuelve a intentarlo";
            system("pause");
        break;
        }
    }
}
 
//Función para imprimir el menu
void Menu()
{
    //Imprime el menu de opciones
    system("cls");
    cout << "\n--------------------------------------------------" << endl;
    cout << "\t\tAHORCADO" << endl;
    cout << "1.- Jugar" << endl;
    cout << "0.- Salir" << endl << endl;
    cout << "Elija la opcion: ";
}
 
int ini_palabra_misterio(char palabra_misterio[TAM])
{
    cout << "Jugador maestro, escribe la palabra secreta: ";
 
    cin.ignore();
    cin.getline(palabra_misterio,TAM);
    cin.clear();
 
    return strlen(palabra_misterio);
}
 
void ini_palabra_adivinar(int num_letras, char palabra_adivinar[TAM])
{
    for(int i = 0; i < num_letras; i++)
        palabra_adivinar[i] = '_';
}
 
void imprimir_palabra(int num_letras, char palabra_adivinar[TAM])
{
    cout << "\n\n";
    for(int i = 0; i < num_letras; i++)
        cout << palabra_adivinar[i] << ' ';
}

void adivinaLetra(int num_letras, char palabra_misterio[TAM], char palabra_adivinar[TAM])
{
    char letra[TAM];
    bool una_letra = false;

    while(una_letra==false)
    {
        cout << "Ingresa una letra: ";
        cin.getline(letra,TAM);

        if(strlen(letra)>1)
        {
            
        }
    }

    
    for(int i = 0; i<num_letras; i++)
    {

    }
}

 
//Dibujo de ahorcado según intentos
//------------------------------------------------------------------------------
void dibujaAhorcado(int intentos)
{
    //Limpia pantalla
    system("cls");
 
    //Título
    cout << "\n--------------------------------------------------" << endl;
    cout << "\t\tAhorcado";
    cout << "\n--------------------------------------------------" << endl;
 
    switch(intentos)
    {
        case 0:  
            printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
            break;
        case 1:
            printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
            break;
        case 2:
            printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
            break;
        case 3:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
            break;
        case 4:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |\n    |\n    |\n ----------");
            break;
        case 5:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |      /\n    |\n    |\n ----------");
            break;
        case 6:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |      / ");
            printf("\\");
            printf("\n");
            printf("    |\n    |\n ----------");
            break;
        case 7:
            printf("\n     _______\n    |       |\n    |_______0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |      / ");
            printf("\\");
            printf("\n");
            printf("    |\n    |\n ----------");
            break;
    }
}