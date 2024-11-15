IF OBJECT_ID('dbo.ENCARGADO','U') IS NOT NULL
    DROP TABLE ENCARGADO;
IF OBJECT_ID('dbo.CAMION','U') IS NOT NULL	
	drop table CAMION;
IF OBJECT_ID('dbo.BARCO','U') IS NOT NULL	
	drop table BARCO;
IF OBJECT_ID('dbo.DRON','U') IS NOT NULL	
	drop table DRON;

CREATE TABLE ENCARGADO (
    Id				INT PRIMARY KEY IDENTITY(1,1), 
    Nombre			VARCHAR(20) NOT NULL, 
    Apellido		VARCHAR(20) NOT NULL, 
    Correo			VARCHAR(20) NOT NULL, 
    Edad			INT NOT NULL, 
    Codigo			VARCHAR(20) NOT NULL, 
    Cargo			VARCHAR(20) NOT NULL, 
    Contacto		VARCHAR(20), 
    Foto			IMAGE
);
CREATE TABLE CAMION (
    Id				INT PRIMARY KEY IDENTITY(1,1), 
    Velocidad		DECIMAL(10,2) NULL,
	Combustible		DECIMAL(10,2) NULL,
    Matricula		VARCHAR (10) NOT NULL,
	Capacidad		INT NOT NULL
);
CREATE TABLE BARCO (
    Id				INT PRIMARY KEY IDENTITY(1,1), 
    CapacidadMax	DECIMAL(10,2) NULL,
	Combustible		DECIMAL(10,2) NULL,
    Cantidad		INT NOT NULL	
);
CREATE TABLE DRON (
    Id				INT PRIMARY KEY IDENTITY(1,1), 
    Velocidad		DECIMAL(10,2) NULL,
	Bateria			INT,
    Alcance			DECIMAL(10,2) NULL
);

----------------------------------------------
----------------ENCARGADOS--------------------

IF EXISTS(SELECT * 
		 FROM sysobjects
		 WHERE id = object_id(N'[dbo].[usp_AgregarEncargado]')
				AND OBJECTPROPERTY(id, N'IsProcedure')=1)
BEGIN
	DROP PROCEDURE [dbo].[usp_AgregarEncargado]
END
GO
-- Stored Procedure para Agregar un Vehículo
CREATE PROCEDURE usp_AgregarEncargado(
    @Nombre			VARCHAR(20), 
    @Apellido		VARCHAR(20), 
    @Correo			VARCHAR(20), 
    @Edad			INT, 
    @Codigo			VARCHAR(20), 
    @Cargo			VARCHAR(20), 
    @Contacto		VARCHAR(20), 
    @Foto			IMAGE,
	@Id				INT OUT
) AS
BEGIN
	INSERT INTO ENCARGADO (Nombre, Apellido, Correo, Edad, Codigo, Cargo, Contacto, Foto)
	VALUES (@Nombre, @Apellido, @Correo, @Edad, @Codigo, @Cargo, @Contacto, @Foto);
	SET @Id = SCOPE_IDENTITY()
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ActualizarEncargado]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].[usp_ActualizarEncargado]
END
GO
-- Stored Procedure para Actualizar un Vehículo
CREATE PROCEDURE usp_ActualizarEncargado(
	 @Id				INT,
	 @Nombre			VARCHAR(20), 
     @Apellido			VARCHAR(20), 
     @Correo			VARCHAR(20), 
     @Edad				INT, 
     @Codigo			VARCHAR(20), 
     @Cargo				VARCHAR(20), 
     @Contacto			VARCHAR(20), 
     @Foto				IMAGE
) AS
BEGIN
	 UPDATE ENCARGADO
	 SET Nombre = @Nombre, Apellido = @Apellido, Correo = @Correo, Edad = @Edad, 
	 Codigo = @Codigo, Cargo = @Cargo, Contacto = @Contacto, Foto = @Foto
	 WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_EliminarEncargado]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_EliminarEncargado
END
GO
-- Stored Procedure para Eliminar un Vehículo
CREATE PROCEDURE usp_EliminarEncargado
	 @Id INT
AS
BEGIN
	 DELETE FROM ENCARGADO WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarEncargados]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarEncargados
END
GO
-- Stored Procedure para Consultar Todos los Vehículos
CREATE PROCEDURE usp_ConsultarEncargados
AS
BEGIN
	SELECT * FROM ENCARGADO;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarEncargadosPorId]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarEncargadosPorId
END
GO
-- Stored Procedure para Consultar un Vehículo por Id
CREATE PROCEDURE usp_ConsultarEncargadosPorId
	@Id INT
AS
BEGIN
	SELECT * FROM ENCARGADO WHERE Id = @Id;
END;
GO


----------------------------------------------
------------------CAMIONES---------------------

IF EXISTS(SELECT * 
		 FROM sysobjects
		 WHERE id = object_id(N'[dbo].[usp_AgregarCamion]')
				AND OBJECTPROPERTY(id, N'IsProcedure')=1)
BEGIN
	DROP PROCEDURE [dbo].[usp_AgregarCamion]
END
GO
-- Stored Procedure para Agregar 
CREATE PROCEDURE usp_AgregarCamion(
    @Velocidad		DECIMAL(10,2),
	@Combustible	DECIMAL(10,2),
    @Matricula		VARCHAR (10),
	@Capacidad		INT,
	@Id				INT OUT
) AS

BEGIN
	INSERT INTO CAMION(Velocidad, Combustible, Matricula, Capacidad)
	VALUES (@Velocidad, @Combustible, @Matricula, @Capacidad);
	SET @Id = SCOPE_IDENTITY()
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ActualizarCamion]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].[usp_ActualizarCamion]
END
GO
-- Stored Procedure para Actualizar 
CREATE PROCEDURE usp_ActualizarCamion(
	 @Id			INT,
	 @Velocidad		DECIMAL(10,2),
	 @Combustible	DECIMAL(10,2),
     @Matricula		VARCHAR (10),
	 @Capacidad		INT
) AS
BEGIN
	 UPDATE CAMION
	 SET Velocidad = @Velocidad, Combustible = @Combustible, Matricula = @Matricula, Capacidad = @Capacidad
	 WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_EliminarCamion]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_EliminarCamion
END
GO
-- Stored Procedure para Eliminar 
CREATE PROCEDURE usp_EliminarCamion
	 @Id INT
AS
BEGIN
	 DELETE FROM CAMION WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarCamiones]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarCamiones
END
GO
-- Stored Procedure para Consultar
CREATE PROCEDURE usp_ConsultarCamiones
AS
BEGIN
	SELECT * FROM CAMION;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarCamionPorId]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarCamionPorId
END
GO
-- Stored Procedure para Consultar por Id
CREATE PROCEDURE usp_ConsultarCamionPorId
	@Id INT
AS
BEGIN
	SELECT * FROM CAMION WHERE Id = @Id;
END;
GO


----------------------------------------------
------------------BARCOS----------------------

IF EXISTS(SELECT * 
		 FROM sysobjects
		 WHERE id = object_id(N'[dbo].[usp_AgregarBarco]')
				AND OBJECTPROPERTY(id, N'IsProcedure')=1)
BEGIN
	DROP PROCEDURE [dbo].[usp_AgregarBarco]
END
GO
-- Stored Procedure para Agregar un Vehículo
CREATE PROCEDURE usp_AgregarBarco(
    @CapacidadMax	DECIMAL(10,2), 
    @Combustible	DECIMAL(10,2), 
    @Cantidad		INT,
	@Id				INT OUT
) AS
BEGIN
	INSERT INTO BARCO(CapacidadMax, Combustible, Cantidad)
	VALUES (@CapacidadMax, @Combustible, @Cantidad);
	SET @Id = SCOPE_IDENTITY()
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ActualizarBarco]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].[usp_ActualizarBarco]
END
GO
-- Stored Procedure para Actualizar un Vehículo
CREATE PROCEDURE usp_ActualizarBarco(
	 @Id			INT,
	 @CapacidadMax	DECIMAL(10,2), 
     @Combustible	DECIMAL(10,2), 
     @Cantidad		INT
) AS
BEGIN
	 UPDATE BARCO
	 SET CapacidadMax = @CapacidadMax, Combustible = @Combustible, Cantidad = @Cantidad
	 WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_EliminarBarco]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_EliminarBarco
END
GO
-- Stored Procedure para Eliminar un Vehículo
CREATE PROCEDURE usp_EliminarBarco
	 @Id INT
AS
BEGIN
	 DELETE FROM BARCO WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarBarcos]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarBarcos
END
GO
-- Stored Procedure para Consultar Todos los Vehículos
CREATE PROCEDURE usp_ConsultarBarcos
AS
BEGIN
	SELECT * FROM BARCO;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarBarcoPorId]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarBarcoPorId
END
GO
-- Stored Procedure para Consultar un Vehículo por Id
CREATE PROCEDURE usp_ConsultarBarcoPorId
	@Id INT
AS
BEGIN
	SELECT * FROM BARCO WHERE Id = @Id;
END;
GO



--------------------------------------------
------------------DRON----------------------

IF EXISTS(SELECT * 
		 FROM sysobjects
		 WHERE id = object_id(N'[dbo].[usp_AgregarDron]')
				AND OBJECTPROPERTY(id, N'IsProcedure')=1)
BEGIN
	DROP PROCEDURE [dbo].[usp_AgregarDron]
END
GO
-- Stored Procedure para Agregar
CREATE PROCEDURE usp_AgregarDron(
    @Velocidad	DECIMAL(10,2), 
    @Bateria	INT, 
    @Alcance	DECIMAL(10,2), 
	@Id			INT OUT
) AS
BEGIN
	INSERT INTO DRON(Velocidad, Bateria, Alcance)
	VALUES (@Velocidad, @Bateria, @Alcance);
	SET @Id = SCOPE_IDENTITY()
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ActualizarDron]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].[usp_ActualizarDron]
END
GO
-- Stored Procedure para Actualizar
CREATE PROCEDURE usp_ActualizarDron(
	 @Id			INT,
	 @Velocidad		DECIMAL(10,2), 
     @Bateria		INT, 
     @Alcance		DECIMAL(10,2)
) AS
BEGIN
	 UPDATE DRON
	 SET Velocidad = @Velocidad, Bateria = @Bateria, Alcance = @Alcance
	 WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_EliminarDron]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_EliminarDron
END
GO
-- Stored Procedure para Eliminar
CREATE PROCEDURE usp_EliminarDron
	 @Id INT
AS
BEGIN
	 DELETE FROM DRON WHERE Id = @Id;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarDron]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarDron
END
GO
-- Stored Procedure para Consultar
CREATE PROCEDURE usp_ConsultarDron
AS
BEGIN
	SELECT * FROM DRON;
END;
GO


IF EXISTS(  SELECT * 
			FROM sysobjects
			WHERE id = object_id(N'[dbo].[usp_ConsultarDronPorId]')
			  AND OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
	DROP PROCEDURE [dbo].usp_ConsultarDronPorId
END
GO
-- Stored Procedure para Consultar un Vehículo por Id
CREATE PROCEDURE usp_ConsultarDronPorId
	@Id INT
AS
BEGIN
	SELECT * FROM DRON WHERE Id = @Id;
END;
GO


SELECT * FROM DRON;
SELECT * FROM CAMION;
SELECT * FROM BARCO;
SELECT * FROM ENCARGADO;
