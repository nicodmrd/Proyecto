#pragma once

#pragma once
#include "Coordenadas.h"
#include "Encargado.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    [Serializable] public ref class Acopio {
    public:
        Coordenadas^ Posicion;
        List<Encargado^>^ EmpleadosAcopio;

    };
}


