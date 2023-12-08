#ifndef PREINSCRIPCION_H
#define PREINSCRIPCION_H

#include "mailing.h"
#include "usuario.h"
#include <string>

class Preinscripcion
{
private:
    std::string user_;
    int act_id_;
    bool status_;  // True: preinscripción aceptada, False: preinscripción pendiente
    int capacity_; // Capacidad actual de la actividad
    int maxcapacity_;

public:
    // Constructor
    Preinscripcion(std::string user = "empty",
                   int act_id = 0,
                   bool status = false,
                   int capacity = 0,
                   int maxcapacity = 0)
    {
        user_ = user;
        act_id_ = act_id;
        status_ = status;
        capacity_ = capacity;
        maxcapacity_ = maxcapacity;
    }

    // Función para verificar capacidad y decidir preinscripción
    bool AskCapacity(int maxcapacity, int capacity, bool status)
    {
        if (capacity < maxcapacity)
        {
            std::cout << "Hay aforo disponible. ¿Desea preinscribirse? (Si/No):\n";
            char respuesta;
            std::cin >> respuesta;
            if (respuesta == 'Si' || respuesta == 'si' || respuesta == 'Sí' || respuesta == 'sí')
            {
                status == true;
                std::cout << "Se ha preinscrito correctamente.\n";
                return (respuesta == 'Si' || respuesta == 'si' || respuesta == 'Sí' || respuesta == 'sí');
            }
            else
            {
                std::cout << "No se ha preinscrito a la actividad.\n";
                return status; // return false;
            }
        }
        else
        {
            std::cout << "El aforo está completo. Preinscripción pendiente.\n";
            return status; // return false;
        }
    }

    // Función para pedir datos al usuario
    void AskData()
    {
        std::cout << "Ingrese su Nick:\n";
        std::cin >> user_;
    }

    // Función para guardar datos del usuario preinscrito de la clase Usuario
    void SetData(Usuario &user)
    {
        user_ = user.nick;
        std::cout << "Datos guardados para " << user_ << std::endl;
    }

    void SendData(Mailing &mailing)
    {
        mailing.SendMail(user_, status_);
    }

    // Función para mostrar la lista de preinscripciones (datos de los usuarios preinscritos y pendientes por preinscribirse)
    void ShowData()
    {
    }
};
#endif