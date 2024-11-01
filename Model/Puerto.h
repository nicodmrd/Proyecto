#pragma once
#include "Coordenadas.h"
#include "Encargado.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    public ref class Puerto {
    public:
        Coordenadas^ Posicion;
        List<Encargado^>^ EmpleadosAcopio;
    };
}
