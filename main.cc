#include <iostream>
#include <fstream>
#include "actividad.h"
#include <list>

/*HECHO:
 CREAR ACTIVIDADES
 MODIFICAR ACTIVIDADES
 AÑADIR ACTIVIDAD A LA LISTA
 ACTIVAR/DESACTIVAR ACTIVIDADES
*/


int main(void)
{
    int rol, opt=1;
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
	int capacity;
	int faculty_id;
    int i=0;

    /*::list<Preinscripcion> pre_list;
    Preinscripcion aux1;
    std::string user;
    int pre_id;*/

    std::cout << "\n-----------------------------------------------------------------------\n"; //Selección de rol
    std::cout << "¡Bienvenido a UCOTALLERES! Seleccione el rol con el que desea acceder.\n";
    std::cout << "1) Visitante\n2) Usuario registrado\n3) Director académico\n4) Organizador\n";
    std::cout << "-----------------------------------------------------------------------\n\n";
    std::cout << "--> ";
    std::cin >> rol;

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
            fin>>capacity;
            fin.ignore();
            fin>>faculty_id;
            fin.ignore();
            aux.SetActId(act_id);
            aux.SetName(name);
            aux.SetBeginDate(begin_date);
            aux.SetEndDate(end_date);
            aux.SetStatus(status);
            aux.SetDescription(description);
            aux.SetCapacity(capacity);
            aux.SetFacultyId(faculty_id);
            act_list.push_back(aux);
        }
        fin.close();
    }
    act_id++; //ID DE LA PRÓXIMA ACTIVIDAD

    /*fin.open("preinscripciones.txt"); //ABRIMOS EL FICHERO
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
            fin>>status;
            fin.ignore();
            aux1.SetPreId(pre_id); //Cambiar según el nombre
            aux1.SetUser(user);
            aux1.SetStatus(status);
            pre_list.push_back(aux1);
        }
        fin.close();
    }*/

    int aux_id; //ID AUXILIAR DENTRO DEL SWITCH
    int mode; //Opción dentro del switch
    int cont; //Auxiliar contador

    
    if(rol==1)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl;
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
        while (opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Mis inscripciones\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl;
                SeeActs(rol, act_list);
                break;
            case 2:
                break;
            case 3:
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
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Enviar correo\n4) Activar/Desactivar actividad\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl;
                SeeActs(rol, act_list);
                break;
            case 2:
                break;
                
            case 3:

                break;
            case 4:
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
                    std::cout<<"\nNo existe ninguna actividad con ese ID.\n";
                    mode=138;
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
                            std::cout<<"\nActividad activada correctamente\n";
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
                            std::cout<<"\nActividad desactivada correctamente\n";
                            break;
                        }
                    }
                    break;

                case 138:
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
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Enviar correo\n4) Activar/Desactivar actividad\n5) Crear nueva actividad\n6) Eliminar actividad\n7) Modificar actividad\n8) Revisar preinscripciones\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            
            switch (opt)
            {
            case 0:
                break;

            case 1:
                std::cout<<std::endl;
                SeeActs(rol, act_list);
                break;

            case 2:
                break;
                
            case 3:

                break;
            case 4: //FUNCIONA
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
                    std::cout<<"\nNo existe ninguna actividad con ese ID.\n";
                    mode=138;
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
                            std::cout<<"\nActividad activada correctamente\n";
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
                            std::cout<<"\nActividad desactivada correctamente\n"<<it->GetStatus();
                            break;
                        }
                    }
                    break;

                case 138:
                    break;

                default:
                    std::cout<<"Opción no válida\n";
                    break;
                }

                break;
                
            case 5: //FUNCIONA
                std::cout<<std::endl;
                CreateAct(act_id, act_list);
                act_id++; //Aumentamos id para la siguiente creación
                break;

            case 6: //FUNCIONA
                std::cout<<std::endl;
                std::cout<<"\nIntroduzca el ID de la actividad a eliminar: ";
                std::cin>>aux_id;

                cont=0;
                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        DeleteList(it->GetActId(), act_list);
                        std::cout<<"\nActividad eliminada correctamente\n";
                        cont++;
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\nNo existe ninguna actividad con ese ID.\n";
                }
                break;

            case 7: //FUNCIONA
                std::cout<<std::endl;
                std::cout<<"\nIntroduzca el ID de la actividad a modificar: ";
                std::cin>>aux_id;
                std::cout<<std::endl;

                cont=0;
                for(auto it=act_list.begin(); it!=act_list.end(); it++)
                {
                    if(aux_id==it->GetActId())
                    {
                        ChangeAct(*it);
                        std::cout<<"\nActividad modificada correctamente\n";
                        cont++;
                        break;
                    }
                }
                if(cont==0)
                {
                    std::cout<<"\nNo existe ninguna actividad con ese ID.\n";
                }
                break;
                
            case 8:
                break;

            default:
                std::cout << "Opción no válida\n\n";
                break;

            }
        }
    }
    else
    {
        std::cout << "\nRol no válido, vuelva a ejecutar el programa.\n";
    }

    fout.open("actividades.txt");
    if(fout.is_open()==false)
    {
        printf("Error de la base de datos\n");
        exit(EXIT_FAILURE);
    }
    for(auto it=act_list.begin(); it!=act_list.end(); it++)
    {
        fout<<it->GetActId()<<"\n"<<it->GetName()<<"\n"<<it->GetBeginDate()<<"\n"<<it->GetEndDate()<<"\n"<<it->GetStatus()<<"\n"<<it->GetDescription()<<"\n"<<it->GetCapacity()<<"\n"<<it->GetFacultyId()<< std::endl;
    }
    std::cout << "\n¡Gracias por usar UCOTALLERES!\n"<<std::endl;
    fout.close();
}