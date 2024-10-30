#pragma once

#include "EncargadosForm.h"
#include "DronForm.h"
#include "CamionesForm.h"
#include "BarcoForm.h"
#include "ContenedorForm.h"
#include "ComboBoxItem.h"

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
		bool HayDispositivos;
		FilterInfoCollection^ MisDispositivos;
		VideoCaptureDevice^ MiWebCam;
	private: System::Windows::Forms::ComboBox^ cbCamara;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnPruebas;
	private: System::Windows::Forms::Button^ btnPruebas2;

	private: int camaraActual = -1;
	
	public:
		MyWindowMain(void)
		{
			InitializeComponent();
			LoadImage();

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
			
			toolTip1->SetToolTip(btnAreaAnalisis, "Realizar área de análisis");
			toolTip2->SetToolTip(btnReiniciar, "Reiniciar simulación");
			toolTip3->SetToolTip(btnDetener, "Detener simulación");
			toolTip4->SetToolTip(btnIniciar, "Iniciar simulación");
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
	private: System::Windows::Forms::TextBox^ txtAreaLargo;
	private: System::Windows::Forms::TextBox^ txtAreaAncho;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;







	private: System::Windows::Forms::Label^ label1;





	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnReiniciar;

	private: System::Windows::Forms::Button^ btnDetener;

	private: System::Windows::Forms::Button^ btnIniciar;


	private: System::Windows::Forms::ToolStripMenuItem^ contenedoresToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::PictureBox^ videoCamara;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ detener_proceso;
	private: System::Windows::Forms::Button^ iniciar_proceso;
	public: System::Windows::Forms::DataGridView^ desechogrid;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ plasticobox;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cartonbox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vidriobox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ otrosbox;
	private: System::Windows::Forms::Button^ btnAreaAnalisis;

	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::ToolTip^ toolTip4;
	private: System::Windows::Forms::Button^ btnCursor;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cmb4Encargado;

	private: System::Windows::Forms::ComboBox^ cmb3Encargado;

	private: System::Windows::Forms::ComboBox^ cmb2Encargado;

	private: System::Windows::Forms::ComboBox^ cmb1Encargado;
private: System::Windows::Forms::Button^ btnAumentarContenedor;


	private: System::Windows::Forms::Button^ btnAsignarBarcos;
	private: System::Windows::Forms::Button^ btnAsignarCamion;


	private: System::Windows::Forms::Button^ btnAsignarDron;
private: System::Windows::Forms::ComboBox^ cmbIdDron;

private: System::Windows::Forms::Button^ btnValidarDron;



private: System::Windows::Forms::DataGridView^ dataGridView1;




private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::TextBox^ txtDronBateria;


private: System::Windows::Forms::Button^ btnRecargarCmbBarco;

private: System::Windows::Forms::Button^ btnRecargarBateria;

private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TextBox^ txtCamionCombustible;

private: System::Windows::Forms::ComboBox^ cmbIdCamion;

private: System::Windows::Forms::Button^ btnValidarCamion;
private: System::Windows::Forms::Button^ btnRecargarCmbCamion;


private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::TextBox^ txtBarcoCombustible;

private: System::Windows::Forms::ComboBox^ cmbIdBarco;


private: System::Windows::Forms::Button^ btnValidarBarco;

private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::DataGridView^ dgvBarcosAsignados;

private: System::Windows::Forms::DataGridView^ dgvCamionesAsignados;





private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdDesecho;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCoordX;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ CoordY;
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
private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCamion;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ MatriculaCamion;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdBarco;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ CapacidadCoord;
private: Microsoft::Web::WebView2::WinForms::WebView2^ MapaWeb;









	private: System::Windows::Forms::ToolStripMenuItem^ camionesToolStripMenuItem;

		   void LoadImage()
		   {
			   Mapa^ mapa = gcnew Mapa();

			   // Cargar la imagen desde una ruta relativa
			   pictureBox1->Image = Image::FromFile(mapa->Imagen);
			   pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox

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
			this->txtAreaLargo = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaAncho = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->btnDetener = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnPruebas = (gcnew System::Windows::Forms::Button());
			this->MapaWeb = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
			this->dgvCamionesAsignados = (gcnew System::Windows::Forms::DataGridView());
			this->IdCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MatriculaCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvBarcosAsignados = (gcnew System::Windows::Forms::DataGridView());
			this->IdBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CapacidadCoord = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtCamionCombustible = (gcnew System::Windows::Forms::TextBox());
			this->cmbIdCamion = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarCamion = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbCamion = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBarcoCombustible = (gcnew System::Windows::Forms::TextBox());
			this->cmbIdBarco = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarBateria = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtDronBateria = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
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
			this->btnPruebas2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MapaWeb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamionesAsignados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcosAsignados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoCamara))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->desechogrid))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->archivoToolStripMenuItem,
					this->mantenimientoToolStripMenuItem, this->ayudaToolStripMenuItem, this->acercaDeToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip2->Size = System::Drawing::Size(1112, 24);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			this->menuStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyWindowMain::menuStrip1_ItemClicked);
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->salirToolStripMenuItem });
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(96, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::salirToolStripMenuItem_Click);
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->encargadosToolStripMenuItem,
					this->barcosToolStripMenuItem, this->dronToolStripMenuItem, this->camionesToolStripMenuItem, this->contenedoresToolStripMenuItem
			});
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->mantenimientoToolStripMenuItem->Text = L"Mantenimiento";
			// 
			// encargadosToolStripMenuItem
			// 
			this->encargadosToolStripMenuItem->Name = L"encargadosToolStripMenuItem";
			this->encargadosToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->encargadosToolStripMenuItem->Text = L"Encargados";
			this->encargadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::encargadosToolStripMenuItem_Click);
			// 
			// barcosToolStripMenuItem
			// 
			this->barcosToolStripMenuItem->Name = L"barcosToolStripMenuItem";
			this->barcosToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->barcosToolStripMenuItem->Text = L"Barcos";
			this->barcosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::barcosToolStripMenuItem_Click);
			// 
			// dronToolStripMenuItem
			// 
			this->dronToolStripMenuItem->Name = L"dronToolStripMenuItem";
			this->dronToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->dronToolStripMenuItem->Text = L"Dron";
			this->dronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::dronToolStripMenuItem_Click);
			// 
			// camionesToolStripMenuItem
			// 
			this->camionesToolStripMenuItem->Name = L"camionesToolStripMenuItem";
			this->camionesToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->camionesToolStripMenuItem->Text = L"Camiones";
			this->camionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::camionesToolStripMenuItem_Click);
			// 
			// contenedoresToolStripMenuItem
			// 
			this->contenedoresToolStripMenuItem->Name = L"contenedoresToolStripMenuItem";
			this->contenedoresToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->contenedoresToolStripMenuItem->Text = L"Contenedores";
			this->contenedoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::contenedoresToolStripMenuItem_Click);
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->guíaDelSoftwareToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// guíaDelSoftwareToolStripMenuItem
			// 
			this->guíaDelSoftwareToolStripMenuItem->Name = L"guíaDelSoftwareToolStripMenuItem";
			this->guíaDelSoftwareToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->guíaDelSoftwareToolStripMenuItem->Text = L"Guía del software";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->integrantesToolStripMenuItem,
					this->informaciónDelProyectoToolStripMenuItem
			});
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			this->acercaDeToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->acercaDeToolStripMenuItem->Text = L"Acerca de";
			// 
			// integrantesToolStripMenuItem
			// 
			this->integrantesToolStripMenuItem->Name = L"integrantesToolStripMenuItem";
			this->integrantesToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->integrantesToolStripMenuItem->Text = L"Integrantes";
			// 
			// informaciónDelProyectoToolStripMenuItem
			// 
			this->informaciónDelProyectoToolStripMenuItem->Name = L"informaciónDelProyectoToolStripMenuItem";
			this->informaciónDelProyectoToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->informaciónDelProyectoToolStripMenuItem->Text = L"Información del proyecto";
			// 
			// txtAreaLargo
			// 
			this->txtAreaLargo->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaLargo->Enabled = false;
			this->txtAreaLargo->Location = System::Drawing::Point(812, 86);
			this->txtAreaLargo->Margin = System::Windows::Forms::Padding(2);
			this->txtAreaLargo->Name = L"txtAreaLargo";
			this->txtAreaLargo->ReadOnly = true;
			this->txtAreaLargo->Size = System::Drawing::Size(79, 19);
			this->txtAreaLargo->TabIndex = 33;
			// 
			// txtAreaAncho
			// 
			this->txtAreaAncho->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaAncho->Enabled = false;
			this->txtAreaAncho->Location = System::Drawing::Point(812, 62);
			this->txtAreaAncho->Margin = System::Windows::Forms::Padding(2);
			this->txtAreaAncho->Name = L"txtAreaAncho";
			this->txtAreaAncho->ReadOnly = true;
			this->txtAreaAncho->Size = System::Drawing::Size(79, 19);
			this->txtAreaAncho->TabIndex = 32;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(765, 89);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Largo";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(765, 64);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Ancho";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(666, -14);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"INGRESE DATOS PARA LA SIMULACIÓN";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(7, 5);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(688, 623);
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyWindowMain::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyWindowMain::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyWindowMain::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyWindowMain::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyWindowMain::pictureBox1_MouseUp);
			// 
			// btnReiniciar
			// 
			this->btnReiniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnReiniciar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReiniciar.Image")));
			this->btnReiniciar->Location = System::Drawing::Point(850, 13);
			this->btnReiniciar->Margin = System::Windows::Forms::Padding(2);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(40, 44);
			this->btnReiniciar->TabIndex = 19;
			this->btnReiniciar->UseVisualStyleBackColor = true;
			this->btnReiniciar->Click += gcnew System::EventHandler(this, &MyWindowMain::btnReiniciar_Click);
			// 
			// btnDetener
			// 
			this->btnDetener->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnDetener->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDetener.Image")));
			this->btnDetener->Location = System::Drawing::Point(805, 13);
			this->btnDetener->Margin = System::Windows::Forms::Padding(2);
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->Size = System::Drawing::Size(40, 44);
			this->btnDetener->TabIndex = 18;
			this->btnDetener->UseVisualStyleBackColor = true;
			this->btnDetener->Click += gcnew System::EventHandler(this, &MyWindowMain::btnDetener_Click);
			// 
			// btnIniciar
			// 
			this->btnIniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnIniciar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciar.Image")));
			this->btnIniciar->Location = System::Drawing::Point(760, 12);
			this->btnIniciar->Margin = System::Windows::Forms::Padding(2);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(40, 44);
			this->btnIniciar->TabIndex = 17;
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MyWindowMain::button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(9, 25);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1096, 656);
			this->tabControl1->TabIndex = 35;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->btnPruebas2);
			this->tabPage1->Controls->Add(this->btnPruebas);
			this->tabPage1->Controls->Add(this->MapaWeb);
			this->tabPage1->Controls->Add(this->dgvCamionesAsignados);
			this->tabPage1->Controls->Add(this->dgvBarcosAsignados);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->txtCamionCombustible);
			this->tabPage1->Controls->Add(this->cmbIdCamion);
			this->tabPage1->Controls->Add(this->btnValidarCamion);
			this->tabPage1->Controls->Add(this->btnRecargarCmbCamion);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->txtBarcoCombustible);
			this->tabPage1->Controls->Add(this->cmbIdBarco);
			this->tabPage1->Controls->Add(this->btnValidarBarco);
			this->tabPage1->Controls->Add(this->btnRecargarCmbBarco);
			this->tabPage1->Controls->Add(this->btnRecargarBateria);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->txtDronBateria);
			this->tabPage1->Controls->Add(this->dataGridView1);
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
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->txtAreaLargo);
			this->tabPage1->Controls->Add(this->btnReiniciar);
			this->tabPage1->Controls->Add(this->txtAreaAncho);
			this->tabPage1->Controls->Add(this->btnDetener);
			this->tabPage1->Controls->Add(this->btnIniciar);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(1088, 630);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Simulación para cada proceso";
			// 
			// btnPruebas
			// 
<<<<<<< HEAD
			this->btnPruebas->Location = System::Drawing::Point(760, 130);
			this->btnPruebas->Name = L"btnPruebas";
			this->btnPruebas->Size = System::Drawing::Size(33, 23);
=======
			this->btnPruebas->Location = System::Drawing::Point(783, 130);
			this->btnPruebas->Name = L"btnPruebas";
			this->btnPruebas->Size = System::Drawing::Size(30, 23);
>>>>>>> AA
			this->btnPruebas->TabIndex = 83;
			this->btnPruebas->Text = L"P1";
			this->btnPruebas->UseVisualStyleBackColor = true;
			this->btnPruebas->Click += gcnew System::EventHandler(this, &MyWindowMain::btnPruebas_Click);
			// 
			// MapaWeb
			// 
			this->MapaWeb->AllowExternalDrop = true;
			this->MapaWeb->CreationProperties = nullptr;
			this->MapaWeb->DefaultBackgroundColor = System::Drawing::Color::White;
			this->MapaWeb->Location = System::Drawing::Point(7, 5);
			this->MapaWeb->Name = L"MapaWeb";
			this->MapaWeb->Size = System::Drawing::Size(688, 623);
			this->MapaWeb->TabIndex = 82;
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
			this->dgvCamionesAsignados->Location = System::Drawing::Point(861, 465);
			this->dgvCamionesAsignados->Margin = System::Windows::Forms::Padding(2);
			this->dgvCamionesAsignados->Name = L"dgvCamionesAsignados";
			this->dgvCamionesAsignados->RowHeadersVisible = false;
			this->dgvCamionesAsignados->RowHeadersWidth = 51;
			this->dgvCamionesAsignados->RowTemplate->Height = 24;
			this->dgvCamionesAsignados->Size = System::Drawing::Size(218, 157);
			this->dgvCamionesAsignados->TabIndex = 81;
			// 
			// IdCamion
			// 
			this->IdCamion->HeaderText = L"Id";
			this->IdCamion->MinimumWidth = 6;
			this->IdCamion->Name = L"IdCamion";
			this->IdCamion->Width = 50;
			// 
			// MatriculaCamion
			// 
			this->MatriculaCamion->HeaderText = L"Matricula (POO-123)";
			this->MatriculaCamion->MinimumWidth = 6;
			this->MatriculaCamion->Name = L"MatriculaCamion";
			this->MatriculaCamion->Width = 125;
			// 
			// dgvBarcosAsignados
			// 
			this->dgvBarcosAsignados->AllowUserToAddRows = false;
			this->dgvBarcosAsignados->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBarcosAsignados->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdBarco,
					this->CapacidadCoord
			});
			this->dgvBarcosAsignados->Location = System::Drawing::Point(861, 303);
			this->dgvBarcosAsignados->Margin = System::Windows::Forms::Padding(2);
			this->dgvBarcosAsignados->Name = L"dgvBarcosAsignados";
			this->dgvBarcosAsignados->RowHeadersVisible = false;
			this->dgvBarcosAsignados->RowHeadersWidth = 51;
			this->dgvBarcosAsignados->RowTemplate->Height = 24;
			this->dgvBarcosAsignados->Size = System::Drawing::Size(218, 157);
			this->dgvBarcosAsignados->TabIndex = 80;
			// 
			// IdBarco
			// 
			this->IdBarco->HeaderText = L"Id";
			this->IdBarco->MinimumWidth = 6;
			this->IdBarco->Name = L"IdBarco";
			this->IdBarco->Width = 50;
			// 
			// CapacidadCoord
			// 
			this->CapacidadCoord->HeaderText = L"Cantidad Coordenadas";
			this->CapacidadCoord->MinimumWidth = 6;
			this->CapacidadCoord->Name = L"CapacidadCoord";
			this->CapacidadCoord->Width = 125;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(765, 583);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(93, 13);
			this->label17->TabIndex = 79;
			this->label17->Text = L"Cantidad utilizada ";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(770, 598);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(76, 19);
			this->textBox4->TabIndex = 78;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(716, 567);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(65, 13);
			this->label16->TabIndex = 77;
			this->label16->Text = L"Contenedor ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(716, 294);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(100, 13);
			this->label15->TabIndex = 76;
			this->label15->Text = L"ASIGNAR UNIDAD";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(716, 484);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(97, 13);
			this->label14->TabIndex = 75;
			this->label14->Text = L"Camion de traslado";
			// 
			// txtCamionCombustible
			// 
			this->txtCamionCombustible->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtCamionCombustible->Enabled = false;
			this->txtCamionCombustible->Location = System::Drawing::Point(766, 501);
			this->txtCamionCombustible->Margin = System::Windows::Forms::Padding(2);
			this->txtCamionCombustible->Name = L"txtCamionCombustible";
			this->txtCamionCombustible->ReadOnly = true;
			this->txtCamionCombustible->Size = System::Drawing::Size(80, 19);
			this->txtCamionCombustible->TabIndex = 74;
			// 
			// cmbIdCamion
			// 
			this->cmbIdCamion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdCamion->FormattingEnabled = true;
			this->cmbIdCamion->Location = System::Drawing::Point(718, 500);
			this->cmbIdCamion->Margin = System::Windows::Forms::Padding(2);
			this->cmbIdCamion->Name = L"cmbIdCamion";
			this->cmbIdCamion->Size = System::Drawing::Size(38, 21);
			this->cmbIdCamion->TabIndex = 73;
			// 
			// btnValidarCamion
			// 
			this->btnValidarCamion->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarCamion.Image")));
			this->btnValidarCamion->Location = System::Drawing::Point(718, 524);
			this->btnValidarCamion->Margin = System::Windows::Forms::Padding(2);
			this->btnValidarCamion->Name = L"btnValidarCamion";
			this->btnValidarCamion->Size = System::Drawing::Size(38, 41);
			this->btnValidarCamion->TabIndex = 72;
			this->btnValidarCamion->UseVisualStyleBackColor = true;
			this->btnValidarCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarCamion_Click);
			// 
			// btnRecargarCmbCamion
			// 
			this->btnRecargarCmbCamion->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarCmbCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarCmbCamion.Image")));
			this->btnRecargarCmbCamion->Location = System::Drawing::Point(767, 524);
			this->btnRecargarCmbCamion->Margin = System::Windows::Forms::Padding(2);
			this->btnRecargarCmbCamion->Name = L"btnRecargarCmbCamion";
			this->btnRecargarCmbCamion->Size = System::Drawing::Size(38, 41);
			this->btnRecargarCmbCamion->TabIndex = 71;
			this->btnRecargarCmbCamion->UseVisualStyleBackColor = true;
			this->btnRecargarCmbCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarCmbCamion_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(716, 401);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 13);
			this->label5->TabIndex = 68;
			this->label5->Text = L"Barco recolector";
			// 
			// txtBarcoCombustible
			// 
			this->txtBarcoCombustible->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtBarcoCombustible->Enabled = false;
			this->txtBarcoCombustible->Location = System::Drawing::Point(766, 417);
			this->txtBarcoCombustible->Margin = System::Windows::Forms::Padding(2);
			this->txtBarcoCombustible->Name = L"txtBarcoCombustible";
			this->txtBarcoCombustible->ReadOnly = true;
			this->txtBarcoCombustible->Size = System::Drawing::Size(80, 19);
			this->txtBarcoCombustible->TabIndex = 67;
			// 
			// cmbIdBarco
			// 
			this->cmbIdBarco->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdBarco->FormattingEnabled = true;
			this->cmbIdBarco->Location = System::Drawing::Point(717, 417);
			this->cmbIdBarco->Margin = System::Windows::Forms::Padding(2);
			this->cmbIdBarco->Name = L"cmbIdBarco";
			this->cmbIdBarco->Size = System::Drawing::Size(38, 21);
			this->cmbIdBarco->TabIndex = 66;
			// 
			// btnValidarBarco
			// 
			this->btnValidarBarco->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarBarco->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarBarco.Image")));
			this->btnValidarBarco->Location = System::Drawing::Point(717, 441);
			this->btnValidarBarco->Margin = System::Windows::Forms::Padding(2);
			this->btnValidarBarco->Name = L"btnValidarBarco";
			this->btnValidarBarco->Size = System::Drawing::Size(38, 41);
			this->btnValidarBarco->TabIndex = 65;
			this->btnValidarBarco->UseVisualStyleBackColor = true;
			this->btnValidarBarco->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarBarco_Click);
			// 
			// btnRecargarCmbBarco
			// 
			this->btnRecargarCmbBarco->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarCmbBarco->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarCmbBarco.Image")));
			this->btnRecargarCmbBarco->Location = System::Drawing::Point(766, 441);
			this->btnRecargarCmbBarco->Margin = System::Windows::Forms::Padding(2);
			this->btnRecargarCmbBarco->Name = L"btnRecargarCmbBarco";
			this->btnRecargarCmbBarco->Size = System::Drawing::Size(38, 41);
			this->btnRecargarCmbBarco->TabIndex = 63;
			this->btnRecargarCmbBarco->UseVisualStyleBackColor = true;
			this->btnRecargarCmbBarco->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarCmbBarco_Click);
			// 
			// btnRecargarBateria
			// 
			this->btnRecargarBateria->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarBateria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarBateria.Image")));
			this->btnRecargarBateria->Location = System::Drawing::Point(765, 358);
			this->btnRecargarBateria->Margin = System::Windows::Forms::Padding(2);
			this->btnRecargarBateria->Name = L"btnRecargarBateria";
			this->btnRecargarBateria->Size = System::Drawing::Size(38, 41);
			this->btnRecargarBateria->TabIndex = 62;
			this->btnRecargarBateria->UseVisualStyleBackColor = true;
			this->btnRecargarBateria->Click += gcnew System::EventHandler(this, &MyWindowMain::btnRecargarBateria_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(716, 318);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 61;
			this->label4->Text = L"Dron scanner";
			// 
			// txtDronBateria
			// 
			this->txtDronBateria->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtDronBateria->Enabled = false;
			this->txtDronBateria->Location = System::Drawing::Point(765, 335);
			this->txtDronBateria->Margin = System::Windows::Forms::Padding(2);
			this->txtDronBateria->Name = L"txtDronBateria";
			this->txtDronBateria->ReadOnly = true;
			this->txtDronBateria->Size = System::Drawing::Size(80, 19);
			this->txtDronBateria->TabIndex = 59;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdDesecho,
					this->IdCoordX, this->CoordY
			});
			this->dataGridView1->Location = System::Drawing::Point(910, 13);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(168, 274);
			this->dataGridView1->TabIndex = 58;
			// 
			// IdDesecho
			// 
			this->IdDesecho->HeaderText = L"Id";
			this->IdDesecho->MinimumWidth = 6;
			this->IdDesecho->Name = L"IdDesecho";
			this->IdDesecho->Width = 50;
			// 
			// IdCoordX
			// 
			this->IdCoordX->HeaderText = L"X";
			this->IdCoordX->MinimumWidth = 6;
			this->IdCoordX->Name = L"IdCoordX";
			this->IdCoordX->Width = 50;
			// 
			// CoordY
			// 
			this->CoordY->HeaderText = L"Y";
			this->CoordY->MinimumWidth = 6;
			this->CoordY->Name = L"CoordY";
			this->CoordY->Width = 50;
			// 
			// cmbIdDron
			// 
			this->cmbIdDron->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIdDron->FormattingEnabled = true;
			this->cmbIdDron->Location = System::Drawing::Point(717, 333);
			this->cmbIdDron->Margin = System::Windows::Forms::Padding(2);
			this->cmbIdDron->Name = L"cmbIdDron";
			this->cmbIdDron->Size = System::Drawing::Size(38, 21);
			this->cmbIdDron->TabIndex = 53;
			// 
			// btnValidarDron
			// 
			this->btnValidarDron->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarDron->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarDron.Image")));
			this->btnValidarDron->Location = System::Drawing::Point(718, 358);
			this->btnValidarDron->Margin = System::Windows::Forms::Padding(2);
			this->btnValidarDron->Name = L"btnValidarDron";
			this->btnValidarDron->Size = System::Drawing::Size(38, 41);
			this->btnValidarDron->TabIndex = 50;
			this->btnValidarDron->UseVisualStyleBackColor = true;
			this->btnValidarDron->Click += gcnew System::EventHandler(this, &MyWindowMain::btnValidarDron_Click);
			// 
			// btnAumentarContenedor
			// 
			this->btnAumentarContenedor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAumentarContenedor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAumentarContenedor.Image")));
			this->btnAumentarContenedor->Location = System::Drawing::Point(718, 583);
			this->btnAumentarContenedor->Margin = System::Windows::Forms::Padding(2);
			this->btnAumentarContenedor->Name = L"btnAumentarContenedor";
			this->btnAumentarContenedor->Size = System::Drawing::Size(38, 41);
			this->btnAumentarContenedor->TabIndex = 49;
			this->btnAumentarContenedor->UseVisualStyleBackColor = true;
			// 
			// btnAsignarBarcos
			// 
			this->btnAsignarBarcos->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarBarcos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarBarcos.Image")));
			this->btnAsignarBarcos->Location = System::Drawing::Point(807, 440);
			this->btnAsignarBarcos->Margin = System::Windows::Forms::Padding(2);
			this->btnAsignarBarcos->Name = L"btnAsignarBarcos";
			this->btnAsignarBarcos->Size = System::Drawing::Size(38, 41);
			this->btnAsignarBarcos->TabIndex = 48;
			this->btnAsignarBarcos->UseVisualStyleBackColor = true;
			this->btnAsignarBarcos->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAsignarBarcos_Click);
			// 
			// btnAsignarCamion
			// 
			this->btnAsignarCamion->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarCamion.Image")));
			this->btnAsignarCamion->Location = System::Drawing::Point(808, 524);
			this->btnAsignarCamion->Margin = System::Windows::Forms::Padding(2);
			this->btnAsignarCamion->Name = L"btnAsignarCamion";
			this->btnAsignarCamion->Size = System::Drawing::Size(38, 41);
			this->btnAsignarCamion->TabIndex = 47;
			this->btnAsignarCamion->UseVisualStyleBackColor = true;
			this->btnAsignarCamion->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAsignarCamion_Click);
			// 
			// btnAsignarDron
			// 
			this->btnAsignarDron->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarDron->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarDron.Image")));
			this->btnAsignarDron->Location = System::Drawing::Point(807, 358);
			this->btnAsignarDron->Margin = System::Windows::Forms::Padding(2);
			this->btnAsignarDron->Name = L"btnAsignarDron";
			this->btnAsignarDron->Size = System::Drawing::Size(38, 41);
			this->btnAsignarDron->TabIndex = 46;
			this->btnAsignarDron->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(712, 119);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(188, 13);
			this->label13->TabIndex = 45;
			this->label13->Text = L"ENCARGADO POR CADA PROCESO";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(712, 252);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(63, 13);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Tratamiento";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(712, 214);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(58, 13);
			this->label11->TabIndex = 43;
			this->label11->Text = L"Transporte";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(712, 177);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 42;
			this->label10->Text = L"Recolección";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(712, 140);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 41;
			this->label9->Text = L"Escaneo";
			// 
			// cmb4Encargado
			// 
			this->cmb4Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb4Encargado->FormattingEnabled = true;
			this->cmb4Encargado->Location = System::Drawing::Point(716, 267);
			this->cmb4Encargado->Margin = System::Windows::Forms::Padding(2);
			this->cmb4Encargado->Name = L"cmb4Encargado";
			this->cmb4Encargado->Size = System::Drawing::Size(176, 21);
			this->cmb4Encargado->TabIndex = 40;
			// 
			// cmb3Encargado
			// 
			this->cmb3Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb3Encargado->FormattingEnabled = true;
			this->cmb3Encargado->Location = System::Drawing::Point(715, 230);
			this->cmb3Encargado->Margin = System::Windows::Forms::Padding(2);
			this->cmb3Encargado->Name = L"cmb3Encargado";
			this->cmb3Encargado->Size = System::Drawing::Size(176, 21);
			this->cmb3Encargado->TabIndex = 39;
			// 
			// cmb2Encargado
			// 
			this->cmb2Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb2Encargado->FormattingEnabled = true;
			this->cmb2Encargado->Location = System::Drawing::Point(715, 193);
			this->cmb2Encargado->Margin = System::Windows::Forms::Padding(2);
			this->cmb2Encargado->Name = L"cmb2Encargado";
			this->cmb2Encargado->Size = System::Drawing::Size(176, 21);
			this->cmb2Encargado->TabIndex = 38;
			// 
			// cmb1Encargado
			// 
			this->cmb1Encargado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb1Encargado->FormattingEnabled = true;
			this->cmb1Encargado->Location = System::Drawing::Point(715, 155);
			this->cmb1Encargado->Margin = System::Windows::Forms::Padding(2);
			this->cmb1Encargado->Name = L"cmb1Encargado";
			this->cmb1Encargado->Size = System::Drawing::Size(176, 21);
			this->cmb1Encargado->TabIndex = 37;
			// 
			// btnCursor
			// 
			this->btnCursor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnCursor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCursor.Image")));
			this->btnCursor->Location = System::Drawing::Point(715, 12);
			this->btnCursor->Margin = System::Windows::Forms::Padding(2);
			this->btnCursor->Name = L"btnCursor";
			this->btnCursor->Size = System::Drawing::Size(40, 44);
			this->btnCursor->TabIndex = 35;
			this->btnCursor->UseVisualStyleBackColor = true;
			this->btnCursor->Click += gcnew System::EventHandler(this, &MyWindowMain::btnCursor_Click);
			// 
			// btnAreaAnalisis
			// 
			this->btnAreaAnalisis->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAreaAnalisis->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAreaAnalisis.Image")));
			this->btnAreaAnalisis->Location = System::Drawing::Point(715, 64);
			this->btnAreaAnalisis->Margin = System::Windows::Forms::Padding(2);
			this->btnAreaAnalisis->Name = L"btnAreaAnalisis";
			this->btnAreaAnalisis->Size = System::Drawing::Size(40, 44);
			this->btnAreaAnalisis->TabIndex = 34;
			this->btnAreaAnalisis->UseVisualStyleBackColor = true;
			this->btnAreaAnalisis->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAreaAnalisis_Click);
			this->btnAreaAnalisis->MouseHover += gcnew System::EventHandler(this, &MyWindowMain::button1_MouseHover);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->cbCamara);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->videoCamara);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->detener_proceso);
			this->tabPage2->Controls->Add(this->iniciar_proceso);
			this->tabPage2->Controls->Add(this->desechogrid);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(1088, 630);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Simulación separador de desecho";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// cbCamara
			// 
			this->cbCamara->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbCamara->FormattingEnabled = true;
			this->cbCamara->Location = System::Drawing::Point(176, 48);
			this->cbCamara->Margin = System::Windows::Forms::Padding(2);
			this->cbCamara->Name = L"cbCamara";
			this->cbCamara->Size = System::Drawing::Size(205, 21);
			this->cbCamara->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(34, 51);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 17);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Seleccionar cámara: ";
			// 
			// videoCamara
			// 
			this->videoCamara->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->videoCamara->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->videoCamara->Location = System::Drawing::Point(15, 174);
			this->videoCamara->Margin = System::Windows::Forms::Padding(2);
			this->videoCamara->Name = L"videoCamara";
			this->videoCamara->Size = System::Drawing::Size(482, 284);
			this->videoCamara->TabIndex = 13;
			this->videoCamara->TabStop = false;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(583, 30);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(244, 20);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Cantidad detectada por el sensor";
			// 
			// detener_proceso
			// 
			this->detener_proceso->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->detener_proceso->Location = System::Drawing::Point(729, 82);
			this->detener_proceso->Margin = System::Windows::Forms::Padding(2);
			this->detener_proceso->Name = L"detener_proceso";
			this->detener_proceso->Size = System::Drawing::Size(131, 28);
			this->detener_proceso->TabIndex = 11;
			this->detener_proceso->Text = L"DETENER PROCESO";
			this->detener_proceso->UseVisualStyleBackColor = true;
			// 
			// iniciar_proceso
			// 
			this->iniciar_proceso->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->iniciar_proceso->Location = System::Drawing::Point(557, 82);
			this->iniciar_proceso->Margin = System::Windows::Forms::Padding(2);
			this->iniciar_proceso->Name = L"iniciar_proceso";
			this->iniciar_proceso->Size = System::Drawing::Size(131, 28);
			this->iniciar_proceso->TabIndex = 10;
			this->iniciar_proceso->Text = L"INICIAR PROCESO";
			this->iniciar_proceso->UseVisualStyleBackColor = true;
			this->iniciar_proceso->Click += gcnew System::EventHandler(this, &MyWindowMain::iniciar_proceso_Click);
			// 
			// desechogrid
			// 
			this->desechogrid->AllowUserToDeleteRows = false;
			this->desechogrid->AllowUserToResizeColumns = false;
			this->desechogrid->AllowUserToResizeRows = false;
			this->desechogrid->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->desechogrid->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->desechogrid->ColumnHeadersHeight = 60;
			this->desechogrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->desechogrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->plasticobox,
					this->cartonbox, this->vidriobox, this->otrosbox
			});
			this->desechogrid->Location = System::Drawing::Point(512, 133);
			this->desechogrid->Margin = System::Windows::Forms::Padding(2);
			this->desechogrid->Name = L"desechogrid";
			this->desechogrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->desechogrid->RowHeadersVisible = false;
			this->desechogrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->desechogrid->RowTemplate->DividerHeight = 10;
			this->desechogrid->RowTemplate->Height = 90;
			this->desechogrid->RowTemplate->ReadOnly = true;
			this->desechogrid->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->desechogrid->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->desechogrid->Size = System::Drawing::Size(380, 477);
			this->desechogrid->TabIndex = 9;
			this->desechogrid->VirtualMode = true;
			// 
			// plasticobox
			// 
			this->plasticobox->HeaderText = L"PLÁSTICO";
			this->plasticobox->MinimumWidth = 100;
			this->plasticobox->Name = L"plasticobox";
			this->plasticobox->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->plasticobox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->plasticobox->Width = 125;
			// 
			// cartonbox
			// 
			this->cartonbox->HeaderText = L"CARTÓN";
			this->cartonbox->MinimumWidth = 100;
			this->cartonbox->Name = L"cartonbox";
			this->cartonbox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->cartonbox->Width = 125;
			// 
			// vidriobox
			// 
			this->vidriobox->HeaderText = L"VIDRIO";
			this->vidriobox->MinimumWidth = 100;
			this->vidriobox->Name = L"vidriobox";
			this->vidriobox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->vidriobox->Width = 125;
			// 
			// otrosbox
			// 
			this->otrosbox->HeaderText = L"OTROS";
			this->otrosbox->MinimumWidth = 100;
			this->otrosbox->Name = L"otrosbox";
			this->otrosbox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->otrosbox->Width = 125;
			// 
			// toolTip1
			// 
			this->toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyWindowMain::toolTip1_Popup);
			// 
			// btnPruebas2
			// 
<<<<<<< HEAD
			this->btnPruebas2->Location = System::Drawing::Point(799, 130);
			this->btnPruebas2->Name = L"btnPruebas2";
			this->btnPruebas2->Size = System::Drawing::Size(33, 23);
=======
			this->btnPruebas2->Location = System::Drawing::Point(819, 130);
			this->btnPruebas2->Name = L"btnPruebas2";
			this->btnPruebas2->Size = System::Drawing::Size(30, 23);
>>>>>>> AA
			this->btnPruebas2->TabIndex = 84;
			this->btnPruebas2->Text = L"P2";
			this->btnPruebas2->UseVisualStyleBackColor = true;
			this->btnPruebas2->Click += gcnew System::EventHandler(this, &MyWindowMain::btnPruebas2_Click);
			// 
			// MyWindowMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 693);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip2;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyWindowMain";
			this->Text = L"Simulador para la gestión de basura marina";
			this->Load += gcnew System::EventHandler(this, &MyWindowMain::MyWindowMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyWindowMain::MyWindowMain_KeyDown);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MapaWeb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamionesAsignados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcosAsignados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoCamara))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->desechogrid))->EndInit();
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
					dynamic_cast<ComboBox^>(control)->SelectedIndex = -1; // Reiniciar el ComboBox para que no haya selección
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
				// Filtrar y añadir a ComboBox1 (Escaneo)
				for each (Encargado ^ encargado in _encargadoList) {
					if (encargado->Cargo == "Escaneo") {
						cmb1Encargado->Items->Add(encargado);
					}
					else if (encargado->Cargo == "Recolección") {
						cmb2Encargado->Items->Add(encargado);
					}
					else if (encargado->Cargo == "Transporte") {
						cmb3Encargado->Items->Add(encargado);
					}
					else {
						cmb4Encargado->Items->Add(encargado);
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


	private: System::Void salirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
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

		   //DECLARAR OBJETOS:
		   List<Desecho^>^ _desecho = gcnew List<Desecho^>();
	private: Area^ _area = gcnew Area();
		   bool IniciarProceso = false;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//GENERA RUTA DEL CAMION
		System::String^ origin = "{ lat: -12.053763093969444, lng: -77.14634104154212}";
		System::String^ destination = "{ lat: -12.069060413055682, lng: -77.07815928837975 }";
		this->MapaWeb->CoreWebView2->ExecuteScriptAsync("calculateAndDisplayRoute(" + origin + ", " + destination + ");");

		IniciarProceso = true;
		try {
			// Crear una instancia de Random
			Random^ rand = gcnew Random();

			// Limpiar los puntos existentes
			_desecho->Clear();

			// Generar 800 puntos en coordenadas aleatorias
			for (int i = 0; i < 800; i++) {
				int x = rand->Next(0, pictureBox1->Width);   // Coordenada X aleatoria
				int y = rand->Next(0, pictureBox1->Height);  // Coordenada Y aleatoria
				Desecho^ d = gcnew Desecho(1.2, "Botella de plastico", x, y);
				_desecho->Add(d); // Agregar el punto a la lista
			}

			// Volver a dibujar el PictureBox
			pictureBox1->Invalidate(); // Esto forzará el redibujo del PictureBox
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnGenerarArea_Click(System::Object^ sender, System::EventArgs^ e) {
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

	private: System::Void iniciar_proceso_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		Point startPoint;  // Punto inicial del rectángulo
		Point endPoint;    // Punto final del rectángulo
		bool isDrawing = false;  // Indica si se está dibujando
		bool GenerarAreaPresionado = false; // Indica si se ha hecho clic en el botón
		float rotationAngle = 0; // Ángulo de rotación para el rectángulo

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (GenerarAreaPresionado) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				startPoint = e->Location; // Capturar el punto inicial al hacer clic
				isDrawing = true;         // Activar la bandera de dibujo
			}
		}
	}

	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (GenerarAreaPresionado) {
			if (isDrawing) {
				endPoint = e->Location;   // Actualizar el punto final mientras el mouse se mueve
				pictureBox1->Invalidate(); // Redibujar el PictureBox en cada movimiento
			}
		}
	}

	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (GenerarAreaPresionado) {
			if (isDrawing) {
				endPoint = e->Location;   // Capturar el punto final al soltar el botón
				isDrawing = false;        // Terminar el dibujo
				// Calcular ancho y largo
				int ancho = Math::Abs(endPoint.X - startPoint.X);
				int largo = Math::Abs(endPoint.Y - startPoint.Y);

				// Guardar las dimensiones en los TextBox
				txtAreaAncho->Text = ancho.ToString();
				txtAreaLargo->Text = largo.ToString();
				pictureBox1->Invalidate(); // Forzar el redibujo del PictureBox para mostrar el rectángulo final
			}
		}
	}


	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		if (IniciarProceso) {
			Graphics^ g = e->Graphics;
			Graphics^ f = e->Graphics;
			Pen^ pen = gcnew Pen(Color::Red);
			Pen^ area = gcnew Pen(Color::Red, 2);

			if (_area != nullptr) {
				f->DrawRectangle(area,
					Convert::ToInt32(_area->X - _area->Ancho / 2),
					Convert::ToInt32(_area->Y - _area->Largo / 2),
					Convert::ToInt32(_area->Ancho),
					Convert::ToInt32(_area->Largo));
			}

			for each (Desecho ^ d in _desecho) {
				// Dibuja la coordenada del Desecho
				if (d->Posicion != nullptr) {  // Verificar que la posición no sea nula
					Coordenadas^ coord = d->Posicion; // Acceder directamente a la posición
					g->DrawEllipse(pen, static_cast<int>(coord->X), static_cast<int>(coord->Y), 5, 5);
					// Dibuja un punto de tamaño 5x5
				}
			}
		}

		if (GenerarAreaPresionado) {
			if (startPoint != endPoint) {  // Solo dibuja si los puntos son diferentes
				Graphics^ g = e->Graphics;
				Pen^ pen = gcnew Pen(Color::Black, 2); // Color rojo y grosor de 4 píxeles

				// Calcular las coordenadas del rectángulo
				int x = Math::Min(startPoint.X, endPoint.X);
				int y = Math::Min(startPoint.Y, endPoint.Y);
				int width = Math::Abs(startPoint.X - endPoint.X);
				int height = Math::Abs(startPoint.Y - endPoint.Y);

				// Mover el origen de coordenadas al centro del rectángulo
				g->TranslateTransform(x + width / 2.0f, y + height / 2.0f);

				// Aplicar la rotación
				g->RotateTransform(rotationAngle);

				// Dibujar el rectángulo con el centro en el nuevo origen
				g->DrawRectangle(pen, -width / 2, -height / 2, width, height);

				// Restaurar la transformación para futuras operaciones
				g->ResetTransform();

			}
		}

	}


	private: System::Void MyWindowMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (GenerarAreaPresionado) {
			if (e->KeyCode == Keys::R) {
				rotationAngle += 15;  // Incrementar el ángulo de rotación en 15 grados
				if (rotationAngle >= 360) {
					rotationAngle = 0;  // Reiniciar el ángulo si alcanza los 360 grados
				}
				pictureBox1->Invalidate();  // Redibujar el PictureBox con la nueva rotación
			}
		}
	}

	private: System::Void button1_MouseHover(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void toolTip1_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {

	}
	private: System::Void btnAreaAnalisis_Click(System::Object^ sender, System::EventArgs^ e) {
		GenerarAreaPresionado = true;
		// Define las coordenadas para las esquinas del rect�ngulo
		double lat1 = -12.07488;
		double lng1 = -77.155983;
		double lat2 = -12.07588;
		double lng2 = -77.156983;

		// Genera el script en JavaScript para dibujar el rect�ngulo
		String^ script = String::Format("dibujarRectangulo({0}, {1}, {2}, {3});", lat2, lng2, lat1, lng1);

		// Ejecuta el script en WebView2
		MapaWeb->CoreWebView2->ExecuteScriptAsync(script);
	}
	private: System::Void btnCursor_Click(System::Object^ sender, System::EventArgs^ e) {
		GenerarAreaPresionado = false;
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
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

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
	MapaWeb->ExecuteScriptAsync("generarPuntoAleatorio();");
}
private: System::Void btnPruebas2_Click(System::Object^ sender, System::EventArgs^ e) {
<<<<<<< HEAD
	MapaWeb->ExecuteScriptAsync("borrarPuntos();");
=======
	MapaWeb->ExecuteScriptAsync("eliminarPuntos();");
}
};
>>>>>>> AA
}
};
}