inherit cargo systemd

SUMMARY = "Sylphrena core application"
SECTION = "sylphrena-core"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRCREV = "${AUTOREV}"

PR = "r001"
PV = "1.0.0"

SRC_URI = "git://github.com/ShardAi/sylphrena-source.git;protocol=git"

S = "${WORKDIR}/git/sylphrena-core"

CARGO_SRC_DIR=""

SRC_URI += " \
crate://crates.io/daemonize/0.3.0 \
crate://crates.io/libc/0.2.42 \
"

NATIVE_SYSTEMD_SUPPORT = "1"
SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "init_sylphrena_core.service"

include sylphrena-core-${PV}.inc
include sylphrena-core.inc

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 ${S}/target/${HOST_SYS}/release/sylphrena-core ${D}${bindir}

             install -d ${D}/${sbindir}
             install -m 0755 ${WORKDIR}/git/sylphrena-init/init_sylphrena_core.sh ${D}/${sbindir}

             install -d ${D}${systemd_unitdir}/system/
             install -m 0644 ${WORKDIR}/git/sylphrena-init/init_sylphrena_core.service ${D}${systemd_unitdir}/system
}
