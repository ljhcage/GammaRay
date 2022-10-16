/*
  timezoneoffsetdatamodel.h

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2017-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Volker Krause <volker.krause@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later OR LicenseRef-KDAB-GammaRay

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.
*/

#ifndef GAMMARAY_TIMEZONEOFFSETDATAMODEL_H
#define GAMMARAY_TIMEZONEOFFSETDATAMODEL_H

#include <QAbstractItemModel>
#include <QTimeZone>

namespace GammaRay {

class TimezoneOffsetDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TimezoneOffsetDataModel(QObject *parent = nullptr);
    ~TimezoneOffsetDataModel() override;

    void setTimezone(const QTimeZone &tz);

    int columnCount(const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    QVector<QTimeZone::OffsetData> m_offsets;
};

}

#endif // GAMMARAY_TIMEZONEOFFSETDATAMODEL_H
