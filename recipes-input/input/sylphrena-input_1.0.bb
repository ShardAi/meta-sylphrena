SUMMARY = "Sylphrena input application"
SECTION = "input"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

PR = "r001"

SRC_URI = "			\	
	file://syl_socketClient.cpp	\
	file://syl_socketClient.h	\
	file://main.cpp	\
	"

S = "${WORKDIR}"

do_compile() {
	     ${CXX} -std=c++11 main.cpp syl_socketClient.cpp syl_socketClient.h -o syl_input
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 syl_input ${D}${bindir}
}
