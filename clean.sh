#!/bin/bash

pushd tool
make clean
popd

pushd kpayload
make clean
popd

pushd installer
make clean
popd

rm -f ps4-hen-vtx.bin payload.js
