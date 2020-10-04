#!/bin/bash

echo "Copying files to " $1
cp -rfv custom-trace Makefile $1
cd arch-x86-entry-syscalls
cp -fv * $1/arch/x86/entry/syscalls
cd ..
