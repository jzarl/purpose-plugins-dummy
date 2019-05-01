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

class ShareFailJob : public Purpose::Job
{
    Q_OBJECT
public:
    explicit ShareFailJob(QObject *parent = nullptr)
        : Purpose::Job(parent)
    {}

    void start() override
    {
        qDebug() << "ShareFailJob::start()";
        setError(KJob::UserDefinedError);
        setErrorText(i18n("Failed to share files because ShareFailPlugin always fails."));
        emitResult();
    }

    };

}

class Q_DECL_EXPORT ShareFailPlugin : public Purpose::PluginBase
{
    Q_OBJECT
public:
    ShareFailPlugin(QObject *p, const QVariantList &)
        : Purpose::PluginBase(p)
    {}

    Purpose::Job *createJob() const override
    {
        qDebug() << "ShareFailPlugin::createJob()";
        return new ShareFailJob(nullptr);
    }
};

K_PLUGIN_CLASS_WITH_JSON(ShareFailPlugin, "sharefailplugin.json")

#include "sharefailplugin.moc"
