#include <iostream>
#include <fstream>
#include "actividad.h"
#include "preinscripcion.h"
#include "inscripcion.h"
#include "funciones.h"
#include <list>

/*HECHO:
 CREAR ACTIVIDADES
 MODIFICAR ACTIVIDADES
 AÑADIR ACTIVIDAD A LA LISTA
 ACTIVAR/DESACTIVAR ACTIVIDADES
*/

int main(void)
{
    int rol=1, opt=-1;
    std::ifstream fin;
    std::ofstream fout;

    std::list<Actividad> act_list;
    Actividad aux(0);
    int act_id=-1;
	std::string name;
	std::string begin_date;
	std::string end_date;
	bool status;
	std::string description;
    float price;
	int capacity;
	int faculty_id;
    int i=0;

    std::list<Preinscripcion> pre_list;
    Preinscripcion aux1(0, 0);
    std::string user;
    int pre_id=0;
    int actpre_id;
    //bool status
    bool paynote;

    std::list<Inscripcion> ins_list;
    Inscripcion aux2;
    int actins_id;
    int ins_id=0;

    fin.open("actividades.txt"); //ABRIMOS EL FICHERO
    if(fin.is_open()==false)
    {
        fout.open("actividades.txt");
        if(fout.is_open()==false)
        {
            printf("Error de la base de datos\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            fout.close();
        }
    }
    else
    {
        while(fin>>act_id) //LA VARIABLE ACT_ID SIRVE COMO CONTADOR PARA SABER QUÉ ID PONERLE A LA NUEVA ACTIVIDAD CREADA
        {
            fin.ignore();
            getline(fin, name);
            getline(fin, begin_date);
            getline(fin, end_date);
            fin>>status;
            fin.ignore();
            getline(fin, description);
            fin>>price;
            fin.ignore();
            fin>>capacity;
            fin.ignore();
            fin>>faculty_id;
            fin.ignore();
            aux.SetActId(act_id);
            aux.SetName(name);
            aux.SetBeginDate(begin_date);
            aux.SetEndDate(end_date);
            aux.SetStatus(status);
            aux.SetPrice(price);
            aux.SetDescription(description);
            aux.SetCapacity(capacity);
            aux.SetFacultyId(faculty_id);
            act_list.push_back(aux);
        }
        fin.close();
    }
    act_id++; //ID DE LA PRÓXIMA ACTIVIDAD

    fin.open("preinscripciones.txt"); //ABRIMOS EL FICHERO
    if(fin.is_open()==false)
    {
        fout.open("preinscripciones.txt");
        if(fout.is_open()==false)
        {
            printf("Error de la base de datos\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            fout.close();
        }
    }
    else
    {
        while(fin>>pre_id) //LA VARIABLE ACT_ID SIRVE COMO CONTADOR PARA SABER QUÉ ID PONERLE A LA NUEVA ACTIVIDAD CREADA
        {
            fin.ignore();
            getline(fin, user);
            fin>>actpre_id;
            fin.ignore();
            fin>>status;
            fin.ignore();
            fin>>paynote;
            fin.ignore();
            aux1.SetPreId(pre_id); //Cambiar según el nombre
            aux1.SetUser(user);
            aux1.SetStatus(status);
            aux1.SetActId(actpre_id);
            aux1.SetPayNote(paynote);
            pre_list.push_back(aux1);
        }
        fin.close();
    }
    pre_id++; //ID DE LA PRÓXIMA PREINSCRIPCIÓN

    fin.open("inscripciones.txt"); //ABRIMOS EL FICHERO
    if(fin.is_open()==false)
    {
        fout.open("inscripciones.txt");
        if(fout.is_open()==false)
        {
            printf("Error de la base de datos\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            fout.close();
        }
    }
    else
    {
        while(fin>>ins_id) //LA VARIABLE ACT_ID SIRVE COMO CONTADOR PARA SABER QUÉ ID PONERLE A LA NUEVA ACTIVIDAD CREADA
        {
            fin.ignore();
            getline(fin, user);
            fin>>actins_id;
            fin.ignore();
            aux2.SetInsId(ins_id); //Cambiar según el nombre
            aux2.SetUser(user);
            aux2.SetActId(actins_id);
            ins_list.push_back(aux2);
        }
        fin.close();
    }
    ins_id++; //ID DE LA PRÓXIMA 
    
    while (rol!=0) //COMIENZO DEL WHILE MÁS GRANDE (HASTA LINEA 601)
    {
    
    std::cout << "\n-----------------------------------------------------------------------\n"; //Selección de rol
    std::cout << "¡Bienvenido a UCOTALLERES! Seleccione el rol con el que desea acceder.\n";
    std::cout << "0) Salir\n1) Visitante\n2) Usuario registrado\n3) Director académico\n4) Organizador\n";
    std::cout << "-----------------------------------------------------------------------\n\n";
    std::cout << "--> ";
    std::cin >> rol;

    opt=1;
    int aux_id; //ID AUXILIAR DENTRO DEL SWITCH
    int aux_capacity; //CAPACITY AUXILIAR DENTRO DEL SWITCH
    int aux_preid; //PREID AUXILIAR DENTRO DEL SWITCH
    bool aux_status; //STATUS AUXILIAR DENTRO DEL SWITCH
    int mode; //Opción dentro del switch
    int cont; //Auxiliar contador
    char conf;
    
    if(rol==0)
    {
        std::cout << "\n¡Gracias por usar UCOTALLERES!\n"<<std::endl;
    }
    else if(rol==1)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Atras\n1) Consultar actividades\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl<<std::endl;
                SeeActs(rol, act_list);
                break;
            
            default:
                std::cout << "Opción no válida\n\n";
                break;
            }
        }

    }
    else if(rol==2)
    {
        std::cout<<"\nIntroduzca su user: ";
        std::cin>>user;
        while (opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Atras\n1) Consultar actividades\n2) Preinscribirse\n3) Mis preinscripciones e inscripciones\n4) Pagar preinscripciones\n5) Borrar preinscripcion o inscripcion\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl<<std::endl;
                SeeActs(rol, act_list);
                break;
            case 2:
                std::cout<<std::endl;
                std::cout<<"Introduzca el ID de la actividad en la que desea inscribirse: ";
                std::cin>>aux_id;
                std::cout<<std::endl;
                cont=0;

                for(auto it=pre_list.begin(); it!=pre_list.end(); it++)
                {
                    if(user==it->GetUser() && aux_id==it->GetActId())
                    {
                        cont=-1;
                        std::cout<<"~Su preinscripcion a esta actividad ya está pendiente~\n";
                        break;
                    }
                }
                if(cont==-1)
                {
                    break;
                }

                for(auto it=ins_list.begin(); it!=ins_list.end(); it++)
                {
                    if(user==it->GetUser() && aux_id==it->GetActId())
                    {
                        cont=-1;
                        std::cout<<"~Ya está inscrito a esta actividad~\n";
                        break;
                    }
                }
                if(cont==-1)
                {
                    break;
                }

                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        aux_capacity=it->GetCapacity();
                        aux_status=it->GetStatus();

                        if(aux_status==true)
                        {
                            cont++;
                            CreatePreinscription(pre_id, aux_id, aux_capacity, pre_list, user);
                            pre_id++;
                            it->SetCapacity(aux_capacity);
                            std::cout<<"~Su preinscripción ha sido enviada~\n";
                        }
                    }
                }
                if(cont==0)
                {
                    std::cout<<"~No existe ninguna actividad con ese ID~\n";
                    break;
                }

                break;

            case 3:
                std::cout << "\n-----------------------------------------------------------------------\n";
                std::cout<<"PREINSCRIPCIONES PENDIENTES\n";
                SeePreinscriptions(rol, pre_list, user);
                std::cout << "-----------------------------------------------------------------------\n";
                std::cout << "\n-----------------------------------------------------------------------\n";
                std::cout<<"INSCRIPCIONES ACEPTADAS\n";
                SeeIns(rol, ins_list, user); //HABRÍA QUE PASAR EL USER TAMBIÉN
                std::cout << "-----------------------------------------------------------------------\n";
                break;
                
            case 4:
                std::cout<<"\nIntroduzca el ID de la actividad a pagar: ";
                std::cin>>aux_id;
                std::cout<<std::endl;
                cont=0;
                for(auto it=pre_list.begin(); it!=pre_list.end(); it++)
                {
                    if(aux_id==it->GetActId() && user==it->GetUser())
                    {
                        cont++;
                        if(it->GetPayNote()==true)
                        {
                            std::cout<<"~Actividad ya pagada~\n";
                        }
                        else
                        {
                            MakePayment(aux_id, pre_list);
                            std::cout<<"~Pagare subido correctamente~\n";
                        }
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"~No está preinscrito a ninguna actividad con ese ID~\n";
                }
                break;
            
            case 5:
                std::cout<<std::endl;
                std::cout<<"Introduzca el ID de la actividad de la que desea eliminar su inscripcion o preinscripcion: ";
                std::cin>>aux_id;
                std::cout<<std::endl;
                cont=0;
                for(auto it1=pre_list.begin(); it1!=pre_list.end(); it1++)
                {
                    if(aux_id==it1->GetActId() && user==it1->GetUser())
                    {
                        for(auto it2=act_list.begin(); it2!=act_list.end(); it2++)
                        {
                            if(aux_id==it2->GetActId())
                            {
                                aux_capacity=it2->GetCapacity();
                                aux_capacity++;
                                it2->SetCapacity(aux_capacity);
                                cont++;
                                pre_list.erase(it1);
                                break;
                            }
                        }
                        std::cout<<"~Preinscripcion eliminada correctamente~\n";
                        break;
                    }
                
                }
                for(auto it1=ins_list.begin(); it1!=ins_list.end(); it1++)
                {
                    if(aux_id==it1->GetActId() && user==it1->GetUser())
                    {
                        for(auto it2=act_list.begin(); it2!=act_list.end(); it2++)
                        {
                            if(aux_id==it2->GetActId())
                            {
                                aux_capacity=it2->GetCapacity();
                                aux_capacity++;
                                it2->SetCapacity(aux_capacity);
                                cont++;
                                ins_list.erase(it1);
                                break;
                            }
                        }
                        std::cout<<"~Inscripcion eliminada correctamente~\n";
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"~No está inscrito en esa actividad o no existe~\n";
                }
                break;
            default:
                std::cout << "Opción no válida\n\n";
                break;
            }
        }
    }
    else if(rol==3)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Atras\n1) Consultar actividades\n2) Activar/Desactivar actividad\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl<<std::endl;
                SeeActs(rol, act_list);
                break;
            case 2:
                std::cout<<std::endl;
                std::cout<<"Introduzca el ID de la actividad: ";
                std::cin>>aux_id;

                cont=0;
                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        cont++;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\n~No existe ninguna actividad con ese ID~\n";
                    break;
                }
                else
                {
                    std::cout<<"\n¿Desea activar (0) o desactivar (1) la actividad?: ";
                    std::cin>>mode;
                }

                switch (mode)
                {
                case 0:
                    for(auto it=act_list.begin(); it!=act_list.end(); it++)
                    {
                        if(aux_id==it->GetActId())
                        {
                            ShowAct(*it);
                            std::cout<<"\n~Actividad activada correctamente~\n";
                            break;
                        }
                    }
                    break;
                case 1:
                    for(auto it=act_list.begin(); it!=act_list.end(); it++)
                    {
                        if(aux_id==it->GetActId())
                        {
                            HideAct(*it);
                            std::cout<<"\n~Actividad desactivada correctamente~\n";
                            break;
                        }
                    }
                    break;
                default:
                    std::cout<<"Opción no válida\n";
                    break;
                }


                break;
            
            default:
                
                std::cout << "Opción no válida\n\n";
                break;
            }
        }
    }
    else if(rol==4)
    {
        while(opt!=0)
        {

            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Atras\n1) Consultar actividades\n2) Activar/Desactivar actividad\n3) Crear nueva actividad\n4) Eliminar actividad\n5) Modificar actividad\n6) Revisar preinscripciones\n7) Revisar inscripciones\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl<<std::endl;
                SeeActs(rol, act_list);
                break;

            case 2: //FUNCIONA
                std::cout<<"\nIntroduzca el ID de la actividad: ";
                std::cin>>aux_id;

                cont=0;
                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        cont++;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\n~No existe ninguna actividad con ese ID~\n";
                    break;
                }
                else
                {
                    std::cout<<"\n¿Desea activar (0) o desactivar (1) la actividad?: ";
                    std::cin>>mode;
                }

                switch (mode)
                {
                case 0:
                    for(auto it=act_list.begin(); it!=act_list.end(); it++)
                    {
                        if(aux_id==it->GetActId())
                        {
                            ShowAct(*it);
                            std::cout<<"\n~Actividad activada correctamente~\n";
                            break;
                        }
                    }
                    break;
                case 1:
                    for(auto it=act_list.begin(); it!=act_list.end(); it++)
                    {
                        if(aux_id==it->GetActId())
                        {
                            HideAct(*it);
                            std::cout<<"\n~Actividad desactivada correctamente~\n"<<it->GetStatus();
                            break;
                        }
                    }
                    break;

                default:
                    std::cout<<"Opción no válida\n";
                    break;
                }

                break;
                
            case 3: //FUNCIONA
                std::cout<<std::endl;
                CreateAct(act_id, act_list);
                act_id++; //Aumentamos id para la siguiente creación
                std::cout<<"\n~Actividad creada correctamente~\n";
                break;

            case 4: //FUNCIONA
                std::cout<<std::endl;
                std::cout<<"Introduzca el ID de la actividad a eliminar: ";
                std::cin>>aux_id;

                cont=0;
                for(auto it1=act_list.begin(); it1!=act_list.end(); it1++)
                {
                    if(aux_id==it1->GetActId())
                    {
                        DeleteList(it1->GetActId(), act_list);
                        std::cout<<"\n~Actividad eliminada correctamente~\n";
                        cont=pre_list.size();
                        auto it=pre_list.begin();
                        for(int i=0; i<cont; i++)
                        {
                            if(aux_id==it->GetActId())
                            {
                                pre_list.erase(it);
                            }
                            it++;
                        }
                        cont=ins_list.size();
                        auto it1=ins_list.begin();
                        for(int i=0; i<cont; i++)
                        {
                            if(aux_id==it1->GetActId())
                            {
                                ins_list.erase(it1);
                            }
                            it1++;
                        }
                        cont=1;
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\nNo existe ninguna actividad con ese ID.\n";
                }
                break;

            case 5: //FUNCIONA
                std::cout<<std::endl;
                std::cout<<"Introduzca el ID de la actividad a modificar: ";
                std::cin>>aux_id;
                std::cout<<std::endl;

                cont=0;
                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        ChangeAct(*it);
                        std::cout<<"\n~Actividad modificada correctamente~\n";
                        cont++;
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\n~No existe ninguna actividad con ese ID~\n";
                }
                break;
                
            case 6:
                std::cout<<"\nPREINSCRIPCIONES PENDIENTES:\n\n";
                SeePreinscriptions(rol, pre_list);

                std::cout<<"\n¿Desea aceptar alguna preinscripcion? (s/n): ";
                std::cin>>conf;

                if(conf=='s')
                {
                    int v[pre_list.size()];
                    std::cout<<"\nIntroduzca los IDs de las preinscripciones a aceptar y escriba 0 cuando desee parar.";
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    for(int i=0; i<pre_list.size(); i++)
                    {
                        std::cin>>v[i];
                        if(v[i]==0)
                        {
                            break;
                        }
                    }
                    std::cout<<std::endl;
                    if(v[0]==0)
                    {
                        std::cout<<"~Ninguna preinscripcion ha sido aceptada~\n";
                    }
                    /*if(v[0]==0)
                    {
                        cont=pre_list.size();
                        auto it=pre_list.begin();
                        for(int i=0; i<cont; i++)
                        {
                            ChangeStatus(it->GetPreId(), pre_list);
                            if(it->GetStatus()==true)
                            {
                                CreateIns(*it, ins_list, pre_list);
                                std::cout<<"~Preinscripcion "<<it->GetPreId()<<" aceptada correctamente~\n";
                            }
                            it++;
                        }
                        std::cout<<"\n~Todas las preinscripciones pagadas han sido aceptadas correctamente~\n";
                        break;
                    }*/
                    cont=pre_list.size();
                    for(int i=0;i<cont; ++i)
                    {
                        if(v[i]==0)
                        {
                            break;
                        }

                        for(auto it=pre_list.begin(); it!=pre_list.end(); it++)
                        {
                            if(v[i]==it->GetPreId())
                            {
                                ChangeStatus(it->GetPreId(), pre_list);
                                if(it->GetStatus()==true)
                                {
                                    CreateIns(*it, ins_list, pre_list);
                                    std::cout<<"~Preinscripcion "<<it->GetPreId()<<" aceptada correctamente~\n";
                                    
                                }
                                break;
                            }
                        }
                    }
                }

                break;

            case 7:
                std::cout<<"\nINSCRIPCIONES:\n\n";
                SeeIns(rol, ins_list);
                break;

            default:
                std::cout << "Opción no válida\n\n";
                break;

            }
        }
    }
    else
    {
        std::cout << "\nRol no válido, vuelva a ejecutar el programa.\n\n";
    }
    }

    fout.open("actividades.txt");
    if(fout.is_open()==false)
    {
        printf("Error de la base de datos\n");
        exit(EXIT_FAILURE);
    }
    for(auto it=act_list.begin(); it!=act_list.end(); it++)
    {
        fout<<it->GetActId()<<"\n"<<it->GetName()<<"\n"<<it->GetBeginDate()<<"\n"<<it->GetEndDate()<<"\n"<<it->GetStatus()<<"\n"<<it->GetDescription()<<"\n"<<it->GetPrice()<<"\n"<<it->GetCapacity()<<"\n"<<it->GetFacultyId()<< std::endl;
    }
    fout.close();

    fout.open("preinscripciones.txt");
    if(fout.is_open()==false)
    {
        printf("Error de la base de datos\n");
        exit(EXIT_FAILURE);
    }
    for(auto it=pre_list.begin(); it!=pre_list.end(); it++)
    {
        fout<<it->GetPreId()<<"\n"<<it->GetUser()<<"\n"<<it->GetActId()<<"\n"<<it->GetStatus()<<"\n"<<it->GetPayNote()<<std::endl;
    }
    fout.close();

    fout.open("inscripciones.txt");
    if(fout.is_open()==false)
    {
        printf("Error de la base de datos\n");
        exit(EXIT_FAILURE);
    }
    for(auto it=ins_list.begin(); it!=ins_list.end(); it++)
    {
        fout<<it->GetInsId()<<"\n"<<it->GetUser()<<"\n"<<it->GetActId()<<std::endl;
    }
    fout.close();

}