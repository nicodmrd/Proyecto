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
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
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
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Timer^ updateTimer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			int pointCount = 10; // Puedes cambiar este valor seg�n sea necesario

			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			// Configuraci�n del fondo y estilo del gr�fico
			this->chart1->BackColor = System::Drawing::Color::Gainsboro;
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea1->BorderColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			// Configuraci�n de la leyenda
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			legend1->Name = L"Legend1";
			legend1->Enabled = false; // Deshabilitar la leyenda
			this->chart1->Legends->Add(legend1);
			// Posici�n y tama�o del gr�fico
			this->chart1->Location = System::Drawing::Point(57, 60);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(704, 300);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			// Configuraci�n de la serie
			series1->BackImageTransparentColor = System::Drawing::Color::Transparent;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Cantidad";
			series1->YValuesPerPoint = 6;
			series1->ToolTip = "Cantidad: #VALY"; // Configurar el ToolTip para mostrar la cantidad
			this->chart1->Series->Add(series1);
			// Configuraci�n adicional del gr�fico
			this->chart1->ResetAutoValues();

			// T�tulos del gr�fico
			this->chart1->Titles->Clear();
			this->chart1->Titles->Add(String::Format("Cantidad de Desechos Reciclados por Tipo"));  // T�tulo din�mico

			// Configuraci�n de los ejes
			this->chart1->ChartAreas[0]->AxisX->Title = "Tipos de desechos";  // T�tulo del eje X
			this->chart1->ChartAreas[0]->AxisY->Title = "Cantidad de desechos";  // T�tulo del eje Y
			this->chart1->ChartAreas[0]->AxisY->MajorGrid->LineColor = Color::LightGray;  // Color de la cuadr�cula mayor en el eje Y
			this->chart1->ChartAreas[0]->AxisX->MajorGrid->LineColor = Color::LightGray;  // Color de la cuadr�cula mayor en el eje X

			// Aseg�rate de que el gr�fico se dibuje con las columnas (SeriesChartType::Column)
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;  // Tipo de gr�fico de columnas
			this->chart1->Series->Clear();  // Limpiar las series existentes antes de agregar nuevas
			this->chart1->Series->Add(series1);  // A�adir la serie de nuevo si es necesario

			this->chart1->Click += gcnew System::EventHandler(this, &GarbageReportForm::chart1_Click);
			// 
			// GarbageReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 421);
			this->Controls->Add(this->chart1);
			this->MaximizeBox = false; // Ocultar el bot�n de maximizar
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Hacer el borde no redimensionable
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
