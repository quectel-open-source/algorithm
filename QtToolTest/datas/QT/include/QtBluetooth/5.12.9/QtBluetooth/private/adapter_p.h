/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p adapter_p.h:adapter.cpp org.bluez.all.xml org.bluez.Adapter
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef ADAPTER_P_H
#define ADAPTER_P_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.bluez.Adapter
 */
class OrgBluezAdapterInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.bluez.Adapter"; }

public:
    OrgBluezAdapterInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgBluezAdapterInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> CancelDeviceCreation(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("CancelDeviceCreation"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> CreateDevice(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("CreateDevice"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> CreatePairedDevice(const QString &in0, const QDBusObjectPath &in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("CreatePairedDevice"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> FindDevice(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("FindDevice"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetProperties()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetProperties"), argumentList);
    }

    inline QDBusPendingReply<QList<QDBusObjectPath> > ListDevices()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("ListDevices"), argumentList);
    }

    inline QDBusPendingReply<> RegisterAgent(const QDBusObjectPath &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("RegisterAgent"), argumentList);
    }

    inline QDBusPendingReply<> ReleaseMode()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("ReleaseMode"), argumentList);
    }

    inline QDBusPendingReply<> ReleaseSession()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("ReleaseSession"), argumentList);
    }

    inline QDBusPendingReply<> RemoveDevice(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("RemoveDevice"), argumentList);
    }

    inline QDBusPendingReply<> RequestMode(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("RequestMode"), argumentList);
    }

    inline QDBusPendingReply<> RequestSession()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("RequestSession"), argumentList);
    }

    inline QDBusPendingReply<> SetProperty(const QString &in0, const QDBusVariant &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("SetProperty"), argumentList);
    }

    inline QDBusPendingReply<> StartDiscovery()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("StartDiscovery"), argumentList);
    }

    inline QDBusPendingReply<> StopDiscovery()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("StopDiscovery"), argumentList);
    }

    inline QDBusPendingReply<> UnregisterAgent(const QDBusObjectPath &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("UnregisterAgent"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void DeviceCreated(const QDBusObjectPath &in0);
    void DeviceDisappeared(const QString &in0);
    void DeviceFound(const QString &in0, const QVariantMap &in1);
    void DeviceRemoved(const QDBusObjectPath &in0);
    void PropertyChanged(const QString &in0, const QDBusVariant &in1);
};

namespace org {
  namespace bluez {
    typedef ::OrgBluezAdapterInterface Adapter;
  }
}
#endif
