#include "MyWindowMain.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace GUIApp;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Iniciar la aplicación con la instancia Singleton de MyWindowMain
	Application::Run(MyWindowMain::Instance);
}

