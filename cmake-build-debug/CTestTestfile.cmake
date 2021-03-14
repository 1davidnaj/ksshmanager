# CMake generated Testfile for 
# Source directory: /home/davidnaj/cpp/ksshmanager
# Build directory: /home/davidnaj/cpp/ksshmanager/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/snap/clion/139/bin/cmake/linux/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/davidnaj/cpp/ksshmanager/cmake-build-debug/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
set_tests_properties(appstreamtest PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;184;add_test;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;202;appstreamtest;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;0;;/home/davidnaj/cpp/ksshmanager/CMakeLists.txt;12;include;/home/davidnaj/cpp/ksshmanager/CMakeLists.txt;0;")
