inherit cargo systemd

SUMMARY = "Sylphrena input application"
SECTION = "sylphrena-input"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRCREV = "${AUTOREV}"

PR = "r001"
PV = "1.0.0"

SRC_URI = "git://github.com/ShardAi/sylphrena-source.git;protocol=git"

S = "${WORKDIR}/git/sylphrena-input"

CARGO_SRC_DIR=""

SRC_URI += " \
crate://crates.io/daemonize/0.3.0 \
crate://crates.io/libc/0.2.42 \
"

FILES_${PN} += " \
	/lib \
	/lib/syl \
	/lib/syl/res \
        /lib/syl/res/training_text_long \
        /lib/syl/res/training_text_short \
"

NATIVE_SYSTEMD_SUPPORT = "1"
SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "init_sylphrena_input.service"

include sylphrena-input-${PV}.inc
include sylphrena-input.inc

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 ${S}/target/${HOST_SYS}/release/sylphrena-input ${D}${bindir}

             install -d ${D}/${sbindir}
             install -m 0755 ${WORKDIR}/git/sylphrena-init/init_sylphrena_input.sh ${D}/${sbindir}

             install -d ${D}${systemd_unitdir}/system/
             install -m 0644 ${WORKDIR}/git/sylphrena-init/init_sylphrena_input.service ${D}${systemd_unitdir}/system

             install -d ${D}${base_libdir}/syl/res/
             cp ${WORKDIR}/git/resources/training_text_long ${D}${base_libdir}/syl/res/
             cp ${WORKDIR}/git/resources/training_text_short ${D}${base_libdir}/syl/res/
}


