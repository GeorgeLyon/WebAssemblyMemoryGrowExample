#!/bin/bash

clang \
--target=wasm32 \
-nostdlib \
-Wl,--no-entry \
-Wl,--export=write_value_at \
-Wl,--allow-undefined \
write_value_at.c \
-o write_value_at.wasm