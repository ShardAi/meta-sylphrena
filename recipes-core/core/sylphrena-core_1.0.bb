SUMMARY = "Sylphrena core application"
SECTION = "sylphrena-core"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

PR = "r001"

SRC_URI = "			\	
	file://syl_socketServer.cpp	\
	file://syl_socketServer.h	\
	file://syl_core.cpp	\
	file://syl_core.h	\
	file://syl_lib.h	\
	file://syl_lib.cpp	\
	file://main.cpp	\
   	file://init_syl.sh 	\
	"

S = "${WORKDIR}"

do_compile() {
	     ${CXX} -std=c++11 -pthread main.cpp syl_core.cpp syl_core.h syl_socketServer.h syl_socketServer.cpp syl_lib.h syl_lib.cpp -o syl_core
}

do_install() {
	     install -d ${D}${sysconfdir}/init.d
	     install -d ${D}${sysconfdir}/rcS.d
	     install -d ${D}${sysconfdir}/rc1.d
	     install -d ${D}${sysconfdir}/rc2.d
	     install -d ${D}${sysconfdir}/rc3.d
	     install -d ${D}${sysconfdir}/rc4.d
	     install -d ${D}${sysconfdir}/rc5.d
	     install -d ${D}${bindir}
	     install -m 0755 syl_core ${D}${bindir}
	     install -m 0755 ${WORKDIR}/init_syl.sh  ${D}${sysconfdir}/init.d/

	     ln -sf ../init.d/init_syl.sh  ${D}${sysconfdir}/rcS.d/S90init_syl
}
