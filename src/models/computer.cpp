/*
   jmbde a BDE Tool for companies
   Copyright (C) 2013-2020  Jürgen Mülbert

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
*/

#include "models/computer.h"

Model::Computer::Computer(QObject *parent)
    : CommonData(parent)
{
    // Set the Model
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable(this->m_tableName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    setIndexes();
}

Model::Computer::~Computer()
{
}

void Model::Computer::setIndexes()
{
    m_ComputerIdIndex = m_model->fieldIndex(QLatin1String("computer_id"));
    m_NameIndex = m_model->fieldIndex(QLatin1String("name"));
    m_SerialNumberIndex = m_model->fieldIndex(QLatin1String("serial_number"));
    m_ServiceTagIndex = m_model->fieldIndex(QLatin1String("service_tag"));
    m_ServiceNumberIndex = m_model->fieldIndex(QLatin1String("service_number"));
    m_MemoryIndex = m_model->fieldIndex(QLatin1String("memory"));
    m_DriveSizeIndex = m_model->fieldIndex(QLatin1String("drive_size"));
    m_DriveTypeIndex = m_model->fieldIndex(QLatin1String("drive_type"));
    m_NetworkIndex = m_model->fieldIndex(QLatin1String("network"));
    m_ActiveIndex = m_model->fieldIndex(QLatin1String("active"));
    m_ReplaceIndex = m_model->fieldIndex(QLatin1String("replace"));
    m_DeviceNameIdIndex = m_model->fieldIndex(QLatin1String("device_name_id"));
    m_DeviceTypeIdIndex = m_model->fieldIndex(QLatin1String("device_type_id"));
    m_EmployeeIdIndex = m_model->fieldIndex(QLatin1String("employe_id"));
    m_PlaceIdIndex = m_model->fieldIndex(QLatin1String("place_id"));
    m_DepartmentIdIndex = m_model->fieldIndex(QLatin1String("department_id"));
    m_ManufacturerIdIndex = m_model->fieldIndex(QLatin1String("manufacturer_id"));
    m_InventoryIdIndex = m_model->fieldIndex(QLatin1String("inventory_id"));
    m_ProcessorIdIndex = m_model->fieldIndex(QLatin1String("processor_id"));
    m_OSIdIndex = m_model->fieldIndex(QLatin1String("os_id"));
    m_ComputerSoftwareIdIndex = m_model->fieldIndex(QLatin1String("computer_software_id"));
    m_PrinterIdIndex = m_model->fieldIndex(QLatin1String("printer_id"));
    m_LastUpdateIndex = m_model->fieldIndex(QLatin1String("last_update"));
}

auto Model::Computer::initializeRelationalModel() -> QSqlRelationalTableModel *
{
    m_model = new QSqlRelationalTableModel(this);

    m_model->setTable(this->m_tableName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    m_model->select();

    return m_model;
}

auto Model::Computer::initializeInputDataModel() -> QSqlRelationalTableModel *
{
    m_model = new QSqlRelationalTableModel(this);

    m_model->setTable(this->m_tableName);

    return m_model;
}

auto Model::Computer::initializeViewModel() -> QSqlTableModel *
{
    m_model->select();

    return m_model;
}

auto Model::Computer::generateTableString(const QString &header) -> QString
{
    QString outString;

    qCDebug(jmbdemodelsLog, "Header: %s ( Columns: %i - Rows: %i )", header.toUtf8().constData(), m_model->columnCount(), m_model->rowCount());

    QList<int> set;

    // Document Title
    outString = QLatin1String("<h1>");
    outString += header;
    outString += QLatin1String("</h1>");
    outString += QLatin1String("<hr />");
    outString += QLatin1String(R"(<table width="100%" cellspacing="0" class="tbl">)");
    outString += QLatin1String("<thead> <tr>");

    for (const auto i : set) {
        qDebug() << "int i = " << i;
        outString += QLatin1String("<th>");
        outString.append(m_model->headerData(i, Qt::Horizontal).toString());
        outString += QLatin1String("</th>");
    }

    return outString;
}

auto Model::Computer::generateFormularString(const QString &header) -> QString
{
    QString outString;

    qCDebug(jmbdemodelsLog, "Header: %s ( Columns: %i - Rows: %i )", header.toUtf8().constData(), m_model->columnCount(), m_model->rowCount());

    QList<int> set;

    // Document Title
    outString = QLatin1String("<h1>");
    outString += header;
    outString += QLatin1String("</h1>");
    outString += QLatin1String("<hr />");

    return outString;
}
