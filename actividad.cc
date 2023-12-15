#include "actividad.h"
#include "funciones.h"
#include <list>

void CreateAct(int act_count,std::list <Actividad> &act_list)
{
    Actividad a(act_count);
    AddInfo(a);
    AddList(a, act_list);
}

void ChangeAct(Actividad &a)
{
    int id=a.GetActId();
    std::cout<<"-----------------------------------------------------------------------\n";
    std::cout<<"Seleccione el campo a modificar:"<<std::endl;
    std::cout<<"1)Nombre"<<std::endl;
    std::cout<<"2)Fecha de inicio"<<std::endl;
    std::cout<<"3)Fecha de finalización"<<std::endl;
    std::cout<<"4)Descripción"<<std::endl;
    std::cout<<"5)Precio"<<std::endl;
    std::cout<<"6)Aforo"<<std::endl;
    std::cout<<"7)ID de la facultad"<<std::endl;
    std::cout<<"-----------------------------------------------------------------------\n"<<std::endl;
    std::cout<<"--> ";
    int i;
    std::cin>>i;
    std::cout<<std::endl;
    std::string n;
    int m;
	float j;
    switch(i) //NO SE PUEDEN DECLARAR VARIAS VARIABLES CON EL MISMO NOMBRE Y DISTINTO TIPO, DECLARAR TODAS ANTES DE EMPEZAR EL SWITCH
    { //DECLARAR i ANTES DE ELEGIR EL SWITCH Y HACER cin
        case 1:
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetName(n);
        break;

        case 2:
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetBeginDate(n);
        break;

        case 3:
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetEndDate(n);
        break;

        case 4:
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>n;
            a.SetDescription(n);
        break;

		case 5:
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>j;
            a.SetPrice(j);
        break;

        case 6://CAMBIAR m POR EJEMPLO
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>m;
            a.SetCapacity(m);
        break;

        case 7: //CAMBIAR A m POR EJEMPLO
            std::cout<<"Introduzca el nuevo campo para la actividad"<<std::endl;
            std::cin>>m;
            a.SetFacultyId(m);
        break;

        default:
            std::cout<<"Error, valor incorrecto"<<std::endl;
        break;
    }
}

void AddInfo(Actividad &a)
{

    std::string name ,description ,begin_date ,end_date;
	int capacity,faculty_id;
	float price;
    std::cout<<"Introduzca el nombre de la actividad: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout<<"Introduzca la fecha de inicio de la actividad: ";
    std::cin>>begin_date;
    std::cout<<"Introduzca la fecha de finalización de la actividad: ";
    std::cin>>end_date;
    std::cout<<"Introduzca el aforo de la actividad: ";
    std::cin>>capacity;
	std::cout<<"Introduzca el precio de inscripción a la actividad: ";
    std::cin>>price;
    std::cout<<"Introduzca el id de la facultad a la que se asocia la actividad: ";
    std::cin>>faculty_id;
    std::cout<<"Introduzca la descripción de la actividad: ";
    std::cin.ignore();
    getline(std::cin, description);
    a.SetName(name);
	a.SetBeginDate(begin_date);
	a.SetEndDate(end_date);
	a.SetStatus(false);
	a.SetDescription(description);
	a.SetCapacity(capacity);
	a.SetPrice(price);
	a.SetFacultyId(faculty_id);
}

void ShowAct(Actividad &a)
{
    a.SetStatus(true);
}

void HideAct(Actividad &a)
{
    a.SetStatus(false);
}

void SeeActs(int rol, std::list<Actividad> act_list)
{
    int cont=0;
    if(rol==1 || rol==2)
    {   
        for(auto it=act_list.begin();it!=act_list.end();++it)
        {
            if(it->GetStatus()==true) //Poner con formato
            {
                cont++;
                std::cout<<"ID:                         "<<it->GetActId()<<std::endl;
                std::cout<<"Nombre:                     "<<it->GetName()<<std::endl;
                std::cout<<"Fecha de Inicio:            "<<it->GetBeginDate()<<std::endl;
                std::cout<<"Fecha de Finalizacion:      "<<it->GetEndDate()<<std::endl;
                std::cout<<"Aforo:                      "<<it->GetCapacity()<<std::endl;
                std::cout<<"Precio:                     "<<it->GetPrice()<<std::endl;
                std::cout<<"ID de la facultad asociada: "<<it->GetFacultyId()<<std::endl;
                std::cout<<it->GetDescription()<<std::endl;
                std::cout<<std::endl;
            }
        }
        if(cont==0)
        {
            std::cout<<"~No hay actividades activas en este momento~"<<std::endl;
        }
    }
    else
    {
        if(act_list.size()==0)
        {
            std::cout<<"~No existe ninguna actividad~"<<std::endl;
        }
        else
        {
            for(auto it=act_list.begin();it!=act_list.end();++it)
            {
                cont++;
                std::cout<<"ID:                         "<<it->GetActId()<<std::endl;
                std::cout<<"Nombre:                     "<<it->GetName()<<std::endl;
                std::cout<<"Fecha de Inicio:            "<<it->GetBeginDate()<<std::endl;
                std::cout<<"Fecha de Finalizacion:      "<<it->GetEndDate()<<std::endl;
                std::cout<<"Aforo:                      "<<it->GetCapacity()<<std::endl;
                std::cout<<"Precio:                     "<<it->GetPrice()<<std::endl;
                std::cout<<"ID de la facultad asociada: "<<it->GetFacultyId()<<std::endl;
                if(it->GetStatus()==1)
                {
                    std::cout<<"Estado:                     ACTIVA"<<std::endl;
                }
                else
                {
                    std::cout<<"Estado:                     INACTIVA"<<std::endl;
                }
                std::cout<<it->GetDescription()<<std::endl;
                std::cout<<std::endl;
            }
        }
    }
}

bool AddList(Actividad a,std::list <Actividad> &act_list)
{
	for(auto it=act_list.begin(); it!=act_list.end(); ++it)
    {
		if(it->GetActId()==a.GetActId())
        {
			return false;
		}
	}
	act_list.push_back(a);
	return true;
}

bool DeleteList(Actividad a,std::list <Actividad> &act_list)
{
	for(auto it=act_list.begin(); it!=act_list.end(); ++it){
		if(it->GetActId()==a.GetActId()){
			act_list.erase(it);
			return true;
		}
	}
	return false;
}