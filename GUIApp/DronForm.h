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
	private: System::Windows::Forms::Button^ Cancel_button;

	private: System::Windows::Forms::Button^ Ok_button;






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
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->Ok_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgDron))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDron))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(105, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 16);
			this->label1->TabIndex = 54;
			this->label1->Text = L"CONFIGURACIÓN";
			// 
			// imgDron
			// 
			this->imgDron->Location = System::Drawing::Point(376, 34);
			this->imgDron->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->imgDron->Name = L"imgDron";
			this->imgDron->Size = System::Drawing::Size(271, 276);
			this->imgDron->TabIndex = 53;
			this->imgDron->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(89, 171);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(134, 16);
			this->label8->TabIndex = 52;
			this->label8->Text = L"ÁREA DE ESCANEO";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 199);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 16);
			this->label7->TabIndex = 50;
			this->label7->Text = L"Alcance-scan L:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(35, 98);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 16);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Velocidad (km/h):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 16);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Batería:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 16);
			this->label3->TabIndex = 60;
			this->label3->Text = L"Id:";
			this->label3->Click += gcnew System::EventHandler(this, &DronForm::label3_Click);
			// 
			// dgvDron
			// 
			this->dgvDron->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDron->ColumnHeadersHeight = 29;
			this->dgvDron->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->IdDron, this->VelocidadDron,
					this->BateriaDron, this->AlcanceDron
			});
			this->dgvDron->Location = System::Drawing::Point(15, 336);
			this->dgvDron->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgvDron->Name = L"dgvDron";
			this->dgvDron->RowHeadersVisible = false;
			this->dgvDron->RowHeadersWidth = 51;
			this->dgvDron->RowTemplate->Height = 24;
			this->dgvDron->Size = System::Drawing::Size(675, 94);
			this->dgvDron->TabIndex = 62;
			this->dgvDron->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DronForm::dgvDron_CellClick);
			this->dgvDron->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DronForm::dgvDron_CellContentClick);
			// 
			// IdDron
			// 
			this->IdDron->HeaderText = L"Id";
			this->IdDron->MinimumWidth = 6;
			this->IdDron->Name = L"IdDron";
			// 
			// VelocidadDron
			// 
			this->VelocidadDron->HeaderText = L"Velocidad";
			this->VelocidadDron->MinimumWidth = 6;
			this->VelocidadDron->Name = L"VelocidadDron";
			// 
			// BateriaDron
			// 
			this->BateriaDron->HeaderText = L"Batería";
			this->BateriaDron->MinimumWidth = 6;
			this->BateriaDron->Name = L"BateriaDron";
			// 
			// AlcanceDron
			// 
			this->AlcanceDron->HeaderText = L"Alcance";
			this->AlcanceDron->MinimumWidth = 6;
			this->AlcanceDron->Name = L"AlcanceDron";
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(200, 65);
			this->txtId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(100, 22);
			this->txtId->TabIndex = 63;
			// 
			// txtVelocidad
			// 
			this->txtVelocidad->Location = System::Drawing::Point(200, 95);
			this->txtVelocidad->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtVelocidad->Name = L"txtVelocidad";
			this->txtVelocidad->Size = System::Drawing::Size(100, 22);
			this->txtVelocidad->TabIndex = 64;
			// 
			// txtBateria
			// 
			this->txtBateria->Location = System::Drawing::Point(200, 124);
			this->txtBateria->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBateria->Name = L"txtBateria";
			this->txtBateria->Size = System::Drawing::Size(100, 22);
			this->txtBateria->TabIndex = 65;
			// 
			// txtAlcance
			// 
			this->txtAlcance->Location = System::Drawing::Point(200, 196);
			this->txtAlcance->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtAlcance->Name = L"txtAlcance";
			this->txtAlcance->Size = System::Drawing::Size(100, 22);
			this->txtAlcance->TabIndex = 66;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAgregar->Location = System::Drawing::Point(41, 241);
			this->btnAgregar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(105, 30);
			this->btnAgregar->TabIndex = 67;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &DronForm::btnAgregar_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(175, 241);
			this->btnActualizar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(105, 30);
			this->btnActualizar->TabIndex = 68;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &DronForm::btnActualizar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->Location = System::Drawing::Point(109, 276);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(105, 30);
			this->btnEliminar->TabIndex = 69;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &DronForm::btnEliminar_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->CausesValidation = false;
			this->Cancel_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancel_button->Location = System::Drawing::Point(421, 448);
			this->Cancel_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(115, 37);
			this->Cancel_button->TabIndex = 71;
			this->Cancel_button->Text = L"Cancelar";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &DronForm::Cancel_button_Click);
			// 
			// Ok_button
			// 
			this->Ok_button->CausesValidation = false;
			this->Ok_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ok_button->Location = System::Drawing::Point(175, 448);
			this->Ok_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Ok_button->Name = L"Ok_button";
			this->Ok_button->Size = System::Drawing::Size(115, 37);
			this->Ok_button->TabIndex = 70;
			this->Ok_button->Text = L"Aceptar";
			this->Ok_button->UseVisualStyleBackColor = true;
			this->Ok_button->Click += gcnew System::EventHandler(this, &DronForm::Ok_button_Click);
			// 
			// DronForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 496);
			this->ControlBox = false;
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->Ok_button);
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
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
		List<Dron^>^ lista_drones_original = Service::QueryDron();
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
	private: System::Void Ok_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void Cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
	Service::RevertirCambiosDron(lista_drones_original);
	ShowDron();
	this->Close();
}
};
}
