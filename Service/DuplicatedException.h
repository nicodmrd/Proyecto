#pragma once
namespace SimuladorService {
	public ref class DuplicatedException : public System::Exception {
	public:
		DuplicatedException(System::String^ message) : Exception(message) {}
	};
}
