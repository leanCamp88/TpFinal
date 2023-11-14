#include "menu.h"


menuLogin()
{
    while(1)
    {
        int log = login();

        switch(log)
        {
        case 1:
            menuAdministrador();
            break;
        case 2:
            menuAdministrativo();
            break;
        case 3:
            menuBioquimicoTecnico();
            break;
        default:
            printf("ERROR EN LOGIN\n");
            break;
        }
    }
}

menuAdministrador()
{
    int opc = 0;

    switch(opc)
    {
    case 1:
        menuEmpleados();
        break;
    case 2:
        menuPracticas();
        break;
    case 3:
        menuListadosYBusquedas();
        break;

    default:
        menuLogin();
        break;
    }
}

menuAdministrativo()
{

}

menuBioquimicoTecnico()
{

}


