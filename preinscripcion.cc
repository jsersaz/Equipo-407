#include "preinscripcion.h"
#include "actividad.h"
#include <iostream>
#include <string>
#include <list>

void CreatePreinscription(int pre_count, std::string act_id, int capacity, std::list <Preinscripcion> pre_list){
	if(capacity>0){
		Preinscripcion p=Preinscripcion(pre_count, act_id);
		AddData(p);
		AddListPre(p,pre_list);
		capacity--;
	}
	else{
		std::cout<<"Aforo insuficiente. Imposible crear la preinscripción\n";
	}
}

void AddData(Preinscripcion p){
	std::string user;
	std::cout<<"Introduzca su usuario: ";
	std::cin>>user;
	p.SetUser(user);
}

void SeePreinscriptions(){
	std::string nick;
	std::cout<<"Introduzca su usuario: ";
	std::cin>>nick;
	if(rol==2){
        for(auto it=pre_list.begin();it!=pre_list.end();++it){
            if(it->GetUser()==nick){
                std::cout<<"ID de preinscripción: "<<it->GetPreId()<<std::endl;
                std::cout<<"Usuario: "<<it->GetUser()<<std::endl;
				std::cout<<"ID de actividad: "<<it->GetActId()<<std::endl;
            }
        }
    }
    else if(rol==3||rol==4){
        for(auto it=pre_list.begin();it!=pre_list.end();++it){
            std::cout<<"ID de preinscripción: "<<it->GetPreId()<<std::endl;
			std::cout<<"Usuario: "<<it->GetUser()<<std::endl;
			std::cout<<"ID de actividad: "<<it->GetActId()<<std::endl;
            if(it->GetStatus()==true){
                std::cout<<"Estado: Aceptada"<<std::endl;
            }
            else{
                std::cout<<"Estado: No aceptada"<<std::endl;
            }
        }
    }
}

void MakePayment(std::string pre_id, std::list <Preinscripcion> pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==pre_id){
			p.SetPayNote(true);
		}
	}
}

void ChangeStatus(std::string pre_id, std::list <Preinscripcion> pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(p.GetPayNote()==true){
			if(it->GetPreId()==pre_id){
				p.SetStatus(true);
				std::cout<<"Preinscripción aceptada\n";
			}
		}
		else{
			std::cout<<"Pagaré no enviado. Imposible aceptar la preinscripción\n";
		}
	}
}

bool AddListPre(Preinscripcion p, std::list <Preinscripcion> pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==p.GetPreId()){
			return false;
		}
	}
	pre_list.push_back(p);
	return true;
}

bool DeleteListPre(Preinscripcion p, std::list <Preinscripcion> pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==p.GetPreId()){
			pre_list.erase(it);
			return true;
		}
	}
	return false;
}