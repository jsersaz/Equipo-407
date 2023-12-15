#include "inscripcion.h"
#include "funciones.h"
#include <iostream>
#include <list>
#include <string>

bool AddListIns(Inscripcion i,std::list <Inscripcion> &ins_list) 
{
	for(auto it=ins_list.begin(); it!=ins_list.end(); ++it){
		if(it->GetInsId()==i.GetInsId()){
			return false;
		}
	}
	ins_list.push_back(i);
	return true;
}

bool DeleteListIns(Inscripcion i,std::list <Inscripcion> &ins_list)
{
	for(auto it=ins_list.begin(); it!=ins_list.end(); ++it){
		if(it->GetInsId()==i.GetInsId()){
			ins_list.erase(it);
			return true;
		}
	}
	return false;
}

bool CreateIns(Preinscripcion p,std::list <Inscripcion> &ins_list,std::list <Preinscripcion> &pre_list)
{
    Inscripcion i=Inscripcion(p.GetUser(),p.GetActId(),p.GetPreId()); 
    AddListIns(i,ins_list);
    DeleteListPre(p,pre_list);
    return true;
}

void SeeIns(int rol,std::list <Inscripcion> ins_list, std::string nick) //HE CAMBIADO PASAR EL NICK COMO ARGUMENTO
{
    int cont=0;
    if(rol==2)
    {
        for(auto it=ins_list.begin();it!=ins_list.end();++it)
        {
            if(it->GetUser()==nick)
            {
                cont++;
                std::cout<<"ID:              "<<it->GetInsId()<<std::endl;
                std::cout<<"Usuario:         "<<it->GetUser()<<std::endl;
                std::cout<<"ID de actividad: "<<it->GetActId()<<std::endl<<std::endl;
            }
        }
        if(cont==0)
        {
            std::cout<<std::endl<<"~No esta inscrito en ninguna actividad en este momento ~"<<std::endl;
        }
    }
    else if(rol>2)
    {
        if(ins_list.size()==0)
        {
            std::cout<<std::endl<<"~No existe ninguna inscripcion~"<<std::endl;
        }
        for(auto it=ins_list.begin();it!=ins_list.end();++it)
        {
            std::cout<<"ID:              "<<it->GetInsId()<<std::endl;
            std::cout<<"Usuario:         "<<it->GetUser()<<std::endl;
            std::cout<<"ID de actividad: "<<it->GetActId()<<std::endl<<std::endl;
        }
    }
}