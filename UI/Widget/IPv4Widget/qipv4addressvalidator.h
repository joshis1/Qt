/*****************************************************************************/
/* \file qipv4addressvalidator
 *
 * \brief Validates whether it is a valid ipv4address or not. This file has implementation
 * to start to validate ipv4 address.
 *
 * \author  Shreyas Joshi
 *
 * \copyright
 * The copyright in this material is owned by Shreyas Joshi.
 * It may not be reproduced, used, sold or in any other way exploited or
 * transferred to any third party without the prior written permission of author.
 *
 ******************************************************************************/
#ifndef QIPV4ADDRESSVALIDATOR_H
#define QIPV4ADDRESSVALIDATOR_H

#include <QValidator>

class QIPv4AddressValidator: public QValidator
{
    Q_OBJECT
public:
    // using old compiler otherwise used nullptr
   explicit QIPv4AddressValidator(QObject *parent = 0);
   virtual State validate ( QString & input, int & pos ) const; // using old compiler otherwise used override
private:
};

#endif // QIPV4ADDRESSVALIDATOR_H
