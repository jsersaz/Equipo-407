#include "actividad.h"
#include <fstream>
#include <stdlib>

void Actividad::CreateAct(int act_count)
{
    Actividad a=Actividad(act_count);
    AddInfo(a);
}

void Actividad::AddInfo(Actividad a)
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
    SaveAct(a);
}

void Actividad::SaveAct(Actividad a)
{
    std::ofstream f("actividades.txt");
    if(f.is_open()==false)
    {
        std::cout<<"Error de apertura"<<std::endl;
    }
    else
    {
        f<<a.GetStatus()<<" "<<a.GetActId()<<" "<<a.GetName()<<" "<<a.GetDescription()<<" "<<a.GetBeginDate()<<" "<<a.GetEndDate()<<" "<<a.GetCapacity()<<" "<<a.GetFacultyId()<<std::endl;
        f.close();
    }
}

void Actividad::ShowAct(Actividad a)
{
    a.SetStatus(true);
    SaveAct(a);
}

void Actividad::HideAct(Actividad a)
{
    a.SetStatus(false);
    SaveAct(a);
}

void Actividad::SeeActs(int rol)
{
    std::string s;
    if(rol==1 || rol==2)
    {
        std::ifstream f("actividades.txt");
        if(f.is_open()==false)
        {
            std::cout<<"Error de apertura"<<std::endl;
        }
        else
        {
            while(!f.eof())
            {
                if((f>>bool i)==true)
                {
                    getline(f,s);
                    std::cout<<s<<std::endl;
                }
            }
            f.close();
        }
    }
    else
    {
        while(!f.eof())
        {
            if((f>>bool i)==true)
            {
                getline(f,s);
                std::cout<<s<<std::endl;
            }
        }
        f.close();
    }
}

bool Actividad::AddList(Activity a){
	for(auto it=activity_list_.begin(); it!=activity_list_.end(); ++it){
		if(it->GetActId()==a.GetActId()){
			return false;
		}
	}
	activity_list_.push_back(a);
	return true;
}

bool Actividad::DeleteList(Activity a){
	for(auto it=activity_list_.begin(); it!=activity_list_.end(); ++it){
		if(it->GetActId()==a.GetActId()){
			activity_list_.erase(it);
			return true;
		}
	}
	return false;
}
