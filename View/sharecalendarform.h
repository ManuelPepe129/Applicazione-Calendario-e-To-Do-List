//
// Created by manue on 26/10/2021.
//

#ifndef APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_SHARECALENDARFORM_H
#define APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_SHARECALENDARFORM_H

#include <QDialog>
#include <QWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QLabel>
#include "../Controller/connectionmanager.h"

/***
 * @brief Form to fill in order to share the calendar with another user.
 * @details There is not any invitation process implemented. So the notification
 * is not needed and the server behaves as if sharees immediately accept invitations.
 * The sharee, a user to whom a calendar has been shared, will have the rights of read and write.
 */

class ShareCalendarForm : public QDialog {
Q_OBJECT
public:
    /**
     * Constructor
     * @param Qwidget parent of the dialog. The default location od the QDialog is centered on top of the parent.
     * @param connectionManagers
     */
    ShareCalendarForm(QWidget *parent, QMap<QString, std::shared_ptr<ConnectionManager>> connectionManagers);

private:
    QWidget *parent;  /**< parent widget of the qdialog */
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QGridLayout *layout;
    QLabel *calendarLabel;
    QComboBox *calendar; /**< name of the calendar that the user want to sharee */
    QLabel *emailLabel;
    QLineEdit *email; /**< email of the the user to whom a calendar has been shared */
    QLabel *nameLabel;
    QLineEdit *name; /**< name of the the user to whom a calendar has been shared */
    QDialogButtonBox *dialogButtonBox;  /**< buttons for closing the dialog and for sharing the calendar */
    QMap<QString, std::shared_ptr<ConnectionManager>> connectionManagers;

    void setupUI();

    /***
     * @brief close the QDialog
     * @details This event handler is called with the given event when Qt receives a window close request for a top-level widget from the window system.
     * @param event
     */
    void closeEvent(QCloseEvent *event) override;

signals:
    /***
     *@brief When shareCalendarFormClosed signal is emitted, the CalendarWidget::onShareCalendarFormClosed slot connected to it is executed
     */
    void shareCalendarFormClosed();

private slots:

 /***
  * @brief calls the function makeShareCalendarRequest of connection manager in order to save the sharing information in the server
  * @details This is called when the signal "accepted" connected to it is emitted.
  * First of all, the function verifies if mandatory fields are filled in.
  * If something misses, a QMessageBox will appear.
  * Otherwise, the function makeShareCalendarRequest is called.
  */
    void onAcceptButtonClicked();
};


#endif //APPLICAZIONE_CALENDARIO_E_TO_DO_LIST_ALL_IN_ONE_SHARECALENDARFORM_H
