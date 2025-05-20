#!/bin/bash

# Check if docs/html/index.html exists
if [ ! -f "docs/html/index.html" ]; then
    echo "Documentation not found. Generating documentation..."
    doxygen Doxyfile
fi

# Get the absolute path to the documentation
DOC_PATH="$(pwd)/docs/html/index.html"

# Open documentation based on OS
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    open -a "Safari" "$DOC_PATH" || open -a "Google Chrome" "$DOC_PATH" || open -a "Firefox" "$DOC_PATH"
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    xdg-open "$DOC_PATH" || firefox "$DOC_PATH" || google-chrome "$DOC_PATH"
else
    echo "Please open $DOC_PATH in your web browser"
fi 