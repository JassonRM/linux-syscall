/usr/bin/env bash

\cp -rf custom-trace $1
cd arch-x86-entry-syscalls
\cp -f * $1/arch/x86/entry/syscalls
cd ..
