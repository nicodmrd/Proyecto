#pragma once

#include "EncargadosForm.h"
#include "DronForm.h"
#include "CamionesForm.h"
#include "BarcoForm.h"
#include "ContenedorForm.h"

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
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
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



	private: System::Windows::Forms::ToolStripMenuItem^ camionesToolStripMenuItem;

		   void LoadImage()
		   {
			   Mapa^ mapa = gcnew Mapa();

			   // Cargar la imagen desde una ruta relativa
			   pictureBox1->Image = Image::FromFile(mapa->Imagen);
			   pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox

		   }
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->txtAreaLargo->Location = System::Drawing::Point(996, 301);
			this->txtAreaLargo->Name = L"txtAreaLargo";
			this->txtAreaLargo->Size = System::Drawing::Size(100, 27);
			this->txtAreaLargo->TabIndex = 33;
			// 
			// txtAreaAncho
			// 
			this->txtAreaAncho->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaAncho->Location = System::Drawing::Point(996, 246);
			this->txtAreaAncho->Name = L"txtAreaAncho";
			this->txtAreaAncho->Size = System::Drawing::Size(100, 27);
			this->txtAreaAncho->TabIndex = 32;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(896, 308);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 20);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Largo";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(896, 253);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 20);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Ancho";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(896, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 20);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Dimensiones";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(884, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(282, 20);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Coordenadas (centro del rectangulo)";
			// 
			// txtAreaY
			// 
			this->txtAreaY->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaY->Location = System::Drawing::Point(996, 144);
			this->txtAreaY->Name = L"txtAreaY";
			this->txtAreaY->Size = System::Drawing::Size(100, 27);
			this->txtAreaY->TabIndex = 27;
			// 
			// txtAreaX
			// 
			this->txtAreaX->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaX->Location = System::Drawing::Point(996, 96);
			this->txtAreaX->Name = L"txtAreaX";
			this->txtAreaX->Size = System::Drawing::Size(100, 27);
			this->txtAreaX->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(896, 151);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 20);
			this->label3->TabIndex = 25;
			this->label3->Text = L"center_y";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(896, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 20);
			this->label2->TabIndex = 24;
			this->label2->Text = L"center_x";
			// 
			// btnGenerarArea
			// 
			this->btnGenerarArea->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnGenerarArea->Location = System::Drawing::Point(932, 362);
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
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(9, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(767, 771);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyWindowMain::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyWindowMain::pictureBox1_Paint);
			// 
			// btnReiniciar
			// 
			this->btnReiniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnReiniciar->Location = System::Drawing::Point(947, 578);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(102, 33);
			this->btnReiniciar->TabIndex = 19;
			this->btnReiniciar->Text = L"REINICIAR";
			this->btnReiniciar->UseVisualStyleBackColor = true;
			// 
			// btnDetener
			// 
			this->btnDetener->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnDetener->Location = System::Drawing::Point(946, 525);
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->Size = System::Drawing::Size(103, 33);
			this->btnDetener->TabIndex = 18;
			this->btnDetener->Text = L"DETENER";
			this->btnDetener->UseVisualStyleBackColor = true;
			// 
			// btnIniciar
			// 
			this->btnIniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnIniciar->Location = System::Drawing::Point(947, 475);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(102, 33);
			this->btnIniciar->TabIndex = 17;
			this->btnIniciar->Text = L"INICIAR";
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
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->txtAreaX);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->txtAreaY);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1204, 783);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Simulación para cada proceso";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->detener_proceso);
			this->tabPage2->Controls->Add(this->iniciar_proceso);
			this->tabPage2->Controls->Add(this->desechogrid);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			// MyWindowMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 857);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"MyWindowMain";
			this->Text = L"Simulador para la gestión de basura marina";
			this->Load += gcnew System::EventHandler(this, &MyWindowMain::MyWindowMain_Load);
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

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

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
};
}
