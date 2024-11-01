#pragma once

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
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
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~EmployeesReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ EncargadosChart;


	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->EncargadosChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EncargadosChart))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(77, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(455, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Empleados por �rea de la empresa";
			// 
			// EncargadosChart
			// 
			chartArea1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->Name = L"ChartArea1";
			this->EncargadosChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->EncargadosChart->Legends->Add(legend1);
			this->EncargadosChart->Location = System::Drawing::Point(49, 108);
			this->EncargadosChart->Name = L"EncargadosChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			//series1->Name = L"Series1";
			this->EncargadosChart->Series->Add(series1);
			this->EncargadosChart->Size = System::Drawing::Size(507, 291);
			this->EncargadosChart->TabIndex = 2;
			this->EncargadosChart->Text = L"chart1";
			// 
			// EmployeesReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 779);
			this->Controls->Add(this->EncargadosChart);
			this->Controls->Add(this->label2);
			this->Name = L"EmployeesReportForm";
			this->Text = L"Reporte de empleados";
			this->Load += gcnew System::EventHandler(this, &EmployeesReportForm::EmployeesReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EncargadosChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EmployeesReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Suponemos que los datos ya se obtienen por �reas (barco, puerto, cami�n, acopio)
		Dictionary<String^, int>^ empleadosPorArea = gcnew Dictionary<String^, int>();
		empleadosPorArea["Barco"] = 30;    // Cambia estos valores por los datos reales de cada �rea
		empleadosPorArea["Puerto"] = 45;
		empleadosPorArea["Cami�n"] = 20;
		empleadosPorArea["Acopio"] = 35;

		// Limpiar series anteriores (si es necesario)
		EncargadosChart->Series->Add("N�mero de Empleados");
		// A�adir los datos al chart
		int index = 0;
		for each (KeyValuePair<String^, int> areaData in empleadosPorArea) {
			EncargadosChart->Series["N�mero de Empleados"]->Points->Add(areaData.Value);
			EncargadosChart->Series["N�mero de Empleados"]->Points[index]->AxisLabel = areaData.Key;
			EncargadosChart->Series["N�mero de Empleados"]->Points[index]->Label = "Empleados: " + areaData.Value;
			index++;
		}
	}
	};
}
