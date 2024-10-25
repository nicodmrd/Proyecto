
#pragma once
#include "Coordenadas.h"
#include "Contenedor.h"
using namespace System::Collections::Generic;

namespace Model {
    [Serializable] public ref class Barco {
    public:
        int Id;
        double CapacidadMax;
        double CapacidadActual;
        double NivelCombustible;
        Coordenadas^ Posicion;
        int CantCoordendas;
        Contenedor^ Contenedores;

        void RecogerDesecho();

        void DescargarDesecho();

        void ValidarCombustible();

        void RecargarCombustible();
    };
}