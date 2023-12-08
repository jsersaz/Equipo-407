#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
#include <string>

class Inscripcion
{
private:
    std::string user_;
    int act_id_;
    bool status_; // True: inscripción aceptada, False: inscripción denegada
    float price_;
    bool pay_note_; // True: pagaré subido, False: pagaré no subido
    std::string description_;
    int ins_id_; // Identificador de la inscripción.

public:
    // Constructor
    Inscripcion(std::string user = "empty",
                int act_id = 0,
                bool status = false,
                float price = 0,
                bool pay_note = false,
                std::string description = "empty",
                int ins_id = 0)
    {
        user_ = user;
        act_id_ = act_id;
        status_ = status;
        price_ = price;
        pay_note_ = pay_note;
        description_ = description;
        ins_id_ = ins_id;
    }

    // Función para introducir el usuario
    void SetUser(std::string user)
    {
        std::cout << "Ingrese su Nick:\n";
        std::cin >> user;
    }

    // Función para introducir el precio de la inscripción
    void SetPrice(float price)
    {
        std::cout << "Ingrese el precio de la inscripción:\n";
        std::cin >> price;
    }

    // Función para modificar el estado del pagaré
    void SetPayNote(bool pay_note)
    {
        pay_note_ = pay_note;
        std::cout << "El estado del pagaré es " << pay_note << ". ¿Desea cambiarlo? (Si/No)\n";
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 'Si' || respuesta == 'si' || respuesta == 'Sí' || respuesta == 'sí')
        {
            if (pay_note)
            {
                pay_note = false;
            }
            else
            {
                pay_note = true;
            }
            std::cout << "Se ha modificado el estado del pagaré correctamente.\n";
        }
        else
        {
            std::cout << "No ha modificado el estado del pagaré.\n";
        }
    }

    // Funcion para modificarl el estado de la inscripción
    void SetStatus(bool status)
    {
        status_ = status;
        std::cout << "El estado de la inscripcion es " << status << ". ¿Desea cambiarlo? (Si/No)\n";
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 'Si' || respuesta == 'si' || respuesta == 'Sí' || respuesta == 'sí')
        {
            if (status)
            {
                status = false;
            }
            else
            {
                status = true;
            }
            std::cout << "Se ha modificado el estado de la inscripcion correctamente.\n";
        }
        else
        {
            std::cout << "No ha modificado el estado de la inscripcion.\n";
        }
    }

    // Funcion para modificar la descripción de la inscripción
    void SetDescription(std::string description)
    {
        description_ = description;
        std::cout << "Introduzca la descripción de la inscripción:\n";
        std::cin >> description;
    }

    // Funcion para obtener el usuario
    std::string GetUser() { return user_; }

    // Funcion para obtener el precio
    float GetPrice() { return price_; }

    // Funcion para obtener el pagaré (true: subido, false: por subir)
    bool GetPayNote() { return pay_note_; }

    // Funcion para obtener el estado de la inscripción (true: inscrito, false: no inscrito)
    bool GetStatus() { return status_; }

    // Funcion para obtener la descripción
    std::string GetDescription() { return description_; }
};
#endif