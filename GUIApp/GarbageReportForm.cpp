#include "GarbageReportForm.h"
#include "MyWindowMain.h"

using namespace System::Windows::Forms;
using namespace GUIApp;

System::Void GUIApp::GarbageReportForm::GarbageReportForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	DataGridView^ desechogridcopia = MyWindowMain::Instance->desechogrid;
	int plastico = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["plasticobox"]->Value);
	int vidrio = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["vidriobox"]->Value);
	int carton = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["cartonbox"]->Value);
	int otros = Convert::ToInt32(desechogridcopia->Rows[0]->Cells["otrosbox"]->Value);


	this->chart1->Series["Cantidad"]->Points->AddXY("Plastico", plastico);
	this->chart1->Series["Cantidad"]->Points->AddXY("Cartón", vidrio);
	this->chart1->Series["Cantidad"]->Points->AddXY("Vidrio", carton);
	this->chart1->Series["Cantidad"]->Points->AddXY("Otros", otros);
}
