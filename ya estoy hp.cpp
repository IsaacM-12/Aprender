#include <iostream>
#include <string>
#include <cstdlib>

/*

Isaac Melendez Gatgens
2021123344

Pablo Sandi Sanchez
2021120523

Axel Solano Bejarano
2021453483


*/
using namespace std;


struct administrador{
    string nombre;
    administrador* sig;

    administrador(string n){
        nombre = n;
        sig = NULL;
    };
};


struct profesor{
    int cedula;
    string nombre;
    profesor * sig, *ant;
    struct enlaceProfesor * suGrupo;

    profesor(string x,int c){
        suGrupo = NULL;
        nombre = x;
        cedula = c;
        sig= NULL;
        ant= NULL;
    }
};


struct semestre{
    int sem;
    int year;
    semestre*sig, *ant;
    struct charla* suCharla;
    struct enlaceSemestre* suCurso;

    semestre(int x, int y){
        suCurso = NULL;
        sem = x;
        year = y;
        sig= NULL;
        ant= NULL;
        suCharla = NULL;
    }
};


struct estudiante{
    string nombre;
    int carnet;
    estudiante* sig;
    struct enlaceEstudiante * suGrupo;

    estudiante(string n, int x){
        suGrupo = NULL;
        nombre = n;
        carnet = x;
        sig = NULL;
    };
};


struct curso{
    string codigo;
    string nombre;
    int creditos;
    curso *sig;
    struct grupo* enlaceG;

    curso(string x, string h, int c){
        enlaceG = NULL;
        nombre = x;
        codigo = h;
        creditos = c;
        sig = NULL;

    }
};


struct grupo{
    int num;
    grupo* sig;
    int cupos;
    string aula;
    curso * enlaceCurso;

    struct actividades* tarea;
    struct actividades* proyecto;
    struct actividades* gira;
    struct actividades* examen;

    grupo(int n, int c,string a){
        enlaceCurso = NULL;
        aula = a;
        cupos = c;
        num = n;
        tarea= NULL;
        proyecto = NULL;
        gira = NULL;
        examen= NULL;
        sig = NULL;
    };
};


struct charla{
    int dia;
    int mes;
    int num;
    charla* sig;

    charla(int n,int d, int m){
        mes = m;
        dia = d;
        num = n;
        sig = NULL;
    };
};

/*
struct charlaAsistida{
    int dia;
    int mes;
    int num;
    charla* sig;

    charlaAsistida(int n, int d, int m){
        mes = m;
        dia = d;
        num = n;
        sig = NULL;
    };
};
*/

struct charlaAsistida{
    int num;
    charlaAsistida* sig;
    int year;
    int sem;

    charlaAsistida(int n, int y, int s){
        num = n;
        year = y;
        sem = s;
        sig = NULL;
    };
};


struct actividades{
    actividades* sig;
    int numero;
    int dia;
    int mes;
    int valor;
    string nombre;

    actividades(int n, int d,int m, int v, string h){
        sig = NULL;
        valor = v;
        numero = n;
        dia = d;
        mes = m;
        nombre = h;
    };
};

/*
struct actividadesEntregadas{
    actividadesEntregadas* sig;
    int numero;
    int dia;
    int mes;
    int valor;
    string nombre;

    actividadesEntregadas(int n, int d, int m ,int v, string h){
        sig = NULL;
        valor = v;
        numero = n;
        dia = d;
        mes = m;
        nombre = h;
    };
};
*/
struct actividadesEntregadas{
    actividadesEntregadas* sig;
    int numero;
    int nota;
    string nombre;
    int grupo;
    string curso;

    actividadesEntregadas(int n, string h, int g, string c){
        sig = NULL;
        numero = n;
        nombre = h;
        nota = 100;
        grupo = g;
        curso = c;
    };
};






                                                                                //STRUCT ENLACE

struct enlaceProfesor{
    enlaceProfesor* sig;
    grupo * enlaceG;

    enlaceProfesor(){
        sig = NULL;
        enlaceG = NULL;

    };
};


struct enlaceEstudiante{
    enlaceEstudiante* sig;
    grupo * enlaceG;
    actividadesEntregadas * actividad;
    charlaAsistida * charlas;

    enlaceEstudiante(){
        sig = NULL;
        enlaceG = NULL;
        actividad = NULL;
        charlas = NULL;
    };
};


struct enlaceSemestre{
    enlaceSemestre* sig;
    curso * enlaceC;

    enlaceSemestre(){
        sig = NULL;
        enlaceC = NULL;
    };
};







                                                                                //GLOBALES

administrador * lisadmin;
profesor * lisprofesor;
semestre * lissemestre;
estudiante * lisestudiante;
curso * liscurso;
grupo * lisgrupo; //no deberia haber un lisgrupo







                                                                                //BUSCAR


estudiante* buscarEstudiante(int x, estudiante* lista){
    if(lista == NULL)
        return NULL;
    estudiante *temp = lista;

    while(temp!= NULL){

        if(temp->carnet == x)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


profesor* buscarProfe(int x, profesor* lista){


    if(lista == NULL)
        return NULL;
    profesor *temp = lista;

    while(temp!= NULL){

        if(temp->cedula == x)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


grupo* buscarGrupo(int x, grupo* lista){


    if(lista == NULL)
        return NULL;
    grupo *temp = lista;

    while(temp!= NULL){

        if(temp->num == x)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


grupo* buscarGrupoCurso(int x, grupo* lista, string curso){


    if(lista == NULL)
        return NULL;
    grupo *temp = lista;

    while(temp!= NULL){

        if(temp->num == x && temp->enlaceCurso->nombre == curso)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


curso* buscarCurso(string x, curso* lista){


    if(lista == NULL)
        return NULL;
    curso *temp = lista;

    do{

        if(temp->nombre == x)
            return temp;

        temp = temp->sig;
    }while(temp!= lista);

    return NULL;
}

semestre* buscarSemestre(int year,int sem,semestre* lista){

    if(lista == NULL)
        return NULL;

    semestre *temp = lista;

    while(temp!= NULL){

        if((temp->sem == sem) && (temp->year == year))
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


actividades* buscarActividad(int x, actividades *lista){
    if(lista == NULL)
        return NULL;
    actividades *temp = lista;

    while(temp!= NULL){

        if(temp->numero == x)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


actividades* buscarActividadValor(int x,int y, actividades *lista){
    if(lista == NULL)
        return NULL;
    actividades *temp = lista;

    while(temp!= NULL){

        if((temp->numero == x)&&(temp->valor == y))
            return temp;

        temp = temp->sig;
    }

    return NULL;
}


charla* buscarCharla(int x, charla *lista){
    if(lista == NULL)
        return NULL;
    charla *temp = lista;

    while(temp!= NULL){

        if(temp->num == x)
            return temp;

        temp = temp->sig;
    }

    return NULL;
}






                                                                                //MODIFICAR


void modificarCurso(string cActual, string nNuevo, string cNuevo, int creNuevo,curso *lista){

            if(lista == NULL)
                    cout<<"\nLista vacia.";
            else{
                curso *temp = lista;

                while(temp!= liscurso){

                    if(temp->codigo == cActual){
                        temp->nombre= nNuevo;
                        temp->codigo= cNuevo;
                        temp->creditos= creNuevo;
                        cout<<"\nSe modifico correctamente";
                        break;
                    }
                    temp = temp->sig;
                }
            }
}


void modificarProfesorNombre(string nActual, string nNuevo, profesor *lista){

            if(lista == NULL)
                    cout<<"\nLista vacia.";
            else{
                profesor *temp = lista;

                while(temp!= NULL){

                    if(temp->nombre == nActual){
                        temp->nombre= nNuevo;
                        cout<<"\nSe modifico correctamente";
                        break;
                    }
                    temp = temp->sig;
                }
            }
}


void modificarProfesorCedula(int cActual, int cNuevo, profesor *lista){

            if(lista == NULL)
                    cout<<"\nLista vacia.";
            else{
                profesor *temp = lista;

                while(temp!= NULL){

                    if(temp->cedula == cActual){
                        temp->cedula= cNuevo;
                        cout<<"\nSe modifico correctamente";
                        break;
                    }
                    temp = temp->sig;
                }
            }
}


void modificarEstudianteNombre(string nActual, string nNuevo, estudiante *lista){

            if(lista == NULL)
                    cout<<"\nLista vacia.";
            else{
                estudiante *temp = lista;

                while(temp!= NULL){

                    if(temp->nombre == nActual){
                        temp->nombre= nNuevo;
                        cout<<"\nSe modifico correctamente";
                        break;
                    }
                    temp = temp->sig;
                }
            }
}


void modificarEstudianteCarnet(int cActual, int cNuevo, estudiante *lista){

            if(lista == NULL)
                    cout<<"\nLista vacia.";
            else{
                estudiante *temp = lista;

                while(temp!= NULL){

                    if(temp->carnet == cActual){
                        temp->carnet= cNuevo;
                        cout<<"\nSe modifico correctamente";
                        break;
                    }
                    temp = temp->sig;
                }
            }
}


void modificarActividad(string tipo, int nActual,int vActual, int nNuevo, int vNuevo, int cedula,int numGrupo, string nombreCurso, profesor * lista){

    profesor * tempE = buscarProfe(cedula,lista);
    if(tempE == NULL){
        cout<<"No se encuentra el estudiante";
        return;
    }
    else{

        enlaceProfesor *temp = tempE->suGrupo;
        curso *tempC = temp->enlaceG->enlaceCurso;

            if(temp->enlaceG->num = numGrupo){
                cout<<tempC->nombre<<endl;
                if(tempC->nombre == nombreCurso){


                    if(tipo == "proyecto" ){
                        actividades*actividad = buscarActividadValor(nActual,vActual, temp->enlaceG->proyecto);
                        if(actividad != NULL){
                            actividad->numero = nNuevo;
                        }
                    else{
                        cout<<"El grupo no tiene proyectos"<<endl;
                        return;
                    }
                }

                    if(tipo == "tarea" ){
                        actividades*actividad = buscarActividadValor(nActual,vActual, temp->enlaceG->tarea);
                        if(actividad != NULL){
                            actividad->numero = nNuevo;
                        }
                    else{
                        cout<<"El grupo no tiene tareas"<<endl;
                        return;
                    }
                }

                    if(tipo == "gira" ){
                        actividades*actividad = buscarActividadValor(nActual,vActual, temp->enlaceG->gira);
                        if(actividad != NULL){
                            actividad->numero = nNuevo;
                        }
                    else{
                        cout<<"El grupo no tiene giras"<<endl;
                        return;
                    }
                }

                    if(tipo == "examen" ){
                        actividades* actividad = buscarActividadValor(nActual,vActual, temp->enlaceG->examen);
                        if(actividad != NULL){
                            actividad->numero = nNuevo;
                        }
                    else{
                        cout<<"El grupo no tiene examenes"<<endl;
                        return;
                    }
                }
            }


    }
}
}








                                                                                //BORRAR


void borrarCurso(string n,curso *lista){


        if(lista == NULL){
            cout <<"\nLista vacía";
            return ;
        }
        else if(lista->codigo== n){
            lista = lista->sig;
            return ;
        }
        else{
                 curso *temp = lista->sig;
                 curso *tempAnt= lista->sig;
                    while(temp != liscurso){

                            if(temp->codigo == n){
                                    tempAnt->sig  = temp->sig;
                                    return ;
                            }

                            tempAnt= temp;
                            temp = temp->sig;
                    }

            if(temp==liscurso){
                cout<<"El codigo no esta en la lista.";
                return ;
            }

        }
}


profesor * borrarProfesor(int cedula, profesor * lista){

    if(lista == NULL)
            cout<<"\nNo hay profesores";
    else if(lista->cedula == cedula){
                lista = lista->sig;
                if(lista != NULL)
                    lista->ant = NULL;
            }

    else{

        profesor * temp = lista;
        profesor * tempAnt = NULL;

        while(temp!= NULL){

            if(temp->cedula == cedula){
                tempAnt->sig = temp->sig;
                if(temp->sig!= NULL)
                    temp->sig->ant= tempAnt;
                break;
            }
            tempAnt = temp;
            temp = temp->sig;

        }
    }
    return lista;
}


void borrarEstudiante(int n){


        if(lisestudiante == NULL){
            cout <<"\nLista vacia";
            return ;
        }
        else if(lisestudiante->carnet== n){
            lisestudiante = lisestudiante->sig;
            return ;
        }
        else{
                 estudiante *temp = lisestudiante;
                 estudiante *tempAnt= lisestudiante;
                    while(temp != NULL){

                            if(temp->carnet == n){
                                    tempAnt->sig  = temp->sig;
                                    return ;
                            }

                            tempAnt= temp;
                            temp = temp->sig;
                    }

            if(temp==NULL){
                cout<<"El carnet no esta en la lista.";
                return ;
            }

        }
}









                                                                                //RELACIONES


void relacionarProfesor(int cedula,profesor* listaP, int num, grupo* listaG, string curso){
    profesor* profe = buscarProfe(cedula, listaP);
    if(profe == NULL){
        cout<<"El profesor no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupoCurso(num, listaG, curso);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    enlaceProfesor* nnP = new enlaceProfesor();

    nnP->enlaceG = grupo;
    nnP->sig = profe->suGrupo;

    profe->suGrupo = nnP;

}


void borrarRelacionProfesor(int cedula,profesor* listaP, int num, grupo* listaG,string curso){
    profesor* profe = buscarProfe(cedula, listaP);
    if(profe == NULL){
        cout<<"El profesor no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupoCurso(num, listaG, curso);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    if(profe->suGrupo == NULL){
            cout <<"\nLista vacia";
            return ;
        }
        else if(profe->suGrupo->enlaceG== grupo){
            profe->suGrupo = profe->suGrupo->sig;
            return ;
        }
        else{
                 enlaceProfesor *temp = profe->suGrupo;
                 enlaceProfesor *tempAnt= profe->suGrupo;
                    while(temp != NULL){

                            if(temp->enlaceG == grupo){
                                    tempAnt->sig  = temp->sig;
                                    return ;
                            }

                            tempAnt= temp;
                            temp = temp->sig;
                    }

            if(temp==NULL){
                cout<<"El profesor no esta enlazado al grupo.";
                return ;
            }

        }

}



void relacionarGrupoCurso(string nombre, curso* listaC, int num, grupo* listaG){
    curso* curso = buscarCurso(nombre, listaC);
    if(curso == NULL){
        cout<<"El curso no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupo(num, listaG);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }


    curso->enlaceG = grupo;

    grupo->enlaceCurso = curso;

}



void relacionarEstudiante(int carnet, estudiante* listaE, int num, grupo* listaG, string curso){
    estudiante* estudiante = buscarEstudiante(carnet, listaE);
    if(estudiante == NULL){
        cout<<"El Estudiante no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupoCurso(num, listaG, curso);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    enlaceEstudiante* nnE = new enlaceEstudiante();

    nnE->enlaceG = grupo;
    nnE->sig = estudiante->suGrupo;

    estudiante->suGrupo = nnE;

}


void borrarRelacionEstudiante(int carnet, estudiante* listaE, int num, grupo* listaG, string curso){
    estudiante* estudiante = buscarEstudiante(carnet, listaE);
    if(estudiante == NULL){
        cout<<"El Estudiante no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupoCurso(num, listaG, curso);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    if(estudiante->suGrupo == NULL){
            cout <<"\nLista vacia";
            return ;
        }
        else if(estudiante->suGrupo->enlaceG== grupo){
            estudiante->suGrupo = estudiante->suGrupo->sig;
            return ;
        }
        else{
                 enlaceEstudiante *temp = estudiante->suGrupo;
                 enlaceEstudiante *tempAnt= estudiante->suGrupo;
                    while(temp != NULL){

                            if(temp->enlaceG == grupo){
                                    tempAnt->sig  = temp->sig;
                                    return ;
                            }

                            tempAnt= temp;
                            temp = temp->sig;
                    }

            if(temp==NULL){
                cout<<"El estudiante no esta enlazado al grupo.";
                return ;
            }

        }

}


void registrarActividadCumplida(int carnet, string nombreCurso, int numGrupo, int numActividad, string tipo, estudiante * lista){

    estudiante * tempEst = buscarEstudiante(carnet,lista);
    if(tempEst == NULL){
        cout<<"No se encuentra el estudiante";
        return;
    }
    else{

        enlaceEstudiante*temp = tempEst->suGrupo;

            if(temp->enlaceG->num = numGrupo){
                if(temp->enlaceG->enlaceCurso->nombre == nombreCurso){

                    actividadesEntregadas *nn = new actividadesEntregadas(numActividad, tipo, numGrupo, nombreCurso);

                    if(tipo == "proyecto" ){

                        if(buscarActividad(numActividad, temp->enlaceG->proyecto) != NULL){
                            nn->sig = temp->actividad;
                            temp->actividad = nn;
                        }
                    else{
                        cout<<"El grupo no tiene proyectos"<<endl;
                        return;
                    }
                }

                    if(tipo == "tarea" ){
                        if(buscarActividad(numActividad, temp->enlaceG->tarea) != NULL){
                            nn->sig = temp->actividad;
                            temp->actividad = nn;
                        }
                    else{
                        cout<<"El grupo no tiene tareas"<<endl;
                        return;
                    }
                }

                    if(tipo == "gira" ){
                        if(buscarActividad(numActividad, temp->enlaceG->gira) != NULL){
                            nn->sig = temp->actividad;
                            temp->actividad = nn;
                        }
                    else{
                        cout<<"El grupo no tiene giras"<<endl;
                        return;
                    }
                }

                    if(tipo == "examen" ){
                        if(buscarActividad(numActividad, temp->enlaceG->examen) != NULL){
                            nn->sig = temp->actividad;
                            temp->actividad = nn;
                        }
                    else{
                        cout<<"El grupo no tiene examenes"<<endl;
                        return;
                    }
                }

                }
            }
    if(temp == NULL){

        cout<<"No tiene el grupo asignado";
        return;
    }

        }

}


void registrarCharlaAsistida(int carnet, int ano, int sem, int numCharla, estudiante * lista, semestre * listaSem){

    estudiante * tempEst = buscarEstudiante(carnet,lista);
    if(tempEst == NULL){
        cout<<"No se encuentra el estudiante";
        return;
    }

    semestre * tempSem = buscarSemestre(ano, sem, listaSem);
    if(tempSem == NULL){
        cout<<"No se encuentra el semestre";
        return;
    }

    else{

        if(tempEst->suGrupo != NULL){
            enlaceEstudiante*temp = tempEst->suGrupo;

            charlaAsistida * nn = new charlaAsistida(numCharla, ano, sem);

            if(buscarCharla(numCharla, tempSem->suCharla) != NULL){
                nn->sig = temp->charlas;
                temp->charlas = nn;
            }
            else{
                cout<< "La charla no existe en el semestre" << endl;
            }
        }
        else{
            cout<<"El estudiante debe estar relacionado a un curso antes de poder relacionarse con una charla"<<endl;
        }

        }

}






                                                                                //IMPRIMIR


void imprimirEstudiante(estudiante* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        estudiante *temp = lista;
        while(temp != NULL){
            cout<<"nombre " << temp->nombre<<" - carnet "<< temp->carnet<<"  - relacionado con " << temp->suGrupo <<endl;

            temp = temp->sig;
        }
    }
}


void imprimirSemestre(semestre* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        semestre *temp = lista;
        while(temp != NULL){
            cout<<"semestre " << temp->sem <<" - year "<< temp->year<< endl;

            temp = temp->sig;
        }
    }
}


void imprimirGrupo(grupo* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        grupo *temp = lista;
        while(temp != NULL){
            cout<<"numero " << temp->num<<" - cupos "<< temp->cupos<<"  - aula "<< temp->aula << "    -   enlace " << temp->enlaceCurso->nombre<<endl;

            temp = temp->sig;
        }
    }
}


void imprimirActividad(grupo* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        actividades * tempA;
        grupo *tempG = lista;

        cout << "\n";
        while(tempG != NULL){
            tempA = tempG->tarea;
            while(tempA != NULL){
                cout<<tempA->nombre<<"  - valor  "<< tempA->valor<<endl;
                tempA = tempA->sig;
            }
            tempG = tempG->sig;
        }


        tempG = lista;
        cout << "\n\n";
        while(tempG != NULL){
            tempA = tempG->proyecto;
            while(tempA != NULL){
                cout<<tempA->nombre<<"  - valor  "<< tempA->valor<<endl;
                tempA = tempA->sig;
            }
            tempG = tempG->sig;
        }


        tempG = lista;
        cout << "\n\n";
        while(tempG != NULL){
            tempA = tempG->examen;
            while(tempA != NULL){
                cout<<tempA->nombre<<"  - valor  "<< tempA->valor<<endl;
                tempA = tempA->sig;
            }
            tempG = tempG->sig;
        }

        tempG = lista;
        cout << "\n\n";
        while(tempG != NULL){
            tempA = tempG->gira;
            while(tempA != NULL){
                cout<<tempA->nombre<<"  - valor  "<< tempA->valor<<endl;
                tempA = tempA->sig;
            }
            tempG = tempG->sig;
        }
    }
}


void imprimirActividadInforme(int n,grupo* lista,string t){

    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        actividades * tempA;
        grupo *tempG = buscarGrupo(n,lista);

        cout << "\n";

            tempA = tempG->tarea;
            while(tempA != NULL){
                cout<<tempA->nombre<<"- Numero :" <<tempA->numero <<"  - Mes:  "<< tempA->mes<< " - Dia :"<< tempA->dia << " - Curso : "<<t<<endl;
                tempA = tempA->sig;
            }



        tempG = buscarGrupo(n,lista);;
        cout << "\n";

            tempA = tempG->proyecto;
            while(tempA != NULL){
                cout<<tempA->nombre<<"- Numero :" <<tempA->numero <<"  - Mes:  "<< tempA->mes<< " - Dia :"<< tempA->dia <<" - Curso : "<<t<<endl;
                tempA = tempA->sig;
            }



        tempG = buscarGrupo(n,lista);
        cout << "\n";

            tempA = tempG->examen;
            while(tempA != NULL){
                cout<<tempA->nombre<<"- Numero :" <<tempA->numero <<"  - Mes:  "<< tempA->mes<< " - Dia :"<< tempA->dia <<" - grupo : " <<tempG->num<<" - Curso : "<<t<<endl;
                tempA = tempA->sig;
            }


        tempG = buscarGrupo(n,lista);
        cout << "\n";

            tempA = tempG->gira;
            while(tempA != NULL){
                cout<<tempA->nombre<<"- Numero :" <<tempA->numero <<"  - Mes:  "<< tempA->mes<< " - Dia :"<< tempA->dia <<" - Curso : "<<t<<endl;
                tempA = tempA->sig;
            }

    }
}


void imprimirProfesor(profesor* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        profesor *temp = lista;
        while(temp != NULL){
            cout<<"nombre " << temp->nombre<<" - cedula "<< temp->cedula<< endl;

            temp = temp->sig;
        }
    }
}


void imprimirCurso(curso* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        curso *temp = lista;
        do{
            cout<<"nombre " << temp->nombre<<" - codigo "<< temp->codigo<<"  - creditos "<<temp->creditos<<endl;

            temp = temp->sig;
        }while(temp != lista);
    }
}


void imprimirInforme(int nombreE){

        profesor *tempE = buscarProfe(nombreE,lisprofesor);
        if(tempE== NULL){
            cout<<"No se encuentra ";
            return;
        }


        enlaceProfesor *tempM = tempE->suGrupo;

        while(tempM != NULL){

            grupo* grup = tempM->enlaceG;
            string temp = grup->enlaceCurso->nombre;

            int ng = grup->num;
            imprimirActividadInforme(ng,lisgrupo,temp);
            tempM = tempM->sig;
        }


}


void imprimirCharla(semestre* lista){
    if (lista == NULL)
        cout << "\nNo hay semestres\n";
    else{
        charla * tempC;
        semestre *tempS = lista;

        cout << "\n";


        while(tempS != NULL){
            tempC = tempS->suCharla;

            while(tempC != NULL){
                cout<<"Numero :" << tempC->num <<"  - Mes:  "<< tempC->mes << " - Dia :"<< tempC->dia <<endl;
                tempC = tempC->sig;
            }
            tempS = tempS->sig;
        }
    }
}















                                                                                //INSERTAR


administrador* insertarInicioAdministrador(string x, administrador* lista){

    administrador* nn = new administrador(x);
    nn->sig = lista;
    lista = nn;

    return lista;
}


profesor* insertarInicioProfesor(string n, int c, profesor* lista){

    profesor *nn = new profesor(n, c);

    nn->sig = lista;

    if(lista != NULL)
        lista->ant = nn;

    lista = nn;


return lista;
}


semestre* insertarOrdenadoSemestre(int num,int year, semestre* lista){

    semestre *nn = new semestre(num,year);

    if(lista == NULL)
        lista = nn;

    else if(year < lista->year){
            nn->sig = lista;
            lista->ant = nn;
            lista = nn;
    }

    else if((year == lista->year) && (num < lista->sem)){

            nn->sig = lista;
            lista->ant = nn;
            lista = nn;
            }
     else{

        semestre*temp = lista;
        semestre*tempAnt = NULL;

        while((temp != NULL) && (year > temp->year)){
                tempAnt = temp;
                temp = temp->sig;
        }

        if(temp == NULL){
               tempAnt->sig = nn;
               nn->ant =  tempAnt;
        }
        else if((year == temp->year) && (num < temp->sem)){
            nn->sig = temp;
            nn->ant = tempAnt;
            tempAnt->sig = nn;
            temp->ant = nn;
            }

        else{
            if(temp->sig != NULL){
            nn->sig = temp->sig;
            temp->sig->ant = temp;
            }
            temp->sig = nn;
            nn->ant = temp;
        }
     }


    return lista;
}


curso * insertarFinalCursos(string n, string co, int cre, curso* lista){

            curso* nn = new curso(n, co, cre);
                if(lista == NULL){
                    lista = nn;
                    lista->sig = lista;// nn->sig = nn;
                }
                else{

                    //buscar el ultimo para que apunte al nuevo
                    curso* temp = lista;
                    while(temp->sig != lista){
                        temp = temp->sig;
                    }
                    temp->sig= nn;
                    nn->sig = lista;// el nuevo se enlaza con el primero
                }
    return lista;
}


void insertarActividadProfe(string tipo, int valor, int num, int mes, int dia, string curso, int grupo, int cedula){

    profesor * tempProf = buscarProfe(cedula,lisprofesor);
    if(tempProf == NULL){
        cout<<"No se encuentra el profesor";
        return;
    }
    else{

    enlaceProfesor *temp = tempProf->suGrupo;
    while(temp!= NULL){
        if(temp->enlaceG->num = grupo){
                if(temp->enlaceG->enlaceCurso->nombre == curso){

                    actividades *nn = new actividades(num,dia,mes,valor,tipo);

                    if(tipo == "proyecto" ){

                        if(temp->enlaceG->proyecto == NULL){
                            temp->enlaceG->proyecto = nn;
                        }

                        else if(mes < temp->enlaceG->proyecto->mes){
                            nn->sig = temp->enlaceG->proyecto;
                            temp->enlaceG->proyecto = nn;
                        }

                        else if((mes == temp->enlaceG->proyecto->mes) && (dia < temp->enlaceG->proyecto->dia)){
                                nn->sig = temp->enlaceG->proyecto;
                                temp->enlaceG->proyecto = nn;
                                }
                        else{
                            actividades * tempA = temp->enlaceG->proyecto;
                            actividades * tempAnt = temp->enlaceG->proyecto;

                            while((tempA != NULL) && (mes > tempA->mes)){
                                tempAnt = tempA;
                                tempA = tempA->sig;
                            }

                            if(tempA == NULL){
                                   tempAnt->sig = nn;
                            }

                            else if((mes == tempA->mes) && (dia < tempA->dia)){
                                nn->sig = tempA;
                                tempAnt->sig = nn;
                                }

                            else{
                                if(tempA->sig != NULL){
                                nn->sig = tempA->sig;
                                }
                                tempA->sig = nn;

                            }
                         }
                }

                    else if(tipo == "tarea" ){

                        if(temp->enlaceG->tarea == NULL){
                            temp->enlaceG->tarea = nn;
                        }

                        else if(mes < temp->enlaceG->tarea->mes){
                            nn->sig = temp->enlaceG->tarea;
                            temp->enlaceG->tarea = nn;
                        }

                        else if((mes == temp->enlaceG->tarea->mes) && (dia < temp->enlaceG->tarea->dia)){
                                nn->sig = temp->enlaceG->tarea;
                                temp->enlaceG->tarea = nn;
                                }
                        else{
                            actividades * tempA = temp->enlaceG->tarea;
                            actividades * tempAnt = temp->enlaceG->tarea;

                            while((tempA != NULL) && (mes > tempA->mes)){
                                tempAnt = tempA;
                                tempA = tempA->sig;
                            }

                            if(tempA == NULL){
                                   tempAnt->sig = nn;
                            }

                            else if((mes == tempA->mes) && (dia < tempA->dia)){
                                nn->sig = tempA;
                                tempAnt->sig = nn;
                                }

                            else{
                                if(tempA->sig != NULL){
                                nn->sig = tempA->sig;
                                }
                                tempA->sig = nn;
                            }
                         }
                    }
                    else if(tipo == "gira" ){

                        if(temp->enlaceG->gira == NULL){
                            temp->enlaceG->gira = nn;
                        }

                        else if(mes < temp->enlaceG->gira->mes){
                            nn->sig = temp->enlaceG->gira;
                            temp->enlaceG->gira = nn;
                        }

                        else if((mes == temp->enlaceG->gira->mes) && (dia < temp->enlaceG->gira->dia)){
                                nn->sig = temp->enlaceG->gira;
                                temp->enlaceG->gira = nn;
                                }
                        else{
                            actividades * tempA = temp->enlaceG->gira;
                            actividades * tempAnt = temp->enlaceG->gira;

                            while((tempA != NULL) && (mes > tempA->mes)){
                                tempAnt = tempA;
                                tempA = tempA->sig;
                            }

                            if(tempA == NULL){
                                   tempAnt->sig = nn;
                            }

                            else if((mes == tempA->mes) && (dia < tempA->dia)){
                                nn->sig = tempA;
                                tempAnt->sig = nn;
                                }

                            else{
                                if(tempA->sig != NULL){
                                nn->sig = tempA->sig;
                                }
                                tempA->sig = nn;
                            }
                         }
                    }
                    else if(tipo == "examen" ){

                        if(temp->enlaceG->examen == NULL){
                            temp->enlaceG->examen = nn;
                        }

                        else if(mes < temp->enlaceG->examen->mes){
                            nn->sig = temp->enlaceG->examen;
                            temp->enlaceG->examen = nn;
                        }

                        else if((mes == temp->enlaceG->examen->mes) && (dia < temp->enlaceG->examen->dia)){
                                nn->sig = temp->enlaceG->examen;
                                temp->enlaceG->examen = nn;
                                }
                        else{
                            actividades * tempA = temp->enlaceG->examen;
                            actividades * tempAnt = temp->enlaceG->examen;

                            while((tempA != NULL) && (mes > tempA->mes)){
                                tempAnt = tempA;
                                tempA = tempA->sig;
                            }

                            if(tempA == NULL){
                                   tempAnt->sig = nn;
                            }

                            else if((mes == tempA->mes) && (dia < tempA->dia)){
                                nn->sig = tempA;
                                tempAnt->sig = nn;
                                }

                            else{
                                if(tempA->sig != NULL){
                                nn->sig = tempA->sig;
                                }
                                tempA->sig = nn;

                            }
                         }
                    }
                    else{
                        cout<<"El tipo de asignacion no existe";
                        return;

                    }
                    cout<<"Se inserto la asignacion correctamente";
                    break;//se sale cuando lo inserta
                }
        }

        temp = temp->sig;
    }
    if(temp == NULL){

        cout<<"No tiene el curso asignado";
        return;
    }
    }
}


estudiante * insertarEstudianteOrdenado(string nombre,int carnet){
    estudiante* nn = new estudiante(nombre,carnet);

    if(lisestudiante == NULL){
        lisestudiante = nn;
    }

    else if(carnet < lisestudiante->carnet){
        nn->sig = lisestudiante;
        lisestudiante = nn;
    }

    else{
        estudiante*temp = lisestudiante;
        estudiante*tempAnt = lisestudiante;
        while((temp != NULL) && (carnet > temp->carnet)){
            tempAnt = temp;
            temp = temp->sig;
        }
        tempAnt->sig = nn;
        nn->sig = temp;
    }
    return lisestudiante;
}


grupo * insertarGrupoOrdenado(int num,int cupos,string aula, string curso){
    grupo* nn = new grupo(num,cupos,aula);

    if(lisgrupo == NULL){
        lisgrupo = nn;
    }

    else if(num < lisgrupo->num){
        nn->sig = lisgrupo;
        lisgrupo = nn;
    }

    else{
        grupo*temp = lisgrupo;
        grupo*tempAnt = lisgrupo;
        while((temp != NULL) && (num > temp->num)){
            tempAnt = temp;
            temp = temp->sig;
        }
        tempAnt->sig = nn;
        nn->sig = temp;
    }

    relacionarGrupoCurso(curso, liscurso, num, lisgrupo);

    return lisgrupo;
}


void insertarCharlaSemestre(int year,int num, int mes,int dia, int nCharla,semestre * lista){

    semestre * tempSem = buscarSemestre(year, num, lista);
    if(tempSem == NULL){
        cout<<"No se encuentra el semestre";
        return;
    }
    else{

        charla *nn = new charla(nCharla,dia,mes);

                        if(tempSem->suCharla == NULL){
                            tempSem->suCharla = nn;
                        }

                        else if(mes < tempSem->suCharla->mes){
                            nn->sig = tempSem->suCharla;
                            tempSem->suCharla = nn;
                        }

                        else if((mes == tempSem->suCharla->mes) && (dia < tempSem->suCharla->dia)){
                                nn->sig = tempSem->suCharla;
                                tempSem->suCharla = nn;
                                }
                        else{
                            charla * tempA = tempSem->suCharla;
                            charla * tempAnt = tempSem->suCharla;

                            while((tempA != NULL) && (mes > tempA->mes)){
                                tempAnt = tempA;
                                tempA = tempA->sig;
                            }

                            if(tempA == NULL){
                                   tempAnt->sig = nn;
                            }

                            else if((mes == tempA->mes) && (dia < tempA->dia)){
                                nn->sig = tempA;
                                tempAnt->sig = nn;
                                }

                            else{
                                if(tempA->sig != NULL){
                                nn->sig = tempA->sig;
                                }
                                tempA->sig = nn;
                            }
                         }
    }
    cout << "Se inserto la charla correctamente" << endl;
    return;
}




















bool verRelacionEstudianteCurso(estudiante * est, string elCurso){
    if(est->suGrupo != NULL){
            if(est->suGrupo->enlaceG->enlaceCurso->nombre == elCurso)
                cout<<est->suGrupo->enlaceG->enlaceCurso->nombre<<" son iguales "<<elCurso<<endl;
                cout<<est->suGrupo->enlaceG->enlaceCurso->nombre<<" son iguales "<<elCurso<<endl;
                return true;
    }
    return false;
}


void noEntregadoNada(string curso){
    struct curso * elCurso = buscarCurso(curso,liscurso);
    estudiante * tempEst = lisestudiante;

    while(tempEst!= NULL){

        if(tempEst->suGrupo != NULL){

            while(tempEst->suGrupo->actividad != NULL){

                if(tempEst->suGrupo->actividad->curso == curso)
                    break;

                tempEst->suGrupo->actividad = tempEst->suGrupo->actividad->sig;
            }

            if(tempEst->suGrupo->actividad == NULL)
                cout<<tempEst->nombre<<" no ha entregado nada en "<<curso<<endl;
        }

        tempEst = tempEst->sig;
    }
}













int contadorCharlasAsistidas(int year,int sem,int numBuscado){
    estudiante* tempE = lisestudiante;
    int contador = 0;

    while(tempE != NULL){

        if(tempE->suGrupo != NULL){

                    while(tempE->suGrupo->charlas != NULL){

                        if((tempE->suGrupo->charlas->year == year) && (tempE->suGrupo->charlas->sem == sem) && (tempE->suGrupo->charlas->num == numBuscado) ){ // cuando el semestre coincida y el nuumero tambien
                            contador += 1;
                        }
                        tempE->suGrupo->charlas = tempE->suGrupo->charlas->sig;
                    }
        }

        tempE = tempE->sig;
    }
    return contador;
}



void masCharlasAsistidas(int year,int sem){
    semestre * tempS = buscarSemestre(year,sem,lissemestre);

    int x = 0;
    while(tempS->suCharla != NULL){

        x = contadorCharlasAsistidas(year, sem , tempS->suCharla->num);
        cout<<"En el semestre " << sem << " del ano " << year <<" a la charla numero " << tempS->suCharla->num << " asistieron " << x << " personas." <<endl;
        tempS->suCharla = tempS->suCharla->sig;
    }

}












                                                                                //MENUS


void menuAdministrador(){
    system("cls");

    int opcion;
    string nombre;
    int carnet;
    int cedula;
    int year;
    int numero;
    string codigo;
    int creditos;
    int dia;
    int mes;
    string curso;

cout << " ___  ___   _______  __   __   __    __  "<< endl;
cout << "|   */   | |   ____||  * |  | |  |  |  | "<< endl;
cout << "|     /  | |  |__   |   *|  | |  |  |  | "<< endl;
cout << "|  |*/|  | |   __|  |  *    | |  |  |  | "<< endl;
cout << "|  |  |  | |  |____ |  |*   | |   --   | "<< endl;
cout << "|__|  |__| |_______||__| *__|  *______/  "<< endl;
cout <<endl<<endl;
    //Insertar Admin ?
    cout << "0 - Insertar administrador" << endl;

    cout << "1 - Insertar profesor" << endl;
    cout << "2 - Modificar profesor" << endl;
    cout << "3 - Borrar profesor" << endl;

    cout << "4 - Insertar estudiante" << endl;
    cout << "5 - Modificar estudiante" << endl;
    cout << "6 - Borrar estudiante" << endl;

    cout << "7 - Insertar semestre" << endl;
    cout << "8 - Modificar semestre" << endl;

    cout << "9 - Insertar curso" << endl;
    cout << "10 - Modificar curso" << endl;
    cout << "11 - Borrar curso" << endl;

    cout << "12 - Insertar grupo relacionandolo con cursos"<<endl;

    cout << "13 - Relacionar profesor con grupos"<<endl;
    cout << "14 - Borrar profesor con sus grupos"<<endl;

    cout << "15 - Relacionar estudiante con grupos"<<endl;
    cout << "16 - Borrar estudiante con sus grupos"<<endl;

    cout << "17 - Relacionar los semestres con los cursos, insertar y modificar, lista simple insercion al inicio"<<endl;

    cout << "18 - Consultar en cuales charlas generales de un semestre especifico han participado más estudiantes"<<endl;

    cout << "19 - Ver cuales estudiantes que no han realizado ninguna entrega en un curso especifico" << endl;

    cout << "20 - Salir\n" << endl;


    cin>>opcion;

    if (opcion == 0){
        cout << "Nombre del nuevo administrador:" << endl;
        cin >> nombre;
        lisadmin = insertarInicioAdministrador(nombre,lisadmin);
        cout << "Agregado con exito...." << endl;
    }

    if (opcion == 1){
        cout << "Nombre del nuevo profesor:" << endl;
        cin >> nombre;
        cout << "Cedula del nuevo profesor:" << endl;
        cin >> cedula;
        lisprofesor = insertarInicioProfesor(nombre, cedula, lisprofesor);
        cout << "Agregado con exito...." << endl;


        cout<<"\nlista de profesores:\n";
        imprimirProfesor(lisprofesor);  // para ver como va
        cout<<"\n\n";
    }

    if (opcion == 2){
        cout << "Seleccione la opcion que desea modificar:"<< endl;
        cout << "1 - Nombre" << endl;
        cout << "2 - Cedula" << endl;
        int opcion2;
        cin >> opcion2;
        if(opcion2 == 1){
            cout << "Ingrese el nombre que desea modificar:" << endl;
            string nombreActual;
            cin >> nombreActual;
            cout << "Ingrese el nuevo nombre:" << endl;
            string nombreNuevo;
            cin >> nombreNuevo;
            modificarProfesorNombre(nombreActual, nombreNuevo, lisprofesor);
        }
        if(opcion2 == 2){
            cout << "Ingrese la cedula que desea modificar:" << endl;
            int cedulaActual;
            cin >> cedulaActual;
            cout << "Ingrese la nueva cedula:" << endl;
            int cedulaNueva;
            cin >> cedulaNueva;
            modificarProfesorCedula(cedulaActual, cedulaNueva, lisprofesor);
        }
        //recibir cedula en ambas
    }

    if (opcion == 3){
        cout << "Cedula del profesor a borrar:" << endl;
        cin>> cedula;
        lisprofesor = borrarProfesor(cedula ,lisprofesor);
    }


                                                               //estudiante
    if (opcion == 4){
        cout << "Nombre del nuevo estudiante" << endl;
        cin>> nombre;
        cout << "Carne del nuevo estudiante" << endl;
        cin>> carnet;
        lisestudiante = insertarEstudianteOrdenado(nombre,carnet);
        cout << "Agregado con exito...." << endl;



        cout<<"\nlista de estudiantes:\n";
        imprimirEstudiante(lisestudiante);  // para ver como va
        cout<<"\n\n";
    }

    if (opcion == 5){
        cout << "Ingrese el nombre que desea modificar:" << endl;
        string nombreActual;
        cin >> nombreActual;
        cout << "Ingrese el nuevo nombre:" << endl;
        cin >> nombre;
        modificarEstudianteNombre(nombreActual, nombre, lisestudiante);
    }

    if (opcion == 6){
        cout << "Carnet del estudiante a borrar:" << endl;
        cin>> carnet;
        borrarEstudiante(carnet);
    }


                                                               //semestre
    if (opcion == 7){
        cout << "Numero del nuevo semestre" << endl;
        cin>> numero;
        cout << "año del nuevo semestre" << endl;
        cin>> year;
        lissemestre = insertarOrdenadoSemestre(numero,year,lissemestre);
        cout << "Agregado con exito...." << endl;


        imprimirSemestre(lissemestre); //para probar
    }

    if (opcion == 8){
        cout << "Nombre del semestre a modificar" << endl;
        cin>> nombre;
        // Falta 🤯 pista: al modificar volver a ordenar
        //lissemestre = modificarSemestre(nombre,lissemestre);
    }


                                                               //curso
    if (opcion == 9){
        cout << "Nombre del nuevo curso:" << endl;
        cin>> nombre;
        cout << "Codigo del nuevo curso:" << endl;
        cin >> codigo;
        cout << "Creditos del nuevo curso" << endl;
        cin >> creditos;
        liscurso = insertarFinalCursos(nombre, codigo, creditos, liscurso);
        cout << "Agregado con exito...." << endl;

        imprimirCurso(liscurso);//para probar
    }

    if (opcion == 10){
        cout << "Codigo del curso a modificar:" << endl;
        cin>> codigo;
        cout << "Ingrese el nuevo nombre:" << endl;
        cin >> nombre;
        cout << "Ingrese el nuevo codigo:" << endl;
        string nCodigo;
        cin >> nCodigo;
        cout << "Ingrese los nuevos creditos:" << endl;
        cin >> creditos;
        modificarCurso(codigo, nombre, nCodigo, creditos, liscurso);
    }

    if (opcion == 11){
        cout << "Codigo del curso a borrar:" << endl;
        cin>> codigo;
        borrarCurso(codigo, liscurso);
    }

                                                                //relaciones
    if (opcion == 12){
        cout << "Ingrese el numero del nuevo grupo:" << endl;
        cin>> numero;
        cout << "Ingrese los cupos del nuevo grupo:" << endl;
        int cupos;
        cin>>cupos;
        cout << "Ingrese el aula del nuevo grupo:" << endl;
        string aula;
        cin>>aula;

        cout << "Nombre del curso al que pertenece: " << endl;            // falta relacionarlo
        cin >> nombre;

        lisgrupo = insertarGrupoOrdenado(numero, cupos, aula, nombre);

        imprimirGrupo(lisgrupo);//para probar
    }

    if (opcion == 13){
        cout << "Cedula del profesor a relcionar" << endl;
        cin>> cedula;
        cout << "Numero del grupo a relacionar" << endl;
        cin >> numero;
        cout << "Ingrese el curso del grupo"<< endl;
        string curso;
        cin >> curso;
        relacionarProfesor(cedula,lisprofesor, numero, lisgrupo,curso);
        imprimirInforme(cedula);
    }

    if (opcion == 14){
        cout << "Cedula del profesor a relcionar" << endl;
        cin>> cedula;
        cout << "Numero del grupo a relacionar" << endl;
        cin >> numero;
        cout << "Ingrese el curso del grupo"<< endl;
        string curso;
        cin >> curso;
        borrarRelacionProfesor(cedula,lisprofesor,numero,lisgrupo,curso);
    }

    if (opcion == 15){
        cout << "Carnet del estudiante" << endl;
        cin>> carnet;
        cout << "Numero del grupo a relacionar" << endl;
        cin >> numero;
        cout << "Ingrese el curso del grupo"<< endl;
        cin >> curso;
        relacionarEstudiante(carnet,lisestudiante,numero,lisgrupo,curso);
    }

    if (opcion == 16){
        cout << "Carnet del estudiante" << endl;
        cin>> carnet;
        cout << "Numero del grupo a relacionar" << endl;
        cin >> numero;
        cout << "Ingrese el curso del grupo"<< endl;
        cin >> curso;
        borrarRelacionEstudiante(carnet,lisestudiante,numero,lisgrupo,curso);
    }

    if (opcion == 17){
        cout << "Ingrese el numero del semestre" << endl;
        cin>> dia;
        cout << "Ingrese el año del semestre" << endl;
        cin >> mes;
        cout << "Ingrese el curso del grupo"<< endl;
        cin >> curso;
        //no se cual esssssssssssssssssssssssssssssssssssss--------------------
    }

    if (opcion == 18){
        cout << "Ingrese el numero del semestre" << endl;
        cin>> dia;
        cout << "Ingrese el año del semestre" << endl;
        cin >> mes;
        //reporteCharlaMasEstudiantes(numero,year);
    }

    if (opcion == 19){
        cout << "Ingrese el nombre del curso" << endl;
        cin>> curso;
    }

    if (opcion == 20){
        return;
    }

    if (opcion > 20){
        cout << "Ingrese un numero valido" << endl;
    }

    cout<<endl;
    system ("pause");
    menuAdministrador();
}



void menuProfesor(){
    system("cls");
    string nombre;
    int numero;
    int valor;
    int year;
    int dia;
    int mes;
    int opcion;
    string curso;
    int grupo;
    int cedula;

    cout<<"1 - Insertar actividad"<<endl;
    cout<<"2 - Modificar actividad"<<endl;
    cout<<"3 - Borrar actividad"<<endl;
    cout<<"4 - Insertar charla general en un semestre"<<endl;
    cout<<"5 - Consultar actividades programadas en la semana proxima (todos los cursos)"<<endl;
    cout<<"6 - Consultar actividades programadas para el semestre (todos los cursos)"<<endl;
    cout<<"7 - Consultar entrega de tareas ya concluidas en el curso"<<endl;
    cout<<"8 - Ver cuales estudiantes asistieron a todas las charlas durante un semestre X"<<endl;
    cout<<"9 - Ver cuales Estudiantes no han entregado una asignacion de un curso"<<endl;
    cout<<"10 - Salir"<<endl;

    cin>>opcion;

    if(opcion == 1){
        cout<<"Nombre de la actividad"<<endl;
        cin>>nombre;
        cout<<"Ingrese el valor de la actividad"<<endl;
        cin>>valor;
        cout<<"Ingrese el numero del mes de entrega de la actividad"<<endl;
        cin>>mes;
        cout<<"Ingrese el dia de entrega de la actividad"<<endl;
        cin>>dia;
        cout<<"Ingrese el numero de la actividad"<<endl;
        cin>>numero;
        cout<<"Ingrese el curso de la actividad"<<endl;
        cin>>curso;
        cout<<"Ingrese el grupo de la actividad"<<endl;
        cin>>grupo;
        cout<<"Ingrese su cedula"<<endl;
        cin>>cedula;
        insertarActividadProfe(nombre,valor,numero,mes,dia,curso,grupo,cedula);

        imprimirActividad(lisgrupo); // probando
    }

    if(opcion == 2){
        cout<<"Tipo de la tarea"<<endl;                  // no estoy 100 seguro de mandarlo todo bien
        cin>>nombre;
        cout<<"Ingrese el valor actual de la actividad"<<endl;
        cin>>valor;
        cout<<"Ingrese el numero actual de la actividad"<<endl;
        cin>>numero;
        cout<<"Ingrese el valor nuevo de la actividad"<<endl;
        int valor2;
        cin>>valor2;
        cout<<"Ingrese el numero nuevo de la actividad"<<endl;
        int numero2;
        cin>>numero2;
        cout<<"Ingrese su cedula"<<endl;
        cin>>cedula;
        cout<<"Ingrese el numero del grupo de la actividad"<<endl;
        cin>>grupo;
        cout<<"Ingrese el nombre del curso de la actividad"<<endl;
        cin>>curso;
        modificarActividad(nombre,numero,valor,numero2,valor2,cedula,grupo,curso,lisprofesor);

        imprimirActividad(lisgrupo); // solo paraprobar
    }

    if(opcion == 4){
        cout<<"Ingtguyyfrf el año del semestre"<<endl;



    //------------------------

    if(opcion == 6){
    imprimirInforme(12859603);

    }

    if(opcion == 10){
        return;
    }

    if(opcion > 10){
        cout << "Ingrese un numero valido" << endl;
    }

    cout<<endl;
    system ("pause");
    menuProfesor();

}



void menuEstudiante(){
    system("cls");
    string nombre;
    int opcion;
    int carnet;
    int numero;
    int num;
    string tipo;
    int year;
    string curso;

    cout<<"1 - Registrar actividad cumplida"<<endl;
    cout<<"2 - Registrar participacion en una charla general"<<endl;
    cout<<"3 - Consultar actividades programadas para una semana (identificar choques)"<<endl;

    cin>>opcion;

    if(opcion == 1){
        cout<<"Ingrese su carnet"<<endl;
        cin>>carnet;
        cout<<"Ingrese el nombre del curso"<<endl;
        cin>>curso;
        cout<<"Ingrese el numero del grupo"<<endl;
        cin>>numero;
        cout<<"Ingrese el numero de la actividad"<<endl;
        cin>>num;
        cout<<"Ingrese el tipo de actividad"<<endl;
        cin>>tipo;
        registrarActividadCumplida(carnet, curso, numero, num, tipo,lisestudiante);
        cout<<"Actividad registrada con exito"<<endl;
    }

    if(opcion == 2){
        cout<<"Ingrese el carnet del estudiante"<<endl;
        cin>>carnet;
        cout<<"Ingrese el año del semestre"<<endl;
        cin>>year;
        cout<<"Ingrese el numero del semestre"<<endl;
        cin>>numero;
        cout<<"Ingrese el numero de la charla"<<endl;
        cin>>num;
        registrarCharlaAsistida(carnet, year, numero, num, lisestudiante, lissemestre);
        cout<<"Asistencia a la charla registrada con exito"<<endl;
    }


    cout<<endl;
    system ("pause");
    menuEstudiante();

}



void menuPrincipal(){
cout<<"                 ."<<endl;
cout<<"             :  /" <<endl;
cout<<"           ' _ '"<<endl;
cout<<"       -= ( (_) ) =-"<<endl;
cout<<"           .   ."<<endl;
cout<<"          /  :   "<<endl;
cout<<"      .-.    '"<<endl;
cout<<"      |.|"<<endl;
cout<<"    /)|`|(      \n";
cout<<"   (.(|'|)`)"<<endl;
cout<<"~~~~` `'./'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<"      |.|           ~~"<<endl;
cout<<"      |`|                            ~~"<<endl;
cout<<"     ,|'|.                ~~"<<endl;
cout<<"       '        " <<endl;
cout<<"           ~~     ^~^"<<endl;



    cout << "Bienvenido, de que manera desea ingresar al sistema \n" << endl;                                               //editar
    cout << "1 - Administrador" << endl;
    cout << "2 - Usuario" << endl;
    int seleccionar;
    cin>>seleccionar;

    if (seleccionar == 1){
        menuAdministrador();
    }

    if (seleccionar == 2) {
        cout << "Seleccione el tipo de usuario" << endl;
        cout << "1 - Estudiante" << endl;
        cout << "2 - Profesor" << endl;
        int opcion;
        cin>>opcion;
        if(opcion == 1){
            menuEstudiante();
        }
        if(opcion == 2){
            menuProfesor();
        }
    }
}






int main(){
                                                                        //estudiantes
    lisestudiante = insertarEstudianteOrdenado("Mario",2021121233);
    lisestudiante = insertarEstudianteOrdenado("Pedro",2020211233);
    lisestudiante = insertarEstudianteOrdenado("Juan",2019421273);
    lisestudiante = insertarEstudianteOrdenado("Klarence",2018215287);
    lisestudiante = insertarEstudianteOrdenado("Rayan",2056421296);

                                                                        //profesores
    lisprofesor = insertarInicioProfesor("Allan",200390421,lisprofesor);
    lisprofesor = insertarInicioProfesor("Fabricio",782802345,lisprofesor);
    lisprofesor = insertarInicioProfesor("Marta",12859603,lisprofesor);
    lisprofesor = insertarInicioProfesor("Loren",789842378,lisprofesor);
    lisprofesor = insertarInicioProfesor("Eduardo",12838453,lisprofesor);

                                                                        //semestres
    lissemestre = insertarOrdenadoSemestre(1, 2020, lissemestre);
    lissemestre = insertarOrdenadoSemestre(2, 2020, lissemestre);
    lissemestre = insertarOrdenadoSemestre(1, 2021, lissemestre);
    lissemestre = insertarOrdenadoSemestre(2, 2021, lissemestre);
    lissemestre = insertarOrdenadoSemestre(1, 2022, lissemestre);

                                                                        //cursos
    liscurso = insertarFinalCursos("Matematicas","IC-202",4,liscurso);
    liscurso = insertarFinalCursos("Estructura","IC-305",4,liscurso);
    liscurso = insertarFinalCursos("Taller","IC-501",3,liscurso);
    liscurso = insertarFinalCursos("Comunicacion","IC-102",2,liscurso);
    liscurso = insertarFinalCursos("Ingles","IC-270",6,liscurso);

                                                                        //grupos
    lisgrupo = insertarGrupoOrdenado(16,4,"B17","Matematicas");
    lisgrupo = insertarGrupoOrdenado(50,21,"A21","Estructura");
    lisgrupo = insertarGrupoOrdenado(54,12,"A5","Taller");
    lisgrupo = insertarGrupoOrdenado(23,5,"B2","Comunicacion");
    lisgrupo = insertarGrupoOrdenado(25,5,"B12","Ingles");


    insertarCharlaSemestre(2020,1,2,3,1,lissemestre);
    insertarCharlaSemestre(2020,1,3,4,3,lissemestre);



    registrarCharlaAsistida(2018215287,2020,1,1,lisestudiante,lissemestre);//klarence



    //masCharlasAsistidas(2020,2,5);
    //masCharlasAsistidas2(2020,2);


    //mas4Cursos();

    system("cls");

    masCharlasAsistidas(2020,1);


    menuPrincipal();

    return 0;
}
