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
	/// Resumen de BarcoForm
	/// </summary>
	public ref class BarcoForm : public System::Windows::Forms::Form
	{
	public:
		BarcoForm(void)
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
		~BarcoForm()
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
	private: System::Windows::Forms::TextBox^ txtBarcoId;
	private: System::Windows::Forms::TextBox^ txtBarcoCapacidad;
	private: System::Windows::Forms::TextBox^ txtBarcoCombustible;
	private: System::Windows::Forms::TextBox^ txtBarcoCantidadCoord;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dgvBarcos;

	private: System::Windows::Forms::Button^ btnAgregarBarco;
	private: System::Windows::Forms::Button^ btnModificarBarco;

	private: System::Windows::Forms::Button^ btnEliminarBarco;






	private: System::Windows::Forms::PictureBox^ imgInterceptor1;
	private: System::Windows::Forms::PictureBox^ imgInterceptor2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdBarco;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CapacidadBarco;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CantCoordenadasBarco;



	private: System::Windows::Forms::PictureBox^ imgInterceptor3;

	protected:
		void LoadImage()
		{
			// Cargar la imagen desde una ruta relativa
			imgInterceptor1->Image = Image::FromFile("interceptor1.png");
			imgInterceptor1->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox
			
			imgInterceptor2->Image = Image::FromFile("interceptor2.png");
			imgInterceptor2->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox
			
			imgInterceptor3->Image = Image::FromFile("interceptor3.png");
			imgInterceptor3->SizeMode = PictureBoxSizeMode::StretchImage;  // Para ajustar la imagen al tamaño del PictureBox

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBarcoId = (gcnew System::Windows::Forms::TextBox());
			this->txtBarcoCapacidad = (gcnew System::Windows::Forms::TextBox());
			this->txtBarcoCombustible = (gcnew System::Windows::Forms::TextBox());
			this->txtBarcoCantidadCoord = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgvBarcos = (gcnew System::Windows::Forms::DataGridView());
			this->IdBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CapacidadBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CantCoordenadasBarco = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAgregarBarco = (gcnew System::Windows::Forms::Button());
			this->btnModificarBarco = (gcnew System::Windows::Forms::Button());
			this->btnEliminarBarco = (gcnew System::Windows::Forms::Button());
			this->imgInterceptor1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgInterceptor2 = (gcnew System::Windows::Forms::PictureBox());
			this->imgInterceptor3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(46, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(46, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Capacidad (kg)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(46, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Combustible (L)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(46, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Cantidad";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(349, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"COORDENADAS ASIGNADAS POR BARCO";
			// 
			// txtBarcoId
			// 
			this->txtBarcoId->Location = System::Drawing::Point(245, 78);
			this->txtBarcoId->Name = L"txtBarcoId";
			this->txtBarcoId->Size = System::Drawing::Size(100, 22);
			this->txtBarcoId->TabIndex = 5;
			// 
			// txtBarcoCapacidad
			// 
			this->txtBarcoCapacidad->Location = System::Drawing::Point(245, 106);
			this->txtBarcoCapacidad->Name = L"txtBarcoCapacidad";
			this->txtBarcoCapacidad->Size = System::Drawing::Size(100, 22);
			this->txtBarcoCapacidad->TabIndex = 6;
			// 
			// txtBarcoCombustible
			// 
			this->txtBarcoCombustible->Location = System::Drawing::Point(245, 134);
			this->txtBarcoCombustible->Name = L"txtBarcoCombustible";
			this->txtBarcoCombustible->Size = System::Drawing::Size(100, 22);
			this->txtBarcoCombustible->TabIndex = 7;
			// 
			// txtBarcoCantidadCoord
			// 
			this->txtBarcoCantidadCoord->Location = System::Drawing::Point(245, 217);
			this->txtBarcoCantidadCoord->Name = L"txtBarcoCantidadCoord";
			this->txtBarcoCantidadCoord->Size = System::Drawing::Size(100, 22);
			this->txtBarcoCantidadCoord->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 37);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(255, 20);
			this->label6->TabIndex = 9;
			this->label6->Text = L"CONFIGURACIÓN POR BARCO";
			// 
			// dgvBarcos
			// 
			this->dgvBarcos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBarcos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdBarco, this->CapacidadBarco,
					this->CantCoordenadasBarco
			});
			this->dgvBarcos->Location = System::Drawing::Point(22, 341);
			this->dgvBarcos->Name = L"dgvBarcos";
			this->dgvBarcos->RowHeadersWidth = 51;
			this->dgvBarcos->RowTemplate->Height = 24;
			this->dgvBarcos->Size = System::Drawing::Size(361, 493);
			this->dgvBarcos->TabIndex = 10;
			this->dgvBarcos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &BarcoForm::dgvBarcos_CellClick);
			// 
			// IdBarco
			// 
			this->IdBarco->HeaderText = L"Id";
			this->IdBarco->MinimumWidth = 6;
			this->IdBarco->Name = L"IdBarco";
			this->IdBarco->Width = 50;
			// 
			// CapacidadBarco
			// 
			this->CapacidadBarco->HeaderText = L"Capacidad (kg)";
			this->CapacidadBarco->MinimumWidth = 6;
			this->CapacidadBarco->Name = L"CapacidadBarco";
			this->CapacidadBarco->Width = 80;
			// 
			// CantCoordenadasBarco
			// 
			this->CantCoordenadasBarco->HeaderText = L"Cantidad (x, y)";
			this->CantCoordenadasBarco->MinimumWidth = 6;
			this->CantCoordenadasBarco->Name = L"CantCoordenadasBarco";
			this->CantCoordenadasBarco->Width = 125;
			// 
			// btnAgregarBarco
			// 
			this->btnAgregarBarco->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAgregarBarco->Location = System::Drawing::Point(22, 271);
			this->btnAgregarBarco->Name = L"btnAgregarBarco";
			this->btnAgregarBarco->Size = System::Drawing::Size(115, 37);
			this->btnAgregarBarco->TabIndex = 11;
			this->btnAgregarBarco->Text = L"Agregar";
			this->btnAgregarBarco->UseVisualStyleBackColor = true;
			this->btnAgregarBarco->Click += gcnew System::EventHandler(this, &BarcoForm::btnAgregarBarco_Click);
			// 
			// btnModificarBarco
			// 
			this->btnModificarBarco->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModificarBarco->Location = System::Drawing::Point(143, 271);
			this->btnModificarBarco->Name = L"btnModificarBarco";
			this->btnModificarBarco->Size = System::Drawing::Size(119, 37);
			this->btnModificarBarco->TabIndex = 12;
			this->btnModificarBarco->Text = L"Modificar";
			this->btnModificarBarco->UseVisualStyleBackColor = true;
			this->btnModificarBarco->Click += gcnew System::EventHandler(this, &BarcoForm::btnModificarBarco_Click);
			// 
			// btnEliminarBarco
			// 
			this->btnEliminarBarco->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminarBarco->Location = System::Drawing::Point(268, 271);
			this->btnEliminarBarco->Name = L"btnEliminarBarco";
			this->btnEliminarBarco->Size = System::Drawing::Size(115, 37);
			this->btnEliminarBarco->TabIndex = 13;
			this->btnEliminarBarco->Text = L"Eliminar";
			this->btnEliminarBarco->UseVisualStyleBackColor = true;
			this->btnEliminarBarco->Click += gcnew System::EventHandler(this, &BarcoForm::btnEliminarBarco_Click);
			// 
			// imgInterceptor1
			// 
			this->imgInterceptor1->Location = System::Drawing::Point(423, 12);
			this->imgInterceptor1->Name = L"imgInterceptor1";
			this->imgInterceptor1->Size = System::Drawing::Size(480, 270);
			this->imgInterceptor1->TabIndex = 14;
			this->imgInterceptor1->TabStop = false;
			// 
			// imgInterceptor2
			// 
			this->imgInterceptor2->Location = System::Drawing::Point(423, 288);
			this->imgInterceptor2->Name = L"imgInterceptor2";
			this->imgInterceptor2->Size = System::Drawing::Size(480, 270);
			this->imgInterceptor2->TabIndex = 15;
			this->imgInterceptor2->TabStop = false;
			// 
			// imgInterceptor3
			// 
			this->imgInterceptor3->Location = System::Drawing::Point(423, 564);
			this->imgInterceptor3->Name = L"imgInterceptor3";
			this->imgInterceptor3->Size = System::Drawing::Size(480, 270);
			this->imgInterceptor3->TabIndex = 16;
			this->imgInterceptor3->TabStop = false;
			// 
			// BarcoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 870);
			this->Controls->Add(this->imgInterceptor3);
			this->Controls->Add(this->imgInterceptor2);
			this->Controls->Add(this->imgInterceptor1);
			this->Controls->Add(this->btnEliminarBarco);
			this->Controls->Add(this->btnModificarBarco);
			this->Controls->Add(this->btnAgregarBarco);
			this->Controls->Add(this->dgvBarcos);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtBarcoCantidadCoord);
			this->Controls->Add(this->txtBarcoCombustible);
			this->Controls->Add(this->txtBarcoCapacidad);
			this->Controls->Add(this->txtBarcoId);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"BarcoForm";
			this->Text = L"Menu de barcos";
			this->Load += gcnew System::EventHandler(this, &BarcoForm::BarcoForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBarcos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgInterceptor3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		void MostrarBarcos() {
			List<Barco^>^ lista_barcos = Service::ConsultarBarcos();
			if (lista_barcos != nullptr) {
				dgvBarcos->Rows->Clear();
				for (int i = 0; i < lista_barcos->Count; i++) {
					dgvBarcos->Rows->Add(gcnew array<String^> {"" + lista_barcos[i]->Id,
						""+lista_barcos[i]->CapacidadMax,
						""+lista_barcos[i]->CantCoordendas});
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
	private: System::Void btnAgregarBarco_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			Barco^ _barco = gcnew Barco();
			_barco->Id = Convert::ToInt32(txtBarcoId->Text);
			_barco->CapacidadMax = Convert::ToDouble(txtBarcoCapacidad->Text);
			_barco->NivelCombustible = Convert::ToDouble(txtBarcoCombustible->Text);
			_barco->CantCoordendas = Convert::ToInt32(txtBarcoCantidadCoord->Text);

			Service::AgregarBarco(_barco);
			MostrarBarcos();
			MessageBox::Show("Se ha agregado un barco con id " + _barco->Id);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se ha podido agregar el barco a la base de datos por el siguiente motivo:\n" +
				ex->Message);
		}
	}
private: System::Void btnEliminarBarco_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ barco_id = txtBarcoId->Text->Trim();
	if (barco_id->Equals("")) {
		MessageBox::Show("Debe seleccionar un barco");
		return;
	}
	try {
		Service::EliminarBarco(Convert::ToInt32(barco_id));

		MostrarBarcos();
		ClearControls();
		MessageBox::Show("Se ha eliminado el barco con Id = " + barco_id + " de manera exitosa.");
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void btnModificarBarco_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ barco_id = txtBarcoId->Text->Trim();
	if (barco_id->Equals("")) {
		MessageBox::Show("Debe seleccionar un barco");
		return;
	}
	try {
		Barco^ _barco = gcnew Barco();
		_barco->Id = Convert::ToInt32(txtBarcoId->Text);
		_barco->CapacidadMax = Convert::ToDouble(txtBarcoCapacidad->Text);
		_barco->NivelCombustible = Convert::ToDouble(txtBarcoCombustible->Text);
		_barco->CantCoordendas = Convert::ToInt32(txtBarcoCantidadCoord->Text);

		Service::ActualizarBarco(_barco);
		MostrarBarcos();
		MessageBox::Show("Se ha podido modificar datos del barco con id: " + _barco->Id);
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void dgvBarcos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	int BarcoId = Convert::ToInt32(dgvBarcos->Rows[dgvBarcos->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
	Barco^ _barco = Service::ConsultarBarcoPorId(BarcoId);

	txtBarcoId->Text = "" + _barco->Id;
	txtBarcoCapacidad->Text = "" + _barco->CapacidadMax;
	txtBarcoCombustible->Text = "" + _barco->NivelCombustible;
	txtBarcoCantidadCoord->Text = "" + _barco->CantCoordendas;
}
private: System::Void BarcoForm_Load(System::Object^ sender, System::EventArgs^ e) {
	MostrarBarcos();
	//PRUEBA GERARDO
}
};
}
