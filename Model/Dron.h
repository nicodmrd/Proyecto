/**
 * Project Untitled
 */

#pragma once
#include "Coordenadas.h"
#include "Area.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    [Serializable] public ref class Dron {
    public:
        int Id;
        double Velocidad;
        int Bateria; 
        double Alcance; 
        Coordenadas^ Posicion;

        void ActivarSistema();
        void VerificarBateria();
        void RecargarBateria();
        void DefinirAreaEscaneo();
        void Escanear();
       
    };
}