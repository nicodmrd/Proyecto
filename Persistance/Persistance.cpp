#include "pch.h"

#include "Persistance.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

SqlConnection^ SimuladorPersistance::Persistance::GetConnection()
{
    SqlConnection^ conn = gcnew SqlConnection();
    //String^ password = "GESTION_DESECHOS";
    String^ password = "uxN3sjWvdajQ";

    //String^ serverName = "db-gestiondesechos.cuaqice5yrvx.us-east-1.rds.amazonaws.com";
    String^ serverName = "200.16.7.140";

    
    conn->ConnectionString = "Server=" + serverName + ";Database = a20217398;User ID = a20217398; Password = " +
        password + ";";
    conn->Open();
    return conn;
}

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
}



// *****************    Definición de los CRUDS - sql   ********************

/*******************    ENCARGADOS  *******/

int SimuladorPersistance::Persistance::AgregarEncargado(Encargado^ encargado)
{
    int encargadoId = 0;
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_AgregarEncargado";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Nombre", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Apellido", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Correo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Edad", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Codigo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Cargo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Contacto", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Foto", System::Data::SqlDbType::Image);

        SqlParameter^ outputIdParam = gcnew SqlParameter("@Id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        cmd->Parameters->Add(outputIdParam);

        cmd->Prepare();
        cmd->Parameters["@Nombre"]->Value = encargado->Nombre;
        cmd->Parameters["@Apellido"]->Value = encargado->Apellido;
        cmd->Parameters["@Correo"]->Value = encargado->Correo;
        cmd->Parameters["@Edad"]->Value = encargado->Edad;
        cmd->Parameters["@Codigo"]->Value = encargado->Codigo;
        cmd->Parameters["@Cargo"]->Value = encargado->Cargo;
        cmd->Parameters["@Contacto"]->Value = encargado->Contacto;
        if (encargado->Foto == nullptr)
            cmd->Parameters["@Foto"]->Value = DBNull::Value;
        else
            cmd->Parameters["@Foto"]->Value = encargado->Foto;

        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

        //Paso 4: Se procesan los resultados
        encargadoId = Convert::ToInt32(cmd->Parameters["@Id"]->Value);
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return encargadoId;
}

List<Encargado^>^ SimuladorPersistance::Persistance::ConsultarEncargados()
{
    List<Encargado^>^ encargadoList = gcnew List<Encargado^>();
    SqlConnection^ conn;
    SqlDataReader^ reader;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarEncargados";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Prepare();

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        while (reader->Read()) {
            
            Encargado^ encargado = gcnew Encargado();
            encargado->Id = Convert::ToInt32(reader["Id"]->ToString());
            encargado->Nombre = reader["Nombre"]->ToString();
            encargado->Apellido = reader["Apellido"]->ToString();
            encargado->Correo = reader["Correo"]->ToString();
            encargado->Edad = Convert::ToInt32(reader["Edad"]->ToString());
            encargado->Codigo = reader["Codigo"]->ToString();
            encargado->Cargo = reader["Cargo"]->ToString();
            encargado->Contacto = reader["Contacto"]->ToString();

            if (!DBNull::Value->Equals(reader["Foto"]))
                encargado->Foto = (array<Byte>^)reader["Foto"];

            encargadoList->Add(encargado);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return encargadoList;
}

int SimuladorPersistance::Persistance::ActualizarEncargado(Encargado^ encargado)
{
    SqlConnection^ conn = nullptr;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_ActualizarEncargado";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);

        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Nombre", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Apellido", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Correo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Edad", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Codigo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Cargo", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Contacto", System::Data::SqlDbType::VarChar, 20);
        cmd->Parameters->Add("@Foto", System::Data::SqlDbType::Image);
        cmd->Prepare();

        cmd->Parameters["@Id"]->Value = encargado->Id;
        cmd->Parameters["@Nombre"]->Value = encargado->Nombre;
        cmd->Parameters["@Apellido"]->Value = encargado->Apellido;
        cmd->Parameters["@Correo"]->Value = encargado->Correo;
        cmd->Parameters["@Edad"]->Value = encargado->Edad;
        cmd->Parameters["@Codigo"]->Value = encargado->Codigo;
        cmd->Parameters["@Cargo"]->Value = encargado->Cargo;
        cmd->Parameters["@Contacto"]->Value = encargado->Contacto;
        if (encargado->Foto == nullptr)
            cmd->Parameters["@Foto"]->Value = DBNull::Value;
        else
            cmd->Parameters["@Foto"]->Value = encargado->Foto;

        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

int SimuladorPersistance::Persistance::EliminarEncargado(int encargadoId)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Se prepara la sentencia
        String^ sqlStr = "dbo.usp_EliminarEncargado";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = encargadoId;

        //Paso 3: Se ejecuta las sentncia SQL
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

Encargado^ SimuladorPersistance::Persistance::ConsultarEncargadoPorId(int encargadoId)
{
    Encargado^ encargado;
    SqlConnection^ conn;
    SqlDataReader^ reader;

    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarEncargadosPorId";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = encargadoId;

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        if (reader->Read()) {
            encargado = gcnew Encargado();

            encargado->Id = Convert::ToInt32(reader["Id"]->ToString());
            encargado->Nombre = reader["Nombre"]->ToString();
            encargado->Apellido = reader["Apellido"]->ToString();
            encargado->Correo = reader["Correo"]->ToString();
            encargado->Edad = Convert::ToInt32(reader["Edad"]->ToString());
            encargado->Codigo = reader["Codigo"]->ToString();
            encargado->Cargo = reader["Cargo"]->ToString();
            encargado->Contacto = reader["Contacto"]->ToString();

            if (!DBNull::Value->Equals(reader["Foto"]))
                encargado->Foto = (array<Byte>^)reader["Foto"];
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return encargado;
}


/*******************    BARCOS  *****************/

int SimuladorPersistance::Persistance::AgregarBarco(Barco^ barco)
{
    int barcoId = 0;
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_AgregarBarco";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@CapacidadMax", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@CapacidadMax"]->Precision = 10;
        cmd->Parameters["@CapacidadMax"]->Scale = 2;
        cmd->Parameters->Add("@Combustible", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Combustible"]->Precision = 10;
        cmd->Parameters["@Combustible"]->Scale = 2;
        cmd->Parameters->Add("@Cantidad", System::Data::SqlDbType::Int);

        SqlParameter^ outputIdParam = gcnew SqlParameter("@Id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        cmd->Parameters->Add(outputIdParam);

        cmd->Prepare();
        cmd->Parameters["@CapacidadMax"]->Value = barco->CapacidadMax;
        cmd->Parameters["@Combustible"]->Value = barco->NivelCombustible;
        cmd->Parameters["@Cantidad"]->Value = barco->CantCoordendas;

        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

        //Paso 4: Se procesan los resultados
        barcoId = Convert::ToInt32(cmd->Parameters["@Id"]->Value);
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return barcoId;
}

List<Barco^>^ SimuladorPersistance::Persistance::ConsultarBarcos()
{
    List<Barco^>^ barcoList = gcnew List<Barco^>();
    SqlConnection^ conn;
    SqlDataReader^ reader;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarBarcos";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Prepare();

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        while (reader->Read()) {

            Barco^ barco = gcnew Barco();

            barco->Id = Convert::ToInt32(reader["Id"]->ToString());
            barco->CapacidadMax = Convert::ToDouble(reader["CapacidadMax"]->ToString());
            barco->NivelCombustible = Convert::ToDouble(reader["Combustible"]->ToString());
            barco->CantCoordendas = Convert::ToInt32(reader["Cantidad"]->ToString());

            barcoList->Add(barco);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return barcoList;
}

int SimuladorPersistance::Persistance::ActualizarBarco(Barco^ barco)
{
    SqlConnection^ conn = nullptr;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_ActualizarBarco";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);

        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@CapacidadMax", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@CapacidadMax"]->Precision = 10;
        cmd->Parameters["@CapacidadMax"]->Scale = 2;
        cmd->Parameters->Add("@Combustible", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Combustible"]->Precision = 10;
        cmd->Parameters["@Combustible"]->Scale = 2;
        cmd->Parameters->Add("@Cantidad", System::Data::SqlDbType::Int);
        cmd->Prepare();

        cmd->Parameters["@Id"]->Value = barco->Id;
        cmd->Parameters["@CapacidadMax"]->Value = barco->CapacidadMax;
        cmd->Parameters["@Combustible"]->Value = barco->NivelCombustible;
        cmd->Parameters["@Cantidad"]->Value = barco->CantCoordendas;

        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

int SimuladorPersistance::Persistance::EliminarBarco(int barcoId)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Se prepara la sentencia
        String^ sqlStr = "dbo.usp_EliminarBarco";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = barcoId;

        //Paso 3: Se ejecuta las sentncia SQL
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

Barco^ SimuladorPersistance::Persistance::ConsultarBarcoPorId(int barcoId)
{
    Barco^ barco;
    SqlConnection^ conn;
    SqlDataReader^ reader;

    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarBarcoPorId";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = barcoId;

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        if (reader->Read()) {
            barco = gcnew Barco();
            barco->Id = Convert::ToInt32(reader["Id"]->ToString());
            barco->CapacidadMax = Convert::ToDouble(reader["CapacidadMax"]->ToString());
            barco->NivelCombustible = Convert::ToDouble(reader["Combustible"]->ToString());
            barco->CantCoordendas = Convert::ToInt32(reader["Cantidad"]->ToString());
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return barco;
}

/*******************    CAMIONES  *****************/
        
int SimuladorPersistance::Persistance::AgregarCamion(Camion^ camion)
{
    int camionId = 0;
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_AgregarCamion";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Velocidad", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Velocidad"]->Precision = 10;
        cmd->Parameters["@Velocidad"]->Scale = 2;
        cmd->Parameters->Add("@Combustible", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Combustible"]->Precision = 10;
        cmd->Parameters["@Combustible"]->Scale = 2;
        cmd->Parameters->Add("@Matricula", System::Data::SqlDbType::VarChar,10);
        cmd->Parameters->Add("@Cantidad", System::Data::SqlDbType::Int);

        SqlParameter^ outputIdParam = gcnew SqlParameter("@Id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        cmd->Parameters->Add(outputIdParam);

        cmd->Prepare();
        cmd->Parameters["@Velocidad"]->Value = camion->Velocidad;
        cmd->Parameters["@Combustible"]->Value = camion->NivelCombustible;
        cmd->Parameters["@Matricula"]->Value = camion->Placa;
        cmd->Parameters["@Cantidad"]->Value = camion->CapacidadContenedores;
        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

        //Paso 4: Se procesan los resultados
        camionId = Convert::ToInt32(cmd->Parameters["@Id"]->Value);
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return camionId;
}

List<Camion^>^ SimuladorPersistance::Persistance::ConsultarCamiones()
{
    List<Camion^>^ camionList = gcnew List<Camion^>();
    SqlConnection^ conn;
    SqlDataReader^ reader;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarCamiones";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Prepare();

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        while (reader->Read()) {

            Camion^ camion = gcnew Camion();

            camion->Id = Convert::ToInt32(reader["Id"]->ToString());
            camion->Velocidad = Convert::ToDouble(reader["Velocidad"]->ToString());
            camion->NivelCombustible = Convert::ToDouble(reader["Combustible"]->ToString());
            camion->Placa = reader["Matricula"]->ToString();
            camion->CapacidadContenedores = Convert::ToInt32(reader["Capacidad"]->ToString());

            camionList->Add(camion);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return camionList;
}

int SimuladorPersistance::Persistance::ActualizarCamion(Camion^ camion)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_ActualizarCamion";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);

        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Velocidad", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Velocidad"]->Precision = 10;
        cmd->Parameters["@Velocidad"]->Scale = 2;
        cmd->Parameters->Add("@Combustible", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Combustible"]->Precision = 10;
        cmd->Parameters["@Combustible"]->Scale = 2;
        cmd->Parameters->Add("@Matricula", System::Data::SqlDbType::VarChar, 10);
        cmd->Parameters->Add("@Cantidad", System::Data::SqlDbType::Int);
        cmd->Prepare();

        cmd->Parameters["@Id"]->Value = camion->Id;
        cmd->Parameters["@Velocidad"]->Value = camion->Velocidad;
        cmd->Parameters["@Combustible"]->Value = camion->NivelCombustible;
        cmd->Parameters["@Matricula"]->Value = camion->Placa;
        cmd->Parameters["@Cantidad"]->Value = camion->CapacidadContenedores;
        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

int SimuladorPersistance::Persistance::EliminarCamion(int camionId)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Se prepara la sentencia
        String^ sqlStr = "dbo.usp_EliminarCamion";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = camionId;

        //Paso 3: Se ejecuta las sentncia SQL
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

Camion^ SimuladorPersistance::Persistance::ConsultarCamionPorId(int camionId)
{
    Camion^ camion;
    SqlConnection^ conn;
    SqlDataReader^ reader;

    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarCamionPorId";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = camionId;

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        if (reader->Read()) {
            camion = gcnew Camion();
            camion->Id = Convert::ToInt32(reader["Id"]->ToString());
            camion->Velocidad = Convert::ToDouble(reader["Velocidad"]->ToString());
            camion->NivelCombustible = Convert::ToDouble(reader["Combustible"]->ToString());
            camion->Placa = reader["Matricula"]->ToString();
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return camion;
}

/*******************    DRONES  *****************/

int SimuladorPersistance::Persistance::AgregarDron(Dron^ dron)
{
    int dronId = 0;
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_AgregarDron";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Velocidad", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Velocidad"]->Precision = 10;
        cmd->Parameters["@Velocidad"]->Scale = 2;
        cmd->Parameters->Add("@Bateria", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Alcance", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Alcance"]->Precision = 10;
        cmd->Parameters["@Alcance"]->Scale = 2;

        SqlParameter^ outputIdParam = gcnew SqlParameter("@Id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        cmd->Parameters->Add(outputIdParam);

        cmd->Prepare();
        cmd->Parameters["@Velocidad"]->Value = dron->Velocidad;
        cmd->Parameters["@Bateria"]->Value = dron->Bateria;
        cmd->Parameters["@Alcance"]->Value = dron->Alcance;
        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

        //Paso 4: Se procesan los resultados
        dronId = Convert::ToInt32(cmd->Parameters["@Id"]->Value);
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return dronId;
}

List<Dron^>^ SimuladorPersistance::Persistance::ConsultarDron()
{
    List<Dron^>^ dronList = gcnew List<Dron^>();
    SqlConnection^ conn;
    SqlDataReader^ reader;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarDron";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Prepare();

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        while (reader->Read()) {

            Dron^ dron = gcnew Dron();

            dron->Id = Convert::ToInt32(reader["Id"]->ToString());
            dron->Velocidad = Convert::ToDouble(reader["Velocidad"]->ToString());
            dron->Bateria = Convert::ToInt32(reader["Bateria"]->ToString());
            dron->Alcance = Convert::ToDouble(reader["Alcance"]->ToString());
            dronList->Add(dron);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return dronList;
}

int SimuladorPersistance::Persistance::ActualizarDron(Dron^ dron)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Abrir y obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia de BD
        String^ sqlStr = "dbo.usp_ActualizarDron";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);

        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Velocidad", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Velocidad"]->Precision = 10;
        cmd->Parameters["@Velocidad"]->Scale = 2;
        cmd->Parameters->Add("@Bateria", System::Data::SqlDbType::Int);
        cmd->Parameters->Add("@Alcance", System::Data::SqlDbType::Decimal);
        cmd->Parameters["@Alcance"]->Precision = 10;
        cmd->Parameters["@Alcance"]->Scale = 2;
        cmd->Prepare();

        cmd->Parameters["@Id"]->Value = dron->Id;
        cmd->Parameters["@Velocidad"]->Value = dron->Velocidad;
        cmd->Parameters["@Bateria"]->Value = dron->Bateria;
        cmd->Parameters["@Alcance"]->Value = dron->Alcance;
        //Paso 3: Ejecutar la sentencia de BD
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Cerrar los objetos de conexión de la BD.
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

int SimuladorPersistance::Persistance::EliminarDron(int dronId)
{
    SqlConnection^ conn;
    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Se prepara la sentencia
        String^ sqlStr = "dbo.usp_EliminarDron";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = dronId;

        //Paso 3: Se ejecuta las sentncia SQL
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (conn != nullptr) conn->Close();
    }
    return 1;
}

Dron^ SimuladorPersistance::Persistance::ConsultarDronPorId(int dronId)
{
    Dron^ dron;
    SqlConnection^ conn;
    SqlDataReader^ reader;

    try {
        //Paso 1: Obtener la conexión a la BD
        conn = GetConnection();

        //Paso 2: Preparar la sentencia SQL
        String^ sqlStr = "dbo.usp_ConsultarDronPorId";
        SqlCommand^ cmd = gcnew SqlCommand(sqlStr, conn);
        cmd->CommandType = System::Data::CommandType::StoredProcedure;
        cmd->Parameters->Add("@Id", System::Data::SqlDbType::Int);
        cmd->Prepare();
        cmd->Parameters["@Id"]->Value = dronId;

        //Paso 3: Ejecutar la sentencia SQL
        reader = cmd->ExecuteReader();

        //Paso 4: Procesar los resultados
        if (reader->Read()) {
            dron = gcnew Dron();
            dron->Id = Convert::ToInt32(reader["Id"]->ToString());
            dron->Velocidad = Convert::ToDouble(reader["Velocidad"]->ToString());
            dron->Bateria = Convert::ToInt32(reader["Bateria"]->ToString());
            dron->Alcance = Convert::ToDouble(reader["Alcance"]->ToString());   
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        //Paso 5: Importante! Cerrar los objetos de conexión a la BD
        if (reader != nullptr) reader->Close();
        if (conn != nullptr) conn->Close();
    }
    return dron;
}

