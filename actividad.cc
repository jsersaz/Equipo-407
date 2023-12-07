#include "actividad.h"
#include <fstream>
#include <list>

void CreateAct(int act_count,std::list <Actividad> act_list)
{
    Actividad a=Actividad(act_count);
    AddInfo(a);
    AddList(a,act_list);
}

void ChangeAct(Actividad a)
{
    std::string s;
    int id=a.GetActId(),n,i;
    std::cout<<"Seleccione el campo a modificar:"<<std::endl;
    std::cout<<"1)Nombre"<<std::endl;
    std::cout<<"2)Fecha de inicio"<<std::endl;
    std::cout<<"3)Fecha de finalizacion"<<std::endl;
    std::cout<<"4)Descripcion"<<std::endl;
    std::cout<<"5)Aforo"<<std::endl;
    std::cout<<"6)ID de la facultad"<<std::endl;
    std::cin>>i;
    std::cout<<std::endl;
    switch(i)
    {
        case 1:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>s;
            a.SetName(s);
            std::cout<<std::endl;
        break;

        case 2:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>s;
            a.SetBeginDate(s);
            std::cout<<std::endl;
        break;

        case 3:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>s;
            a.SetEndDate(s);
            std::cout<<std::endl;
        break;

        case 4:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>s;
            a.SetDescription(s);
            std::cout<<std::endl;
        break;

        case 5:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>n;
            a.SetCapacity(n);
            std::cout<<std::endl;
        break;

        case 6:
            std::cout<<"Introduzca el nuevo campo para la actividad: "<<std::endl;
            std::cin>>n;
            a.SetFacultyId(n);
            std::cout<<std::endl;
        break;

        default:
            std::cout<<"Error, valor incorrecto"<<std::endl<<std::endl;
        break;
    }
}

void AddInfo(Actividad a)
{
    std::string name,description,begin_date,end_date;
	int capacity,faculty_id;
    std::cout<<"Introduzca el nombre de la actividad: ";
    getline(std::cin,name);
    std::cout<<"Introduzca la fecha de inicio de la actividad: ";
    std::cin>>begin_date;
    std::cout<<"Introduzca la fecha de finalizacion de la actividad: ";
    std::cin>>end_date;
    std::cout<<"Introduzca el aforo de la actividad: ";
    std::cin>>capacity;
    std::cout<<"Introduzca el id de la facultad a la que se asocia la actividad: ";
    std::cin>>faculty_id;
    std::cout<<"Introduzca la descripcion de la actividad: ";
    getline(std::cin,description);
    std::cout<<std::endl;
    a.SetName(name);
	a.SetBeginDate(begin_date);
	a.SetEndDate(end_date);
	a.SetStatus(false);
	a.SetDescription(description);
	a.SetCapacity(capacity);
	a.SetFacultyId(faculty_id);
}

void ShowAct(Actividad a)
{
    a.SetStatus(true);
}

void HideAct(Actividad a)
{
    a.SetStatus(false);
}

void SeeActs(int rol, std::list<Actividad> act_list)
{
    if(rol==1 || rol==2)
    {
        for(auto it=act_list.begin();it!=act_list.end();++it)
        {
            if(it->GetStatus()==true)
            {
                std::cout<<"ID: "<<it->GetActId()<<std::endl;
                std::cout<<"Nombre: "<<it->GetName()<<std::endl;
                std::cout<<"Fecha de Inicio: "<<it->GetBeginDate()<<std::endl;
                std::cout<<"Fecha de Finalizacion: "<<it->GetEndDate()<<std::endl;
                std::cout<<"Aforo: "<<it->GetCapacity()<<std::endl;
                std::cout<<"ID de facultad: "<<it->GetFacultyId()<<std::endl;
                std::cout<<"Descripcion: "<<it->GetDescription()<<std::endl<<std::endl;
            }
        }
    }
    else
    {
        for(auto it=act_list.begin();it!=act_list.end();++it)
        {
            std::cout<<"ID: "<<it->GetActId()<<std::endl;
            std::cout<<"Nombre: "<<it->GetName()<<std::endl;
            std::cout<<"Fecha de Inicio: "<<it->GetBeginDate()<<std::endl;
            std::cout<<"Fecha de Finalizacion: "<<it->GetEndDate()<<std::endl;
            if(it->GetStatus()==true)
            {
                std::cout<<"Estado: Activada"<<std::endl;
            }
            else
            {
                std::cout<<"Estado: Desactivada"<<std::endl;
            }
            std::cout<<"Aforo: "<<it->GetCapacity()<<std::endl;
            std::cout<<"ID de facultad: "<<it->GetFacultyId()<<std::endl;
            std::cout<<"Descripcion: "<<it->GetDescription()<<std::endl<<std::endl;
        }
    }
}

bool AddList(Actividad a,std::list <Actividad> act_list)
{
	for(auto it=act_list.begin(); it!=act_list.end(); ++it){
		if(it->GetActId()==a.GetActId()){
			return false;
		}
	}
	act_list.push_back(a);
	return true;
}

bool DeleteList(Actividad a,std::list <Actividad> act_list)
{
	for(auto it=act_list.begin(); it!=act_list.end(); ++it){
		if(it->GetActId()==a.GetActId()){
			act_list.erase(it);
			return true;
		}
	}
	return false;
}
