#include "include/Counter.hpp"

Counter::Counter()
    :
    QObject(),
    m_nValue(0) {}

void Counter::slotInc()
{
    emit counterChanged(++m_nValue);

    if (m_nValue == 5)
    {
        emit goodbye();
    }
}