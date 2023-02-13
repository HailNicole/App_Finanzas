#include "languagenotifier.h"

LanguageNotifier::LanguageNotifier(QObject *parent) :
QObject(parent)
{
    installEventFilter(this);
}

bool LanguageNotifier::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        emit languageChanged();
        return false;
    }

    return QObject::eventFilter(obj, event);
}
