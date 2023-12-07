#include <iostream>
#include <fstream>
#include "actividad.h"
#include <list>

int main(void)
{
    int rol, opt=1;
    std::ifstream f;

    std::cout << "\n-----------------------------------------------------------------------\n"; //Selección de rol
    std::cout << "¡Bienvenido a UCOTALLERES! Seleccione el rol con el que desea acceder.\n";
    std::cout << "1) Visitante\n2) Usuario registrado\n3) Director académico\n4) Organizador\n";
    std::cout << "-----------------------------------------------------------------------\n\n";
    std::cout << "--> ";
    std::cin >> rol;
    std::string fichero;

    f.open("actividades.txt"); //ABRIMOS EL FICHERO
    if(f.is_open()==false)
    {
        printf("Error de la base de datos\n");
        exit(EXIT_FAILURE);
    }

    std::list<Actividad> act_list;
    Actividad aux(0);
    int act_id;
	std::string name;
	std::string begin_date;
	std::string end_date;
	bool status;
	std::string description;
	int capacity;
	int faculty_id;
    int i=0;
    
    while(f>>act_id) //LA VARIABLE ACT_ID SIRVE COMO CONTADOR PARA SABER QUÉ ID PONERLE A LA NUEVA ACTIVIDAD CREADA
    {
        f.ignore();
        getline(f, name);
        getline(f, begin_date);
        getline(f, end_date);
        f>>status;
        f.ignore();
        getline(f, description);
        f>>capacity;
        f.ignore();
        f>>faculty_id;
        f.ignore();
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

    f.close();
    
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

                break;
            case 2:
                break;
                
            case 3:

                break;
            case 4:
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
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Enviar correo\n4) Activar/Desactivar actividad\n5) Crear nueva actividad\n6) Modificar actividad\n7) Revisar preinscripciones\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            
            switch (opt)
            {
            case 0:
                break;

            case 1:

                break;

            case 2:
                break;
                
            case 3:

                break;
            case 4:
                break;
                
            case 5:

                break;

            case 6:
                break;

            case 7:
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

    std::ofstream fout;
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
    std::cout << "\n¡Gracias por usar UCOTALLERES!\n";
    fout.close();
}