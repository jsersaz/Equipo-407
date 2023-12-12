#ifndef PREINSCRIPCION_H
#define PREINSCRIPCION_H

/*#include "mailing.h" 
#include "usuario.h"*/
#include <string>
#include <iostream> //AÑADIR

class Preinscripcion
{
private:
    std::string user_;
    int act_id_;
    bool status_;  // True: preinscripción aceptada, False: preinscripción pendiente
    // int capacity_; // Capacidad actual de la actividad
    // int maxcapacity_;
    int preins_id_;
    bool paynote_;

public:
    // Constructor
    Preinscripcion(int preins_id, int act_id, std::string user = "empty", bool status = false, float price = 0)
    {
        preins_id_=preins_id;
        user_ = user;
        act_id_ = act_id;
        status_ = status;
    }

    bool GetPayNote(){return paynote_;}
    std::string GetUser(){return user_;}
    int GetActId(){return act_id_;}
    bool GetStatus(){return status_;}
    int GetPreId(){return preins_id_;}
    void SetPayNote(bool paynote){paynote_=paynote;}
    void SetUser(std::string user){user_=user;}
    void SetActId(int act_id){act_id_=act_id;}
    void SetStatus(bool status){status_=status;}
    void SetPreId(int preins_id){preins_id_=preins_id;}
};
#endif