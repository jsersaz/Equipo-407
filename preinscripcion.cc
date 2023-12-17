#include "preinscripcion.h"
#include "actividad.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <list>

void CreatePreinscription(int pre_count, int act_id, int &capacity, std::list <Preinscripcion> &pre_list, std::string nick){ //HE PASADO EL NICK COMO ARGUMENTO
	if(capacity>0){
		Preinscripcion p=Preinscripcion(pre_count, act_id);
		AddData(p, nick);
		AddListPre(p,pre_list);
		capacity--;
		
	}
	else{
		std::cout<<"~Aforo insuficiente. Imposible crear la preinscripción~\n";
	}
}

void AddData(Preinscripcion &p, std::string user){
	
	p.SetUser(user);
}

void SeePreinscriptions(int rol, std::list <Preinscripcion> pre_list, std::string nick){ //HE CAMBIADO A PASAR EL NICK COMO ARGUMENTO
	
	int cont=0;
	if(rol==2){
        for(auto it=pre_list.begin();it!=pre_list.end();++it){
            if(it->GetUser()==nick){
				cont++;
				std::cout<<std::endl;
                std::cout<<"ID de preinscripción: "<<it->GetPreId()<<std::endl;
                std::cout<<"Usuario:              "<<it->GetUser()<<std::endl;
				std::cout<<"ID de actividad:      "<<it->GetActId()<<std::endl;
				if(it->GetPayNote()==true){
				std::cout<<"Estado:               PAGADA"<<std::endl;
				}
				else{
				std::cout<<"Estado:               NO PAGADA"<<std::endl;
				}
            }
        }
		if(cont==0)
		{
			std::cout<<std::endl<<"~No esta preinscrito en ninguna actividad en este momento ~"<<std::endl;
		}
    }
    else if(rol==3||rol==4){
		if(pre_list.size()==0)
		{
			std::cout<<std::endl<<"~No existe ninguna inscripcion~"<<std::endl;
		}
        for(auto it=pre_list.begin();it!=pre_list.end();++it){
            std::cout<<"ID de preinscripción: "<<it->GetPreId()<<std::endl;
			std::cout<<"Usuario:              "<<it->GetUser()<<std::endl;
			std::cout<<"ID de actividad:      "<<it->GetActId()<<std::endl;
            if(it->GetPayNote()==true){
            std::cout<<"Estado:               PAGADA"<<std::endl;
            }
            else{
            std::cout<<"Estado:               NO PAGADA"<<std::endl;
            }
			std::cout<<std::endl;
        }
    }
}

void MakePayment(int pre_id, std::list <Preinscripcion> &pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==pre_id){
			it->SetPayNote(true);
		}
	}
}

bool ChangeStatus(int pre_id, std::list <Preinscripcion> &pre_list){ 
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPayNote()==true){
			if(it->GetPreId()==pre_id){
				it->SetStatus(true);
				return true;
			}
		}
		else{
			std::cout<<"~Pagaré no enviado. Imposible aceptar la preinscripción "<<pre_id<<"~\n";
			return false;
		}
	}
	return true;
}

bool AddListPre(Preinscripcion p, std::list <Preinscripcion> &pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==p.GetPreId()){
			return false;
		}
	}
	pre_list.push_back(p);
	return true;
}

bool DeleteListPre(Preinscripcion p, std::list <Preinscripcion> &pre_list){
	for(auto it=pre_list.begin(); it!=pre_list.end(); ++it){
		if(it->GetPreId()==p.GetPreId()){
			pre_list.erase(it);
			return true;
		}
	}
	return false;
}