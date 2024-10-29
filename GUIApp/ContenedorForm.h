#pragma once

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
	/// Resumen de ContenedorForm
	/// </summary>
	public ref class ContenedorForm : public System::Windows::Forms::Form
	{
	public:
		ContenedorForm(void)
		{
			InitializeComponent();
			this->MinimizeBox = false;
			this->MaximizeBox = false;
			//
			//TODO: agregar código de constructor aquí
			//
			LoadImage();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ContenedorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnActualizarContenedor;
	private: System::Windows::Forms::PictureBox^ imgContenedor;
	protected:

	protected:


	private: System::Windows::Forms::Button^ btnAgregarContenedor;


	private: System::Windows::Forms::TextBox^ txtCapacidadContenedor;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dgvContenedores;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdContenedor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CapacidadContenedor;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtId;

	protected:	
		void LoadImage()
		{
			// Cargar la imagen desde una ruta relativa
			imgContenedor->Image = Image::FromFile("contenedor.png");
			imgContenedor->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox

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
			this->btnActualizarContenedor = (gcnew System::Windows::Forms::Button());
			this->imgContenedor = (gcnew System::Windows::Forms::PictureBox());
			this->btnAgregarContenedor = (gcnew System::Windows::Forms::Button());
			this->txtCapacidadContenedor = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgvContenedores = (gcnew System::Windows::Forms::DataGridView());
			this->IdContenedor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CapacidadContenedor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgContenedor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvContenedores))->BeginInit();
			this->SuspendLayout();
			// 
			// btnActualizarContenedor
			// 
			this->btnActualizarContenedor->Location = System::Drawing::Point(172, 140);
			this->btnActualizarContenedor->Margin = System::Windows::Forms::Padding(4);
			this->btnActualizarContenedor->Name = L"btnActualizarContenedor";
			this->btnActualizarContenedor->Size = System::Drawing::Size(100, 28);
			this->btnActualizarContenedor->TabIndex = 69;
			this->btnActualizarContenedor->Text = L"Actualizar";
			this->btnActualizarContenedor->UseVisualStyleBackColor = true;
			this->btnActualizarContenedor->Click += gcnew System::EventHandler(this, &ContenedorForm::btnActualizarContenedor_Click);
			// 
			// imgContenedor
			// 
			this->imgContenedor->Location = System::Drawing::Point(326, 12);
			this->imgContenedor->Name = L"imgContenedor";
			this->imgContenedor->Size = System::Drawing::Size(176, 156);
			this->imgContenedor->TabIndex = 64;
			this->imgContenedor->TabStop = false;
			// 
			// btnAgregarContenedor
			// 
			this->btnAgregarContenedor->Location = System::Drawing::Point(33, 140);
			this->btnAgregarContenedor->Margin = System::Windows::Forms::Padding(4);
			this->btnAgregarContenedor->Name = L"btnAgregarContenedor";
			this->btnAgregarContenedor->Size = System::Drawing::Size(100, 28);
			this->btnAgregarContenedor->TabIndex = 62;
			this->btnAgregarContenedor->Text = L"Agregar";
			this->btnAgregarContenedor->UseVisualStyleBackColor = true;
			this->btnAgregarContenedor->Click += gcnew System::EventHandler(this, &ContenedorForm::btnAgregarContenedor_Click);
			// 
			// txtCapacidadContenedor
			// 
			this->txtCapacidadContenedor->Location = System::Drawing::Point(160, 71);
			this->txtCapacidadContenedor->Name = L"txtCapacidadContenedor";
			this->txtCapacidadContenedor->Size = System::Drawing::Size(121, 22);
			this->txtCapacidadContenedor->TabIndex = 66;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 74);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 16);
			this->label6->TabIndex = 60;
			this->label6->Text = L"Capacidad Max. (kg):";
			this->label6->Click += gcnew System::EventHandler(this, &ContenedorForm::label6_Click);
			// 
			// dgvContenedores
			// 
			this->dgvContenedores->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvContenedores->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IdContenedor,
					this->CapacidadContenedor
			});
			this->dgvContenedores->Location = System::Drawing::Point(23, 214);
			this->dgvContenedores->Name = L"dgvContenedores";
			this->dgvContenedores->RowHeadersWidth = 51;
			this->dgvContenedores->RowTemplate->Height = 24;
			this->dgvContenedores->Size = System::Drawing::Size(479, 132);
			this->dgvContenedores->TabIndex = 70;
			//this->dgvContenedores->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ContenedorForm::dgvContenedores_CellClick);
			this->dgvContenedores->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ContenedorForm::dgvContenedores_CellClick);
			this->dgvContenedores->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ContenedorForm::dgvContenedores_CellContentClick);
			// 
			// 
			// IdContenedor
			// 
			this->IdContenedor->HeaderText = L"Id";
			this->IdContenedor->MinimumWidth = 6;
			this->IdContenedor->Name = L"IdContenedor";
			this->IdContenedor->Width = 50;
			// 
			// CapacidadContenedor
			// 
			this->CapacidadContenedor->HeaderText = L"Capacidad Max (kg)";
			this->CapacidadContenedor->MinimumWidth = 6;
			this->CapacidadContenedor->Name = L"CapacidadContenedor";
			this->CapacidadContenedor->Width = 80;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 16);
			this->label1->TabIndex = 71;
			this->label1->Text = L"Id: ";
			this->label1->Click += gcnew System::EventHandler(this, &ContenedorForm::label1_Click);
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(160, 33);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(121, 22);
			this->txtId->TabIndex = 72;
			// 
			// ContenedorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 371);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvContenedores);
			this->Controls->Add(this->btnActualizarContenedor);
			this->Controls->Add(this->imgContenedor);
			this->Controls->Add(this->btnAgregarContenedor);
			this->Controls->Add(this->txtCapacidadContenedor);
			this->Controls->Add(this->label6);
			this->Name = L"ContenedorForm";
			this->Text = L"Menú de contenedores";
			this->Load += gcnew System::EventHandler(this, &ContenedorForm::ContenedorForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgContenedor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvContenedores))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		void MostrarContenedores() {
			List<Contenedor^>^ contenedorList = Service::QueryAllContenedor();
			if (contenedorList != nullptr) {
				dgvContenedores->Rows->Clear();
				for (int i = 0; i < contenedorList->Count; i++) {
					dgvContenedores->Rows->Add(gcnew array<String^> {"" + contenedorList[i]->Id,
						"" + contenedorList[i]->CapacidadMax});
				}
			}
		}

		void ClearControls() {
			for each (Control ^ control in this->Controls) {
				if (control->GetType() == TextBox::typeid) {
					dynamic_cast<TextBox^>(control)->Text = "";
				}
			}
		}

	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void ContenedorForm_Load(System::Object^ sender, System::EventArgs^ e) {
		MostrarContenedores();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void btnAgregarContenedor_Click(System::Object^ sender, System::EventArgs^ e) {
		
		try {
			Contenedor^ _contenedor = gcnew Contenedor();
			_contenedor->Id = Convert::ToInt32(txtId->Text);
			_contenedor->CapacidadMax = Convert::ToDouble(txtCapacidadContenedor->Text);


			Service::AddContenedor(_contenedor);
			MostrarContenedores();
			MessageBox::Show("Se ha agregado un contenedor con id " + _contenedor->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido agregar el contenedor a la base de datos por el siguiente motivo:\n" +
				ex->Message);
		}
		
	}
	private: System::Void btnActualizarContenedor_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ contenedor_id = txtId->Text->Trim();
		if (contenedor_id->Equals("")) {
			MessageBox::Show("Debe seleccionar un contenedor");
			return;
		}
		try {
			Contenedor^ _contenedor = gcnew Contenedor();
			_contenedor->Id = Convert::ToInt32(txtId->Text);
			_contenedor->CapacidadMax = Convert::ToDouble(txtCapacidadContenedor->Text);

			Service::UpdateContenedor(_contenedor);
			MostrarContenedores();
			MessageBox::Show("Se hA modificado los datos del contenedor con Id: " + _contenedor->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido modificar el contenedor por el siguiente motivo:\n" +
				ex->Message);
		}

	}
	private: System::Void dgvContenedores_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		int ContenedorId = Convert::ToInt32(dgvContenedores->Rows[dgvContenedores->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		Contenedor^	_contenedor = Service::QueryContenedorById(ContenedorId);

		txtId->Text = "" + _contenedor->Id;
		txtCapacidadContenedor->Text = "" + _contenedor->CapacidadMax;
	
	}
	private: System::Void dgvContenedores_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
