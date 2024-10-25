#pragma once
#include "Acopio.h"

namespace Model {
    public ref class SistemaAutomatizado {
    public:
        int CantDesechos;
        Acopio^ Ubicacion;

        void EncenderFajaTransportadora();
        void DetectarTipoDesecho();
    };
}