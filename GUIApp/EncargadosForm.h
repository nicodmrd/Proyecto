#pragma once
#include "ComboBoxItem.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;
	using namespace SimuladorService;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de EncargadosForm
	/// </summary>
	public ref class EncargadosForm : public System::Windows::Forms::Form
	{
	public:
		EncargadosForm(void)
		{
			InitializeComponent();
			this->MinimizeBox = false;
			this->MaximizeBox = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~EncargadosForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtEncargadoId;
	private: System::Windows::Forms::TextBox^ txtEncargadoNombre;
	private: System::Windows::Forms::TextBox^ txtEncargadoApellido;
	private: System::Windows::Forms::TextBox^ txtEncargadoCorreo;
	private: System::Windows::Forms::TextBox^ txtEncargadoEdad;
	private: System::Windows::Forms::TextBox^ txtEncargadoCodigo;

	private: System::Windows::Forms::TextBox^ txtEncargadoContacto;

	
	private: System::Windows::Forms::PictureBox^ pbEncargadoFoto;


	private: System::Windows::Forms::Button^ btnEliminarEncargado;
	private: System::Windows::Forms::Button^ btnAgregarEncargado;
	private: System::Windows::Forms::Button^ btnSubirFoto;
	private: System::Windows::Forms::Button^ btnEliminarFoto;








	private: System::Windows::Forms::DataGridView^ dgvEncargados;
	private: System::Windows::Forms::Button^ btnActualizarEncargado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdEncargado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NombreEncargado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ApellidoEncargado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CargoEncargado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ContactoEncargado;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nuevoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ módificarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ salirToolStripMenuItem;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtEncargadoId = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoApellido = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoCorreo = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoEdad = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoCodigo = (gcnew System::Windows::Forms::TextBox());
			this->txtEncargadoContacto = (gcnew System::Windows::Forms::TextBox());
			this->pbEncargadoFoto = (gcnew System::Windows::Forms::PictureBox());
			this->btnEliminarEncargado = (gcnew System::Windows::Forms::Button());
			this->btnAgregarEncargado = (gcnew System::Windows::Forms::Button());
			this->btnSubirFoto = (gcnew System::Windows::Forms::Button());
			this->btnEliminarFoto = (gcnew System::Windows::Forms::Button());
			this->dgvEncargados = (gcnew System::Windows::Forms::DataGridView());
			this->IdEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NombreEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ApellidoEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CargoEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ContactoEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnActualizarEncargado = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuevoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->módificarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncargadoFoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEncargados))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(58, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(58, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Apellido:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(58, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Correo:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(58, 164);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Edad:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(58, 192);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Código:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(58, 220);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Cargo:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(58, 247);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 16);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Contacto:";
			// 
			// txtEncargadoId
			// 
			this->txtEncargadoId->Location = System::Drawing::Point(182, 52);
			this->txtEncargadoId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoId->Name = L"txtEncargadoId";
			this->txtEncargadoId->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoId->TabIndex = 8;
			// 
			// txtEncargadoNombre
			// 
			this->txtEncargadoNombre->Location = System::Drawing::Point(182, 80);
			this->txtEncargadoNombre->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoNombre->Name = L"txtEncargadoNombre";
			this->txtEncargadoNombre->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoNombre->TabIndex = 9;
			// 
			// txtEncargadoApellido
			// 
			this->txtEncargadoApellido->Location = System::Drawing::Point(182, 108);
			this->txtEncargadoApellido->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoApellido->Name = L"txtEncargadoApellido";
			this->txtEncargadoApellido->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoApellido->TabIndex = 10;
			// 
			// txtEncargadoCorreo
			// 
			this->txtEncargadoCorreo->Location = System::Drawing::Point(182, 135);
			this->txtEncargadoCorreo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoCorreo->Name = L"txtEncargadoCorreo";
			this->txtEncargadoCorreo->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoCorreo->TabIndex = 11;
			// 
			// txtEncargadoEdad
			// 
			this->txtEncargadoEdad->Location = System::Drawing::Point(182, 164);
			this->txtEncargadoEdad->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoEdad->Name = L"txtEncargadoEdad";
			this->txtEncargadoEdad->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoEdad->TabIndex = 12;
			// 
			// txtEncargadoCodigo
			// 
			this->txtEncargadoCodigo->Location = System::Drawing::Point(182, 192);
			this->txtEncargadoCodigo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoCodigo->Name = L"txtEncargadoCodigo";
			this->txtEncargadoCodigo->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoCodigo->TabIndex = 13;
			// 
			// txtEncargadoContacto
			// 
			this->txtEncargadoContacto->Location = System::Drawing::Point(182, 248);
			this->txtEncargadoContacto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEncargadoContacto->Name = L"txtEncargadoContacto";
			this->txtEncargadoContacto->Size = System::Drawing::Size(171, 22);
			this->txtEncargadoContacto->TabIndex = 15;
			// 
			// pbEncargadoFoto
			// 
			this->pbEncargadoFoto->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbEncargadoFoto->Location = System::Drawing::Point(427, 40);
			this->pbEncargadoFoto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pbEncargadoFoto->Name = L"pbEncargadoFoto";
			this->pbEncargadoFoto->Size = System::Drawing::Size(205, 190);
			this->pbEncargadoFoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbEncargadoFoto->TabIndex = 16;
			this->pbEncargadoFoto->TabStop = false;
			this->pbEncargadoFoto->Click += gcnew System::EventHandler(this, &EncargadosForm::pbEncargadoFoto_Click);
			// 
			// btnEliminarEncargado
			// 
			this->btnEliminarEncargado->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnEliminarEncargado->Location = System::Drawing::Point(452, 300);
			this->btnEliminarEncargado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEliminarEncargado->Name = L"btnEliminarEncargado";
			this->btnEliminarEncargado->Size = System::Drawing::Size(180, 37);
			this->btnEliminarEncargado->TabIndex = 18;
			this->btnEliminarEncargado->Text = L"Eliminar Datos";
			this->btnEliminarEncargado->UseVisualStyleBackColor = true;
			this->btnEliminarEncargado->Click += gcnew System::EventHandler(this, &EncargadosForm::btnEliminarEncargado_Click);
			// 
			// btnAgregarEncargado
			// 
			this->btnAgregarEncargado->Enabled = false;
			this->btnAgregarEncargado->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnAgregarEncargado->Location = System::Drawing::Point(61, 300);
			this->btnAgregarEncargado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAgregarEncargado->Name = L"btnAgregarEncargado";
			this->btnAgregarEncargado->Size = System::Drawing::Size(180, 36);
			this->btnAgregarEncargado->TabIndex = 16;
			this->btnAgregarEncargado->Text = L"Guardar Datos";
			this->btnAgregarEncargado->UseVisualStyleBackColor = true;
			this->btnAgregarEncargado->Click += gcnew System::EventHandler(this, &EncargadosForm::button2_Click);
			// 
			// btnSubirFoto
			// 
			this->btnSubirFoto->Enabled = false;
			this->btnSubirFoto->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnSubirFoto->Location = System::Drawing::Point(387, 234);
			this->btnSubirFoto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSubirFoto->Name = L"btnSubirFoto";
			this->btnSubirFoto->Size = System::Drawing::Size(126, 36);
			this->btnSubirFoto->TabIndex = 19;
			this->btnSubirFoto->Text = L"Subir Foto";
			this->btnSubirFoto->UseVisualStyleBackColor = true;
			this->btnSubirFoto->Click += gcnew System::EventHandler(this, &EncargadosForm::button3_Click);
			// 
			// btnEliminarFoto
			// 
			this->btnEliminarFoto->Enabled = false;
			this->btnEliminarFoto->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnEliminarFoto->Location = System::Drawing::Point(530, 234);
			this->btnEliminarFoto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEliminarFoto->Name = L"btnEliminarFoto";
			this->btnEliminarFoto->Size = System::Drawing::Size(126, 36);
			this->btnEliminarFoto->TabIndex = 20;
			this->btnEliminarFoto->Text = L"Eliminar Foto";
			this->btnEliminarFoto->UseVisualStyleBackColor = true;
			this->btnEliminarFoto->Click += gcnew System::EventHandler(this, &EncargadosForm::button4_Click);
			// 
			// dgvEncargados
			// 
			this->dgvEncargados->AllowUserToAddRows = false;
			this->dgvEncargados->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEncargados->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->IdEncargado,
					this->NombreEncargado, this->ApellidoEncargado, this->CargoEncargado, this->ContactoEncargado
			});
			this->dgvEncargados->Location = System::Drawing::Point(45, 357);
			this->dgvEncargados->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgvEncargados->Name = L"dgvEncargados";
			this->dgvEncargados->RowHeadersVisible = false;
			this->dgvEncargados->RowHeadersWidth = 51;
			this->dgvEncargados->RowTemplate->Height = 24;
			this->dgvEncargados->Size = System::Drawing::Size(611, 267);
			this->dgvEncargados->TabIndex = 22;
			this->dgvEncargados->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EncargadosForm::dgvEncargados_CellClick);
			this->dgvEncargados->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EncargadosForm::dgvEncargados_CellContentClick);
			// 
			// IdEncargado
			// 
			this->IdEncargado->HeaderText = L"Id";
			this->IdEncargado->MinimumWidth = 6;
			this->IdEncargado->Name = L"IdEncargado";
			this->IdEncargado->Width = 50;
			// 
			// NombreEncargado
			// 
			this->NombreEncargado->HeaderText = L"Nombre";
			this->NombreEncargado->MinimumWidth = 6;
			this->NombreEncargado->Name = L"NombreEncargado";
			this->NombreEncargado->Width = 125;
			// 
			// ApellidoEncargado
			// 
			this->ApellidoEncargado->HeaderText = L"Apellido";
			this->ApellidoEncargado->MinimumWidth = 6;
			this->ApellidoEncargado->Name = L"ApellidoEncargado";
			this->ApellidoEncargado->Width = 125;
			// 
			// CargoEncargado
			// 
			this->CargoEncargado->HeaderText = L"Cargo";
			this->CargoEncargado->MinimumWidth = 6;
			this->CargoEncargado->Name = L"CargoEncargado";
			this->CargoEncargado->Width = 125;
			// 
			// ContactoEncargado
			// 
			this->ContactoEncargado->HeaderText = L"Contacto";
			this->ContactoEncargado->MinimumWidth = 6;
			this->ContactoEncargado->Name = L"ContactoEncargado";
			this->ContactoEncargado->Width = 125;
			// 
			// btnActualizarEncargado
			// 
			this->btnActualizarEncargado->Enabled = false;
			this->btnActualizarEncargado->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnActualizarEncargado->Location = System::Drawing::Point(259, 300);
			this->btnActualizarEncargado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnActualizarEncargado->Name = L"btnActualizarEncargado";
			this->btnActualizarEncargado->Size = System::Drawing::Size(180, 37);
			this->btnActualizarEncargado->TabIndex = 17;
			this->btnActualizarEncargado->Text = L"Modificar Datos";
			this->btnActualizarEncargado->UseVisualStyleBackColor = true;
			this->btnActualizarEncargado->Click += gcnew System::EventHandler(this, &EncargadosForm::btnActualizarEncargado_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(182, 219);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(171, 24);
			this->comboBox1->TabIndex = 23;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->archivoToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(686, 28);
			this->menuStrip1->TabIndex = 24;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nuevoToolStripMenuItem,
					this->módificarToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// nuevoToolStripMenuItem
			// 
			this->nuevoToolStripMenuItem->Name = L"nuevoToolStripMenuItem";
			this->nuevoToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->nuevoToolStripMenuItem->Text = L"Nuevo";
			this->nuevoToolStripMenuItem->Click += gcnew System::EventHandler(this, &EncargadosForm::nuevoToolStripMenuItem_Click);
			// 
			// módificarToolStripMenuItem
			// 
			this->módificarToolStripMenuItem->Name = L"módificarToolStripMenuItem";
			this->módificarToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->módificarToolStripMenuItem->Text = L"Editar";
			this->módificarToolStripMenuItem->Click += gcnew System::EventHandler(this, &EncargadosForm::módificarToolStripMenuItem_Click);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &EncargadosForm::salirToolStripMenuItem_Click);
			// 
			// EncargadosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 658);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->btnActualizarEncargado);
			this->Controls->Add(this->dgvEncargados);
			this->Controls->Add(this->btnEliminarFoto);
			this->Controls->Add(this->btnSubirFoto);
			this->Controls->Add(this->btnAgregarEncargado);
			this->Controls->Add(this->btnEliminarEncargado);
			this->Controls->Add(this->pbEncargadoFoto);
			this->Controls->Add(this->txtEncargadoId);
			this->Controls->Add(this->txtEncargadoNombre);
			this->Controls->Add(this->txtEncargadoApellido);
			this->Controls->Add(this->txtEncargadoCorreo);
			this->Controls->Add(this->txtEncargadoEdad);
			this->Controls->Add(this->txtEncargadoCodigo);
			this->Controls->Add(this->txtEncargadoContacto);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"EncargadosForm";
			this->Text = L"Menú de encargados";
			this->Load += gcnew System::EventHandler(this, &EncargadosForm::EncargadosForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbEncargadoFoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEncargados))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try{
			Encargado^ encargado = gcnew Encargado();
			String^ correo = txtEncargadoCorreo->Text->Trim();
			System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^\\w+([-+.']\\w+)*@(pucp\\.edu\\.pe|gmail\\.com|hotmail\\.com)$");
			if (!regex->IsMatch(correo)) {
				MessageBox::Show("El correo debe tener una extensión válida (@pucp.edu.pe, @gmail.com, o @hotmail.com)");
				return;
			}
			encargado->Id = Convert::ToInt32(txtEncargadoId->Text);
			encargado->Nombre = txtEncargadoNombre->Text;
			encargado->Apellido = txtEncargadoApellido->Text;
			encargado->Correo = txtEncargadoCorreo->Text;
			encargado->Edad = Convert::ToInt32(txtEncargadoEdad->Text);
			encargado->Codigo = txtEncargadoCodigo->Text;
			encargado->Cargo = comboBox1->Text;
			encargado->Contacto = txtEncargadoContacto->Text;

			if (pbEncargadoFoto != nullptr && pbEncargadoFoto->Image != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				pbEncargadoFoto->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				encargado->Foto = ms->ToArray();
			}

			Service::AgregearEncargado(encargado);
			MostrarEncargado();
			MessageBox::Show("Se ha agregado un Encargado con id " + encargado->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido agregar el encargado a la base de datos por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	public:
		void MostrarEncargado() {
			List<Encargado^>^ lista_encargados = Service::ConsultarEncargados();
			if (lista_encargados != nullptr) {
				dgvEncargados->Rows->Clear();
				for (int i = 0; i < lista_encargados->Count; i++) {
					dgvEncargados->Rows->Add(gcnew array<String^> {"" + lista_encargados[i]->Id,
						lista_encargados[i]->Nombre,
						lista_encargados[i]->Apellido,
						lista_encargados[i]->Cargo,
						lista_encargados[i]->Contacto});
				}
			}
		}
		void ClearControls() {
			for each (Control ^ control in this->Controls) {
				if (control->GetType() == TextBox::typeid) {
					dynamic_cast<TextBox^>(control)->Text = "";
				}
				comboBox1->SelectedIndex = -1;
			}
			comboBox1->Items->Equals("");
			pbEncargadoFoto->Image = nullptr;
		}
		void CargoEncargadoComboBox() {
			comboBox1->Items->Clear();
			List<Encargado^>^ _encargadoList = Service::ConsultarEncargados();
			if (_encargadoList != nullptr) {
				comboBox1->Items->Add("Escaneo");
				comboBox1->Items->Add("Recolección");
				comboBox1->Items->Add("Transporte");
				comboBox1->Items->Add("Tratamiento de desechos");
			}
		}

private: System::Void dgvEncargados_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}

private: System::Void btnEliminarEncargado_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ encargado_id = txtEncargadoId->Text->Trim();
	if (encargado_id->Equals("")) {
		MessageBox::Show("Debe seleccionar un encargado");
		return;
	}
	try{
	Service::EliminarEncargado(Convert::ToInt32(encargado_id));

	MostrarEncargado();
	ClearControls();
	MessageBox::Show("Se ha eliminado el encargado con Id = " + encargado_id + " de manera exitosa.");
	}
	catch (Exception^ ex) {
		MessageBox::Show("No ha sido posible eliminar los datos de un encargado por el siguiente motivo:\n" +
			ex->Message);
	}
}
private: System::Void btnActualizarEncargado_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ encargado_id = txtEncargadoId->Text->Trim();
	if (encargado_id->Equals("")) {
		MessageBox::Show("Debe seleccionar un encargado");
		return;
	}
	String^ correo = txtEncargadoCorreo->Text->Trim();
	System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^\\w+([-+.']\\w+)*@(pucp\\.edu\\.pe|gmail\\.com|hotmail\\.com)$");
	if (!regex->IsMatch(correo)) {
		MessageBox::Show("El correo debe tener una extensión válida (@pucp.edu.pe, @gmail.com, o @hotmail.com)");
		return;
	}
	try{
		Encargado^ encargado = gcnew Encargado();

		encargado->Id = Convert::ToInt32(txtEncargadoId->Text);
		encargado->Nombre = txtEncargadoNombre->Text;
		encargado->Apellido = txtEncargadoApellido->Text;
		encargado->Correo = txtEncargadoCorreo->Text;
		encargado->Edad = Convert::ToInt32(txtEncargadoEdad->Text);
		encargado->Codigo = txtEncargadoCodigo->Text;
		encargado->Cargo = comboBox1->Text;
		encargado->Contacto = txtEncargadoContacto->Text;
		if (pbEncargadoFoto != nullptr && pbEncargadoFoto->Image != nullptr) {
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
			pbEncargadoFoto->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
			encargado->Foto = ms->ToArray();
		}

		Service::ActualizarEncargado(encargado);
		MostrarEncargado();
		MessageBox::Show("Se ha podido modificar datos del encargado con id " + encargado->Id);
	}
	catch (Exception^ ex) {
		MessageBox::Show("No se ha podido modificar los datos del encargado por el siguiente motivo:\n" +
			ex->Message);
	}
}
private: System::Void pbEncargadoFoto_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Image Files (*.jpg;*.jpeg;)|*.jpg;*.jpeg;";
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		pbEncargadoFoto->Image = gcnew Bitmap(ofd->FileName);
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	pbEncargadoFoto->Image = nullptr;
}
private: System::Void EncargadosForm_Load(System::Object^ sender, System::EventArgs^ e) {
	CargoEncargadoComboBox();
	MostrarEncargado();
}
private: System::Void dgvEncargados_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	try{
		int EncargadoId = Convert::ToInt32(dgvEncargados->Rows[dgvEncargados->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		Encargado^ _encargado = Service::ConsultarEncargadoPorId(EncargadoId);

		txtEncargadoId->Text = "" + _encargado->Id;
		txtEncargadoNombre->Text = _encargado->Nombre;
		txtEncargadoApellido->Text = _encargado->Apellido;
		txtEncargadoCorreo->Text = _encargado->Correo;
		txtEncargadoEdad->Text = "" + _encargado->Edad;
		txtEncargadoCodigo->Text = _encargado->Codigo;
		comboBox1->Text = _encargado->Cargo;
		txtEncargadoContacto->Text = _encargado->Contacto;

		if (_encargado->Foto != nullptr) {
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(_encargado->Foto);
			pbEncargadoFoto->Image = Image::FromStream(ms);
		}
		else {
			pbEncargadoFoto->Image = nullptr;
			pbEncargadoFoto->Invalidate();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}

private: System::Void nuevoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearControls();
	btnAgregarEncargado->Enabled = true;
	btnActualizarEncargado->Enabled = false;
	btnEliminarEncargado->Enabled = false;

	btnSubirFoto->Enabled = true;
	btnEliminarFoto->Enabled = false;
}
private: System::Void módificarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	btnAgregarEncargado->Enabled = false;
	btnActualizarEncargado->Enabled = true;
	btnEliminarEncargado->Enabled = true;

	btnSubirFoto->Enabled = true;
	btnEliminarFoto->Enabled = true;
}
private: System::Void salirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
