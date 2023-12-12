#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
#include <string>

class Inscripcion
{
private:
    std::string user_;
    int act_id_; // Identificador de la actividad.
    int ins_id_; // Identificador de la inscripción.

public:
    // Constructor
    Inscripcion(std::string user = "empty",
                int act_id = 0,
                int ins_id = 0)
    {
        user_ = user;
        act_id_ = act_id;
        ins_id_ = ins_id;
    }

    std::string GetUser() { return user_; }
    int GetActId() { return act_id_; }
    int GetInsId() { return ins_id_; }

    void SetUser(std::string user) { user_ = user; }
    void SetActId(int act_id) { act_id_ = act_id; }
    void SetInsId(int ins_id) { ins_id_ = ins_id; }

};
#endif