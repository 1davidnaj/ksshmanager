cmake_minimum_required(VERSION 3.0)

project (ksshmanager)

set(QT_MIN_VERSION "5.12.0")
set(KF5_MIN_VERSION "5.57.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)
include(ECMInstallIcons)

# Find Qt modules
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
        Core    # QCommandLineParser, QStringLiteral
        Widgets # QApplication
        )

# Find KDE modules
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
        Config
        Crash
        DocTools
        I18n
        IconThemes
        NotifyConfig
        Notifications
        TextWidgets
        XmlGui
        )

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

ki18n_wrap_ui(ksshmanager_SRCS
        dialogs/add_ssh_session_dialog.ui
        dialogs/settings_dialog.ui)
set(ksshmanager_SRCS main.cpp
        toplevel.h toplevel.cpp
        ssh_session.h ssh_session.cpp
        dialogs/add_ssh_session_dialog.cpp dialogs/add_ssh_session_dialog.h dialogs/add_ssh_session_dialog.ui
        dialogs/settings_dialog.cpp dialogs/settings_dialog.h dialogs/settings_dialog.ui
        )


add_executable(ksshmanager ${ksshmanager_SRCS})

target_link_libraries(ksshmanager
        KF5::ConfigCore
        KF5::ConfigGui
        KF5::Crash
        KF5::I18n
        KF5::IconThemes
        KF5::Notifications
        KF5::NotifyConfig
        KF5::TextWidgets
        KF5::XmlGui
        )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

install(TARGETS ksshmanager ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})