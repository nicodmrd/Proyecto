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

void SimuladorPersistance::Persistance::PersistDesechosTextFile(String^ fileName, Object^ persistObject)
{
    throw gcnew System::NotImplementedException();
}

Object^ SimuladorPersistance::Persistance::LoadDesechosTextFile(String^ fileName)
{
    throw gcnew System::NotImplementedException();
    // TODO: Insertar una instrucción "return" aquí
}

