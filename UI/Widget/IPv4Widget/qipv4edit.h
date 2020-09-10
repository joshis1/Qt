/*****************************************************************************/
/* \file qipv4edit.h
 *
 * \brief  creates custom widget- subclass of QWidget for IPv4 Address.
 *
 * \author  Shreyas Joshi
 *
 * \copyright
 * The copyright in this material is owned by Shreyas Joshi.
 * It may not be reproduced, used, sold or in any other way exploited or
 * transferred to any third party without the prior written permission of author.
 *
 ******************************************************************************/
#ifndef QIPV4EDIT_H
#define QIPV4EDIT_H

#include <QWidget>

class QHBoxLayout;
class QLineEdit;
class QIPv4AddressValidator;

class QIPv4Edit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString getIpv4Address READ getIpv4Address WRITE setIpv4Address NOTIFY signalIpv4AddressChanged)
public:
    /* explicit to avoid any implicit type conversion **/
    explicit QIPv4Edit(QWidget *parent = 0);
    ~QIPv4Edit();
    void setIpv4Address(QString &ipv4Address);
    QString getIpv4Address() const;
    bool isEditReallyFinished(const QString &ipv4Address) const;

signals:
    /* Application can connect to this signal in order to know whether data
     is ready or not **/
    void signalIpv4AddressChanged();

public slots:
    /* When the editing is finished this will be triggered **/
    void slotUpdateIpv4Address();

private:
    // TBD - use smart pointers instead of traditional once using more modern compiler.
    QHBoxLayout *pLayout;
    QLineEdit *pLineEditIPv4;
    QIPv4AddressValidator *pIpv4Validator;
    QString m_ipv4Address;
};

#endif // QIPV4EDIT_H
