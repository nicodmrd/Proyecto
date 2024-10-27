#pragma once

#include "EncargadosForm.h"
#include "DronForm.h"
#include "CamionesForm.h"
#include "BarcoForm.h"
#include "ContenedorForm.h"
#include "ComboBoxItem.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;
	using namespace System::Collections::Generic;
	using namespace SimuladorService;

	/// <summary>
	/// Resumen de MyWindowMain
	/// </summary>
	public ref class MyWindowMain : public System::Windows::Forms::Form
	{
	public:
		MyWindowMain(void)
		{
			InitializeComponent();
			LoadImage();

			//
			//TODO: agregar código de constructor aquí
			//
			toolTip1 = gcnew ToolTip();
			toolTip2 = gcnew ToolTip();
			toolTip3 = gcnew ToolTip();
			toolTip4 = gcnew ToolTip();

			toolTip1->SetToolTip(btnAreaAnalisis, "Realizar área de análisis");
			toolTip2->SetToolTip(btnReiniciar, "Reiniciar simulación");
			toolTip3->SetToolTip(btnDetener, "Detener simulación");
			toolTip4->SetToolTip(btnIniciar, "Iniciar simulación");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyWindowMain()
		{
			if (components)
			{
				delete components;
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


	private: System::Windows::Forms::TextBox^ txtAreaY;
	private: System::Windows::Forms::TextBox^ txtAreaX;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnGenerarArea;
	private: System::Windows::Forms::Label^ label1;





	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnReiniciar;

	private: System::Windows::Forms::Button^ btnDetener;

	private: System::Windows::Forms::Button^ btnIniciar;


	private: System::Windows::Forms::ToolStripMenuItem^ contenedoresToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cmb4Encargado;

	private: System::Windows::Forms::ComboBox^ cmb3Encargado;

	private: System::Windows::Forms::ComboBox^ cmb2Encargado;

	private: System::Windows::Forms::ComboBox^ cmb1Encargado;

	private: System::Windows::Forms::Button^ btnAgregarContenedor;
	private: System::Windows::Forms::Button^ btnAsignarBarcos;
	private: System::Windows::Forms::Button^ btnAsignarCamion;


	private: System::Windows::Forms::Button^ btnAsignarDron;



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
			this->txtAreaY = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnGenerarArea = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->btnDetener = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnAgregarContenedor = (gcnew System::Windows::Forms::Button());
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnCursor = (gcnew System::Windows::Forms::Button());
			this->btnAreaAnalisis = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
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
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->menuStrip2->Size = System::Drawing::Size(1232, 28);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			this->menuStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyWindowMain::menuStrip1_ItemClicked);
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->salirToolStripMenuItem });
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(121, 26);
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
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->mantenimientoToolStripMenuItem->Text = L"Mantenimiento";
			// 
			// encargadosToolStripMenuItem
			// 
			this->encargadosToolStripMenuItem->Name = L"encargadosToolStripMenuItem";
			this->encargadosToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->encargadosToolStripMenuItem->Text = L"Encargados";
			this->encargadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::encargadosToolStripMenuItem_Click);
			// 
			// barcosToolStripMenuItem
			// 
			this->barcosToolStripMenuItem->Name = L"barcosToolStripMenuItem";
			this->barcosToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->barcosToolStripMenuItem->Text = L"Barcos";
			this->barcosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::barcosToolStripMenuItem_Click);
			// 
			// dronToolStripMenuItem
			// 
			this->dronToolStripMenuItem->Name = L"dronToolStripMenuItem";
			this->dronToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->dronToolStripMenuItem->Text = L"Dron";
			this->dronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::dronToolStripMenuItem_Click);
			// 
			// camionesToolStripMenuItem
			// 
			this->camionesToolStripMenuItem->Name = L"camionesToolStripMenuItem";
			this->camionesToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->camionesToolStripMenuItem->Text = L"Camiones";
			this->camionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::camionesToolStripMenuItem_Click);
			// 
			// contenedoresToolStripMenuItem
			// 
			this->contenedoresToolStripMenuItem->Name = L"contenedoresToolStripMenuItem";
			this->contenedoresToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->contenedoresToolStripMenuItem->Text = L"Contenedores";
			this->contenedoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyWindowMain::contenedoresToolStripMenuItem_Click);
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->guíaDelSoftwareToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// guíaDelSoftwareToolStripMenuItem
			// 
			this->guíaDelSoftwareToolStripMenuItem->Name = L"guíaDelSoftwareToolStripMenuItem";
			this->guíaDelSoftwareToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->guíaDelSoftwareToolStripMenuItem->Text = L"Guía del software";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->integrantesToolStripMenuItem,
					this->informaciónDelProyectoToolStripMenuItem
			});
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			this->acercaDeToolStripMenuItem->Size = System::Drawing::Size(89, 24);
			this->acercaDeToolStripMenuItem->Text = L"Acerca de";
			// 
			// integrantesToolStripMenuItem
			// 
			this->integrantesToolStripMenuItem->Name = L"integrantesToolStripMenuItem";
			this->integrantesToolStripMenuItem->Size = System::Drawing::Size(260, 26);
			this->integrantesToolStripMenuItem->Text = L"Integrantes";
			// 
			// informaciónDelProyectoToolStripMenuItem
			// 
			this->informaciónDelProyectoToolStripMenuItem->Name = L"informaciónDelProyectoToolStripMenuItem";
			this->informaciónDelProyectoToolStripMenuItem->Size = System::Drawing::Size(260, 26);
			this->informaciónDelProyectoToolStripMenuItem->Text = L"Información del proyecto";
			// 
			// txtAreaLargo
			// 
			this->txtAreaLargo->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaLargo->Location = System::Drawing::Point(1008, 128);
			this->txtAreaLargo->Name = L"txtAreaLargo";
			this->txtAreaLargo->Size = System::Drawing::Size(100, 22);
			this->txtAreaLargo->TabIndex = 33;
			// 
			// txtAreaAncho
			// 
			this->txtAreaAncho->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaAncho->Location = System::Drawing::Point(1008, 98);
			this->txtAreaAncho->Name = L"txtAreaAncho";
			this->txtAreaAncho->Size = System::Drawing::Size(100, 22);
			this->txtAreaAncho->TabIndex = 32;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(949, 131);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 16);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Largo";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(945, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 16);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Ancho";
			// 
			// txtAreaY
			// 
			this->txtAreaY->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaY->Location = System::Drawing::Point(839, 128);
			this->txtAreaY->Name = L"txtAreaY";
			this->txtAreaY->Size = System::Drawing::Size(100, 22);
			this->txtAreaY->TabIndex = 27;
			// 
			// txtAreaX
			// 
			this->txtAreaX->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaX->Location = System::Drawing::Point(839, 98);
			this->txtAreaX->Name = L"txtAreaX";
			this->txtAreaX->Size = System::Drawing::Size(100, 22);
			this->txtAreaX->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(804, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 16);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Cy";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(804, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 16);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Cx";
			// 
			// btnGenerarArea
			// 
			this->btnGenerarArea->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnGenerarArea->Location = System::Drawing::Point(893, 174);
			this->btnGenerarArea->Name = L"btnGenerarArea";
			this->btnGenerarArea->Size = System::Drawing::Size(134, 38);
			this->btnGenerarArea->TabIndex = 23;
			this->btnGenerarArea->Text = L"Generar Área";
			this->btnGenerarArea->UseVisualStyleBackColor = true;
			this->btnGenerarArea->Click += gcnew System::EventHandler(this, &MyWindowMain::btnGenerarArea_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(888, -17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 16);
			this->label1->TabIndex = 22;
			this->label1->Text = L"INGRESE DATOS PARA LA SIMULACIÓN";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(9, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(767, 771);
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
			this->btnReiniciar->Location = System::Drawing::Point(934, 21);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(54, 54);
			this->btnReiniciar->TabIndex = 19;
			this->btnReiniciar->UseVisualStyleBackColor = true;
			// 
			// btnDetener
			// 
			this->btnDetener->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnDetener->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDetener.Image")));
			this->btnDetener->Location = System::Drawing::Point(874, 21);
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->Size = System::Drawing::Size(54, 54);
			this->btnDetener->TabIndex = 18;
			this->btnDetener->UseVisualStyleBackColor = true;
			// 
			// btnIniciar
			// 
			this->btnIniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnIniciar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciar.Image")));
			this->btnIniciar->Location = System::Drawing::Point(809, 21);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(54, 54);
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
			this->tabControl1->Location = System::Drawing::Point(12, 31);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1212, 812);
			this->tabControl1->TabIndex = 35;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->btnAgregarContenedor);
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
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->btnCursor);
			this->tabPage1->Controls->Add(this->btnAreaAnalisis);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->txtAreaLargo);
			this->tabPage1->Controls->Add(this->btnReiniciar);
			this->tabPage1->Controls->Add(this->txtAreaAncho);
			this->tabPage1->Controls->Add(this->btnDetener);
			this->tabPage1->Controls->Add(this->btnIniciar);
			this->tabPage1->Controls->Add(this->btnGenerarArea);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->txtAreaX);
			this->tabPage1->Controls->Add(this->txtAreaY);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1204, 783);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Simulación para cada proceso";
			// 
			// btnAgregarContenedor
			// 
			this->btnAgregarContenedor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAgregarContenedor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAgregarContenedor.Image")));
			this->btnAgregarContenedor->Location = System::Drawing::Point(810, 628);
			this->btnAgregarContenedor->Name = L"btnAgregarContenedor";
			this->btnAgregarContenedor->Size = System::Drawing::Size(54, 54);
			this->btnAgregarContenedor->TabIndex = 49;
			this->btnAgregarContenedor->UseVisualStyleBackColor = true;
			// 
			// btnAsignarBarcos
			// 
			this->btnAsignarBarcos->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarBarcos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarBarcos.Image")));
			this->btnAsignarBarcos->Location = System::Drawing::Point(811, 508);
			this->btnAsignarBarcos->Name = L"btnAsignarBarcos";
			this->btnAsignarBarcos->Size = System::Drawing::Size(54, 54);
			this->btnAsignarBarcos->TabIndex = 48;
			this->btnAsignarBarcos->UseVisualStyleBackColor = true;
			// 
			// btnAsignarCamion
			// 
			this->btnAsignarCamion->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarCamion.Image")));
			this->btnAsignarCamion->Location = System::Drawing::Point(811, 568);
			this->btnAsignarCamion->Name = L"btnAsignarCamion";
			this->btnAsignarCamion->Size = System::Drawing::Size(54, 54);
			this->btnAsignarCamion->TabIndex = 47;
			this->btnAsignarCamion->UseVisualStyleBackColor = true;
			// 
			// btnAsignarDron
			// 
			this->btnAsignarDron->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarDron->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarDron.Image")));
			this->btnAsignarDron->Location = System::Drawing::Point(811, 448);
			this->btnAsignarDron->Name = L"btnAsignarDron";
			this->btnAsignarDron->Size = System::Drawing::Size(54, 54);
			this->btnAsignarDron->TabIndex = 46;
			this->btnAsignarDron->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(804, 226);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(242, 16);
			this->label13->TabIndex = 45;
			this->label13->Text = L"ENCARGADO POR PROCESO (ÁREA)";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(807, 365);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(79, 16);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Tratamiento";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(804, 331);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(73, 16);
			this->label11->TabIndex = 43;
			this->label11->Text = L"Transporte";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(805, 297);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(83, 16);
			this->label10->TabIndex = 42;
			this->label10->Text = L"Recolección";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(804, 263);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 16);
			this->label9->TabIndex = 41;
			this->label9->Text = L"Escaneo";
			// 
			// cmb4Encargado
			// 
			this->cmb4Encargado->FormattingEnabled = true;
			this->cmb4Encargado->Location = System::Drawing::Point(912, 357);
			this->cmb4Encargado->Name = L"cmb4Encargado";
			this->cmb4Encargado->Size = System::Drawing::Size(200, 24);
			this->cmb4Encargado->TabIndex = 40;
			// 
			// cmb3Encargado
			// 
			this->cmb3Encargado->FormattingEnabled = true;
			this->cmb3Encargado->Location = System::Drawing::Point(912, 323);
			this->cmb3Encargado->Name = L"cmb3Encargado";
			this->cmb3Encargado->Size = System::Drawing::Size(200, 24);
			this->cmb3Encargado->TabIndex = 39;
			// 
			// cmb2Encargado
			// 
			this->cmb2Encargado->FormattingEnabled = true;
			this->cmb2Encargado->Location = System::Drawing::Point(912, 289);
			this->cmb2Encargado->Name = L"cmb2Encargado";
			this->cmb2Encargado->Size = System::Drawing::Size(200, 24);
			this->cmb2Encargado->TabIndex = 38;
			// 
			// cmb1Encargado
			// 
			this->cmb1Encargado->FormattingEnabled = true;
			this->cmb1Encargado->Location = System::Drawing::Point(912, 255);
			this->cmb1Encargado->Name = L"cmb1Encargado";
			this->cmb1Encargado->Size = System::Drawing::Size(200, 24);
			this->cmb1Encargado->TabIndex = 37;
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(1127, 278);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(54, 54);
			this->button1->TabIndex = 36;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// btnCursor
			// 
			this->btnCursor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnCursor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCursor.Image")));
			this->btnCursor->Location = System::Drawing::Point(1054, 21);
			this->btnCursor->Name = L"btnCursor";
			this->btnCursor->Size = System::Drawing::Size(54, 54);
			this->btnCursor->TabIndex = 35;
			this->btnCursor->UseVisualStyleBackColor = true;
			this->btnCursor->Click += gcnew System::EventHandler(this, &MyWindowMain::btnCursor_Click);
			// 
			// btnAreaAnalisis
			// 
			this->btnAreaAnalisis->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAreaAnalisis->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAreaAnalisis.Image")));
			this->btnAreaAnalisis->Location = System::Drawing::Point(994, 21);
			this->btnAreaAnalisis->Name = L"btnAreaAnalisis";
			this->btnAreaAnalisis->Size = System::Drawing::Size(54, 54);
			this->btnAreaAnalisis->TabIndex = 34;
			this->btnAreaAnalisis->UseVisualStyleBackColor = true;
			this->btnAreaAnalisis->Click += gcnew System::EventHandler(this, &MyWindowMain::btnAreaAnalisis_Click);
			this->btnAreaAnalisis->MouseHover += gcnew System::EventHandler(this, &MyWindowMain::button1_MouseHover);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->detener_proceso);
			this->tabPage2->Controls->Add(this->iniciar_proceso);
			this->tabPage2->Controls->Add(this->desechogrid);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1204, 783);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Simulación separador de desecho";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(20, 214);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(642, 349);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(777, 37);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(299, 25);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Cantidad detectada por el sensor";
			// 
			// detener_proceso
			// 
			this->detener_proceso->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->detener_proceso->Location = System::Drawing::Point(972, 101);
			this->detener_proceso->Name = L"detener_proceso";
			this->detener_proceso->Size = System::Drawing::Size(175, 35);
			this->detener_proceso->TabIndex = 11;
			this->detener_proceso->Text = L"DETENER PROCESO";
			this->detener_proceso->UseVisualStyleBackColor = true;
			// 
			// iniciar_proceso
			// 
			this->iniciar_proceso->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->iniciar_proceso->Location = System::Drawing::Point(743, 101);
			this->iniciar_proceso->Name = L"iniciar_proceso";
			this->iniciar_proceso->Size = System::Drawing::Size(175, 35);
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
			this->desechogrid->Location = System::Drawing::Point(683, 164);
			this->desechogrid->Name = L"desechogrid";
			this->desechogrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->desechogrid->RowHeadersVisible = false;
			this->desechogrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->desechogrid->RowTemplate->DividerHeight = 10;
			this->desechogrid->RowTemplate->Height = 90;
			this->desechogrid->RowTemplate->ReadOnly = true;
			this->desechogrid->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->desechogrid->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->desechogrid->Size = System::Drawing::Size(506, 587);
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
			// MyWindowMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 857);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->IsMdiContainer = true;
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip2;
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
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->desechogrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//METODOS

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

		if (_area == nullptr) {
			_area = gcnew Area();
		}
		_area->X = Convert::ToDouble(txtAreaX->Text);
		_area->Y = Convert::ToDouble(txtAreaY->Text);
		_area->Ancho = Convert::ToDouble(txtAreaAncho->Text);
		_area->Largo = Convert::ToDouble(txtAreaLargo->Text);
		pictureBox1->Invalidate();
	}
	private: System::Void MyWindowMain_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarEncargados();


	}
	private: System::Void contenedoresToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ContenedorForm^ form = gcnew ContenedorForm();
		form->ShowDialog(); // Mostrar el formulario de forma modal
	}

	private: System::Void iniciar_proceso_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		try {
			String^ result;
			String^ protocol = "UART";
			if (Service::protocolDictionary->ContainsKey(protocol)) {
				result = Service::TiposDesechosSistema(Service::protocolDictionary[protocol], cant1, cant2, cant3, cant4);
			}
			if (result == nullptr || result->Equals("")) {
				MessageBox::Show("No se ha logrado realizar el envío");
			}
			else {
				MessageBox::Show(result);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ha ocurrido un problema: " + ex->Message);
		}
		*/
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
	}
	private: System::Void btnCursor_Click(System::Object^ sender, System::EventArgs^ e) {
		GenerarAreaPresionado = false;
	}
	};
}
