/**
 * Project Untitled
 */


#pragma once
#include "Coordenadas.h"
#include "Desecho.h"


using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    public ref class Mapa {
    public:
        int Id;
        double Largo;
        double Ancho;
        String^ Imagen = "mapa.png";
        List<Coordenadas^>^ Posicion;
        List<Desecho^>^ Desechos;

        void CargarMapa();

        void GenerarArea();

        void GenerarDesechos();

        void MostrarMapa();

        void ObtenerCoordenada();
    };
}