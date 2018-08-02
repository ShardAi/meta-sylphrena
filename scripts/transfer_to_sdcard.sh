#!/bin/bash

sudo dd if=tmp/deploy/images/raspberrypi3/rpi-sylphrena-image-raspberrypi3.rpi-sdimg of=/dev/sdb
sudo sync
