/*
 Copyright 2019 Johannes Zarl-Zierl <johannes@zarl-zierl.at>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License as
 published by the Free Software Foundation; either version 2 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 MA 02110-1301, USA.

 SPDX-License-Identifier: GPL-2.0-or-later
*/

#include <purpose/pluginbase.h>

#include <KPluginFactory>
#include <KLocalizedString>
#include <QDebug>

namespace {

class ShareSuccessJob : public Purpose::Job
{
    Q_OBJECT
public:
    explicit ShareSuccessJob(QObject *parent = nullptr)
        : Purpose::Job(parent)
    {}

    void start() override
    {
        qDebug() << "ShareSuccessJob::start()";
        QJsonArray urlsJson = data().value(QStringLiteral("urls")).toArray();
        qDebug() << "urls:" << urlsJson;
        setOutput( {{ QStringLiteral("url"), QString::fromUtf8("https://www.example.com/uploads/latest") }});
        emitResult();
        qDebug() << "ShareSuccessJob::start() done.";
    }

    };

}

class Q_DECL_EXPORT ShareSuccessPlugin : public Purpose::PluginBase
{
    Q_OBJECT
public:
    ShareSuccessPlugin(QObject *p, const QVariantList &)
        : Purpose::PluginBase(p)
    {}

    Purpose::Job *createJob() const override
    {
        qDebug() << "ShareSuccessPlugin::createJob()";
        return new ShareSuccessJob(nullptr);
    }
};

K_PLUGIN_CLASS_WITH_JSON(ShareSuccessPlugin, "sharesuccessplugin.json")

#include "sharesuccessplugin.moc"
