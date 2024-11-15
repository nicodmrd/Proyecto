#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace Model;
using namespace System::Data::SqlClient;

namespace SimuladorPersistance {
	public ref class Persistance
	{
	private:
		static SqlConnection^ GetConnection();
	public:

		static void PersistBinaryFile(String^ fileName, Object^ persistObject);
		static Object^ LoadBinaryFile(String^ fileName);

		static void PersistDesechosTextFile(String^ fileName, Object^ persistObject);
		static Object^ LoadDesechosTextFile(String^ fileName);

		
		//CRUDS con base de datos - sql 
		//ENCARGADOS
		static int AgregarEncargado(Encargado^ encargado);
		static List<Encargado^>^ ConsultarEncargados();
		static int ActualizarEncargado(Encargado^ encargado);
		static int EliminarEncargado(int encargadoId);
		static Encargado^ ConsultarEncargadoPorId(int encargadoId);

		//BARCOS
		static int AgregarBarco(Barco^ barco);
		static List<Barco^>^ ConsultarBarcos();
		static int ActualizarBarco(Barco^ barco);
		static int EliminarBarco(int barcoId);
		static Barco^ ConsultarBarcoPorId(int barcoId);
		
		//CAMIONES
		static int AgregarCamion(Camion^ camion);
		static List<Camion^>^ ConsultarCamiones();
		static int ActualizarCamion(Camion^ camion);
		static int EliminarCamion(int camionId);
		static Camion^ ConsultarCamionPorId(int camionId);

		//DRONES
		static int AgregarDron(Dron^ dron);
		static List<Dron^>^ ConsultarDron();
		static int ActualizarDron(Dron^ dron);
		static int EliminarDron(int dronId);
		static Dron^ ConsultarDronPorId(int dronId);
		
	};
}
