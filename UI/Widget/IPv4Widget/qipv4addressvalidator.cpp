/*****************************************************************************/
/* \file qipv4addressvalidator
 *
 * \brief Validates whether it is a valid ipv4address or not. This file has
 * implementation to start to validate ipv4 address.
 *
 * \author  Shreyas Joshi
 *
 * \copyright
 * The copyright in this material is owned by Shreyas Joshi.
 * It may not be reproduced, used, sold or in any other way exploited or
 * transferred to any third party without the prior written permission of author.
 *
 ******************************************************************************/
#include "qipv4addressvalidator.h"

/******************************************************************************/
/* \fn  QIPv4AddressValidator
 *
 * \param none
 *
 * \return This is the constructor of QIPv4AddressValidator;
 *
 * \verbatim
 * \endverbatim
 *****************************************************************************/
QIPv4AddressValidator::QIPv4AddressValidator(QObject *parent)
{
     Q_UNUSED(parent)
}

/******************************************************************************/
/* \fn  validate
 *
 * \param input, and cursor position after writing the character in Line Edit
 *
 * \return This is the validate function of QIPv4AddressValidator class; It returns
 * Acceptable State if the input is valid otherwise invalid state.
 *
 * \brief  This checks whether each subnet is not more than 255.
 * Also, a zero in the subnet means the next digit cannot be filled in the same subnet.
 * 1<space>3 is considred as 13 and is allowed by the user.
 * 00 or 01 or 02.. is not allowed
 * 256 is not allowed since it is more than 255
 *
 * \verbatim
 * \endverbatim
 *****************************************************************************/
QValidator::State QIPv4AddressValidator::validate(QString &input, int &pos) const
{
    int prev_cursor_pos = 0;
    // backspace -- very beginning
    if( pos == 0)
    {
        return Acceptable;
    }
    if( pos == 4 || pos == 8 || pos == 12)
    {
        // crossing '.' delimeter
        prev_cursor_pos = pos - 2;
    }
    else
    {
        prev_cursor_pos = pos -1;
    }
    // Is it a space
    if(input.at(prev_cursor_pos).isDigit())
    {
        int digit = input.at(prev_cursor_pos).digitValue();
        if(prev_cursor_pos != 0 && prev_cursor_pos != 4 && prev_cursor_pos != 8 )
        {
            // the 2nd pos in each subnet
            if(prev_cursor_pos == 1 || prev_cursor_pos == 9 || prev_cursor_pos == 13)
            {
                // MSB in its subnet
                if( input.at(prev_cursor_pos-1).isDigit())
                {
                    if(input.at(prev_cursor_pos-1).digitValue() == 0)
                    {
                        // can't have 0 and number
                        return Invalid;
                    }
                }
            }
            // this means it is the last pos in each subnet
            else
            {
                int tensplaceVal = 0;
                int hundredsplaceVal= 0;
                if(input.at(prev_cursor_pos-2).isDigit())
                {
                    if(input.at(prev_cursor_pos-2).digitValue() == 0)
                    {
                        // can't have 0 and number
                        return Invalid;
                    }
                    // check the middle is present or not
                    if(input.at(prev_cursor_pos-1).isDigit())
                    {
                        tensplaceVal = input.at(prev_cursor_pos-1).digitValue() * 10;
                    }
                    else
                    {
                        if(input.at(prev_cursor_pos-2).isDigit())
                        {
                            // 1 space 3 is actually 13.
                            tensplaceVal = input.at(prev_cursor_pos-2).digitValue() * 10;
                            // no hundreds place
                            hundredsplaceVal = -1;
                        }
                    }
                    if(input.at(prev_cursor_pos-2).isDigit() && hundredsplaceVal != -1)
                    {
                        hundredsplaceVal = input.at(prev_cursor_pos-2).digitValue() * 100;
                    }
                    int number = hundredsplaceVal + tensplaceVal + digit;
                    if( number < 0 || number > 255)
                    {
                        return Invalid;
                    }
                }
            }
        }
    }
    return Acceptable;
}
