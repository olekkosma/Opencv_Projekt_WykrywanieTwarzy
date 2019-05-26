#include "MyForm.h"

using namespace System;

[STAThreadAttribute]
int main() {
	
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Windows::Forms::Application::Run(gcnew Projektopencv::MyForm());
	return 0;
}