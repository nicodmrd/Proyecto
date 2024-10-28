#include "pch.h"

#include "Service.h"
#include "DuplicatedException.h"
#include "DoesNotExistException.h"

using namespace System::IO;

//------------------------------------Encargados----------------------------------------------
void SimuladorService::Service::AgregearEncargado(Encargado^ encargado)
{
    for each (Encargado ^ _encargado in lista_encargados) {
        if (_encargado->Id == encargado->Id)
            throw gcnew DuplicatedException("El encargado con el id ingresado ya existe en la base de datos.");
    }
    lista_encargados->Add(encargado);
    Persistance::PersistBinaryFile(BIN_ENCARGADO_FILE_NAME, lista_encargados);
}
void SimuladorService::Service::ActualizarEncargado(Encargado^ encargado)
{
    for (int i = 0; i < lista_encargados->Count; i++) {
        if (lista_encargados[i]->Id == encargado->Id) {
            lista_encargados[i] = encargado;
            Persistance::PersistBinaryFile(BIN_ENCARGADO_FILE_NAME, lista_encargados);
            return;
        }
    }
    throw gcnew DoesNotExistException("El encargado no existe en la base de datos.");
}
void SimuladorService::Service::EliminarEncargado(int EncargadoId)
{
    for (int i = 0; i < lista_encargados->Count; i++) {
        if (lista_encargados[i]->Id == EncargadoId) {
            lista_encargados->RemoveAt(i);
            Persistance::PersistBinaryFile(BIN_ENCARGADO_FILE_NAME, lista_encargados);
            return;
        }
    }
    throw gcnew DoesNotExistException("El encargado no existe en la base de datos.");
}
List<Encargado^>^ SimuladorService::Service::ConsultarEncargados()
{
    try {
        lista_encargados = (List<Encargado^>^)Persistance::LoadBinaryFile(BIN_ENCARGADO_FILE_NAME);
        if (lista_encargados == nullptr)
            lista_encargados = gcnew List<Encargado^>();
    }
    catch (FileNotFoundException^ ) {
    }
    return lista_encargados;
}
Encargado^ SimuladorService::Service::ConsultarEncargadoPorId(int EncargadoId)
{
    lista_encargados = ConsultarEncargados();
    for (int i = 0; i < lista_encargados->Count; i++) {
        if (lista_encargados[i]->Id == EncargadoId) {
            return lista_encargados[i];
        }
    }
    return nullptr;
}

void SimuladorService::Service::RevertirCambiosEncargado(List<Encargado^>^ listaoriginal)
{
    Persistance::PersistBinaryFile(BIN_ENCARGADO_FILE_NAME, listaoriginal);
}


//--------------------------------------------Camiones------------------------------------------
void SimuladorService::Service::AgregarCamion(Camion^ camion)
{
    for each (Camion ^ _camion in lista_camiones) {
        if (_camion->Id == camion->Id)
            throw gcnew DuplicatedException("El camion con el id ingresado ya existe en la base de datos.");
    }
    lista_camiones->Add(camion);
    Persistance::PersistBinaryFile(BIN_CAMION_FILE_NAME, lista_camiones);
    Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);

}
void SimuladorService::Service::ActualizarCamion(Camion^ camion)
{
    for (int i = 0; i < lista_camiones->Count; i++) {
        if (lista_camiones[i]->Id == camion->Id) {
            lista_camiones[i] = camion;
            Persistance::PersistBinaryFile(BIN_CAMION_FILE_NAME, lista_camiones);
            Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);
            return;
        }
    }
    throw gcnew DoesNotExistException("El camión ingresado no existe en la base de datos.");
}
void SimuladorService::Service::EliminarCamion(int CamionId)
{
    for (int i = 0; i < lista_camiones->Count; i++) {
        if (lista_camiones[i]->Id == CamionId) {
            lista_camiones->RemoveAt(i);
            Persistance::PersistBinaryFile(BIN_CAMION_FILE_NAME, lista_camiones);
            Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);
            return;
        }
    }
    throw gcnew DoesNotExistException("El camión ingresado no existe en la base de datos.");
}
List<Camion^>^ SimuladorService::Service::ConsultarCamion()
{
    try {
        lista_camiones = (List<Camion^>^)Persistance::LoadBinaryFile(BIN_CAMION_FILE_NAME);
        if (lista_camiones == nullptr)    lista_camiones = gcnew List<Camion^>();
    }
    catch (FileNotFoundException^) {
    }
    return lista_camiones;
}
Camion^ SimuladorService::Service::ConsultarCamionPorId(int CamionId)
{
    lista_camiones = ConsultarCamion();
    for (int i = 0; i < lista_camiones->Count; i++) {
        if (lista_camiones[i]->Id == CamionId) {
            return lista_camiones[i];
        }
    }
    return nullptr;
}

void SimuladorService::Service::RevertirCambiosCamion(List<Camion^>^ listaoriginal)
{
    Persistance::PersistBinaryFile(BIN_CAMION_FILE_NAME, listaoriginal);
}

//------------------------------------------Barcos--------------------------------------------------
void SimuladorService::Service::AgregarBarco(Barco^ barco_center) {
    for each (Barco ^ barco in barcoList) {
        if (barco->Id == barco_center->Id)
            throw gcnew DuplicatedException("El barco ya existe en la base de datos.");
    }
    barcoList->Add(barco_center);
    Persistance::PersistBinaryFile(BIN_BARCO_FILE_NAME, barcoList);
}
void SimuladorService::Service::ActualizarBarco(Barco^ barco_center) {
    for (int i = 0; i < barcoList->Count; i++) {
        if (barcoList[i]->Id == barco_center->Id) {
            barcoList[i] = barco_center;
            Persistance::PersistBinaryFile(BIN_BARCO_FILE_NAME, barcoList);
            return;
        }
    }
    throw gcnew DuplicatedException("El barco no existe en la base de datos.");
}
void SimuladorService::Service::EliminarBarco(int barco_center) {
    for (int i = 0; i < barcoList->Count; i++) {
        if (barcoList[i]->Id == barco_center) {
            barcoList->RemoveAt(i);
            Persistance::PersistBinaryFile(BIN_BARCO_FILE_NAME, barcoList);
            return;
        }
    }
    throw gcnew DoesNotExistException("El barco no existe en la base de datos.");
}
List<Barco^>^ SimuladorService::Service::ConsultarBarcos() {
    try {
        barcoList = (List<Barco^>^)Persistance::LoadBinaryFile(BIN_BARCO_FILE_NAME);
        if (barcoList== nullptr)    
            barcoList = gcnew List<Barco^>();
    }
    catch (FileNotFoundException^ ex) {
        throw ex;
    }
    return barcoList;
}
Barco^ SimuladorService::Service::ConsultarBarcoPorId(int barco_center) {
    for (int i = 0; i < barcoList->Count; i++) {
        if (barcoList[i]->Id == barco_center) {
            return barcoList[i];
        }
    }
    return nullptr;
}
void SimuladorService::Service::RevertirCambiosBarco(List<Barco^>^ listaoriginal)
{
    Persistance::PersistBinaryFile(BIN_BARCO_FILE_NAME, listaoriginal);
}

//-----------------------------------------Contenedores--------------------------------------------------
void SimuladorService::Service::AddContenedor(Contenedor^ contenedor_center) {
    for each (Contenedor ^ contenedor in contenedorList) {
        if (contenedor->Id == contenedor_center->Id)
            throw gcnew DuplicatedException("El contenedor ya existe en la base de datos.");
    }
    contenedorList->Add(contenedor_center);
    //Persistance::PersistXMLFile(XML_CONTENEDOR_FILE_NAME, contenedorList);
    Persistance::PersistBinaryFile(BIN_CONTENEDOR_FILE_NAME, contenedorList);
    //Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);
}
void SimuladorService::Service::UpdateContenedor(Contenedor^ contenedor_center) {
    for (int i = 0; i < contenedorList->Count; i++) {
        if (contenedorList[i]->Id == contenedor_center->Id) {
            contenedorList[i] = contenedor_center;
            //Persistance::PersistXMLFile(XML_CONTENEDOR_FILE_NAME, contenedorList);
            Persistance::PersistBinaryFile(BIN_CONTENEDOR_FILE_NAME, contenedorList);
            //Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);
            return;
        }
    }
    throw gcnew DuplicatedException("El contenedor no existe en la base de datos.");
}
void SimuladorService::Service::DeleteContenedor(int contenedor_center) {
    for (int i = 0; i < contenedorList->Count; i++) {
        if (contenedorList[i]->Id == contenedor_center) {
            contenedorList->RemoveAt(i);
            Persistance::PersistBinaryFile(BIN_CONTENEDOR_FILE_NAME, contenedorList);
            //Persistance::PersistBinaryFile(BIN_COORDENADAS_FILE_NAME, coordendas_list);
            return;
        }
    }
    throw gcnew DoesNotExistException("El contenedor no existe en la base de datos.");
}
List<Contenedor^>^ SimuladorService::Service::QueryAllContenedor() {
    //contenedorList = gcnew List<Contenedor^>();
    try {
        //robotsList = (List<RobotWaiter^>^)Persistance::LoadRobotWaitersTextFile(TXT_ROBOT_FILE_NAME);
        //contenedorList = (List<Contenedor^>^)Persistance::LoadContenedorXmlFile(XML_CONTENEDOR_FILE_NAME);
        contenedorList = (List<Contenedor^>^)Persistance::LoadBinaryFile(BIN_CONTENEDOR_FILE_NAME);
        if (contenedorList == nullptr)
            contenedorList = gcnew List<Contenedor^>();
    }
    catch (FileNotFoundException^ ex) {
        throw ex;
    }
    return contenedorList;
}
Contenedor^ SimuladorService::Service::QueryContenedorById(int contenedor_center) {
    for (int i = 0; i < contenedorList->Count; i++) {
        if (contenedorList[i]->Id == contenedor_center) {
            return contenedorList[i];
        }
    }
    return nullptr;
}

void SimuladorService::Service::RevertirCambiosContenedor(List<Contenedor^>^ listaoriginal)
{
    Persistance::PersistBinaryFile(BIN_CONTENEDOR_FILE_NAME, listaoriginal);
}

//-----------------------------------------Dron--------------------------------------------------
void SimuladorService::Service::AddDron(Dron^ DronId) {
    if (dronList->Count > 0) {
        throw gcnew Exception("Solo se puede agregar un único dron.");
    }
    dronList->Add(DronId);
    Persistance::PersistBinaryFile(BIN_DRON_FILE_NAME, dronList);
}

void SimuladorService::Service::UpdateDron(Dron^ DronId) {
    if (dronList->Count == 0) {
        throw gcnew DoesNotExistException("No hay dron en la base de datos para actualizar.");
    }

    if (dronList[0]->Id == DronId->Id) {
        dronList[0] = DronId;
        Persistance::PersistBinaryFile(BIN_DRON_FILE_NAME, dronList);
    }
    else {
        throw gcnew DoesNotExistException("El código del dron no existe en la base de datos.");
    }
}
void SimuladorService::Service::DeleteDron(int DronId) {
    if (dronList->Count == 0) {
        throw gcnew DoesNotExistException("No hay dron en la base de datos para eliminar.");
    }

    if (dronList[0]->Id == DronId) {
        dronList->Clear();  // Elimina el único dron
        Persistance::PersistBinaryFile(BIN_DRON_FILE_NAME, dronList);
    }
    else {
        throw gcnew DoesNotExistException("El código del dron no existe en la base de datos.");
    }
}
List<Dron^>^ SimuladorService::Service::QueryDron() {
    try {
        dronList = (List<Dron^>^)Persistance::LoadBinaryFile(BIN_DRON_FILE_NAME);
        if (dronList == nullptr)
            dronList = gcnew List<Dron^>();
    }
      catch (FileNotFoundException^ ex) {
          throw ex;
    }
    return dronList;
}
Dron^ SimuladorService::Service::QueryDronById(int DronId) {
    dronList = QueryDron();
    if (dronList->Count > 0 && dronList[0]->Id == DronId) {
        return dronList[0];
    }
    return nullptr;

}

void SimuladorService::Service::RevertirCambiosDron(List<Dron^>^ listaoriginal)
{
    Persistance::PersistBinaryFile(BIN_DRON_FILE_NAME, listaoriginal);
}

String^ SimuladorService::Service::TiposDesechosSistema(Protocol protocol, int _cantPlastico, int _cantVidrio, int _cantCarton, int _cantOtros)
{
    String^ result;
    try {
        desechoList = (List<Desecho^>^)Persistance::LoadTextFile(TXT_DESECHOS_FILE_NAME);
        String^ message;
        switch (protocol) {
        case Protocol::UART:
            message = "PLASTICO=" + Convert::ToString(_cantPlastico) +
                ",VIDRIO=" + Convert::ToString(_cantVidrio) +
                ",CARTON=" + Convert::ToString(_cantCarton) +
                ",OTROS=" + Convert::ToString(_cantOtros) + "\n";
            result = message;
            break;

        case Protocol::NMEA:
            result = "";
            break;
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    return result;
}
