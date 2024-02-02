#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 input_directory"
    exit 1
fi

input_directory=$1

# Check if libreoffice is installed
if ! command -v libreoffice &> /dev/null; then
    echo "libreoffice is not installed. Please install the libreoffice package."
    exit 1
fi

# Convert DOCX files to PDF
for file in "$input_directory"/*.docx; do
    if [ -f "$file" ]; then
        output_file="${file%.*}.pdf"
        libreoffice --headless --convert-to pdf --outdir "$input_directory" "$file"
        if [ $? -eq 0 ]; then
            echo "Conversion completed successfully: $file -> $output_file"
        else
            echo "Conversion failed: $file"
        fi
    fi
done
