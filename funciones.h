#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "actividad.h"
#include <list>

void CreateAct(int act_count,std::list <Actividad> act_list);
void ChangeAct(Actividad a);
void AddInfo(Actividad a);
void ShowAct(Actividad a);
void HideAct(Actividad a)
void SeeActs(int rol, std::list<Actividad> act_list);
bool AddList(Actividad a,std::list <Actividad> act_list);
bool DeleteList(Actividad a,std::list <Actividad> act_list);

#endif