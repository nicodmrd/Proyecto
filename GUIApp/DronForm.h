#pragma once

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;
	using namespace SimuladorService;

	/// <summary>
	/// Resumen de DronForm
	/// </summary>
	public ref class DronForm : public System::Windows::Forms::Form
	{
	public:
		DronForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			LoadImage();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~DronForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::PictureBox^ imgDron;
	private: System::Windows::Forms::Label^ label8;




	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;




	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridView^ dgvDron;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdDron;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ VelocidadDron;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BateriaDron;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AlcanceDron;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::TextBox^ txtVelocidad;
	private: System::Windows::Forms::TextBox^ txtBateria;
	private: System::Windows::Forms::TextBox^ txtAlcance;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnEliminar;





	private: System::Windows::Forms::Label^ label2;
	protected:
		void LoadImage()
		{
			// Cargar la imagen desde una ruta relativa
			imgDron->Image = Image::FromFile("dron.png");
			imgDron->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox

		}
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->imgDron = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dgvDron = (gcnew System::Windows::Forms::DataGridView());
			this->IdDron = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->VelocidadDron = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BateriaDron = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AlcanceDron = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->txtVelocidad = (gcnew System::Windows::Forms::TextBox());
			this->txtBateria = (gcnew System::Windows::Forms::TextBox());
			this->txtAlcance = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgDron))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDron))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 17);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 54;
			this->label1->Text = L"CONFIGURACIÓN";
			// 
			// imgDron
			// 
			this->imgDron->Location = System::Drawing::Point(282, 28);
			this->imgDron->Margin = System::Windows::Forms::Padding(2);
			this->imgDron->Name = L"imgDron";
			this->imgDron->Size = System::Drawing::Size(203, 224);
			this->imgDron->TabIndex = 53;
			this->imgDron->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(67, 139);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(108, 13);
			this->label8->TabIndex = 52;
			this->label8->Text = L"ÁREA DE ESCANEO";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 162);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(84, 13);
			this->label7->TabIndex = 50;
			this->label7->Text = L"Alcance-scan L:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 80);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Velocidad (km/h):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 104);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Batería:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 56);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 13);
			this->label3->TabIndex = 60;
			this->label3->Text = L"Id:";
			this->label3->Click += gcnew System::EventHandler(this, &DronForm::label3_Click);
			// 
			// dgvDron
			// 
			this->dgvDron->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDron->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->IdDron, this->VelocidadDron,
					this->BateriaDron, this->AlcanceDron
			});
			this->dgvDron->Location = System::Drawing::Point(11, 273);
			this->dgvDron->Margin = System::Windows::Forms::Padding(2);
			this->dgvDron->Name = L"dgvDron";
			this->dgvDron->RowHeadersWidth = 51;
			this->dgvDron->RowTemplate->Height = 24;
			this->dgvDron->Size = System::Drawing::Size(506, 76);
			this->dgvDron->TabIndex = 62;
			this->dgvDron->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DronForm::dgvDron_CellClick);
			this->dgvDron->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DronForm::dgvDron_CellContentClick);
			// 
			// IdDron
			// 
			this->IdDron->HeaderText = L"Id";
			this->IdDron->MinimumWidth = 6;
			this->IdDron->Name = L"IdDron";
			this->IdDron->Width = 50;
			// 
			// VelocidadDron
			// 
			this->VelocidadDron->HeaderText = L"Velocidad";
			this->VelocidadDron->MinimumWidth = 6;
			this->VelocidadDron->Name = L"VelocidadDron";
			this->VelocidadDron->Width = 150;
			// 
			// BateriaDron
			// 
			this->BateriaDron->HeaderText = L"Batería";
			this->BateriaDron->MinimumWidth = 6;
			this->BateriaDron->Name = L"BateriaDron";
			this->BateriaDron->Width = 150;
			// 
			// AlcanceDron
			// 
			this->AlcanceDron->HeaderText = L"Alcance";
			this->AlcanceDron->Name = L"AlcanceDron";
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(150, 53);
			this->txtId->Margin = System::Windows::Forms::Padding(2);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(76, 20);
			this->txtId->TabIndex = 63;
			// 
			// txtVelocidad
			// 
			this->txtVelocidad->Location = System::Drawing::Point(150, 77);
			this->txtVelocidad->Margin = System::Windows::Forms::Padding(2);
			this->txtVelocidad->Name = L"txtVelocidad";
			this->txtVelocidad->Size = System::Drawing::Size(76, 20);
			this->txtVelocidad->TabIndex = 64;
			// 
			// txtBateria
			// 
			this->txtBateria->Location = System::Drawing::Point(150, 101);
			this->txtBateria->Margin = System::Windows::Forms::Padding(2);
			this->txtBateria->Name = L"txtBateria";
			this->txtBateria->Size = System::Drawing::Size(76, 20);
			this->txtBateria->TabIndex = 65;
			// 
			// txtAlcance
			// 
			this->txtAlcance->Location = System::Drawing::Point(150, 159);
			this->txtAlcance->Margin = System::Windows::Forms::Padding(2);
			this->txtAlcance->Name = L"txtAlcance";
			this->txtAlcance->Size = System::Drawing::Size(76, 20);
			this->txtAlcance->TabIndex = 66;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAgregar->Location = System::Drawing::Point(31, 196);
			this->btnAgregar->Margin = System::Windows::Forms::Padding(2);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(79, 24);
			this->btnAgregar->TabIndex = 67;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &DronForm::btnAgregar_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(131, 196);
			this->btnActualizar->Margin = System::Windows::Forms::Padding(2);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(79, 24);
			this->btnActualizar->TabIndex = 68;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &DronForm::btnActualizar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(82, 224);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(2);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(79, 24);
			this->btnEliminar->TabIndex = 69;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &DronForm::btnEliminar_Click);
			// 
			// DronForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 360);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->txtAlcance);
			this->Controls->Add(this->txtBateria);
			this->Controls->Add(this->txtVelocidad);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->dgvDron);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imgDron);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"DronForm";
			this->Text = L"Menu drone scanner";
			this->Load += gcnew System::EventHandler(this, &DronForm::DronForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgDron))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDron))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		void ShowDron() {
			List<Dron^>^ dronList = Service::QueryDron();
			if (dronList != nullptr) {
				dgvDron->Rows->Clear();
				for (int i = 0; i < dronList->Count; i++) {
					dgvDron->Rows->Add(gcnew array<String^> {"" + dronList[i]->Id,
						"" + dronList[i]->Velocidad,
						"" + dronList[i]->Bateria,
						"" + dronList[i]->Alcance});
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
	private: System::Void btnAgregarDron_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			Dron^ dron = gcnew Dron();
			dron->Id = Convert::ToInt32(txtId->Text);
			dron->Velocidad = Convert::ToDouble(txtVelocidad->Text);
			dron->Bateria = Convert::ToInt32(txtBateria->Text);
			dron->Alcance = Convert::ToDouble(txtAlcance->Text);

			Service::AddDron(dron);
			ShowDron();
			MessageBox::Show("Se ha agregado un dron con id " + dron->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido agregar el dron a la base de datos por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	private: System::Void btnActualizarDron_Click_1(System::Object^ sender, System::EventArgs^ e) {
		String^ dron_Id = txtId->Text->Trim();
		if (dron_Id->Equals("")) {
			MessageBox::Show("Debe selecionar id de un camión");
			return;
		}
		try {
			Dron^ dron = gcnew Dron();

			dron->Id = Convert::ToInt32(txtId->Text);
			dron->Velocidad = Convert::ToDouble(txtVelocidad->Text);
			dron->Bateria = Convert::ToInt32(txtBateria->Text);
			dron->Alcance = Convert::ToDouble(txtAlcance->Text);

			Service::UpdateDron(dron);
			MessageBox::Show("Se ha podido actualizado los datos del dron-escaner");
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}
	}
	private: System::Void DronForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ShowDron();
	}
	private: System::Void txtVelocidadDron_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtBateria_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtAlcanceScan_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dronId = txtId->Text->Trim();
		if (dronId->Equals("")) {
			MessageBox::Show("Debe seleccionar un dron");
			return;
		}
		try {
			Service::DeleteDron(Convert::ToInt32(dronId));

			ShowDron();
			ClearControls();
			MessageBox::Show("Se ha eliminado el dron con id: " + dronId + " de manera exitosa.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("No ha sido posible eliminar los datos de un camion por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	private: System::Void dgvDron_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			Dron^ dron = gcnew Dron();

			dron->Id = Convert::ToInt32(txtId->Text);
			dron->Velocidad = Convert::ToDouble(txtVelocidad->Text);
			dron->Bateria = Convert::ToInt32(txtBateria->Text);
			dron->Alcance = Convert::ToDouble(txtAlcance->Text);

			Service::AddDron(dron);
			ShowDron();
			MessageBox::Show("Se ha agregado un dron con id " + dron->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido agregar el encargado a la base de datos por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dron_id = txtId->Text->Trim();
		if (dron_id->Equals("")) {
			MessageBox::Show("Debe seleccionar el dron");
			return;
		}
		try {
			Dron^ dron = gcnew Dron();

			dron->Id = Convert::ToInt32(txtId->Text);
			dron->Velocidad = Convert::ToDouble(txtVelocidad->Text);
			dron->Bateria = Convert::ToInt32(txtBateria->Text);
			dron->Alcance = Convert::ToDouble(txtAlcance->Text);

			Service::UpdateDron(dron);
			ShowDron();
			MessageBox::Show("Se ha podido modificar datos del dron con id " + dron->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido modificar los datos del dron por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dron_id = txtId->Text->Trim();
		if (dron_id->Equals("")) {
			MessageBox::Show("Debe seleccionar el dron");
			return;
		}
		try {
			Service::DeleteDron(Convert::ToInt32(dron_id));
			ShowDron();
			ClearControls();
			MessageBox::Show("Se ha eliminado el dron con Id = " + dron_id + " de manera exitosa.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("No ha sido posible eliminar los datos del dron por el siguiente motivo:\n" +
				ex->Message);
		}
	}
	private: System::Void dgvDron_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int dronId = Convert::ToInt32(dgvDron->Rows[dgvDron->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		Dron^ _dron = Service::QueryDronById(dronId);
		txtId->Text = "" + _dron->Id;
		txtVelocidad->Text = "" + _dron->Velocidad;
		txtBateria->Text = "" + _dron->Bateria;
		txtAlcance->Text = "" + _dron->Alcance;
	}
	};
}
