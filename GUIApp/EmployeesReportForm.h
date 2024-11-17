#pragma once

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace Model;
	using namespace SimuladorService;
	/// <summary>
	/// Resumen de EmployeesReportForm
	/// </summary>
	public ref class EmployeesReportForm : public System::Windows::Forms::Form
	{
	public:
		EmployeesReportForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~EmployeesReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ subtitleLabel;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	
	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->subtitleLabel = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->titleLabel->Location = System::Drawing::Point(12, 9);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(314, 32);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Reporte de Empleados";
			this->titleLabel->ForeColor = System::Drawing::Color::Black; // Color de texto
			// 
			// subtitleLabel
			// 
			this->subtitleLabel->AutoSize = true;
			this->subtitleLabel->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->subtitleLabel->Location = System::Drawing::Point(14, 41);
			this->subtitleLabel->Name = L"subtitleLabel";
			this->subtitleLabel->Size = System::Drawing::Size(308, 23);
			this->subtitleLabel->TabIndex = 1;
			this->subtitleLabel->Text = L"Lista de empleados y sus detalles";
			this->subtitleLabel->ForeColor = System::Drawing::Color::Black; // Color de texto
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeight = 29;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 0;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Gainsboro;
			this->chart1->BorderlineColor = System::Drawing::Color::Gray;
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->AxisX->LabelStyle->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisX->Title = L"Tipos de Cargos";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			chartArea1->AxisY->LabelStyle->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisY->Title = L"Cantidad de Empleados";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea1->BorderColor = System::Drawing::Color::Transparent;
			chartArea1->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			legend1->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(50, 80);
			this->chart1->Name = L"chart1";
			series1->BackImageTransparentColor = System::Drawing::Color::Transparent;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			series1->Color = System::Drawing::Color::SteelBlue;
			series1->Legend = L"Legend1";
			series1->Name = L"Cantidad";
			series1->YValuesPerPoint = 6;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(540, 300);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &EmployeesReportForm::chart1_Click);
			// 
			// EmployeesReportForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(638, 400);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->subtitleLabel);
			this->Controls->Add(this->titleLabel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EmployeesReportForm";
			this->Text = L"Encargados por área";
			this->TransparencyKey = System::Drawing::Color::White;
			this->Load += gcnew System::EventHandler(this, &EmployeesReportForm::EmployeesReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EmployeesReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Encargado^>^ listaEncargado = Service::ConsultarEncargados();
		if (listaEncargado != nullptr) {
			// CARGOS: Escaneo, Recoleccion, Transporte y Tratamiento de desechos  
			int escaneo = 0;
			int recoleccion = 0;
			int transporte = 0;
			int tratamiento = 0;
			for each (Encargado ^ e in listaEncargado) {
				String^ cargo = e->Cargo;
				if (cargo == "Escaneo") {
					escaneo++;
				}
				else if (cargo == "Recolección") {
					recoleccion++;
				}
				else if (cargo == "Transporte") {
					transporte++;
				}
				else if (cargo == "Tratamiento de desechos") {
					tratamiento++;
				}
			}
			this->chart1->Series["Cantidad"]->Points->AddXY("Transporte", transporte);
			this->chart1->Series["Cantidad"]->Points->AddXY("Recolección", recoleccion);
			this->chart1->Series["Cantidad"]->Points->AddXY("Escaneo", escaneo);
			this->chart1->Series["Cantidad"]->Points->AddXY("Tratamiento", tratamiento);
		}
	}
	private: System::Void EncargadosChart_Click(System::Object ^ sender, System::EventArgs ^ e) {
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}