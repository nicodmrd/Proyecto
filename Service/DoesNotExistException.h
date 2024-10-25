#pragma once
namespace SimuladorService {
	public ref class DoesNotExistException : public System::Exception {
	public:
		DoesNotExistException(System::String^ message) : Exception(message) {}
	};
}
