#!/bin/bash
for file in [0-9]*.c; do
	cp "$file" "${file%.c}_bonus.c"
done;
