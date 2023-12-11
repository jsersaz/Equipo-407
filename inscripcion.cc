#include "inscripcion.h"
#include "preinscripcion.cc"
#include <iostream>
#include <list>
#include <string>

bool AddListIns(Inscripcion i,std::list <Inscripcion> ins_list)
{
	for(auto it=ins_list.begin(); it!=ins_list.end(); ++it){
		if(it->GetInsId()==i.GetInsId()){
			return false;
		}
	}
	ins_list.push_back(i);
	return true;
}

bool DeleteListIns(Inscripcion i,std::list <Inscripcion> ins_list)
{
	for(auto it=ins_list.begin(); it!=ins_list.end(); ++it){
		if(it->GetInsId()==i.GetInsId()){
			ins_list.erase(it);
			return true;
		}
	}
	return false;
}

bool CreateIns(Preinscripcion p,std::list <Inscripcion> ins_list,std::list <Preinscripcion> pre_list)
{
    if(p.GetStatus==false)
    {
        std::string res;
        std::cout<<"La preinscripción seleccionada no ha sido aceptada aún. Desea continuar de todas formas?"<<std::endl;
        std::cin>>res;
        if(toupper(res)=="NO")
        {
            return false;
        }
    }
    Inscripcion i=Inscripcion(p.GetUser,p.GetPreInsId,p.GetActId);
    AddListIns(i,ins_list);
    DeleteListPre(p,pre_list);
    return true;
}

bool ShowIns(std::list <Inscripcion> ins_list)
{
    for(auto it=ins_list.begin();it!=ins_list.end();++it)
    {
            std::cout<<"ID: "<<it->GetInsId()<<std::endl;
            std::cout<<"Usuario: "<<it->GetUser()<<std::endl;
            std::cout<<"ID de actividad: "<<it->GetActId()<<std::endl<<std::endl;
    }
}