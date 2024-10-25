/**
 * Project Untitled
 */


#pragma once
using namespace System;

namespace Model {
    [Serializable] public ref class Encargado {
    public:
        int Id;
        String^ Nombre;
        String^ Apellido;
        String^ Correo;
        int Edad;
        String^ Codigo;
        String^ Cargo;
        String^ Contacto;
        String^ Observaciones;
        array<Byte>^ Foto;

        void ObtenerDatosEncargado();

        void AgregarObservacion();
    };
}