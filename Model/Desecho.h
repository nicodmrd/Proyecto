/**
 * Project Untitled
 */


#pragma once
#include "Coordenadas.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Model {
    public ref class Desecho {
    public:
        //int Id;
        double Peso;
        String^ Tipo;
        Coordenadas^ Posicion;
        Desecho() {

        }
        // Constructor
        Desecho(double peso, String^ tipo, int x, int y) {
            //Id = id;
            Peso = peso;
            Tipo = tipo;
            Posicion = gcnew Coordenadas(x,y);
            //Posicion->Add(gcnew Coordenadas(x, y)); // Agregar coordenada al crear el desecho
        }
    };
}