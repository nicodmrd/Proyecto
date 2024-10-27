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
			//TODO: agregar c�digo de constructor aqu�
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
			
			toolTip1->SetToolTip(btnAreaAnalisis, "Realizar �rea de an�lisis");
			toolTip2->SetToolTip(btnReiniciar, "Reiniciar simulaci�n");
			toolTip3->SetToolTip(btnDetener, "Detener simulaci�n");
			toolTip4->SetToolTip(btnIniciar, "Iniciar simulaci�n");
			toolTip5->SetToolTip(btnCursor, "Cursor");

			toolTip6->SetToolTip(btnValidarDron, "Validar bater�a del dron");
			toolTip7->SetToolTip(btnValidarBarco, "Validar combustible del barco");
			toolTip8->SetToolTip(btnValidarCamion, "Validar combustible del cami�n");
			toolTip9->SetToolTip(btnRecargarBateria, "Recargar bater�a del dron");
			toolTip10->SetToolTip(btnRecargarCmbBarco, "Suministrar combustible al barco");
			toolTip11->SetToolTip(btnRecargarCmbCamion, "Suministrar combustible al cami�n");
			toolTip12->SetToolTip(btnAsignarDron, "Asignar dron");
			toolTip13->SetToolTip(btnAsignarBarcos, "Asignar barco");
			toolTip14->SetToolTip(btnAsignarCamion, "Asignar cami�n");
			toolTip15->SetToolTip(btnAumentarContenedor, "Agregar un contenedor");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
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
	private: System::Windows::Forms::ToolStripMenuItem^ gu�aDelSoftwareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ acercaDeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ integrantesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ informaci�nDelProyectoToolStripMenuItem;
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
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::Button^ btnValidarDron;



private: System::Windows::Forms::DataGridView^ dataGridView1;




private: System::Windows::Forms::Label^ label4;

private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ btnRecargarCmbBarco;

private: System::Windows::Forms::Button^ btnRecargarBateria;

private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::ComboBox^ comboBox5;
private: System::Windows::Forms::Button^ btnValidarCamion;
private: System::Windows::Forms::Button^ btnRecargarCmbCamion;


private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::ComboBox^ comboBox4;
private: System::Windows::Forms::Button^ btnValidarBarco;

private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::DataGridView^ dataGridView3;




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









	private: System::Windows::Forms::ToolStripMenuItem^ camionesToolStripMenuItem;

		   void LoadImage()
		   {
			   Mapa^ mapa = gcnew Mapa();

			   // Cargar la imagen desde una ruta relativa
			   pictureBox1->Image = Image::FromFile(mapa->Imagen);
			   pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tama�o del PictureBox

		   }
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyWindowMain::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->gu�aDelSoftwareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->integrantesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informaci�nDelProyectoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarCamion = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbCamion = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->btnValidarBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarCmbBarco = (gcnew System::Windows::Forms::Button());
			this->btnRecargarBateria = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->IdDesecho = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IdCoordX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CoordY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			this->IdBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CapacidadCoord = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IdCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MatriculaCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->menuStrip2->Size = System::Drawing::Size(1482, 28);
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
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->gu�aDelSoftwareToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// gu�aDelSoftwareToolStripMenuItem
			// 
			this->gu�aDelSoftwareToolStripMenuItem->Name = L"gu�aDelSoftwareToolStripMenuItem";
			this->gu�aDelSoftwareToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->gu�aDelSoftwareToolStripMenuItem->Text = L"Gu�a del software";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->integrantesToolStripMenuItem,
					this->informaci�nDelProyectoToolStripMenuItem
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
			// informaci�nDelProyectoToolStripMenuItem
			// 
			this->informaci�nDelProyectoToolStripMenuItem->Name = L"informaci�nDelProyectoToolStripMenuItem";
			this->informaci�nDelProyectoToolStripMenuItem->Size = System::Drawing::Size(260, 26);
			this->informaci�nDelProyectoToolStripMenuItem->Text = L"Informaci�n del proyecto";
			// 
			// txtAreaLargo
			// 
			this->txtAreaLargo->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaLargo->Location = System::Drawing::Point(1083, 106);
			this->txtAreaLargo->Name = L"txtAreaLargo";
			this->txtAreaLargo->Size = System::Drawing::Size(104, 22);
			this->txtAreaLargo->TabIndex = 33;
			// 
			// txtAreaAncho
			// 
			this->txtAreaAncho->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaAncho->Location = System::Drawing::Point(1083, 76);
			this->txtAreaAncho->Name = L"txtAreaAncho";
			this->txtAreaAncho->Size = System::Drawing::Size(104, 22);
			this->txtAreaAncho->TabIndex = 32;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1020, 109);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 16);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Largo";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1020, 79);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 16);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Ancho";
			// 
			// txtAreaY
			// 
			this->txtAreaY->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaY->Location = System::Drawing::Point(1313, 733);
			this->txtAreaY->Name = L"txtAreaY";
			this->txtAreaY->Size = System::Drawing::Size(100, 22);
			this->txtAreaY->TabIndex = 27;
			// 
			// txtAreaX
			// 
			this->txtAreaX->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->txtAreaX->Location = System::Drawing::Point(1313, 711);
			this->txtAreaX->Name = L"txtAreaX";
			this->txtAreaX->Size = System::Drawing::Size(100, 22);
			this->txtAreaX->TabIndex = 26;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1284, 739);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 16);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Cy";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1285, 714);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 16);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Cx";
			// 
			// btnGenerarArea
			// 
			this->btnGenerarArea->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnGenerarArea->Location = System::Drawing::Point(1181, 717);
			this->btnGenerarArea->Name = L"btnGenerarArea";
			this->btnGenerarArea->Size = System::Drawing::Size(97, 38);
			this->btnGenerarArea->TabIndex = 23;
			this->btnGenerarArea->Text = L"Generar �rea";
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
			this->label1->Text = L"INGRESE DATOS PARA LA SIMULACI�N";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(9, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(917, 767);
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
			this->btnReiniciar->Location = System::Drawing::Point(1133, 16);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(54, 54);
			this->btnReiniciar->TabIndex = 19;
			this->btnReiniciar->UseVisualStyleBackColor = true;
			// 
			// btnDetener
			// 
			this->btnDetener->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnDetener->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDetener.Image")));
			this->btnDetener->Location = System::Drawing::Point(1073, 16);
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->Size = System::Drawing::Size(54, 54);
			this->btnDetener->TabIndex = 18;
			this->btnDetener->UseVisualStyleBackColor = true;
			// 
			// btnIniciar
			// 
			this->btnIniciar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnIniciar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciar.Image")));
			this->btnIniciar->Location = System::Drawing::Point(1013, 15);
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
			this->tabControl1->Size = System::Drawing::Size(1462, 808);
			this->tabControl1->TabIndex = 35;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->dataGridView3);
			this->tabPage1->Controls->Add(this->dataGridView2);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->comboBox5);
			this->tabPage1->Controls->Add(this->btnValidarCamion);
			this->tabPage1->Controls->Add(this->btnRecargarCmbCamion);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->comboBox4);
			this->tabPage1->Controls->Add(this->btnValidarBarco);
			this->tabPage1->Controls->Add(this->btnRecargarCmbBarco);
			this->tabPage1->Controls->Add(this->btnRecargarBateria);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->comboBox1);
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
			this->tabPage1->Size = System::Drawing::Size(1454, 779);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Simulaci�n para cada proceso";
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdCamion,
					this->MatriculaCamion
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView3->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView3->Location = System::Drawing::Point(1148, 565);
			this->dataGridView3->Name = L"dataGridView3";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView3->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(290, 96);
			this->dataGridView3->TabIndex = 81;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdBarco,
					this->CapacidadCoord
			});
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView2->Location = System::Drawing::Point(1148, 377);
			this->dataGridView2->Name = L"dataGridView2";
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(290, 160);
			this->dataGridView2->TabIndex = 80;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(1020, 717);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(116, 16);
			this->label17->TabIndex = 79;
			this->label17->Text = L"Cantidad utilizada ";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox4->Location = System::Drawing::Point(1027, 736);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 78;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(955, 698);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(80, 16);
			this->label16->TabIndex = 77;
			this->label16->Text = L"Contenedor ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(955, 362);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(122, 16);
			this->label15->TabIndex = 76;
			this->label15->Text = L"ASIGNAR UNIDAD";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(955, 596);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(124, 16);
			this->label14->TabIndex = 75;
			this->label14->Text = L"Camion de traslado";
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox3->Location = System::Drawing::Point(1021, 617);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(106, 22);
			this->textBox3->TabIndex = 74;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(958, 615);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(50, 24);
			this->comboBox5->TabIndex = 73;
			// 
			// btnValidarCamion
			// 
			this->btnValidarCamion->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarCamion.Image")));
			this->btnValidarCamion->Location = System::Drawing::Point(957, 645);
			this->btnValidarCamion->Name = L"btnValidarCamion";
			this->btnValidarCamion->Size = System::Drawing::Size(50, 50);
			this->btnValidarCamion->TabIndex = 72;
			this->btnValidarCamion->UseVisualStyleBackColor = true;
			// 
			// btnRecargarCmbCamion
			// 
			this->btnRecargarCmbCamion->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarCmbCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarCmbCamion.Image")));
			this->btnRecargarCmbCamion->Location = System::Drawing::Point(1023, 645);
			this->btnRecargarCmbCamion->Name = L"btnRecargarCmbCamion";
			this->btnRecargarCmbCamion->Size = System::Drawing::Size(50, 50);
			this->btnRecargarCmbCamion->TabIndex = 71;
			this->btnRecargarCmbCamion->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(955, 494);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(106, 16);
			this->label5->TabIndex = 68;
			this->label5->Text = L"Barco recolector";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox2->Location = System::Drawing::Point(1021, 513);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 22);
			this->textBox2->TabIndex = 67;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(956, 513);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(50, 24);
			this->comboBox4->TabIndex = 66;
			// 
			// btnValidarBarco
			// 
			this->btnValidarBarco->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarBarco->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarBarco.Image")));
			this->btnValidarBarco->Location = System::Drawing::Point(956, 543);
			this->btnValidarBarco->Name = L"btnValidarBarco";
			this->btnValidarBarco->Size = System::Drawing::Size(50, 50);
			this->btnValidarBarco->TabIndex = 65;
			this->btnValidarBarco->UseVisualStyleBackColor = true;
			// 
			// btnRecargarCmbBarco
			// 
			this->btnRecargarCmbBarco->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarCmbBarco->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarCmbBarco.Image")));
			this->btnRecargarCmbBarco->Location = System::Drawing::Point(1021, 543);
			this->btnRecargarCmbBarco->Name = L"btnRecargarCmbBarco";
			this->btnRecargarCmbBarco->Size = System::Drawing::Size(50, 50);
			this->btnRecargarCmbBarco->TabIndex = 63;
			this->btnRecargarCmbBarco->UseVisualStyleBackColor = true;
			// 
			// btnRecargarBateria
			// 
			this->btnRecargarBateria->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnRecargarBateria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRecargarBateria.Image")));
			this->btnRecargarBateria->Location = System::Drawing::Point(1020, 440);
			this->btnRecargarBateria->Name = L"btnRecargarBateria";
			this->btnRecargarBateria->Size = System::Drawing::Size(50, 50);
			this->btnRecargarBateria->TabIndex = 62;
			this->btnRecargarBateria->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(954, 391);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 16);
			this->label4->TabIndex = 61;
			this->label4->Text = L"Dron scanner";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox1->Location = System::Drawing::Point(1020, 412);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 22);
			this->textBox1->TabIndex = 59;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdDesecho,
					this->IdCoordX, this->CoordY
			});
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->Location = System::Drawing::Point(1214, 13);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(224, 337);
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(956, 410);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(50, 24);
			this->comboBox1->TabIndex = 53;
			// 
			// btnValidarDron
			// 
			this->btnValidarDron->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnValidarDron->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnValidarDron.Image")));
			this->btnValidarDron->Location = System::Drawing::Point(957, 440);
			this->btnValidarDron->Name = L"btnValidarDron";
			this->btnValidarDron->Size = System::Drawing::Size(50, 50);
			this->btnValidarDron->TabIndex = 50;
			this->btnValidarDron->UseVisualStyleBackColor = true;
			// 
			// btnAumentarContenedor
			// 
			this->btnAumentarContenedor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAumentarContenedor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAumentarContenedor.Image")));
			this->btnAumentarContenedor->Location = System::Drawing::Point(957, 717);
			this->btnAumentarContenedor->Name = L"btnAumentarContenedor";
			this->btnAumentarContenedor->Size = System::Drawing::Size(50, 50);
			this->btnAumentarContenedor->TabIndex = 49;
			this->btnAumentarContenedor->UseVisualStyleBackColor = true;
			// 
			// btnAsignarBarcos
			// 
			this->btnAsignarBarcos->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarBarcos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarBarcos.Image")));
			this->btnAsignarBarcos->Location = System::Drawing::Point(1076, 541);
			this->btnAsignarBarcos->Name = L"btnAsignarBarcos";
			this->btnAsignarBarcos->Size = System::Drawing::Size(50, 50);
			this->btnAsignarBarcos->TabIndex = 48;
			this->btnAsignarBarcos->UseVisualStyleBackColor = true;
			// 
			// btnAsignarCamion
			// 
			this->btnAsignarCamion->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarCamion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarCamion.Image")));
			this->btnAsignarCamion->Location = System::Drawing::Point(1077, 645);
			this->btnAsignarCamion->Name = L"btnAsignarCamion";
			this->btnAsignarCamion->Size = System::Drawing::Size(50, 50);
			this->btnAsignarCamion->TabIndex = 47;
			this->btnAsignarCamion->UseVisualStyleBackColor = true;
			// 
			// btnAsignarDron
			// 
			this->btnAsignarDron->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAsignarDron->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAsignarDron.Image")));
			this->btnAsignarDron->Location = System::Drawing::Point(1076, 440);
			this->btnAsignarDron->Name = L"btnAsignarDron";
			this->btnAsignarDron->Size = System::Drawing::Size(50, 50);
			this->btnAsignarDron->TabIndex = 46;
			this->btnAsignarDron->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(950, 146);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(234, 16);
			this->label13->TabIndex = 45;
			this->label13->Text = L"ENCARGADO POR CADA PROCESO";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(950, 310);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(79, 16);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Tratamiento";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(950, 264);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(73, 16);
			this->label11->TabIndex = 43;
			this->label11->Text = L"Transporte";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(950, 218);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(83, 16);
			this->label10->TabIndex = 42;
			this->label10->Text = L"Recolecci�n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(950, 172);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 16);
			this->label9->TabIndex = 41;
			this->label9->Text = L"Escaneo";
			// 
			// cmb4Encargado
			// 
			this->cmb4Encargado->FormattingEnabled = true;
			this->cmb4Encargado->Location = System::Drawing::Point(954, 329);
			this->cmb4Encargado->Name = L"cmb4Encargado";
			this->cmb4Encargado->Size = System::Drawing::Size(233, 24);
			this->cmb4Encargado->TabIndex = 40;
			// 
			// cmb3Encargado
			// 
			this->cmb3Encargado->FormattingEnabled = true;
			this->cmb3Encargado->Location = System::Drawing::Point(953, 283);
			this->cmb3Encargado->Name = L"cmb3Encargado";
			this->cmb3Encargado->Size = System::Drawing::Size(234, 24);
			this->cmb3Encargado->TabIndex = 39;
			// 
			// cmb2Encargado
			// 
			this->cmb2Encargado->FormattingEnabled = true;
			this->cmb2Encargado->Location = System::Drawing::Point(953, 237);
			this->cmb2Encargado->Name = L"cmb2Encargado";
			this->cmb2Encargado->Size = System::Drawing::Size(234, 24);
			this->cmb2Encargado->TabIndex = 38;
			// 
			// cmb1Encargado
			// 
			this->cmb1Encargado->FormattingEnabled = true;
			this->cmb1Encargado->Location = System::Drawing::Point(953, 191);
			this->cmb1Encargado->Name = L"cmb1Encargado";
			this->cmb1Encargado->Size = System::Drawing::Size(234, 24);
			this->cmb1Encargado->TabIndex = 37;
			// 
			// btnCursor
			// 
			this->btnCursor->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnCursor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCursor.Image")));
			this->btnCursor->Location = System::Drawing::Point(953, 15);
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
			this->btnAreaAnalisis->Location = System::Drawing::Point(953, 79);
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
			this->tabPage2->Size = System::Drawing::Size(1454, 779);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Simulaci�n separador de desecho";
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
			this->plasticobox->HeaderText = L"PL�STICO";
			this->plasticobox->MinimumWidth = 100;
			this->plasticobox->Name = L"plasticobox";
			this->plasticobox->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->plasticobox->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->plasticobox->Width = 125;
			// 
			// cartonbox
			// 
			this->cartonbox->HeaderText = L"CART�N";
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
			// MyWindowMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 853);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->IsMdiContainer = true;
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"MyWindowMain";
			this->Text = L"Simulador para la gesti�n de basura marina";
			this->Load += gcnew System::EventHandler(this, &MyWindowMain::MyWindowMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyWindowMain::MyWindowMain_KeyDown);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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
				// Filtrar y a�adir a ComboBox1 (Escaneo)
				for each (Encargado ^ encargado in _encargadoList) {
					if (encargado->Cargo == "Escaneo") {
						cmb1Encargado->Items->Add(encargado);
					}
					else if (encargado->Cargo == "Recolecci�n") {
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
			pictureBox1->Invalidate(); // Esto forzar� el redibujo del PictureBox
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
				MessageBox::Show("No se ha logrado realizar el env�o");
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
		Point startPoint;  // Punto inicial del rect�ngulo
		Point endPoint;    // Punto final del rect�ngulo
		bool isDrawing = false;  // Indica si se est� dibujando
		bool GenerarAreaPresionado = false; // Indica si se ha hecho clic en el bot�n
		float rotationAngle = 0; // �ngulo de rotaci�n para el rect�ngulo

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
				endPoint = e->Location;   // Capturar el punto final al soltar el bot�n
				isDrawing = false;        // Terminar el dibujo
				pictureBox1->Invalidate(); // Forzar el redibujo del PictureBox para mostrar el rect�ngulo final
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
				if (d->Posicion != nullptr) {  // Verificar que la posici�n no sea nula
					Coordenadas^ coord = d->Posicion; // Acceder directamente a la posici�n
					g->DrawEllipse(pen, static_cast<int>(coord->X), static_cast<int>(coord->Y), 5, 5);
					// Dibuja un punto de tama�o 5x5
				}
			}
		}

		if (GenerarAreaPresionado) {
			if (startPoint != endPoint) {  // Solo dibuja si los puntos son diferentes
				Graphics^ g = e->Graphics;
				Pen^ pen = gcnew Pen(Color::Black, 2); // Color rojo y grosor de 4 p�xeles

				// Calcular las coordenadas del rect�ngulo
				int x = Math::Min(startPoint.X, endPoint.X);
				int y = Math::Min(startPoint.Y, endPoint.Y);
				int width = Math::Abs(startPoint.X - endPoint.X);
				int height = Math::Abs(startPoint.Y - endPoint.Y);

				// Mover el origen de coordenadas al centro del rect�ngulo
				g->TranslateTransform(x + width / 2.0f, y + height / 2.0f);

				// Aplicar la rotaci�n
				g->RotateTransform(rotationAngle);

				// Dibujar el rect�ngulo con el centro en el nuevo origen
				g->DrawRectangle(pen, -width / 2, -height / 2, width, height);

				// Restaurar la transformaci�n para futuras operaciones
				g->ResetTransform();

			}
		}

	}


	private: System::Void MyWindowMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (GenerarAreaPresionado) {
			if (e->KeyCode == Keys::R) {
				rotationAngle += 15;  // Incrementar el �ngulo de rotaci�n en 15 grados
				if (rotationAngle >= 360) {
					rotationAngle = 0;  // Reiniciar el �ngulo si alcanza los 360 grados
				}
				pictureBox1->Invalidate();  // Redibujar el PictureBox con la nueva rotaci�n
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
