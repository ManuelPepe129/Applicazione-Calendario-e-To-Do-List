#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QDialogButtonBox>
#include "../Controller/connectionManager.h"
#include "calendarchoicedialog.h"

namespace Ui {
    class LoginForm;
}

/**
 *  @brief Form to log in the calendarName server
 *
 */

class LoginForm : public QDialog {
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr, ConnectionManager *connectionManager = nullptr);

    ~LoginForm();

    /// @brief set the ConnectionManager
    void setConnectionManager(ConnectionManager *connectionManager);

private
    slots:

            /// @brief buttonClicked callback
            void onLoginButtonClicked();

    /** @brief checks the login reply
     * @details if the reply has no errors, accept and close the widget
     */
    void responseHandler(QNetworkReply *reply);

private:
    Ui::LoginForm *ui;
    std::shared_ptr<ConnectionManager *> connectionManager;

    QGroupBox *groupBox;
    QGridLayout *layout;
    QFormLayout *formLayout;

    QLabel *userLabel;
    QLineEdit *user;
    QLabel *passwordLabel;
    QLineEdit *password;
    QDialogButtonBox *dialogButtonBox;

    QMetaObject::Connection connection;
};

#endif // LOGINFORM_H
