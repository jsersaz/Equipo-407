#include "preinscripcion.h"
#include <iostream>
#include <string>

bool Preinscripcion::AskCapacity()
{
    return true;
}

void Preinscripcion::AskData()
{
    std::cout << "Ingrese su Nick: ";
    std::cin >> user_;
}

void Preinscripcion::SetData()
{
    std::cout << "Datos guardados para " << user_ << std::endl;
}

void Preinscripcion::SetStatus(bool status)
{
    if (status == true){
        std::cout << "Preinscripción exitosa " << std::endl;
    } else {
        std::cout << "Preinscripción pendiente " << std::endl;
    }
}
void Preinscripcion::SendData(Mailing& mailing)
{
    mailing.SendMail(user_, status_);
}