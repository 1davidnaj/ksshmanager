//
// Created by davidnaj on 14.03.21.
//

#ifndef KSSHMANAGER_SETTINGS_DIALOG_H
#define KSSHMANAGER_SETTINGS_DIALOG_H

#include <QDialog>
#include "toplevel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsDialog; }
QT_END_NAMESPACE

class SettingsDialog : public QDialog {
Q_OBJECT

public:
    explicit SettingsDialog(TopLevel *parent = nullptr);

    ~SettingsDialog() override;

private:
    TopLevel* m_topLevel;

    QMap<int, SshSession> m_sshSessionsList;

    Ui::SettingsDialog *ui;

    void selectedSessionIndexChanged();
    void deleteSshSession();
    void saveAndClose();
};

#endif //KSSHMANAGER_SETTINGS_DIALOG_H
