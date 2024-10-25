/**
 * Project Untitled
 */


#pragma once
#include "Coordenadas.h"
#include "Contenedor.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    [Serializable] public ref class Camion {
    public:
        int Id;
        int CapacidadContenedores;
        double Velocidad;
        String^ Placa;
        double NivelCombustible;
        Coordenadas^ Posicion;
        List<Contenedor^>^ Contenedores;

        void CargarContenedor();

        void TransportarAlAcopio();

        void ValidarCombustible();

        void RecargarCombustible();
    };
}