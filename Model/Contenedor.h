
#pragma once
#include "Acopio.h"

using namespace System;
namespace Model {
    [Serializable] public ref class Contenedor {
    public:
        int Id;
        double CapacidadMax;
        Acopio^ Ubicacion;

        void AlmacenarDesecho();

        void VaciarContenedor();

        void validarCapacidad();
    };
}