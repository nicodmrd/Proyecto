#include "GarbageReportForm.h"
#include "MyWindowMain.h"

using namespace System::Windows::Forms;
using namespace GUIApp;

System::Void GUIApp::GarbageReportForm::GarbageReportForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    // Inicializa el temporizador
    updateTimer = gcnew System::Windows::Forms::Timer();
    updateTimer->Interval = 1000; // Actualización cada 1 segundo (ajusta según sea necesario)
    updateTimer->Tick += gcnew System::EventHandler(this, &GUIApp::GarbageReportForm::UpdateChart);
    updateTimer->Start();

    // Llama una vez a la actualización inicial
    UpdateChart(nullptr, nullptr);
}

System::Void GUIApp::GarbageReportForm::UpdateChart(System::Object ^ sender, System::EventArgs ^ e)
{
    DataGridView^ desechogridcopia = MyWindowMain::Instance->desechogrid;

    // Limpia los puntos previos del gráfico para evitar duplicados
    this->chart1->Series["Cantidad"]->Points->Clear();

    if (desechogridcopia->Rows->Count > 0)
    {
        int plastico = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["plasticobox"]->Value);
        int vidrio = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["vidriobox"]->Value);
        int carton = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["cartonbox"]->Value);
        int otros = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["otrosbox"]->Value);
    
        // Añade los puntos actualizados al gráfico con los colores correspondientes
        int index;

        index = this->chart1->Series["Cantidad"]->Points->AddXY("Plastico", plastico);
        this->chart1->Series["Cantidad"]->Points[index]->Color = System::Drawing::Color::Red;

        index = this->chart1->Series["Cantidad"]->Points->AddXY("Cartón", carton);
        this->chart1->Series["Cantidad"]->Points[index]->Color = System::Drawing::Color::Green;

        index = this->chart1->Series["Cantidad"]->Points->AddXY("Vidrio", vidrio);
        this->chart1->Series["Cantidad"]->Points[index]->Color = System::Drawing::Color::Blue;

        index = this->chart1->Series["Cantidad"]->Points->AddXY("Otros", otros);
        this->chart1->Series["Cantidad"]->Points[index]->Color = System::Drawing::Color::White;
	}
	else
	{
		// Si no hay datos, muestra un mensaje en el gráfico
		this->chart1->Series["Cantidad"]->Points->AddXY("No hay datos", Convert::ToDouble(0));
    }

}




