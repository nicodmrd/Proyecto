#pragma once

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GarbageReportForm
	/// </summary>
	public ref class GarbageReportForm : public System::Windows::Forms::Form
	{
	public:
		GarbageReportForm(void)
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
		~GarbageReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Timer^ updateTimer;

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
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Gainsboro;
			chartArea1->AxisX->LabelStyle->Angle = -45;
			chartArea1->AxisX->LabelStyle->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisX->Title = L"Tipos de desechos";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			chartArea1->AxisY->LabelStyle->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			chartArea1->AxisY->LabelStyle->Format = L"N0";
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisY->Title = L"Cantidad de desechos";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea1->BorderColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(57, 41);
			this->chart1->Name = L"chart1";
			series1->BackImageTransparentColor = System::Drawing::Color::Transparent;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Cantidad";
			series1->ToolTip = L"Cantidad: #VALY";
			series1->YValuesPerPoint = 6;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(704, 329);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &GarbageReportForm::chart1_Click);
			// 
			// GarbageReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 416);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"GarbageReportForm";
			this->Text = L"Desechos Reciclados";
			this->Load += gcnew System::EventHandler(this, &GarbageReportForm::GarbageReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GarbageReportForm_Load(System::Object^ sender, System::EventArgs^ e); // REVISA CPP !!!
	private: System::Void UpdateChart(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
