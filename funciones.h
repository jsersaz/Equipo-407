#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "actividad.h"
#include "preinscripcion.h"
#include "inscripcion.h"
#include <iostream>
#include <list>

void CreateAct(int act_count,std::list <Actividad> &act_list); //PONER &
void ChangeAct(Actividad &a);
void AddInfo(Actividad &a);
void ShowAct(Actividad &a);
void HideAct(Actividad &a);
void SeeActs(int rol, std::list<Actividad> act_list);
bool AddList(Actividad a,std::list<Actividad> &act_list);
bool DeleteList(Actividad a,std::list<Actividad> &act_list);

void CreatePreinscription(int pre_count, int act_id, int &capacity, std::list <Preinscripcion> &pre_list, std::string nick);
void AddData(Preinscripcion &p, std::string user);
void SeePreinscriptions(int rol, std::list <Preinscripcion> pre_list, std::string nick="empty");
void MakePayment(int pre_id, std::list <Preinscripcion> &pre_list);
bool ChangeStatus(int pre_id, std::list <Preinscripcion> &pre_list);
bool AddListPre(Preinscripcion p, std::list <Preinscripcion> &pre_list);
bool DeleteListPre(Preinscripcion p, std::list <Preinscripcion> &pre_list);

bool AddListIns(Inscripcion i,std::list <Inscripcion> &ins_list);
bool DeleteListIns(Inscripcion i,std::list <Inscripcion> &ins_list);
bool CreateIns(Preinscripcion p,std::list <Inscripcion> &ins_list,std::list <Preinscripcion> &pre_list);
void SeeIns(int rol,std::list <Inscripcion> ins_list, std::string nick="empty");

#endif