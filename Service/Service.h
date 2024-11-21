#pragma once

using namespace System;
using namespace Model;
using namespace System::Collections::Generic;
using namespace SimuladorPersistance;

namespace SimuladorService {
	
	public ref class Service
	{
		public:

			static String^ BIN_ENCARGADO_FILE_NAME = "encargados.bin";
			static String^ BIN_CAMION_FILE_NAME = "camiones.bin";
			static String^ BIN_BARCO_FILE_NAME = "barcos.bin";
			static String^ BIN_CONTENEDOR_FILE_NAME = "contenedores.bin";
			static String^ BIN_COORDENADAS_FILE_NAME = "coordendas.bin";
			static String^ BIN_DRON_FILE_NAME = "dron.bin";

			static String^ TXT_DESECHOS_FILE_NAME = "desechos_encontrados.txt";

		private:
			static List<Encargado^>^ lista_encargados = gcnew List<Encargado^>();
			static List<Camion^>^ lista_camiones = gcnew List<Camion^>();
			static List<Dron^>^ dronList = gcnew List<Dron^>();
			static List<Barco^>^ barcoList = gcnew List<Barco^>();
			static List<Contenedor^>^ contenedorList = gcnew List<Contenedor^>();
			static List<Coordenadas^>^ coordendas_list = gcnew List<Coordenadas^>();

			static List<Desecho^>^ desechoList = gcnew List<Desecho^>();

		public:
			//Operaciones CRUD (Create, Request, Update, Delete) 

			//---------Encargados----------------
			static int AgregearEncargado(Encargado^);
			static int ActualizarEncargado(Encargado^);
			static int EliminarEncargado(int EncargadoId);
			static List<Encargado^>^ ConsultarEncargados();
			static Encargado^ ConsultarEncargadoPorId(int EncargadoId);

			//---------Camiones------------------
			static int AgregarCamion(Camion^);
			static int ActualizarCamion(Camion^);
			static int EliminarCamion(int CarmionId);
			static List<Camion^>^ ConsultarCamion();
			static Camion^ ConsultarCamionPorId(int CamionId);
			
			//----------Barco---------------------
			static int AgregarBarco(Barco^);
			static int ActualizarBarco(Barco^);
			static int EliminarBarco(int BarcoId);
			static List<Barco^>^ ConsultarBarcos();
			static Barco^ ConsultarBarcoPorId(int BarcoId);

			//----------Contenedores---------------
			static void AddContenedor(Contenedor^);
			static void UpdateContenedor(Contenedor^);
			static void DeleteContenedor(int ContenedorId);
			static List<Contenedor^>^ QueryAllContenedor();
			static Contenedor^ QueryContenedorById(int ContenedorId);

			//---------Dron-----------------------
			static int AddDron(Dron^);
			static int UpdateDron(Dron^);
			static int DeleteDron(int DronId);
			static List<Dron^>^ QueryDron();
			static Dron^ QueryDronById(int DronId);

	};
}
