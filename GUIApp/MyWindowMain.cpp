#include "MyWindowMain.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	GUIApp::MyWindowMain form;
	Application::Run(% form);
}

