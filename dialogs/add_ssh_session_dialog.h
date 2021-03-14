//
// Created by davidnaj on 14.03.21.
//

#ifndef KSSHMANAGER_ADD_SSH_SESSION_DIALOG_H
#define KSSHMANAGER_ADD_SSH_SESSION_DIALOG_H

#include <QDialog>
#include <QObject>
#include "toplevel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddSshSessionDialog; }
QT_END_NAMESPACE

class AddSshSessionDialog : public QDialog {
Q_OBJECT

public:
    explicit AddSshSessionDialog(TopLevel *parent = nullptr);

    ~AddSshSessionDialog() override;

private:
    TopLevel* m_topLevel;

    Ui::AddSshSessionDialog *ui;

    void addSshSession();
};

#endif //KSSHMANAGER_ADD_SSH_SESSION_DIALOG_H
