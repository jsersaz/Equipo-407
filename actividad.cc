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
    int id=a.GetActId();
    std::cout<<"Seleccione el campo a modificar:"<<std::endl;
    std::cout<<"1)Nombre"<<std::endl;
    std::cout<<"2)Fecha de inicio"<<std::endl;
    std::cout<<"3)Fecha de finalizacion"<<std::endl;
    std::cout<<"4)Descripcion"<<std::endl;
    std::cout<<"5)Aforo"<<std::endl;
    std::cout<<"6)ID de la facultad"<<std::endl;
    switch(int i)
    {
        case 1:
            std::string n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetName(n);
        break;

        case 2:
            std::string n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetBeginDate(n);
        break;

        case 3:
            std::string n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetEndDate(n);
        break;

        case 4:
            std::string n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetDescription(n);
        break;

        case 5:
            int n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetCapacity(n);
        break;

        case 6:
            int n;
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetFacultyId(n);
        break;

        default:
            std::cout<<"Error, valor incorrecto"<<std::endl;
        break;
    }
}

void AddInfo(Actividad a)
{
    std::string name,description,begin_date,end_date;
	int capacity,faculty_id;
    std::cout<<"Introduzca el nombre de la actividad:";
    std::cin>>name;
    std::cout<<"Introduzca la descripcion de la actividad:";
    std::cin>>descripcion;
    std::cout<<"Introduzca la fecha de inicio de la actividad:";
    std::cin>>begin_date;
    std::cout<<"Introduzca la fecha de finalizacion de la actividad:";
    std::cin>>end_date;
    std::cout<<"Introduzca el aforo de la actividad:";
    std::cin>>capacity;
    std::cout<<"Introduzca el id de la facultad a la que se asocia la actividad:";
    std::cin>>faculty_id;
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
                std::cout<<it->GetActId()<<std::endl;
                std::cout<<it->GetName()<<std::endl;
                std::cout<<it->GetBeginDate()<<std::endl;
                std::cout<<it->GetEndDate()<<std::endl;
                std::cout<<it->GetDescription()<<std::endl;
                std::cout<<it->GetCapacity()<<std::endl;
                std::cout<<it->GetFacultyId()<<std::endl;
            }
        }
    }
    else
    {
        for(auto it=act_list.begin();it!=act_list.end();++it)
        {
            std::cout<<it->GetActId()<<std::endl;
            std::cout<<it->GetName()<<std::endl;
            std::cout<<it->GetBeginDate()<<std::endl;
            std::cout<<it->GetEndDate()<<std::endl;
            std::cout<<it->GetStatus()<<std::endl;
            std::cout<<it->GetDescription()<<std::endl;
            std::cout<<it->GetCapacity()<<std::endl;
            std::cout<<it->GetFacultyId()<<std::endl;
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
