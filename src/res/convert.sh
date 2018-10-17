#!/bin/bash
RESSORCE_DIR="../src/res/"
ORIG_DIR="orig"

convert() {
    echo convert -density 200 "${ORIG_DIR}/${1}.svg" -resize 32x32 -transparent white ${1}.png 
}


convert superscript
convert subscript