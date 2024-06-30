#include "Jugador.h"
#include "ArchivoJugador.h"

//void cargarCadena(char *caracteres, int tam){
//    int i;
//    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
//    for(i=0; i<tam;i++){
//        caracteres[i]=cin.get();
//        if(caracteres[i]=='\n')break;
//    }
//    caracteres[i]='\0';
//    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
//}


int ArchivoJugador::contarRegistros(){
    FILE *p;
    p=fopen("partidas.dat","rb");
    if(p==NULL){
        std::cout<<"ERROR DE ARCHIVO"<<std::endl;
        return -1;
    }
    fseek(p, 0, 2);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes/sizeof(Jugador);
}

bool ArchivoJugador::grabarArchivo(Jugador obj){

       FILE *p;
    p=fopen("partidas.dat", "ab");
    if(p==NULL){
       std:: cout<<"ERROR DE ARCHIVO"<<std::endl;
        return false;
    }
    fwrite(&obj, sizeof (Jugador), 1, p);
    fclose(p);

        return true;

    }


Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        std::cout<<"ERROR DE ARCHIVO"<<std::endl;

        return obj;
    }
    fseek(p, pos * sizeof(Jugador), 0);
    fread(&obj, sizeof (Jugador), 1, p);
    fclose(p);
    return obj;
}


void ArchivoJugador::mostrarTodosJugadores(const char* filename) {
    int cantRegistros=contarRegistros();
    if (cantRegistros == -1) return;
    Jugador obj;

     FILE *p;
    p = fopen(filename, "rb");
    if (p == NULL) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }
    for(int i=0;i<cantRegistros;i++){
        obj=leerRegistro(i);
        obj.mostrarDatos();
        std::cout << "------------------" << std::endl;

    }
    fclose(p);
    }
