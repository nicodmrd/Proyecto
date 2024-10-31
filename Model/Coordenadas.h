/**
 * Project Untitled
 */


#pragma once
using namespace System;

namespace Model {
    [Serializable] public ref class Coordenadas {
    public:
        double X;
        double Y;

        Coordenadas(double x,double y) {
            X = x;
            Y = y;
        }
        String^ ToString() override {
            return "{ lat: " + X.ToString() + ", lng: " + Y.ToString() + " }";
        }
    };
}