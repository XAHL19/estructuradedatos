#include <iostream>
using namespace std;

struct nodo {
    string nombreEstudiante;
    int codigoEstudiante;
    double notaEstudiante;
    nodo *sig;
};

nodo *cab, *aux1, *aux2;

void registrarDatosEstudiante(){

    aux1=(struct nodo*) malloc(sizeof(nodo));
    cout<<"Primer nombre del estudiante: ";
    cin>>aux1->nombreEstudiante;
    cout<<"Codigo: ";
    cin>>aux1->codigoEstudiante;
    cout<<"Nota: ";
    cin>>aux1->notaEstudiante;
    
    aux1->sig = NULL;

    if(!cab){
        cab = aux1;
    } else {
        aux2=cab;
        while(aux2->sig!=NULL){
            aux2 = aux2->sig;
        }
        aux2->sig = aux1;
    }

}

void mostrarListaEstudiante(){

     aux1=cab;
    while(aux1!=NULL){
        cout<<"Nombre: "<<aux1->nombreEstudiante<<endl;
        cout<<"Codigo: "<<aux1->codigoEstudiante<<endl;
        cout<<"Nota: "<<aux1->notaEstudiante<<endl;

        aux1 = aux1->sig;
    }
}

void ordenarLista(){

    int temporalCodigo;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux1 = cab;
        while(aux1->sig!=NULL){
            if(aux1->codigoEstudiante > aux1->sig->codigoEstudiante){
                temporalCodigo = aux1->codigoEstudiante;
                aux1->codigoEstudiante = aux1->sig->codigoEstudiante;
                aux1->sig->codigoEstudiante = temporalCodigo;
            }
            aux1 = aux1->sig;
        }
        aux2 = aux2->sig;
    }
    
    double temporalNota;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux1 = cab;
        while(aux1->sig!=NULL){
            if(aux1->notaEstudiante > aux1->sig->notaEstudiante){
                temporalNota = aux1->notaEstudiante;
                aux1->notaEstudiante = aux1->sig->notaEstudiante;
                aux1->sig->notaEstudiante = temporalNota;
            }
            aux1 = aux1->sig;
        }
        aux2 = aux2->sig;
    }

}

void encontrarNotaMayor(){
    if(!cab){
        cout<<"El estudiante no esta registrado"<<endl;
    }
    aux1=cab;
    double notaMayor=cab->notaEstudiante;

    while(aux1!= NULL)
    if(aux1->notaEstudiante > notaMayor ){
        notaMayor=aux1->notaEstudiante;
    }
    aux1=aux1->sig; 

    cout<<"Estudiante: "<<aux1->nombreEstudiante<<endl;
    cout<<"Codigo: "<<aux1->codigoEstudiante<<endl;
    cout<<"Nota mayor: "<<notaMayor<<endl;

}

void encontrarNotaMenor(){
    if(!cab){
        cout<<"El estudiante no esta registrado"<<endl;
    }
    aux1=cab;
    double notaMenor=cab->notaEstudiante;

    while(aux1!= NULL)
    if(aux1->notaEstudiante < notaMenor ){
        notaMenor=aux1->notaEstudiante;
    }
    aux1=aux1->sig;   

    cout<<"Estudiante: "<<aux1->nombreEstudiante<<endl;
    cout<<"Codigo: "<<aux1->codigoEstudiante<<endl;
    cout<<"Nota menor: "<<notaMenor<<endl;
 
}

void calcularPromedioEstudiante(){
    if (!cab) {
        cout << "El estudiante no esta registrado" << endl;
    }

    double notasEstudiante = 0;
    int cantidad = 0;
    aux1 = cab;

    while (aux1 != nullptr) {
        notasEstudiante += aux1->notaEstudiante;
        cantidad++;
        aux1 = aux1->sig;
    }

    double promedio = notasEstudiante / cantidad;

    cout<<"Estudiante: "<<aux1->nombreEstudiante<<endl;
    cout<<"Codigo"<<aux1->codigoEstudiante<<endl;
    cout<< "El promedio de las notas del estudiante es: " <<promedio<< endl;

}

int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Resgistrar datos del estudiante"<<endl<<"2. Mostrar estudiantes en la lista"<<endl<<"3. ordenar lista"<<endl<<"4. Encontrar nota mayor"<<endl<<"5. Encontrar nota menor"<<endl<<"6. Calcular promedio del estudiante"<<endl<<"7. Salir del programa"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrarDatosEstudiante();
        break;
        case 2:
            mostrarListaEstudiante();
        break;
        case 3:
            ordenarLista();
            cout<< "Lista ordenada"<<endl;
        break;
         case 4:
            encontrarNotaMayor();
            cout<< "Nota mayor: "<<endl;
        break;   
        case 5:
            encontrarNotaMenor();
            cout<< "Nota menor: "<<endl;
        break;   
        case 6:
            calcularPromedioEstudiante();
            cout<< "Promedio del estudiante: "<<endl;
        break;    
        case 7:
            cout << "Saliendo del programa"<<endl;
        break;
        }
    }while(opcion!=7);
}
