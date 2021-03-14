#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'add_ssh_session_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_SSH_SESSION_DIALOG_H
#define UI_ADD_SSH_SESSION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSshSessionDialog
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *add;
    QGridLayout *gridLayout;
    QLineEdit *user;
    QLineEdit *ip;
    QLabel *userLabel;
    QLabel *ipLabel;
    QLabel *nameLabel;
    QLineEdit *name;

    void setupUi(QWidget *AddSshSessionDialog)
    {
        if (AddSshSessionDialog->objectName().isEmpty())
            AddSshSessionDialog->setObjectName(QString::fromUtf8("AddSshSessionDialog"));
        AddSshSessionDialog->resize(373, 142);
        gridLayout_2 = new QGridLayout(AddSshSessionDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        add = new QPushButton(AddSshSessionDialog);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout_2->addWidget(add, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        user = new QLineEdit(AddSshSessionDialog);
        user->setObjectName(QString::fromUtf8("user"));

        gridLayout->addWidget(user, 1, 1, 1, 1);

        ip = new QLineEdit(AddSshSessionDialog);
        ip->setObjectName(QString::fromUtf8("ip"));

        gridLayout->addWidget(ip, 2, 1, 1, 1);

        userLabel = new QLabel(AddSshSessionDialog);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        gridLayout->addWidget(userLabel, 1, 0, 1, 1);

        ipLabel = new QLabel(AddSshSessionDialog);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));

        gridLayout->addWidget(ipLabel, 2, 0, 1, 1);

        nameLabel = new QLabel(AddSshSessionDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        name = new QLineEdit(AddSshSessionDialog);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(AddSshSessionDialog);

        QMetaObject::connectSlotsByName(AddSshSessionDialog);
    } // setupUi

    void retranslateUi(QWidget *AddSshSessionDialog)
    {
        AddSshSessionDialog->setWindowTitle(tr2i18n("AddSshSessionDialog", nullptr));
        add->setText(tr2i18n("Add", nullptr));
        user->setPlaceholderText(tr2i18n("root", nullptr));
        ip->setText(tr2i18n("00.00.00.00", nullptr));
        userLabel->setText(tr2i18n("User", nullptr));
        ipLabel->setText(tr2i18n("Ip", nullptr));
        nameLabel->setText(tr2i18n("Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSshSessionDialog: public Ui_AddSshSessionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_SSH_SESSION_DIALOG_H

