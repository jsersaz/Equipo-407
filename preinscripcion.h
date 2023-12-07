#ifndef PREINSCRIPCION_H
#define PREINSCRIPCION_H
#include <string>

class Preinscripcion
{
private:
    std::string user_;
    bool status_; //True: aceptada, False: denegada/pendiente
    int act_id_;

public:
    Preinscripcion(std::string user, bool status, int act_id)
    {
        user_ = user;
        status_ = status;
        act_id_ = act_id;
    }
    bool AskCapacity();
    void AskData();
    void SetData();
    void SetStatus(bool status_);
    void SendData(Mailing& mailing);
};
#endif