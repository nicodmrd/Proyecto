/**
 * Project Untitled
 */


#pragma once
#include "Encargado.h"
#include "Area.h"
#include "Mapa.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    public ref class Simulador {
    public:
        String^ Estado;
        List<Encargado^>^ Encargados;
        List<Area^>^ Area;
        Mapa^ Mapa;

        void IniciarSimulador();

        void DelimitarArea();

        void RealizarEscaneo();

        void RealizarRecoleccion();

        void RealizarRecogida();

        void GestionarResiduos();

        void MostrarResumen();
    };
}