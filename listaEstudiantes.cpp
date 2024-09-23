#include <iostream>
using namespace std;

struct nodo {
    string nombreEstudiante;
    int codigoEstudiante;
    float notaEstudiante;
    nodo *sig;
};

nodo *cab, *estudiante, *codigo, *codigo2, *nota, *nota2;

void registrarDatosEstudiante(){
    char student;

    estudiante=(struct nodo*) malloc(sizeof(nodo));
    cout<<"Primer nombre del estudiante: ";
    cin>>estudiante->nombreEstudiante;
    cout<<"Codigo: ";
    cin>>codigo->codigoEstudiante;
    cout<<"nota: ";
    cin>>nota->notaEstudiante;
    
    estudiante->sig = NULL;

    if(!cab){
        cab = codigo;
    } else {
        codigo2=cab;
        while(codigo2->sig!=NULL){
            codigo2 = codigo2->sig;
        }
        codigo2->sig = codigo;

    }

    if(!cab){
        cab = nota;
    } else {
        nota2=cab;
        while(nota2->sig!=NULL){
            nota2 = nota2->sig;
        }
        nota2->sig = nota;

    }

}

void mostrarListaEstudiante(){

     estudiante=cab;
    while(estudiante!=NULL){
        cout<<"Primer nombre del estudiante: "<<estudiante->nombreEstudiante<<endl;
        cout<<"codigo: "<<codigo->codigoEstudiante<<endl;
        cout<<"nota: "<<nota->notaEstudiante<<endl;

        estudiante = estudiante->sig;

}

}

void ordenarPorCodigo(){

    int temporal;
    codigo2 = cab;
    while(codigo2->sig!=NULL){
        codigo = cab;
        while(codigo->sig!=NULL){
            if(codigo->codigoEstudiante > codigo->sig->codigoEstudiante){
                temporal = codigo->codigoEstudiante;
                codigo->codigoEstudiante = codigo->sig->codigoEstudiante;
                codigo->sig->codigoEstudiante = temporal;
            }
            codigo = codigo->sig;
        }
        codigo2 = codigo2->sig;
    }

}
void ordenarPorNota(){

    int temporal;
    nota2 = cab;
    while(nota2->sig!=NULL){
        nota = cab;
        while(nota->sig!=NULL){
            if(nota->notaEstudiante < nota->sig->notaEstudiante){
                temporal = nota->notaEstudiante;
                nota->notaEstudiante = nota->sig->notaEstudiante;
                nota->sig->notaEstudiante = temporal;
            }
            nota = nota->sig;
        }
        nota2 = nota2->sig;
    }
}
void encontrarNotaMayor(){
    if(!cab){
        cout<<"El estudiante no esta registrado"<<endl;
    }
    nota=cab;
    double notaMayor=cab->notaEstudiante;
    while(nota!= NULL)
    if(nota->notaEstudiante > notaMayor ){
        notaMayor=nota->notaEstudiante;
    }
    nota=nota->sig;    
}

void encontrarNotaMenor(){
    if(!cab){
        cout<<"El estudiante no esta registrado"<<endl;
    }
    nota=cab;
    double notaMenor=cab->notaEstudiante;
    while(nota!= NULL)
    if(nota->notaEstudiante < notaMenor ){
        notaMenor=nota->notaEstudiante;
    }
    nota=nota->sig;    
}
void calcularPromedioEstudiante(){


}

int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Resgistrar datos del estudiante"<<endl<<"2. Mostrar estudiantes en la lista"<<endl<<"3. Ordenar estudiantes por codigo"<<endl<<"4. Ordenar estudiantes por nota"<<endl<<"5. Obtener nota mayor"<<endl<<"6. Obtener nota menor"<<endl<<"7.Obtener promedio del estudiante"<<endl<<"8. Salir del programa"<<endl;
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
            ordenarPorCodigo();
            cout<< "Lista ordenada por codigo"<<endl;
        break;
        case 4:
            ordenarPorNota();
            cout<< "Lista ordenada por nota"<<endl;
        break;
         case 5:
            encontrarNotaMayor();
            cout<< "La nota mayoe es: "<<endl;
        break;   
        case 6:
            encontrarNotaMenor();
            cout<< "La nota menor es: "<<endl;
        break;   
        case 7:
            calcularPromedioEstudiante();
            cout<< "El promedio del estudiante es: "<<endl;
        break;    
        case 8:
            cout << "saliendo del programa"<<endl;
        break;
        }
    }while(opcion!=8);
}
