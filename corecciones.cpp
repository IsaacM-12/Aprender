#include <iostream>
#include <string>
#include <cstdlib>

/*

Isaac Melendez Gatgens
2021123344

Pablo Sandi Sanchez
2021120523

A*/
struct semestre{
    int sem;
    int year;
    semestre*sig, *ant;
    struct actividades* charla;
    struct enlaceSemestre* suCurso;

    semestre(int x, int y){
        suCurso = NULL;
        sem = x;
        year = y;
        sig= NULL;
        ant= NULL;
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
    string fecha;
    int num;
    charla* sig;

    charla(int n,string f){
        fecha = f;
        num = n;
        sig = NULL;
    };
};

struct charlaAsistida{
    string fecha;
    int num;
    charla* sig;

    charlaAsistida(int n,string f){
        fecha = f;
        num = n;
        sig = NULL;
    };
};

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

    enlaceEstudiante(){
        sig = NULL;
        enlaceG = NULL;
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


struct actividadesEntregadas{
    actividades* sig;
    int numero;
    string fecha;
    int valor;
    string nombre;

    actividadesEntregadas(int n, string f,int v, string h){
        sig = si;
        valor = v;
        numero = n;
        fecha = f;
        nombre = h;
    };
};

administrador * lisadmin;
profesor * lisprofesor;
semestre * lissemestre;
estudiante * lisestudiante;
curso * liscurso;
grupo * lisgrupo;
charla * lischarla;



                                                                                        //Administrador
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


/*
semestre* insertarOrdenadoSemestre(int x, int y, semestre* lista){

         semestre *nn = new semestre(x, y);

        if(lista == NULL)
            lista = nn;
        else if(x < lista->num){
                nn->sig = lista;
                lista->ant = nn;
                lista = nn;
            }
     else{

        semestre*temp = lista;
        semestre*tempAnt =NULL;
        while((temp != NULL) && (x > temp->num)){
                tempAnt = temp;
                temp = temp->sig;
        }//
        if(temp ==NULL){//el numero a insertar es mayor a todos
               tempAnt->sig = nn;
               nn->ant =  tempAnt;
        }
        else{// insertar en medio
            nn->sig = temp;
            nn->ant = tempAnt;
            tempAnt->sig = nn;
            temp->ant = nn;
        }
     }


return lista;
}
*/
                                                                                       //Curso
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


                                                                                           //profesor
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

void relacionarProfesor(int cedula,profesor* listaP, int num, grupo* listaG){
    profesor* profe = buscarProfe(cedula, listaP);
    if(profe == NULL){
        cout<<"El profesor no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupo(num, listaG);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    enlaceProfesor* nnP = new enlaceProfesor();

    nnP->enlaceG = grupo;
    nnP->sig = profe->suGrupo;

    profe->suGrupo = nnP;

}


void borrarRelacionProfesor(int cedula,profesor* listaP, int num, grupo* listaG){
    profesor* profe = buscarProfe(cedula, listaP);
    if(profe == NULL){
        cout<<"El profesor no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupo(num, listaG);
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

void imprimirInformeMatriculaProfe(int cedula){

        profesor *tempE = buscarProfe(cedula,lisprofesor);

        if(tempE== NULL){
            cout<<"No se encuentra ";
            return;
        }
         cout<<"\n--------------------------INFORME ---------------------------------------\n";

        cout<<"\nMatricula de "<<tempE->nombre<<" con el/los Grupo(s): "<<endl;
        enlaceProfesor *tempM = tempE->suGrupo;

        while(tempM != NULL){

            cout<<"\t"<<tempM->enlaceG->num<<endl;
            tempM = tempM->sig;
        }

        cout<<"\n--------------------------FIN DEL INFORME---------------------------------------\n";

}



                                                                                            //grupo

grupo * insertarGrupoOrdenado(int num,int cupos,string aula){
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
    return lisgrupo;
}


void imprimirGrupo(grupo* lista){
    if (lista == NULL)
        cout << "\nNo hay estudiantes\n";
    else{
        grupo *temp = lista;
        while(temp != NULL){
            cout<<"numero " << temp->num<<" - cupos "<< temp->cupos<<"  - aula "<< temp->aula << "    -   enlace " << temp->enlaceCurso<<endl;

            temp = temp->sig;
        }
    }
}



/*


                                                                                                  //estudiante
*/


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


void relacionarEstudiante(int carnet, estudiante* listaE, int num, grupo* listaG){
    estudiante* estudiante = buscarEstudiante(carnet, listaE);
    if(estudiante == NULL){
        cout<<"El Estudiante no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupo(num, listaG);
    if(grupo == NULL){
        cout<<"El grupo no existe en la lista"<<endl;
        return;
    }

    enlaceEstudiante* nnE = new enlaceEstudiante();

    nnE->enlaceG = grupo;
    nnE->sig = estudiante->suGrupo;

    estudiante->suGrupo = nnE;

}


void borrarRelacionEstudiante(int carnet, estudiante* listaE, int num, grupo* listaG){
    estudiante* estudiante = buscarEstudiante(carnet, listaE);
    if(estudiante == NULL){
        cout<<"El Estudiante no existe en la lista"<<endl;
        return;
    }
    grupo* grupo = buscarGrupo(num, listaG);
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
    cout << "18 - Salir\n" << endl;

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
        cout << "Seleccione la opcion que desea modificar:"<<endl;
        cout << "1 - Nombre" << endl;
        cout << "2 - carnet" << endl;
        int opcion2;
        cin >> opcion2;
        if(opcion2 == 1){
            cout << "Ingrese el nombre que desea modificar:" << endl;
            string nombreActual;
            cin >> nombreActual;
            cout << "Ingrese el nuevo nombre:" << endl;
            string nombreNuevo;
            cin >> nombreNuevo;
            modificarEstudianteNombre(nombreActual, nombreNuevo, lisestudiante);
        }
        if(opcion2 == 2){
            cout << "Ingrese el carnet que desea modificar:" << endl;
            int carnetActual;
            cin >> carnetActual;
            cout << "Ingrese el nuevo carnet:" << endl;
            int carnetNuevo;
            cin >> carnetNuevo;
            modificarEstudianteCarnet(carnetActual, carnetNuevo, lisestudiante);
        }
        //recibir carnet en ambos 🍑
    }

    if (opcion == 6){
        cout << "Carnet del estudiante a borrar:" << endl;
        cin>> carnet;
        borrarEstudiante(carnet);
    }


                                                               //semestre
    if (opcion == 7){
        cout << "Nombre del nuevo semestre" << endl;
        cin>> nombre;
        // Falta 🦧
        //lissemestre = insertarOrdenadoSemestre(nombre,lissemestre);
        cout << "Agregado con exito...." << endl;
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
        imprimirCurso(liscurso);
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

    if (opcion == 12){
        cout << "Ingrese el numero del nuevo grupo:" << endl;
        cin>> numero;
        cout << "Ingrese los cupos del nuevo grupo:" << endl;
        int cupos;
        cin>>cupos;
        cout << "Ingrese el aula del nuevo grupo:" << endl;
        string aula;
        cin>>aula;

        cout << "Curso del nuevo grupo:" << endl;            // falta relacionarlo
        //curso* relacion;
        //cin>>relacion;

        lisgrupo = insertarGrupoOrdenado(numero, cupos, aula);
        imprimirGrupo(lisgrupo);
    }

    if (opcion == 13){
        cout << "Cedula del profesor a relcionar" << endl;
        cin>> cedula;
        cout << "Numero del grupo a relacionar" << endl;
        cin >> numero;
        relacionarProfesor(cedula,lisprofesor, numero, lisgrupo);
        imprimirInformeMatriculaProfe(cedula);
    }


    if (opcion == 18){
        return;
    }


    if (opcion > 18){
        cout << "Ingrese un numero valido" << endl;
    }

    cout<<endl;
    system ("pause");
    menuAdministrador();
}






void menuProfesor(){
    system("cls");
    string nombre;
    int opcion;

    cout<<"1 - Insertar actividad"<<endl;
    cout<<"2 - Insertar charla general en un semestre"<<endl;
    cout<<"3 - Consultar actividades programadas en la semana proxima (todos los cursos)"<<endl;
    cout<<"4 - Consultar actividades programadas para el semestre (todos los cursos)"<<endl;
    cout<<"5 - Consultar entrega de tareas ya concluidas en el curso"<<endl;
    cout<<"6 - Ver cuales estudiantes asistieron a todas las charlas durante un semestre X"<<endl;
    cout<<"7 - Ver cuales Estudiantes no han entregado una asignacion de un curso"<<endl;

    cin>>opcion;

    if(opcion == 1){
        cout<<"Nombre de la actividad"<<endl;

    }

    cout<<endl;
    system ("pause");
    menuProfesor();

}


void menuEstudiante(){
    system("cls");
    string nombre;
    int opcion;

    cout<<"1 - Registrar actividad cumplida o participacion"<<endl;
    cout<<"2 - Registrarse en una charla general"<<endl;
    cout<<"3 - Consultar actividades programadas para una semana (identificar choques)"<<endl;

    cin>>opcion;

    if(opcion == 1){
        cout<<"Nombre de la actividad"<<endl;
        cin>>nombre;


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
    lisestudiante = insertarEstudianteOrdenado("Mario",2021121233);
    lisestudiante = insertarEstudianteOrdenado("Pedro",2020211233);
    lisestudiante = insertarEstudianteOrdenado("Juan",2019421273);

    lisprofesor = insertarInicioProfesor("Allan",200390421,lisprofesor);
    lisprofesor = insertarInicioProfesor("Fabricio",782802345,lisprofesor);
    lisprofesor = insertarInicioProfesor("Marta",12859603,lisprofesor);

    liscurso = insertarFinalCursos("Matematicas","IC-202",4,liscurso);
    liscurso = insertarFinalCursos("Estructura","IC-305",4,liscurso);
    liscurso = insertarFinalCursos("Taller","IC-501",3,liscurso);
    liscurso = insertarFinalCursos("Comunicacion","IC-102",2,liscurso);

    lisgrupo = insertarGrupoOrdenado(16,4,"B17");
    lisgrupo = insertarGrupoOrdenado(50,21,"A21");
    lisgrupo = insertarGrupoOrdenado(54,12,"A5");
    lisgrupo = insertarGrupoOrdenado(23,5,"B2");

    relacionarProfesor(782802345,lisprofesor,50,lisgrupo); // Fabricio con GR 50
    relacionarProfesor(12859603,lisprofesor,23,lisgrupo); // Marta con GR 23


    menuPrincipal();

    return 0;
}
