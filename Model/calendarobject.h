//
// Created by Manuel on 15/09/2021.
//

#ifndef APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_CALENDAROBJECT_H
#define APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_CALENDAROBJECT_H

#include <QObject>
#include <QDateTime>
#include <QString>

class CalendarObject : public QObject {
Q_OBJECT
public:

    CalendarObject();

    CalendarObject(const CalendarObject &other);

    virtual ~CalendarObject() = 0;

    const QString &getCalendarName() const;

    void setCalendarName(const QString &calendarName);

    const QString &getName() const;

    void setName(const QString &name);

    const QString &getLocation() const;

    void setLocation(const QString location);

    const QString &getDescription() const;

    void setDescription(const QString &description);

    const QString &getUID() const;

    void setUID(const QString &uid);

    const QDateTime &getCreationDateTime() const;

    void setCreationDateTime(const QDateTime &creationDateTime);

    const QDateTime &getStartDateTime() const;

    void setStartDateTime(const QDateTime &startDateTime);

    const  QDate &getUntilDateRipetition() const;

    void setUntilDateRipetition(const QDate &untilDateRipetition);

    int getTypeRepetition() const;

    void setTypeRepetition(int typeRepetition);

    int getNumRepetition() const;

    void setNumRepetition(int numRepetition);

    unsigned int getPriority() const;

    void setPriority(unsigned int priority);

    std::shared_ptr<const CalendarObject *> getParent() const;

    const QList<QDate> &getExDates() const;

    void setExDates(const QList<QDate> &exDates);

private:
    QString calendarName;
    QString name;
    QString location;
    QString description;
    QString UID;
    int numRepetition;
    int typeRepetition;
    QDateTime creationDateTime;
    unsigned int priority; // [0-9]
    QDateTime startDateTime;
    QDate untilDateRipetition;    // last valid recurrence date. If the object has not recurrencs, it coincides to startDateTime.
    QList<QDate> exDates;
    std::shared_ptr<const CalendarObject *> parent;

};


#endif //APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_CALENDAROBJECT_H
