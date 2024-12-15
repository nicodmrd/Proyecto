#pragma once

#include "EncargadosForm.h"
#include "EmployeesReportForm.h"
#include "GarbageReportForm.h"
#include "DronForm.h"
#include "CamionesForm.h"
#include "BarcoForm.h"
#include "ContenedorForm.h"
#include "ComboBoxItem.h"

#include <vector>
#include <algorithm>
#include <string>

namespace GUIApp {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;
	using namespace System::Collections::Generic;
	using namespace SimuladorService;
	using namespace System::Threading;
	using namespace System::IO::Ports;
	using namespace System::Globalization;
	//LIBRERIAS DE LA CAMARA
	using namespace AForge::Video;
	using namespace AForge::Video::DirectShow;

	/// <summary>
	/// Resumen de MyWindowMain
	/// </summary>
	public ref class MyWindowMain : public System::Windows::Forms::Form
	{
	// DE LA CÁMARA
	private:
		// Declaración del campo estático sin inicialización
		static MyWindowMain^ instance = nullptr;

		bool HayDispositivos;
		FilterInfoCollection^ MisDispositivos;
		VideoCaptureDevice^ MiWebCam;

		static SerialPort^ ArduinoPort;
		// Definición del delegado
		static Thread^ readThread;
		delegate void UpdateGridDelegate(int, int, int, int);





	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ empleadosPorAreaToolStripMenuItem;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::ComboBox^ cbCamara;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ videoCamara;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ detener_proceso;
	private: System::Windows::Forms::Button^ iniciar_proceso;
	public: System::Windows::Forms::DataGridView^ desechogrid;
	private:

	public:



	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lblCronometro;
	private: System::Windows::Forms::Button^ btnPruebas2;
	private: System::Windows::Forms::Button^ btnPruebas;
	private: Microsoft::Web::WebView2::WinForms::WebView2^ MapaWeb;
	private: System::Windows::Forms::DataGridView^ dgvCamionesAsignados;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCamion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MatriculaCamion;
	private: System::Windows::Forms::DataGridView^ dgvBarcosAsignados;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdBarco;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CapacidadCoord;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ txtCantContenedores;
	private: System::Windows::Forms::TextBox^ txtCamionCombustible;
	private: System::Windows::Forms::TextBox^ txtBarcoCombustible;
	private: System::Windows::Forms::TextBox^ txtDronBateria;
	private: System::Windows::Forms::TextBox^ txtAreaLargo;
	private: System::Windows::Forms::TextBox^ txtAreaAncho;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ cmbIdCamion;
	private: System::Windows::Forms::Button^ btnValidarCamion;
	private: System::Windows::Forms::Button^ btnRecargarCmbCamion;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ cmbIdBarco;
	private: System::Windows::Forms::Button^ btnValidarBarco;
	private: System::Windows::Forms::Button^ btnRecargarCmbBarco;
	private: System::Windows::Forms::Button^ btnRecargarBateria;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dgvCoordenadas;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdDesecho;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCoordX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CoordY;
	private: System::Windows::Forms::ComboBox^ cmbIdDron;
	private: System::Windows::Forms::Button^ btnValidarDron;
	private: System::Windows::Forms::Button^ btnAumentarContenedor;
	private: System::Windows::Forms::Button^ btnAsignarBarcos;
	private: System::Windows::Forms::Button^ btnAsignarCamion;
	private: System::Windows::Forms::Button^ btnAsignarDron;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cmb4Encargado;
	private: System::Windows::Forms::ComboBox^ cmb3Encargado;
	private: System::Windows::Forms::ComboBox^ cmb2Encargado;
	private: System::Windows::Forms::ComboBox^ cmb1Encargado;
	private: System::Windows::Forms::Button^ btnCursor;
	private: System::Windows::Forms::Button^ btnAreaAnalisis;
	private: System::Windows::Forms::Button^ btnReiniciar;
	private: System::Windows::Forms::Button^ btnDetener;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::ToolStripMenuItem^ deschosRecicladosToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ cb_arduino;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ plasticobox;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ cartonbox;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ vidriobox;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ otrosbox;



























	private: int camaraActual = -1;
	
	public:
		MyWindowMain(void)
		{
			InitializeComponent();
			ResetGrid();
			LoadImage();
			

			// Cargar puertos COM disponibles en cb_arduino
			LoadAvailablePorts();
			

			//Inicialización del WebView2
			this->MapaWeb->Source = gcnew System::Uri("file:///ruta/a/tu/HTMLPage.html");

			// Vincular el evento Click del botón btnPruebas
			this->btnPruebas->Click += gcnew System::EventHandler(this, &MyWindowMain::btnPruebas_Click);


			// DE LA CÁMARA 
			
			// Inicialización del ComboBox y dispositivos de cámara
			HayDispositivos = false;
			MisDispositivos = gcnew FilterInfoCollection(FilterCategory::VideoInputDevice);
			if (MisDispositivos->Count > 0) {
				HayDispositivos = true;
				for (int i = 0; i < MisDispositivos->Count; i++) {
					cbCamara->Items->Add(MisDispositivos[i]->Name);  // Añadir dispositivos al ComboBox
				}
				cbCamara->SelectedIndex = 0; // Seleccionar la primera cámara por defecto
				CambiarCamara(0); // Inicia con la primera cámara
			}

			// Vincula el evento al ComboBox para el cambio de selección
			cbCamara->SelectedIndexChanged += gcnew EventHandler(this, &MyWindowMain::cbCamara_SelectedIndexChanged);
			

			//
			//TODO: agregar código de constructor aquí
			//
			toolTip1 = gcnew ToolTip();
			toolTip2 = gcnew ToolTip();
			toolTip3 = gcnew ToolTip();
			toolTip4 = gcnew ToolTip();
			toolTip5 = gcnew ToolTip();
			toolTip6 = gcnew ToolTip();
			toolTip7 = gcnew ToolTip();
			toolTip8 = gcnew ToolTip();
			toolTip9 = gcnew ToolTip();
			toolTip10 = gcnew ToolTip();
			toolTip11 = gcnew ToolTip();
			toolTip12 = gcnew ToolTip();
			toolTip13 = gcnew ToolTip();
			toolTip14 = gcnew ToolTip();
			toolTip15 = gcnew ToolTip();
			
			toolTip1->SetToolTip(btnAreaAnalisis, L"Realizar área de an\u00E1lisis");
			toolTip2->SetToolTip(btnReiniciar, "Reiniciar simulaci\u00F3n");
			toolTip3->SetToolTip(btnDetener, L"Detener simulaci\u00F3n");
			toolTip4->SetToolTip(btnIniciar, L"Iniciar simulaci\u00F3n");
			toolTip5->SetToolTip(btnCursor, "Cursor");

			toolTip6->SetToolTip(btnValidarDron, "Validar batería del dron");
			toolTip7->SetToolTip(btnValidarBarco, "Validar combustible del barco");
			toolTip8->SetToolTip(btnValidarCamion, "Validar combustible del camión");
			toolTip9->SetToolTip(btnRecargarBateria, "Recargar batería del dron");
			toolTip10->SetToolTip(btnRecargarCmbBarco, "Suministrar combustible al barco");
			toolTip11->SetToolTip(btnRecargarCmbCamion, "Suministrar combustible al camión");
			toolTip12->SetToolTip(btnAsignarDron, "Asignar dron");
			toolTip13->SetToolTip(btnAsignarBarcos, "Asignar barco");
			toolTip14->SetToolTip(btnAsignarCamion, "Asignar camión");
			toolTip15->SetToolTip(btnAumentarContenedor, "Agregar un contenedor");
		}


	private: void InitializeDataGrid()
	{
		// Definir el número de filas
		this->desechogrid->Rows->Add("0"); // Plástico (ROJO)
		this->desechogrid->Rows->Add("0"); // Cartón (VERDE)
		this->desechogrid->Rows->Add("0"); // Vidrio (AZUL)
		this->desechogrid->Rows->Add("0"); // Otros (BLANCO)

		// Configurar las celdas como numéricas
		for (int i = 0; i < this->desechogrid->Rows->Count; i++) {
			this->desechogrid->Rows[i]->Cells[0]->Value = "0"; // Inicializar valores en cero
			this->desechogrid->Rows[i]->Cells[1]->Value = "0";
			this->desechogrid->Rows[i]->Cells[2]->Value = "0";
			this->desechogrid->Rows[i]->Cells[3]->Value = "0";
		}
	}



	private: void LoadAvailablePorts() {
		array<String^>^ ports = SerialPort::GetPortNames();
		cb_arduino->Items->Clear();
		for each (String ^ port in ports) {
			cb_arduino->Items->Add(port);
		}
		if (cb_arduino->Items->Count > 0) {
			cb_arduino->SelectedIndex = 0; // Seleccionar el primer puerto por defecto
		}
	}

	protected:

		//DE LA CÁMARA
		
		// Método para manejar la captura de nuevas imágenes de la cámara
		void CapturaNueva(Object^ sender, NewFrameEventArgs^ eventArgs) {
			Bitmap^ imagenOriginal = gcnew Bitmap(eventArgs->Frame);
			Bitmap^ imagenRedimensionada = gcnew Bitmap(imagenOriginal, videoCamara->Size); // Redimensiona la imagen al tamaño del PictureBox

			// Libera la imagen anterior para evitar problemas de memoria
			if (videoCamara->Image != nullptr) {
				delete videoCamara->Image;
			}

			// Asigna la imagen redimensionada al PictureBox
			videoCamara->Image = imagenRedimensionada;
		}


		// Evento del cambio de selección en el ComboBox
		void cbCamara_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
			int selectedIndex = cbCamara->SelectedIndex;
			if (selectedIndex >= 0) {
				CambiarCamara(selectedIndex);
			}
		}

		// Método para cambiar la cámara según el índice seleccionado
		void CambiarCamara(int index) {
			// Verificar si la cámara seleccionada es la misma que la actual
			if (index == camaraActual) {
				return; // Salir si la cámara seleccionada es la misma
			}

			// Detiene la cámara actual si está en ejecución
			if (MiWebCam != nullptr && MiWebCam->IsRunning) {
				MiWebCam->SignalToStop();
				MiWebCam->WaitForStop();
			}

			// Cambia a la nueva cámara seleccionada
			MiWebCam = gcnew VideoCaptureDevice(MisDispositivos[index]->MonikerString);
			MiWebCam->NewFrame += gcnew NewFrameEventHandler(this, &MyWindowMain::CapturaNueva);
			MiWebCam->Start();

			// Actualiza el índice de la cámara activa actual
			camaraActual = index;
		}

		// Sobrescribe el evento de cierre de formulario
		virtual void OnFormClosing(FormClosingEventArgs^ e) override {
			if (MiWebCam != nullptr && MiWebCam->IsRunning) {
				MiWebCam->SignalToStop();  // Detiene la cámara
				MiWebCam->WaitForStop();   // Espera hasta que se detenga completamente
			}
			Form::OnFormClosing(e); // Llama al método base para continuar con el cierre
		}

		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyWindowMain()
		{
			if (components)
			{
				delete components;
			}

			// DE LA CÁMARA
			// Detener la cámara también en el destructor
			if (MiWebCam != nullptr && MiWebCam->IsRunning) {
				MiWebCam->SignalToStop();
				MiWebCam->WaitForStop();
			}
			ClosePort();
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ archivoToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ guíaDelSoftwareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ acercaDeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ integrantesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ informaciónDelProyectoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ encargadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ barcosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dronToolStripMenuItem;


	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::ToolStripMenuItem^ contenedoresToolStripMenuItem;

	private:

	public:



	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::ToolTip^ toolTip4;

private: System::Windows::Forms::ToolTip^ toolTip5;
private: System::Windows::Forms::ToolTip^ toolTip6;
private: System::Windows::Forms::ToolTip^ toolTip7;
private: System::Windows::Forms::ToolTip^ toolTip8;
private: System::Windows::Forms::ToolTip^ toolTip9;
private: System::Windows::Forms::ToolTip^ toolTip10;
private: System::Windows::Forms::ToolTip^ toolTip11;
private: System::Windows::Forms::ToolTip^ toolTip12;
private: System::Windows::Forms::ToolTip^ toolTip13;
private: System::Windows::Forms::ToolTip^ toolTip14;
private: System::Windows::Forms::ToolTip^ toolTip15;




	private: System::Windows::Forms::ToolStripMenuItem^ camionesToolStripMenuItem;

		   void LoadImage()
		   {
			   Mapa^ mapa = gcnew Mapa();

		   }
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyWindowMain::typeid));
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->encargadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->barcosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->camionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contenedoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guíaDelSoftwareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->integrantesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informaciónDelProyectoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->empleadosPorAreaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deschosRecicladosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip6 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip7 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip8 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip9 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip10 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip11 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip12 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip13 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip14 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip15 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->cb_arduino = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cbCamara = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->videoCamara = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->detener_proceso = (gcnew System::Windows::Forms::Button());
			this->iniciar_proceso = (gcnew System::Windows::Forms::Button());
			this->desechogrid = (gcnew System::Windows::Forms::DataGridView());
			this->plasticobox = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cartonbox = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vidriobox = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->otrosbox = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblCronometro = (gcnew System::Windows::Forms::Label());
			this->btnPruebas2 = (gcnew System::Windows::Forms::Button());
			this->btnPruebas = (gcnew System::Windows::Forms::Button());
			this->MapaWeb = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
			this->dgvCamionesAsignados = (gcnew System::Windows::Forms::DataGridView());
			this->IdCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MatriculaCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvBarcosAsignados = (gcnew System::Windows::Forms::DataGridView());
			this->IdBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CapacidadCoord = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtCantContenedores = (gcnew System::Windows::Forms::TextBox());
			this->txtCamionCombustible = (gcnew System::Windows::Forms::TextBox());
			this->txtBarcoCombustible = (gcnew System::Windows::Forms::TextBox());
			this->txtDronBateria = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaLargo = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaAncho = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->cmbIdCamion = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarCamion = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbCamion = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cmbIdBarco = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarBateria = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dgvCoordenadas = (gcnew System::Windows::Forms::DataGridView());
			this->IdDesecho = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IdCoordX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CoordY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cmbIdDron = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarDron = (gcnew System::Windows::Forms::Button());
			this->btnAumentarContenedor = (gcnew System::Windows::Forms::Button());
			this->btnAsignarBarcos = (gcnew System::Windows::Forms::Button());
			this->btnAsignarCamion = (gcnew System::Windows::Forms::Button());
			this->btnAsignarDron = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cmb4Encargado = (gcnew System::Windows::Forms::ComboBox());
			this->cmb3Encargado = (gcnew System::Windows::Forms::ComboBox());
			this->cmb2Encargado = (gcnew System::Windows::Forms::ComboBox());
			this->cmb1Encargado = (gcnew System::Windows::Forms::ComboBox());
			this->btnCursor = (gcnew System::Windows::Forms::Button());
			this->btnAreaAnalisis = (gcnew System::Windows::Forms::Button());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->btnDetener = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoCamara))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->desechogrid))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MapaWeb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamionesAsignados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcosAsignados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCoordenadas))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->archivoToolStripMenuItem,
					this->mantenimientoToolStripMenuItem, this->ayudaToolStripMenuItem, this->acercaDeToolStripMenuItem, this->reportesToolStripMenuItem
			});
			resources->ApplyResources(this->menuStrip2, L"menuStrip2");
			this->menuStrip2->Name = L"menuStrip2";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->salirToolStripMenuItem });
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			resources->ApplyResources(this->archivoToolStripMenuItem, L"archivoToolStripMenuItem");
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			resources->ApplyResources(this->salirToolStripMenuItem, L"salirToolStripMenuItem");
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::salirToolStripMenuItem_Click);
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->encargadosToolStripMenuItem,
					this->barcosToolStripMenuItem, this->dronToolStripMenuItem, this->camionesToolStripMenuItem, this->contenedoresToolStripMenuItem
			});
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			resources->ApplyResources(this->mantenimientoToolStripMenuItem, L"mantenimientoToolStripMenuItem");
			// 
			// encargadosToolStripMenuItem
			// 
			this->encargadosToolStripMenuItem->Name = L"encargadosToolStripMenuItem";
			resources->ApplyResources(this->encargadosToolStripMenuItem, L"encargadosToolStripMenuItem");
			this->encargadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::encargadosToolStripMenuItem_Click);
			// 
			// barcosToolStripMenuItem
			// 
			this->barcosToolStripMenuItem->Name = L"barcosToolStripMenuItem";
			resources->ApplyResources(this->barcosToolStripMenuItem, L"barcosToolStripMenuItem");
			this->barcosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::barcosToolStripMenuItem_Click);
			// 
			// dronToolStripMenuItem
			// 
			this->dronToolStripMenuItem->Name = L"dronToolStripMenuItem";
			resources->ApplyResources(this->dronToolStripMenuItem, L"dronToolStripMenuItem");
			this->dronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::dronToolStripMenuItem_Click);
			// 
			// camionesToolStripMenuItem
			// 
			this->camionesToolStripMenuItem->Name = L"camionesToolStripMenuItem";
			resources->ApplyResources(this->camionesToolStripMenuItem, L"camionesToolStripMenuItem");
			this->camionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::camionesToolStripMenuItem_Click);
			// 
			// contenedoresToolStripMenuItem
			// 
			this->contenedoresToolStripMenuItem->Name = L"contenedoresToolStripMenuItem";
			resources->ApplyResources(this->contenedoresToolStripMenuItem, L"contenedoresToolStripMenuItem");
			this->contenedoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::contenedoresToolStripMenuItem_Click);
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->guíaDelSoftwareToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			resources->ApplyResources(this->ayudaToolStripMenuItem, L"ayudaToolStripMenuItem");
			// 
			// guíaDelSoftwareToolStripMenuItem
			// 
			this->guíaDelSoftwareToolStripMenuItem->Name = L"guíaDelSoftwareToolStripMenuItem";
			resources->ApplyResources(this->guíaDelSoftwareToolStripMenuItem, L"guíaDelSoftwareToolStripMenuItem");
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->integrantesToolStripMenuItem,
					this->informaciónDelProyectoToolStripMenuItem
			});
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			resources->ApplyResources(this->acercaDeToolStripMenuItem, L"acercaDeToolStripMenuItem");
			// 
			// integrantesToolStripMenuItem
			// 
			this->integrantesToolStripMenuItem->Name = L"integrantesToolStripMenuItem";
			resources->ApplyResources(this->integrantesToolStripMenuItem, L"integrantesToolStripMenuItem");
			// 
			// informaciónDelProyectoToolStripMenuItem
			// 
			this->informaciónDelProyectoToolStripMenuItem->Name = L"informaciónDelProyectoToolStripMenuItem";
			resources->ApplyResources(this->informaciónDelProyectoToolStripMenuItem, L"informaciónDelProyectoToolStripMenuItem");
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->empleadosPorAreaToolStripMenuItem,
					this->deschosRecicladosToolStripMenuItem
			});
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			resources->ApplyResources(this->reportesToolStripMenuItem, L"reportesToolStripMenuItem");
			// 
			// empleadosPorAreaToolStripMenuItem
			// 
			this->empleadosPorAreaToolStripMenuItem->Name = L"empleadosPorAreaToolStripMenuItem";
			resources->ApplyResources(this->empleadosPorAreaToolStripMenuItem, L"empleadosPorAreaToolStripMenuItem");
			this->empleadosPorAreaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::empleadosPorAreaToolStripMenuItem_Click);
			// 
			// deschosRecicladosToolStripMenuItem
			// 
			this->deschosRecicladosToolStripMenuItem->Name = L"deschosRecicladosToolStripMenuItem";
			resources->ApplyResources(this->deschosRecicladosToolStripMenuItem, L"deschosRecicladosToolStripMenuItem");
			this->deschosRecicladosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::deschosRecicladosToolStripMenuItem_Click);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyWindowMain::timer1_Tick);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->cb_arduino);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->cbCamara);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->videoCamara);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->detener_proceso);
			this->tabPage2->Controls->Add(this->iniciar_proceso);
			this->tabPage2->Controls->Add(this->desechogrid);
			resources->ApplyResources(this->tabPage2, L"tabPage2");
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyWindowMain::button2_Click);
			// 
			// cb_arduino
			// 
			this->cb_arduino->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_arduino->FormattingEnabled = true;
			resources->ApplyResources(this->cb_arduino, L"cb_arduino");
			this->cb_arduino->Name = L"cb_arduino";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// cbCamara
			// 
			this->cbCamara->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbCamara->FormattingEnabled = true;
			resources->ApplyResources(this->cbCamara, L"cbCamara");
			this->cbCamara->Name = L"cbCamara";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// videoCamara
			// 
			resources->ApplyResources(this->videoCamara, L"videoCamara");
			this->videoCamara->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->videoCamara->Name = L"videoCamara";
			this->videoCamara->TabStop = false;
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// detener_proceso
			// 
			resources->ApplyResources(this->detener_proceso, L"detener_proceso");
			this->detener_proceso->Name = L"detener_proceso";
			this->detener_proceso->UseVisualStyleBackColor = true;
			this->detener_proceso->Click += gcnew System::EventHandler(this, &MyWindowMain::detener_proceso_Click);
			// 
			// iniciar_proceso
			// 
			resources->ApplyResources(this->iniciar_proceso, L"iniciar_proceso");
			this->iniciar_proceso->Name = L"iniciar_proceso";
			this->iniciar_proceso->UseVisualStyleBackColor = true;
			this->iniciar_proceso->Click += gcnew System::EventHandler(this, &MyWindowMain::iniciar_proceso_Click);
			// 
			// desechogrid
			// 
			this->desechogrid->AllowUserToAddRows = false;
			this->desechogrid->AllowUserToDeleteRows = false;
			this->desechogrid->AllowUserToResizeColumns = false;
			this->desechogrid->AllowUserToResizeRows = false;
			this->desechogrid->ReadOnly = false; // Asegúrate de que el DataGridView no sea de solo lectura
			resources->ApplyResources(this->desechogrid, L"desechogrid");
			this->desechogrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->desechogrid->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->desechogrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->desechogrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->plasticobox,
					this->cartonbox, this->vidriobox, this->otrosbox
			});
			this->desechogrid->Name = L"desechogrid";
			this->desechogrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->desechogrid->RowHeadersVisible = false;
			this->desechogrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->desechogrid->RowTemplate->DividerHeight = 10;
			this->desechogrid->RowTemplate->Height = 90;
			this->desechogrid->RowTemplate->ReadOnly = false;
			this->desechogrid->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->desechogrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyWindowMain::desechogrid_CellContentClick);
			// Centralizar el texto en las celdas y en la fila de encabezado
			System::Windows::Forms::DataGridViewCellStyle^ cellStyle = gcnew System::Windows::Forms::DataGridViewCellStyle();
			cellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->desechogrid->ColumnHeadersDefaultCellStyle = cellStyle;
			this->desechogrid->DefaultCellStyle = cellStyle;

			// 
			// plasticobox
			// 
			resources->ApplyResources(this->plasticobox, L"plasticobox");
			this->plasticobox->Name = L"plasticobox";
			this->plasticobox->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->plasticobox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cartonbox
			// 
			resources->ApplyResources(this->cartonbox, L"cartonbox");
			this->cartonbox->Name = L"cartonbox";
			this->cartonbox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// vidriobox
			// 
			resources->ApplyResources(this->vidriobox, L"vidriobox");
			this->vidriobox->Name = L"vidriobox";
			this->vidriobox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// otrosbox
			// 
			resources->ApplyResources(this->otrosbox, L"otrosbox");
			this->otrosbox->Name = L"otrosbox";
			this->otrosbox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->lblCronometro);
			this->tabPage1->Controls->Add(this->btnPruebas2);
			this->tabPage1->Controls->Add(this->btnPruebas);
			this->tabPage1->Controls->Add(this->MapaWeb);
			this->tabPage1->Controls->Add(this->dgvCamionesAsignados);
			this->tabPage1->Controls->Add(this->dgvBarcosAsignados);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->txtCantContenedores);
			this->tabPage1->Controls->Add(this->txtCamionCombustible);
			this->tabPage1->Controls->Add(this->txtBarcoCombustible);
			this->tabPage1->Controls->Add(this->txtDronBateria);
			this->tabPage1->Controls->Add(this->txtAreaLargo);
			this->tabPage1->Controls->Add(this->txtAreaAncho);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->cmbIdCamion);
			this->tabPage1->Controls->Add(this->btnValidarCamion);
			this->tabPage1->Controls->Add(this->btnRecargarCmbCamion);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->cmbIdBarco);
			this->tabPage1->Controls->Add(this->btnValidarBarco);
			this->tabPage1->Controls->Add(this->btnRecargarCmbBarco);
			this->tabPage1->Controls->Add(this->btnRecargarBateria);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->dgvCoordenadas);
			this->tabPage1->Controls->Add(this->cmbIdDron);
			this->tabPage1->Controls->Add(this->btnValidarDron);
			this->tabPage1->Controls->Add(this->btnAumentarContenedor);
			this->tabPage1->Controls->Add(this->btnAsignarBarcos);
			this->tabPage1->Controls->Add(this->btnAsignarCamion);
			this->tabPage1->Controls->Add(this->btnAsignarDron);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->cmb4Encargado);
			this->tabPage1->Controls->Add(this->cmb3Encargado);
			this->tabPage1->Controls->Add(this->cmb2Encargado);
			this->tabPage1->Controls->Add(this->cmb1Encargado);
			this->tabPage1->Controls->Add(this->btnCursor);
			this->tabPage1->Controls->Add(this->btnAreaAnalisis);
			this->tabPage1->Controls->Add(this->btnReiniciar);
			this->tabPage1->Controls->Add(this->btnDetener);
			this->tabPage1->Controls->Add(this->btnIniciar);
			resources->ApplyResources(this->tabPage1, L"tabPage1");
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage1->Name = L"tabPage1";
			// 
			// label20
			// 
			resources->ApplyResources(this->label20, L"label20");
			this->label20->Name = L"label20";
			// 
			// label18
			// 
			resources->ApplyResources(this->label18, L"label18");
			this->label18->Name = L"label18";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// label19
			// 
			resources->ApplyResources(this->label19, L"label19");
			this->label19->Name = L"label19";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// lblCronometro
			// 
			resources->ApplyResources(this->lblCronometro, L"lblCronometro");
			this->lblCronometro->Name = L"lblCronometro";
			// 
			// btnPruebas2
			// 
			resources->ApplyResources(this->btnPruebas2, L"btnPruebas2");
			this->btnPruebas2->Name = L"btnPruebas2";
			this->btnPruebas2->UseVisualStyleBackColor = true;
			this->btnPruebas2->Click += gcnew System::EventHandler(this, &MyWindowMain::btnPruebas2_Click);
			// 
			// btnPruebas
			// 
			resources->ApplyResources(this->btnPruebas, L"btnPruebas");
			this->btnPruebas->Name = L"btnPruebas";
			this->btnPruebas->UseVisualStyleBackColor = true;
			this->btnPruebas->Click += gcnew System::EventHandler(this, &MyWindowMain::btnPruebas_Click);
			// 
			// MapaWeb
			// 
			this->MapaWeb->AllowExternalDrop = true;
			this->MapaWeb->CreationProperties = nullptr;
			this->MapaWeb->DefaultBackgroundColor = System::Drawing::Color::White;
			resources->ApplyResources(this->MapaWeb, L"MapaWeb");
			this->MapaWeb->Name = L"MapaWeb";
			this->MapaWeb->ZoomFactor = 1;
			// 
			// dgvCamionesAsignados
			// 
			this->dgvCamionesAsignados->AllowUserToAddRows = false;
			this->dgvCamionesAsignados->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCamionesAsignados->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdCamion,
					this->MatriculaCamion
			});
			resources->ApplyResources(this->dgvCamionesAsignados, L"dgvCamionesAsignados");
			this->dgvCamionesAsignados->Name = L"dgvCamionesAsignados";
			this->dgvCamionesAsignados->RowHeadersVisible = false;
			this->dgvCamionesAsignados->RowTemplate->Height = 24;
			// 
			// IdCamion
			// 
			resources->ApplyResources(this->IdCamion, L"IdCamion");
			this->IdCamion->Name = L"IdCamion";
			// 
			// MatriculaCamion
			// 
			resources->ApplyResources(this->MatriculaCamion, L"MatriculaCamion");
			this->MatriculaCamion->Name = L"MatriculaCamion";
			// 
			// dgvBarcosAsignados
			// 
			this->dgvBarcosAsignados->AllowUserToAddRows = false;
			this->dgvBarcosAsignados->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBarcosAsignados->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdBarco,
					this->CapacidadCoord
			});
			resources->ApplyResources(this->dgvBarcosAsignados, L"dgvBarcosAsignados");
			this->dgvBarcosAsignados->Name = L"dgvBarcosAsignados";
			this->dgvBarcosAsignados->RowHeadersVisible = false;
			this->dgvBarcosAsignados->RowTemplate->Height = 24;
			// 
			// IdBarco
			// 
			resources->ApplyResources(this->IdBarco, L"IdBarco");
			this->IdBarco->Name = L"IdBarco";
			// 
			// CapacidadCoord
			// 
			resources->ApplyResources(this->CapacidadCoord, L"CapacidadCoord");
			this->CapacidadCoord->Name = L"CapacidadCoord";
			// 
			// label17
			// 
			resources->ApplyResources(this->label17, L"label17");
			this->label17->Name = L"label17";
			// 
			// txtCantContenedores
			// 
			resources->ApplyResources(this->txtCantContenedores, L"txtCantContenedores");
			this->txtCantContenedores->Name = L"txtCantContenedores";
			this->txtCantContenedores->ReadOnly = true;
			// 
			// txtCamionCombustible
			// 
			resources->ApplyResources(this->txtCamionCombustible, L"txtCamionCombustible");
			this->txtCamionCombustible->Name = L"txtCamionCombustible";
			this->txtCamionCombustible->ReadOnly = true;
			// 
			// txtBarcoCombustible
			// 
			resources->ApplyResources(this->txtBarcoCombustible, L"txtBarcoCombustible");
			this->txtBarcoCombustible->Name = L"txtBarcoCombustible";
			this->txtBarcoCombustible->ReadOnly = true;
			// 
			// txtDronBateria
			// 
			resources->ApplyResources(this->txtDronBateria, L"txtDronBateria");
			this->txtDronBateria->Name = L"txtDronBateria";
			this->txtDronBateria->ReadOnly = true;
			// 
			// txtAreaLargo
			// 
			resources->ApplyResources(this->txtAreaLargo, L"txtAreaLargo");
			this->txtAreaLargo->Name = L"txtAreaLargo";
			this->txtAreaLargo->ReadOnly = true;
			// 
			// txtAreaAncho
			// 
			resources->ApplyResources(this->txtAreaAncho, L"txtAreaAncho");
			this->txtAreaAncho->Name = L"txtAreaAncho";
			this->txtAreaAncho->ReadOnly = true;
			// 
			// label16
			// 
			resources->ApplyResources(this->label16, L"label16");
			this->label16->Name = L"label16";
			// 
			// label15
			// 
			resources->ApplyResources(this->label15, L"label15");
			this->label15->Name = L"label15";
			// 
			// label14
			// 
			resources->ApplyResources(this->label14, L"label14");
			this->label14->Name = L"label14";
			// 
			// cmbIdCamion
			// 
			this->cmbIdCamion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdCamion->FormattingEnabled = true;
			resources->ApplyResources(this->cmbIdCamion, L"cmbIdCamion");
			this->cmbIdCamion->Name = L"cmbIdCamion";
			// 
			// btnValidarCamion
			// 
			resources->ApplyResources(this->btnValidarCamion, L"btnValidarCamion");
			this->btnValidarCamion->Name = L"btnValidarCamion";
			this->btnValidarCamion->UseVisualStyleBackColor = true;
			this->btnValidarCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarCamion_Click);
			// 
			// btnRecargarCmbCamion
			// 
			resources->ApplyResources(this->btnRecargarCmbCamion, L"btnRecargarCmbCamion");
			this->btnRecargarCmbCamion->Name = L"btnRecargarCmbCamion";
			this->btnRecargarCmbCamion->UseVisualStyleBackColor = true;
			this->btnRecargarCmbCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarCmbCamion_Click);
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// cmbIdBarco
			// 
			this->cmbIdBarco->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdBarco->FormattingEnabled = true;
			resources->ApplyResources(this->cmbIdBarco, L"cmbIdBarco");
			this->cmbIdBarco->Name = L"cmbIdBarco";
			// 
			// btnValidarBarco
			// 
			resources->ApplyResources(this->btnValidarBarco, L"btnValidarBarco");
			this->btnValidarBarco->Name = L"btnValidarBarco";
			this->btnValidarBarco->UseVisualStyleBackColor = true;
			this->btnValidarBarco->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarBarco_Click);
			// 
			// btnRecargarCmbBarco
			// 
			resources->ApplyResources(this->btnRecargarCmbBarco, L"btnRecargarCmbBarco");
			this->btnRecargarCmbBarco->Name = L"btnRecargarCmbBarco";
			this->btnRecargarCmbBarco->UseVisualStyleBackColor = true;
			this->btnRecargarCmbBarco->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarCmbBarco_Click);
			// 
			// btnRecargarBateria
			// 
			resources->ApplyResources(this->btnRecargarBateria, L"btnRecargarBateria");
			this->btnRecargarBateria->Name = L"btnRecargarBateria";
			this->btnRecargarBateria->UseVisualStyleBackColor = true;
			this->btnRecargarBateria->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarBateria_Click);
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// dgvCoordenadas
			// 
			this->dgvCoordenadas->AllowUserToAddRows = false;
			this->dgvCoordenadas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCoordenadas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdDesecho,
					this->IdCoordX, this->CoordY
			});
			resources->ApplyResources(this->dgvCoordenadas, L"dgvCoordenadas");
			this->dgvCoordenadas->Name = L"dgvCoordenadas";
			this->dgvCoordenadas->RowHeadersVisible = false;
			this->dgvCoordenadas->RowTemplate->Height = 24;
			// 
			// IdDesecho
			// 
			resources->ApplyResources(this->IdDesecho, L"IdDesecho");
			this->IdDesecho->Name = L"IdDesecho";
			// 
			// IdCoordX
			// 
			resources->ApplyResources(this->IdCoordX, L"IdCoordX");
			this->IdCoordX->Name = L"IdCoordX";
			// 
			// CoordY
			// 
			resources->ApplyResources(this->CoordY, L"CoordY");
			this->CoordY->Name = L"CoordY";
			// 
			// cmbIdDron
			// 
			this->cmbIdDron->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdDron->FormattingEnabled = true;
			resources->ApplyResources(this->cmbIdDron, L"cmbIdDron");
			this->cmbIdDron->Name = L"cmbIdDron";
			// 
			// btnValidarDron
			// 
			resources->ApplyResources(this->btnValidarDron, L"btnValidarDron");
			this->btnValidarDron->Name = L"btnValidarDron";
			this->btnValidarDron->UseVisualStyleBackColor = true;
			this->btnValidarDron->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarDron_Click);
			// 
			// btnAumentarContenedor
			// 
			this->btnAumentarContenedor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnAumentarContenedor, L"btnAumentarContenedor");
			this->btnAumentarContenedor->Name = L"btnAumentarContenedor";
			this->btnAumentarContenedor->UseVisualStyleBackColor = true;
			this->btnAumentarContenedor->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAumentarContenedor_Click);
			// 
			// btnAsignarBarcos
			// 
			this->btnAsignarBarcos->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnAsignarBarcos, L"btnAsignarBarcos");
			this->btnAsignarBarcos->Name = L"btnAsignarBarcos";
			this->btnAsignarBarcos->UseVisualStyleBackColor = true;
			this->btnAsignarBarcos->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAsignarBarcos_Click);
			// 
			// btnAsignarCamion
			// 
			this->btnAsignarCamion->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnAsignarCamion, L"btnAsignarCamion");
			this->btnAsignarCamion->Name = L"btnAsignarCamion";
			this->btnAsignarCamion->UseVisualStyleBackColor = true;
			this->btnAsignarCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAsignarCamion_Click);
			// 
			// btnAsignarDron
			// 
			this->btnAsignarDron->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnAsignarDron, L"btnAsignarDron");
			this->btnAsignarDron->Name = L"btnAsignarDron";
			this->btnAsignarDron->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			resources->ApplyResources(this->label13, L"label13");
			this->label13->Name = L"label13";
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			// 
			// cmb4Encargado
			// 
			this->cmb4Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb4Encargado->FormattingEnabled = true;
			resources->ApplyResources(this->cmb4Encargado, L"cmb4Encargado");
			this->cmb4Encargado->Name = L"cmb4Encargado";
			// 
			// cmb3Encargado
			// 
			this->cmb3Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb3Encargado->FormattingEnabled = true;
			resources->ApplyResources(this->cmb3Encargado, L"cmb3Encargado");
			this->cmb3Encargado->Name = L"cmb3Encargado";
			// 
			// cmb2Encargado
			// 
			this->cmb2Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb2Encargado->FormattingEnabled = true;
			resources->ApplyResources(this->cmb2Encargado, L"cmb2Encargado");
			this->cmb2Encargado->Name = L"cmb2Encargado";
			// 
			// cmb1Encargado
			// 
			this->cmb1Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb1Encargado->FormattingEnabled = true;
			resources->ApplyResources(this->cmb1Encargado, L"cmb1Encargado");
			this->cmb1Encargado->Name = L"cmb1Encargado";
			// 
			// btnCursor
			// 
			this->btnCursor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnCursor, L"btnCursor");
			this->btnCursor->Name = L"btnCursor";
			this->btnCursor->UseVisualStyleBackColor = true;
			this->btnCursor->Click += gcnew System::EventHandler(this, &MyWindowMain::btnCursor_Click);
			// 
			// btnAreaAnalisis
			// 
			this->btnAreaAnalisis->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			resources->ApplyResources(this->btnAreaAnalisis, L"btnAreaAnalisis");
			this->btnAreaAnalisis->Name = L"btnAreaAnalisis";
			this->btnAreaAnalisis->UseVisualStyleBackColor = true;
			this->btnAreaAnalisis->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAreaAnalisis_Click);
			// 
			// btnReiniciar
			// 
			resources->ApplyResources(this->btnReiniciar, L"btnReiniciar");
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->UseVisualStyleBackColor = true;
			this->btnReiniciar->Click += gcnew System::EventHandler(this, &MyWindowMain::btnReiniciar_Click);
			// 
			// btnDetener
			// 
			resources->ApplyResources(this->btnDetener, L"btnDetener");
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->UseVisualStyleBackColor = true;
			this->btnDetener->Click += gcnew System::EventHandler(this, &MyWindowMain::btnDetener_Click);
			// 
			// btnIniciar
			// 
			resources->ApplyResources(this->btnIniciar, L"btnIniciar");
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MyWindowMain::button1_Click);
			// 
			// tabControl1
			// 
			resources->ApplyResources(this->tabControl1, L"tabControl1");
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			// 
			// MyWindowMain
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->IsMdiContainer = true;
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip2;
			this->MaximizeBox = false;
			this->Name = L"MyWindowMain";
			this->Load += gcnew System::EventHandler(this, &MyWindowMain::MyWindowMain_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoCamara))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->desechogrid))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MapaWeb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamionesAsignados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcosAsignados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCoordenadas))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//METODOS
		void ClearControls() {
			for each (Control ^ control in this->Controls) {
				if (control->GetType() == TextBox::typeid) {
					dynamic_cast<TextBox^>(control)->Text = "";
				}
				/*
				if (control->GetType() == ComboBox::typeid) {
					dynamic_cast<ComboBox^>(control)->SelectedIndex = -1; 
				}
				*/
				txtAreaAncho->Text = "";
				txtAreaLargo->Text = "";
				cmb1Encargado->SelectedIndex = -1;
				cmb2Encargado->SelectedIndex = -1;
				cmb3Encargado->SelectedIndex = -1;
				cmb4Encargado->SelectedIndex = -1;
				cmbIdDron->SelectedIndex = -1;
				cmbIdBarco->SelectedIndex = -1;
				cmbIdCamion->SelectedIndex = -1;
			}

		}

		void CargarEncargados() {
			cmb1Encargado->Items->Clear();
			cmb2Encargado->Items->Clear();
			cmb3Encargado->Items->Clear();
			cmb4Encargado->Items->Clear();
			List<Encargado^>^ _encargadoList = Service::ConsultarEncargados();
			if (_encargadoList != nullptr) {
				for each (Encargado ^ encargado in _encargadoList) {
					if (encargado->Cargo == "Escaneo") {
						cmb1Encargado->Items->Add(encargado);
					}
					else if (encargado->Cargo == "Tratamiento de desechos") {
						cmb4Encargado->Items->Add(encargado);
					}
					else if (encargado->Cargo == "Transporte") {
						cmb3Encargado->Items->Add(encargado);
					}
					else {
						cmb2Encargado->Items->Add(encargado);
					}
				}
			}
		}
		void CargarDron(){
			cmbIdDron->Items->Clear();
			List<Dron^>^ _dron = Service::QueryDron(); 
			if (_dron != nullptr) {
				for each (Dron ^ d in _dron) {
					cmbIdDron->Items->Add(d->Id);
				}
			}
		}
		void CargarIdBarco() {
			cmbIdBarco->Items->Clear();
			List<Barco^>^ _barcoList = Service::ConsultarBarcos();
			if (_barcoList != nullptr) {
				for each (Barco ^ b in _barcoList) {
					cmbIdBarco->Items->Add(b->Id);
				}
			}
		}
		void CargarIdCamion() {
			cmbIdCamion->Items->Clear();
			List<Camion^>^ _camionList = Service::ConsultarCamion();
			if (_camionList != nullptr) {
				for each (Camion ^ c in _camionList) {
					cmbIdCamion->Items->Add(c->Id);
				}
			}
		}

		// Método para abrir el puerto serial
		void OpenPort() {
			try {
				// Verificar que se haya hecho una selección en el ComboBox cb_arduino
				if (cb_arduino->SelectedIndex == -1) {
					MessageBox::Show("Por favor, selecciona un puerto para el Arduino antes de abrir la conexión.",
						"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return; // Salir de la función si no se ha seleccionado un puerto
				}

				// Cierra el puerto si ya está abierto
				if (ArduinoPort != nullptr && ArduinoPort->IsOpen) {
					ArduinoPort->Close();
				}

				// Inicializa el puerto con el nombre seleccionado en cb_arduino
				String^ selectedPort = cb_arduino->SelectedItem->ToString();
				ArduinoPort = gcnew SerialPort(selectedPort, 9600, Parity::None, 8, StopBits::One);

				// Abre el puerto y asigna el manejador de datos recibidos
				ArduinoPort->Open();
				ArduinoPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &MyWindowMain::OnDataReceived);
			}
			catch (UnauthorizedAccessException^ e) {
				MessageBox::Show("Acceso denegado al puerto " + cb_arduino->SelectedItem + ": " + e->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (IOException^ e) {
				MessageBox::Show("Error de E/S en el puerto " + cb_arduino->SelectedItem + ": " + e->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ e) {
				MessageBox::Show("Error al abrir el puerto " + cb_arduino->SelectedItem + ": " + e->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		
		// Método para cerrar el puerto
		void ClosePort() {
			try {
				if (ArduinoPort != nullptr && ArduinoPort->IsOpen)
					ArduinoPort->Close();
			}
			catch (Exception^ ex) {
				throw ex;
			}
		}
		
		// Método para restablecer los valores del DataGridView
		void ResetGrid() {
			// Asegúrate de que el DataGridView tenga al menos una fila
			if (desechogrid->Rows->Count == 0) {
				desechogrid->Rows->Add(); // Añade una fila si está vacío
			}
		
			// Restablece todos los valores a cero
			desechogrid->Rows[0]->Cells["plasticobox"]->Value = System::Convert::ToInt32(0);
			desechogrid->Rows[0]->Cells["cartonbox"]->Value = System::Convert::ToInt32(0);
			desechogrid->Rows[0]->Cells["vidriobox"]->Value = System::Convert::ToInt32(0);
			desechogrid->Rows[0]->Cells["otrosbox"]->Value = System::Convert::ToInt32(0);
		}
		
		
		// Método que se llama al recibir datos del puerto serial
		void OnDataReceived(Object^ sender, SerialDataReceivedEventArgs^ e) {
			try {
				// Leer línea completa desde el puerto serial
				String^ data = ArduinoPort->ReadLine();
		
				// Ignorar si el proceso no ha comenzado
				if (!procesoIniciado) {
					return; // Salir sin procesar
				}
		
				// Divide los datos por comas
				array<String^>^ valores = data->Split(',');
		
				if (valores->Length == 4) { // Verifica que haya exactamente cuatro valores
					int plastico = Int32::Parse(valores[0]);
					int carton = Int32::Parse(valores[1]);
					int vidrio = Int32::Parse(valores[2]);
					int otros = Int32::Parse(valores[3]);
		
					// Actualiza el DataGridView en el hilo principal
					this->Invoke(gcnew UpdateGridDelegate(this, &MyWindowMain::UpdateDesechoGrid), plastico, carton, vidrio, otros);
				}
			}
			catch (Exception^ ex) {
				// Muestra un mensaje de error en caso de fallos
				MessageBox::Show("Error al leer los datos del puerto serial: " + ex->Message);
			}
		}
		
		void UpdateDesechoGrid(int plastico, int carton, int vidrio, int otros) {
			// Deshabilita la actualización de la interfaz de usuario
			this->desechogrid->SuspendLayout();

			// Restablece los valores antes de la actualización
			if (desechogrid->Rows->Count == 0) {
				desechogrid->Rows->Add();
			}

			// Guarda el índice de la primera columna visible
			int firstDisplayedColumnIndex = desechogrid->FirstDisplayedScrollingColumnIndex;
		
			// Actualiza los valores directamente
			desechogrid->Rows[0]->Cells["plasticobox"]->Value = plastico;
			desechogrid->Rows[0]->Cells["cartonbox"]->Value = carton;
			desechogrid->Rows[0]->Cells["vidriobox"]->Value = vidrio;
			desechogrid->Rows[0]->Cells["otrosbox"]->Value = otros;

			// Restaura el índice de la primera columna visible
			desechogrid->FirstDisplayedScrollingColumnIndex = firstDisplayedColumnIndex;

			// Habilita la actualización de la interfaz de usuario
			this->desechogrid->ResumeLayout();
		}

	private:
		bool procesoIniciado = false; // Bandera para verificar si el proceso ha iniciado
		bool procesoDetenido = false;

	private: System::Void iniciar_proceso_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si el proceso ya ha sido iniciado
		if (procesoIniciado) {
			MessageBox::Show("El proceso ya ha sido iniciado.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Verificar si el proceso ya ha sido iniciado
		if (procesoDetenido) {
			MessageBox::Show("El proceso ya ha sido iniciado y actualmente se encuentra detenido.\n\n"
				"Haz click en 'CONTINUAR' para seguir con la lectura de los datos.",
				"Proceso Detenido", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			return;
		}


		// Verificar que se haya hecho una selección en el ComboBox cb_arduino
		if (cb_arduino->SelectedIndex == -1) {
			MessageBox::Show("Por favor, selecciona un puerto para el Arduino antes de iniciar el proceso.",
				"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return; // Salir de la función si no se ha seleccionado un puerto
		}

		// Verificar si el puerto está abierto; si no, llamar a OpenPort
		if (ArduinoPort == nullptr || !ArduinoPort->IsOpen) {
			OpenPort(); // Intenta abrir el puerto
		}

		// Verificar nuevamente si el puerto está abierto, en caso de que OpenPort fallara
		if (ArduinoPort != nullptr && ArduinoPort->IsOpen) {

			UpdateDesechoGrid(0, 0, 0, 0);
			MessageBox::Show("El proceso de lectura se ha iniciado correctamente.\n\n"
				"Los datos en tiempo real se est\u00E1n registrando en la tabla de resultados.",
				"Proceso Iniciado", MessageBoxButtons::OK, MessageBoxIcon::Information);



			// Enviar el comando "R" al Arduino para comenzar la lectura del sensor de color
			ArduinoPort->WriteLine("R");

			// Reiniciar los valores en el DataGridView a cero
			
			procesoIniciado = true; // Marcar que el proceso ha comenzado
			procesoDetenido = false;
		}
		else {
			MessageBox::Show("No se pudo abrir el puerto para el Arduino. Revisa la conexión y vuelve a intentarlo.",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	
		

	}	
	private: System::Void salirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void encargadosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		EncargadosForm^ form = gcnew EncargadosForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}
	private: System::Void barcosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		BarcoForm^ form = gcnew BarcoForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}

	private: System::Void camionesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		CamionesForm^ form = gcnew CamionesForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}
	private: System::Void dronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		DronForm^ form = gcnew DronForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}

	private:
		int segundos = 0;
		int minutos = 0;
		int horas = 0;

		//UBICACIONES FIJAS
	private:
		Puerto^ puerto = gcnew Puerto();
		Acopio^ pucp = gcnew Acopio();
		Area^ area = gcnew Area();
		int cantBtnInicio = 0;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		cantBtnInicio++;
		if (cantBtnInicio == 1) {
			
			//GENERA RUTA DEL CAMION
			puerto->Posicion = gcnew Coordenadas(-12.069060413055682, -77.07815928837975);
			pucp->Posicion = gcnew Coordenadas(-12.053763093969444, -77.14634104154212);
			this->MapaWeb->CoreWebView2->ExecuteScriptAsync("calculateAndDisplayRoute(" + puerto->Posicion + ", " + pucp->Posicion + ");");

			segundos = 0;
			minutos = 0;
			horas = 0;
			lblCronometro->Text = "00:00:00";  
			timer1->Enabled = true;             // Activa el Timer

			// Anadiremos el simbolo del dron en el mapa

		}
		else {
			MessageBox::Show("La simulación se ejecutando");
		}
	
	}

	void LoadHTMLPage()
	{
		String^ outputPath = Application::StartupPath;
		String^ htmlFilePath = Path::Combine(outputPath, "HTMLPage.html");
		MapaWeb->Source = gcnew Uri(htmlFilePath);
	}
	private: System::Void MyWindowMain_Load(System::Object^ sender, System::EventArgs^ e) { 
		LoadHTMLPage();
		CargarEncargados();
		CargarDron();
		CargarIdBarco();
		CargarIdCamion();

		
	}
	private: System::Void contenedoresToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ContenedorForm^ form = gcnew ContenedorForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}


	private: System::Void btnAreaAnalisis_Click(System::Object^ sender, System::EventArgs^ e) {
		area->long1 = -12.07488;
		area->long2 = -77.155983;
		area->long3 = -12.07588;
		area->long4 = -77.156983;

		double lat1 = area->long1;
		double lng1 = area->long2;
		double lat2 = area->long3;
		double lng2 = area->long4;


		// Genera el script en JavaScript para dibujar el rect�ngulo
		String^ script = String::Format("dibujarRectangulo({0}, {1}, {2}, {3});", lat2, lng2, lat1, lng1);
		// Ejecuta el script en WebView2
		MapaWeb->CoreWebView2->ExecuteScriptAsync(script);

		// Calcula el ancho (diferencia en longitud) y largo (diferencia en latitud)
		double ancho = Math::Abs(lng2 - lng1);
		double largo = Math::Abs(lat2 - lat1);

		txtAreaAncho->Text = ""+ancho;
		txtAreaLargo->Text = ""+largo;
	}
	private: System::Void btnCursor_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btnDetener_Click(System::Object^ sender, System::EventArgs^ e) {
		btnValidarBarco->Enabled = false;
		btnValidarDron->Enabled = false;
		btnValidarCamion->Enabled = false;
		btnRecargarBateria->Enabled = false;
		btnRecargarCmbBarco->Enabled = false;
		btnRecargarCmbCamion->Enabled = false;
		btnAsignarDron->Enabled = false;
		btnAsignarBarcos->Enabled = false;
		btnAsignarCamion->Enabled = false;
		btnAumentarContenedor->Enabled = false;
		timer1->Enabled = false;
	}
private: System::Void btnReiniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearControls();
	btnValidarBarco->Enabled = true;
	btnValidarDron->Enabled = true;
	btnValidarCamion->Enabled = true;
	btnRecargarBateria->Enabled = true;
	btnRecargarCmbBarco->Enabled = true;
	btnRecargarCmbCamion->Enabled = true;
	btnAsignarDron->Enabled = true;
	btnAsignarBarcos->Enabled = true;
	btnAsignarCamion->Enabled = true;
	btnAumentarContenedor->Enabled = true;
	
}
private: 
	void recibirCoordenadas(double latitud, double longitud) {
		Coordenadas^ coord = gcnew Coordenadas(latitud, longitud);
		dgvCoordenadas->Rows->Add(coord->X, coord->Y);
	}

private: System::Void btnAsignarCamion_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ idSeleccionado = cmbIdCamion->SelectedItem->ToString();
	List<Camion^>^ _camionList = Service::ConsultarCamion();
	if (_camionList != nullptr) {
		Camion^ camionSeleccionado = nullptr;
		for each (Camion ^ c in _camionList) {
			if (Convert::ToString(c->Id) == idSeleccionado) {
				camionSeleccionado = c;
				break; 
			}
		}
		if (camionSeleccionado != nullptr) {
			for (int i = 0; i < dgvCamionesAsignados->Rows->Count; i++) {
				if (dgvCamionesAsignados->Rows[i]->Cells[0]->Value->ToString() == idSeleccionado) {
					MessageBox::Show("Este cami�n ya ha sido asignado.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return; 
				}
			}
			dgvCamionesAsignados->Rows->Add(camionSeleccionado->Id, camionSeleccionado->Placa);
		}
	}
	puerto->Posicion = gcnew Coordenadas(-12.069060413055682, -77.07815928837975);
	pucp->Posicion = gcnew Coordenadas(-12.053763093969444, -77.14634104154212);
	MapaWeb->ExecuteScriptAsync("moverCamion("+puerto->Posicion+","+""+pucp->Posicion+"); ");

}
private: System::Void btnAsignarBarcos_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ idSeleccionado = cmbIdBarco->SelectedItem->ToString();
	List<Barco^>^ _barcos = Service::ConsultarBarcos();
	if (_barcos != nullptr) {
		Barco^ barcoSelecionado = nullptr;
		for each (Barco ^ c in _barcos) {
			if (Convert::ToString(c->Id) == idSeleccionado) {
				barcoSelecionado = c;
				break;
			}
		}
		if (barcoSelecionado != nullptr) {
			for (int i = 0; i < dgvBarcosAsignados->Rows->Count; i++) {
				if (dgvBarcosAsignados->Rows[i]->Cells[0]->Value->ToString() == idSeleccionado) {
					MessageBox::Show("Este barco ya ha sido asignado.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}
			dgvBarcosAsignados->Rows->Add(barcoSelecionado->Id, barcoSelecionado->CantCoordendas);
		}
	}
}
//BOTONES DE VALIDAR| RECARGAR
private:
	void MostrarNivelCombustible(ComboBox^ cmb, TextBox^ txtCombustible, String^ tipo) {
		try {
			if (cmb->SelectedItem == nullptr) {
				MessageBox::Show("Por favor, selecciona un " + tipo + ".", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			String^ id_seleccionado = cmb->SelectedItem->ToString();
			if (tipo == "barco") {
				List<Barco^>^ listaBarcos = Service::ConsultarBarcos();
				if (listaBarcos != nullptr) {
					for each (Barco ^ b in listaBarcos) {
						if (Convert::ToString(b->Id) == id_seleccionado) {
							txtCombustible->Text = "" + b->NivelCombustible + "%";
							return;
						}
					}
				}
			}
			else if(tipo == "dron") {
				List<Dron^>^ listDron = Service::QueryDron();
				if (listDron != nullptr) {
					for each (Dron ^ d in listDron) {
						if (Convert::ToString(d->Id) == id_seleccionado) {
							txtCombustible->Text = "" + d->Bateria + "%";
							return;
						}
					}
				}
			}
			else {
				List<Camion^>^ listaCamiones = Service::ConsultarCamion();
				if (listaCamiones != nullptr) {
					for each (Camion ^ c in listaCamiones) {
						if (Convert::ToString(c->Id) == id_seleccionado) {
							txtCombustible->Text = "" + c->NivelCombustible + "%";
							return;
						}
					}
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ha ocurrido un error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	void RecargarCombustible(ComboBox^ cmb, String^ tipo) {
		if (cmb->SelectedItem == nullptr) {
			MessageBox::Show("Por favor, selecciona un " + tipo + ".", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		String^ id_seleccionado = cmb->SelectedItem->ToString();
		if (tipo == "barco") {
			List<Barco^>^ listaBarcos = Service::ConsultarBarcos();
			if (listaBarcos != nullptr) {
				for each (Barco ^ b in listaBarcos) {
					if (Convert::ToString(b->Id) == id_seleccionado) {
						b->NivelCombustible = 100;
						return;
					}
				}
			}
		}
		else if (tipo == "dron") {
			List<Dron^>^ listDron = Service::QueryDron();
			if (listDron != nullptr) {
				for each (Dron ^ d in listDron) {
					if (Convert::ToString(d->Id) == id_seleccionado) {
						d->Bateria = 100;
						return;
					}
				}
			}
		}
		else {
			List<Camion^>^ listaCamiones = Service::ConsultarCamion();
			if (listaCamiones != nullptr) {
				for each (Camion ^ c in listaCamiones) {
					if (Convert::ToString(c->Id) == id_seleccionado) {
						c->NivelCombustible = 100;
						return;
					}
				}
			}
		}
	}
private: System::Void btnValidarBarco_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarNivelCombustible(cmbIdBarco, txtBarcoCombustible, "barco");
}
private: System::Void btnValidarCamion_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarNivelCombustible(cmbIdCamion, txtCamionCombustible, "cami�n");
}
private: System::Void btnRecargarCmbBarco_Click(System::Object^ sender, System::EventArgs^ e) {
	RecargarCombustible(cmbIdBarco, "barco");
	txtBarcoCombustible->Text = "100%";
}
private: System::Void btnRecargarCmbCamion_Click(System::Object^ sender, System::EventArgs^ e) {
	RecargarCombustible(cmbIdCamion, "cami�n");
	txtCamionCombustible->Text = "100%";
}
private: System::Void btnValidarDron_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarNivelCombustible(cmbIdDron, txtDronBateria, "dron");
}
private: System::Void btnRecargarBateria_Click(System::Object^ sender, System::EventArgs^ e) {
	RecargarCombustible(cmbIdDron, "dron");
	txtDronBateria->Text = "100%";

}
private: System::Void btnPruebas_Click(System::Object^ sender, System::EventArgs^ e) {
	this->MapaWeb->CoreWebView2->ExecuteScriptAsync("displayearDron();");

	//MapaWeb->ExecuteScriptAsync("generarPuntosAleatorios();");	
}
private: System::Void btnPruebas2_Click(System::Object^ sender, System::EventArgs^ e) {
	MapaWeb->ExecuteScriptAsync("generarYMoverBarcoManual();");
}

private:
	int contador = 0;

private: System::Void btnAumentarContenedor_Click(System::Object^ sender, System::EventArgs^ e) {
	contador++;
	txtCantContenedores->Text = ""+contador;
}

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	segundos++;
	if (segundos == 60) {
		segundos = 0;
		minutos++;
		if (minutos == 60) {
			minutos = 0;
			horas++;
		}
	}
	lblCronometro->Text = String::Format("{0:D2}:{1:D2}:{2:D2}", horas, minutos, segundos);
}

// Asegúrate de cerrar el puerto cuando se cierre el formulario
private: System::Void MyWindowMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (readThread != nullptr && readThread->IsAlive) {
		readThread->Abort();
	}
	ClosePort();
}
private: System::Void empleadosPorAreaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	EmployeesReportForm^ form = gcnew EmployeesReportForm();
	form->ShowDialog(); // Mostrar el formulario de forma modal

}
private: System::Void deschosRecicladosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	GarbageReportForm^ form = gcnew GarbageReportForm();
	form->ShowDialog(); // Mostrar el formulario de forma modal

}

private: System::Void detener_proceso_Click(System::Object^ sender, System::EventArgs^ e) {

	if (procesoDetenido) {
		MessageBox::Show("El proceso ya ha sido detenido.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		
		return;
	}

	if (!procesoIniciado) {
		MessageBox::Show("El proceso a\u00FAn no ha sido iniciado.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (ArduinoPort->IsOpen) {
		ArduinoPort->WriteLine("L");
		procesoDetenido = true;
		procesoIniciado = false;

		MessageBox::Show("El proceso de lectura se ha detenido correctamente.\n\n"
			"Haz click en 'CONTINUAR' para seguir con la lectura de los datos.",
			"Proceso Detenido", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show("El puerto no está abierto.");
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (procesoIniciado && !procesoDetenido) {
		MessageBox::Show("La lectura de datos ya se esta haciendo de manera correcta", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Information);

		return;
	}

	if (!procesoIniciado && !procesoDetenido) {
		MessageBox::Show("El proceso a\u00FAn no ha sido iniciado.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}


	if (ArduinoPort->IsOpen) {

		MessageBox::Show("El proceso de lectura se ha restablecido correctamente.\n\n"
			"Los datos en tiempo real se est\u00E1n registrando en la tabla de resultados",
			"Proceso Restablecido", MessageBoxButtons::OK, MessageBoxIcon::Information);

		ArduinoPort->WriteLine("H");
		procesoDetenido = false;
		procesoIniciado = true;

	}
}
	public:
		// Propiedad Singleton para obtener la instancia de MyWindowMain
		static property MyWindowMain^ Instance {
			MyWindowMain^ get() {
				if (instance == nullptr) {
					instance = gcnew MyWindowMain();
				}
				return instance;
			}
		}
private: System::Void desechogrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}
};
}
