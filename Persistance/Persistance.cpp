#include "pch.h"

#include "Persistance.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

//Definición de los metodos para persistir
void SimuladorPersistance::Persistance::PersistBinaryFile(String^ fileName, Object^ persistObject)
{
    FileStream^ file;
    BinaryFormatter^ formatter = gcnew BinaryFormatter();
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        formatter->Serialize(file, persistObject);
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (file != nullptr) file->Close();
    }
}

Object^ SimuladorPersistance::Persistance::LoadBinaryFile(String^ fileName)
{
    FileStream^ file;
    Object^ result;
    BinaryFormatter^ formatter;
    try {
        if (File::Exists(fileName)) {
            file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
            formatter = gcnew BinaryFormatter();
            result = formatter->Deserialize(file);
        }
    }
    catch (Exception^) {
        //throw ex;
    }
    finally {
        if (file != nullptr) file->Close();
    }
    return result;
}


int cantPlastico = 0, cantVidrio = 0, cantCarton = 0, cantOtros = 0;

Object^ SimuladorPersistance::Persistance::LoadTextFile(String^ fileName)
{
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<Desecho^>();
    try {
        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);

        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            array<String^>^ record = line->Split('|');

            for each (String ^ tipo in record) {
                Desecho^ _desecho = gcnew Desecho();
                _desecho->Tipo = tipo;
                if (tipo->Equals("Plastico")) {
                    cantPlastico++;
                }
                else if (tipo->Equals("Vidrio")) {
                    cantVidrio++;
                }
                else if (tipo->Equals("Carton")) {
                    cantCarton++;
                }
                else if (tipo->Equals("Otros")) {
                    cantOtros++;
                }
                ((List<Desecho^>^)result)->Add(_desecho);
            }
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (reader != nullptr) reader->Close();
        if (file != nullptr) file->Close();
    }
    return result;
}


