#pragma once

using namespace System;
using namespace Model;
using namespace System::Collections::Generic;
using namespace SimuladorPersistance;

namespace SimuladorService {
	public enum class Protocol {
		UART,
		NMEA
	};
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
			static void AgregearEncargado(Encargado^);
			static void ActualizarEncargado(Encargado^);
			static void EliminarEncargado(int EncargadoId);
			static List<Encargado^>^ ConsultarEncargados();
			static Encargado^ ConsultarEncargadoPorId(int EncargadoId);
			static void RevertirCambiosEncargado(List<Encargado^>^ listaoriginal);

			//---------Camiones------------------
			static void AgregarCamion(Camion^);
			static void ActualizarCamion(Camion^);
			static void EliminarCamion(int CarmionId);
			static List<Camion^>^ ConsultarCamion();
			static Camion^ ConsultarCamionPorId(int CamionId);
			static void RevertirCambiosCamion(List<Camion^>^ listaoriginal);

			//----------Barco---------------------
			static void AgregarBarco(Barco^);
			static void ActualizarBarco(Barco^);
			static void EliminarBarco(int BarcoId);
			static List<Barco^>^ ConsultarBarcos();
			static Barco^ ConsultarBarcoPorId(int BarcoId);
			static void RevertirCambiosBarco(List<Barco^>^ listaoriginal);

			//----------Contenedores---------------
			static void AddContenedor(Contenedor^);
			static void UpdateContenedor(Contenedor^);
			static void DeleteContenedor(int ContenedorId);
			static List<Contenedor^>^ QueryAllContenedor();
			static Contenedor^ QueryContenedorById(int ContenedorId);
			static void RevertirCambiosContenedor(List<Contenedor^>^ listaoriginal);

			//---------Dron-----------------------
			static void AddDron(Dron^);
			static void UpdateDron(Dron^);
			static void DeleteDron(int DronId);
			static List<Dron^>^ QueryDron();
			static Dron^ QueryDronById(int DronId);
			static void RevertirCambiosDron(List<Dron^>^ listaoriginal);

			//Diccionario con los protocolos de comunicación UART y NMEA
			static Dictionary<String^, Protocol>^ protocolDictionary = gcnew Dictionary<String^, Protocol>();
			static Service() {
				// Agregar elementos al diccionario
				protocolDictionary->Add("UART", Protocol::UART);
				protocolDictionary->Add("NMEA", Protocol::NMEA);
			}

			//----------Sistema Automatizado---------------
			static String^ TiposDesechosSistema(Protocol protocol, int _cantPlastico, int _cantVidrio, int _cantCarton, int cantOtros);


	};
}
