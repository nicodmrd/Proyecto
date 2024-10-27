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

        Encargado() {

        }

        Encargado(int id, String^ nombre, String^ apellido, String^ cargo) {
            this->Id = id; // Asignación correcta
            this->Nombre = nombre;
            this->Apellido = apellido;
            this->Cargo = cargo;
        }

        String^ ToString() override {
            return Id + " - " + Nombre + " " + Apellido; // Formato para mostrar en el ComboBox
        }

        void ObtenerDatosEncargado();

        void AgregarObservacion();
    };
}
