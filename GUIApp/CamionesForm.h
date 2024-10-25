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
	/// Resumen de CamionesForm
	/// </summary>
	public ref class CamionesForm : public System::Windows::Forms::Form
	{
	public:
		CamionesForm(void)
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
		~CamionesForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtCamionVelocidad;






	private: System::Windows::Forms::TextBox^ txtCamionId;
	private: System::Windows::Forms::Button^ btnAgregarCamion;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtCamionPlaca;
	private: System::Windows::Forms::TextBox^ txtCamionCapacidadCont;
	private: System::Windows::Forms::TextBox^ txtCamionCombustible;
	private: System::Windows::Forms::DataGridView^ dgvCamion;



	private: System::Windows::Forms::Button^ btnModificarCamion;
	private: System::Windows::Forms::Button^ btnEliminarCamion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCamion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MatriculaCamion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CamionContenedores;



	private: System::Windows::Forms::PictureBox^ pictureBox1;










	protected:

















	protected:

		void LoadImage()
		{
			// Cargar la imagen desde una ruta relativa
			pictureBox1->Image = Image::FromFile("camion.png");
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtCamionVelocidad = (gcnew System::Windows::Forms::TextBox());
			this->txtCamionId = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregarCamion = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtCamionPlaca = (gcnew System::Windows::Forms::TextBox());
			this->txtCamionCapacidadCont = (gcnew System::Windows::Forms::TextBox());
			this->txtCamionCombustible = (gcnew System::Windows::Forms::TextBox());
			this->dgvCamion = (gcnew System::Windows::Forms::DataGridView());
			this->IdCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MatriculaCamion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CamionContenedores = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnModificarCamion = (gcnew System::Windows::Forms::Button());
			this->btnEliminarCamion = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(104, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Combustible (L):";
			// 
			// txtCamionVelocidad
			// 
			this->txtCamionVelocidad->Location = System::Drawing::Point(295, 51);
			this->txtCamionVelocidad->Name = L"txtCamionVelocidad";
			this->txtCamionVelocidad->Size = System::Drawing::Size(100, 22);
			this->txtCamionVelocidad->TabIndex = 17;
			// 
			// txtCamionId
			// 
			this->txtCamionId->Location = System::Drawing::Point(295, 23);
			this->txtCamionId->Name = L"txtCamionId";
			this->txtCamionId->Size = System::Drawing::Size(100, 22);
			this->txtCamionId->TabIndex = 16;
			// 
			// btnAgregarCamion
			// 
			this->btnAgregarCamion->Location = System::Drawing::Point(29, 177);
			this->btnAgregarCamion->Name = L"btnAgregarCamion";
			this->btnAgregarCamion->Size = System::Drawing::Size(118, 31);
			this->btnAgregarCamion->TabIndex = 21;
			this->btnAgregarCamion->Text = L"Agregar";
			this->btnAgregarCamion->UseVisualStyleBackColor = true;
			this->btnAgregarCamion->Click += gcnew System::EventHandler(this, &CamionesForm::btnAgregarCamion_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(104, 141);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 16);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Capacidad de contenedores:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(104, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 16);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Id:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(104, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 16);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Velocidad (km/h):";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(104, 113);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 16);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Matrícula (XML-522):";
			// 
			// txtCamionPlaca
			// 
			this->txtCamionPlaca->Location = System::Drawing::Point(295, 107);
			this->txtCamionPlaca->Name = L"txtCamionPlaca";
			this->txtCamionPlaca->Size = System::Drawing::Size(100, 22);
			this->txtCamionPlaca->TabIndex = 19;
			// 
			// txtCamionCapacidadCont
			// 
			this->txtCamionCapacidadCont->Location = System::Drawing::Point(295, 135);
			this->txtCamionCapacidadCont->Name = L"txtCamionCapacidadCont";
			this->txtCamionCapacidadCont->Size = System::Drawing::Size(100, 22);
			this->txtCamionCapacidadCont->TabIndex = 20;
			// 
			// txtCamionCombustible
			// 
			this->txtCamionCombustible->Location = System::Drawing::Point(295, 79);
			this->txtCamionCombustible->Name = L"txtCamionCombustible";
			this->txtCamionCombustible->Size = System::Drawing::Size(100, 22);
			this->txtCamionCombustible->TabIndex = 18;
			// 
			// dgvCamion
			// 
			this->dgvCamion->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCamion->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdCamion, this->MatriculaCamion,
					this->CamionContenedores
			});
			this->dgvCamion->Location = System::Drawing::Point(12, 223);
			this->dgvCamion->Name = L"dgvCamion";
			this->dgvCamion->RowHeadersWidth = 51;
			this->dgvCamion->RowTemplate->Height = 24;
			this->dgvCamion->Size = System::Drawing::Size(459, 269);
			this->dgvCamion->TabIndex = 30;
			this->dgvCamion->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CamionesForm::dgvCamion_CellClick);
			this->dgvCamion->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CamionesForm::dgvCamion_CellContentClick);
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
			this->MatriculaCamion->HeaderText = L"Matricula";
			this->MatriculaCamion->MinimumWidth = 6;
			this->MatriculaCamion->Name = L"MatriculaCamion";
			this->MatriculaCamion->Width = 150;
			// 
			// CamionContenedores
			// 
			this->CamionContenedores->HeaderText = L"Contenedores";
			this->CamionContenedores->MinimumWidth = 6;
			this->CamionContenedores->Name = L"CamionContenedores";
			this->CamionContenedores->Width = 150;
			// 
			// btnModificarCamion
			// 
			this->btnModificarCamion->Location = System::Drawing::Point(193, 177);
			this->btnModificarCamion->Name = L"btnModificarCamion";
			this->btnModificarCamion->Size = System::Drawing::Size(118, 31);
			this->btnModificarCamion->TabIndex = 22;
			this->btnModificarCamion->Text = L"Modificar";
			this->btnModificarCamion->UseVisualStyleBackColor = true;
			this->btnModificarCamion->Click += gcnew System::EventHandler(this, &CamionesForm::btnModificarCamion_Click);
			// 
			// btnEliminarCamion
			// 
			this->btnEliminarCamion->Location = System::Drawing::Point(337, 177);
			this->btnEliminarCamion->Name = L"btnEliminarCamion";
			this->btnEliminarCamion->Size = System::Drawing::Size(118, 31);
			this->btnEliminarCamion->TabIndex = 23;
			this->btnEliminarCamion->Text = L"Eliminar";
			this->btnEliminarCamion->UseVisualStyleBackColor = true;
			this->btnEliminarCamion->Click += gcnew System::EventHandler(this, &CamionesForm::btnEliminarCamion_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 509);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(459, 153);
			this->pictureBox1->TabIndex = 31;
			this->pictureBox1->TabStop = false;
			// 
			// CamionesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(487, 684);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnEliminarCamion);
			this->Controls->Add(this->btnModificarCamion);
			this->Controls->Add(this->dgvCamion);
			this->Controls->Add(this->txtCamionCombustible);
			this->Controls->Add(this->txtCamionCapacidadCont);
			this->Controls->Add(this->txtCamionPlaca);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtCamionVelocidad);
			this->Controls->Add(this->txtCamionId);
			this->Controls->Add(this->btnAgregarCamion);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CamionesForm";
			this->Text = L"Menú de camiones";
			this->Load += gcnew System::EventHandler(this, &CamionesForm::CamionesForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCamion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		void MostrarDatosCamiones() {
			List<Camion^>^ lista_camiones = Service::ConsultarCamion();
			if (lista_camiones != nullptr) {
				dgvCamion->Rows->Clear();
				for (int i = 0; i < lista_camiones->Count; i++) {
					dgvCamion->Rows->Add(gcnew array<String^> {"" +
						lista_camiones[i]->Id,
						lista_camiones[i]->Placa,
						""+ lista_camiones[i]->CapacidadContenedores});
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
	
	private: System::Void btnAgregarCamion_Click(System::Object^ sender, System::EventArgs^ e) {
		try{
			Camion^ _camion = gcnew Camion();
			_camion->Id = Convert::ToInt32(txtCamionId->Text);
			_camion->Velocidad = Convert::ToDouble(txtCamionVelocidad->Text);
			_camion->Placa = txtCamionPlaca->Text;
			_camion->CapacidadContenedores = Convert::ToInt32(txtCamionCapacidadCont->Text);
			_camion->NivelCombustible = Convert::ToDouble(txtCamionCombustible->Text);
			//Service::Agregar(lista,_camion);
			Service::AgregarCamion(_camion);
			MostrarDatosCamiones();
			MessageBox::Show("Se ha agregado un camion");
		}
		catch (Exception^ ex) {
			MessageBox::Show("" + ex->Message);
		}
	}
private: System::Void CamionesForm_Load(System::Object^ sender, System::EventArgs^ e) {
	MostrarDatosCamiones();
}

private: System::Void btnModificarCamion_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ camion_id = txtCamionId->Text->Trim();
	if (camion_id->Equals("")) {
		MessageBox::Show("Debe selecionar id de un camión");
		return;
	}
	try {
		Camion^ _camion = gcnew Camion();

		_camion->Id = Convert::ToInt32(txtCamionId->Text);
		_camion->Velocidad = Convert::ToDouble(txtCamionVelocidad->Text);
		_camion->NivelCombustible = Convert::ToDouble(txtCamionCombustible->Text);
		_camion->Placa = txtCamionPlaca->Text;
		_camion->CapacidadContenedores = Convert::ToInt32(txtCamionCapacidadCont->Text);

		Service::ActualizarCamion(_camion);
		MostrarDatosCamiones();
		MessageBox::Show("Se ha modificado los datos del camion con placa: " + _camion->Placa);
	}
	catch (Exception^ ex) {
		MessageBox::Show("No se ha podido modificar :\n" +
			ex->Message);
	}
}
private: System::Void btnEliminarCamion_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ camion_id = txtCamionId->Text->Trim();
	if (camion_id->Equals("")) {
		MessageBox::Show("Debe seleccionar un encargado");
		return;
	}
	try {
		Service::EliminarCamion(Convert::ToInt32(camion_id));

		MostrarDatosCamiones();
		ClearControls();
		MessageBox::Show("Se ha eliminado el camion con id: " + camion_id + " de manera exitosa.");
	}
	catch (Exception^ ex) {
		MessageBox::Show("No ha sido posible eliminar los datos de un camion por el siguiente motivo:\n" +
			ex->Message);
	}

}
private: System::Void dgvCamion_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int _camionId = Convert::ToInt32(dgvCamion->Rows[dgvCamion->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
	Camion^ _camion = Service::ConsultarCamionPorId(_camionId);

	txtCamionId->Text = "" + _camion->Id;
	txtCamionVelocidad->Text = "" + _camion->Velocidad;
	txtCamionCombustible->Text = "" + _camion->NivelCombustible;
	txtCamionPlaca->Text = _camion->Placa;
	txtCamionCapacidadCont->Text = "" + _camion->CapacidadContenedores;

}
	

private: System::Void dgvCamion_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
