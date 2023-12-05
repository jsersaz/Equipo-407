#include <iostream>
#include <fstream>


int main(void)
{
    int rol, opt=1;
    std::fstream f;

    std::cout << "\n-----------------------------------------------------------------------\n"; //Selección de rol
    std::cout << "¡Bienvenido a UCOTALLERES! Seleccione el rol con el que desea acceder.\n";
    std::cout << "1) Visitante\n2) Usuario registrado\n3) Director académico\n4) Organizador\n";
    std::cout << "-----------------------------------------------------------------------\n\n";
    std::cout << "--> ";
    std::cin >> rol;

    f.open("actividades.txt");
    if(!f.is_open())
    {
        std::cout << "Error de la base de datos\n"; //No se ha abierto el fichero actividades
        exit(EXIT_FAILURE);
    }

    if(rol==1)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:
                break;
            
            default:
                std::cout << "Opción no válida\n\n";
                break;
            }
        }

    }
    else if(rol==2)
    {
        while (opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:

                break;
            case 2:
                break;
            
            default:
                
                std::cout << "Opción no válida\n\n";
                break;
            }
        }
    }
    else if(rol==3)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Enviar correo\n4) Activar/Desactivar actividad\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            switch (opt)
            {
            case 0:
                break;

            case 1:

                break;
            case 2:
                break;
                
            case 3:

                break;
            case 4:
                break;
            
            default:
                
                std::cout << "Opción no válida\n\n";
                break;
            }
        }
    }
    else if(rol==4)
    {
        while(opt!=0)
        {
            std::cout << "\n-----------------------------------------------------------------------\n";
            std::cout << "Seleccione:\n";
            std::cout << "0) Salir\n1) Consultar actividades\n2) Preinscribirse\n3) Enviar correo\n4) Activar/Desactivar actividad\n5) Crear nueva actividad\n6) Modificar actividad\n";
            std::cout << "-----------------------------------------------------------------------\n\n";
            std::cout << "--> ";
            std::cin >> opt;
            
            switch (opt)
            {
            case 0:
                break;

            case 1:

                break;
            case 2:
                break;
                
            case 3:

                break;
            case 4:
                break;
                
            case 5:

                break;
            case 6:
                break;
                
            default:
                
                std::cout << "Opción no válida\n\n";
                break;

            }
        }
    }
    else
    {
        std::cout << "\nRol no válido, vuelva a ejecutar el programa.\n";
    }

    std::cout << "¡Gracias por usar UCOTALLERES!\n";
    f.close();
}