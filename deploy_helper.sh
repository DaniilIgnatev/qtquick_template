# Qt App Deployment Helper
# This script runs platform-specific deployment tools after CMake install.

set -e

APP_BUNDLE_PATH="build/src/app/app.app"
QML_DIR="src/ui"

if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS: Use macdeployqt
    if command -v macdeployqt >/dev/null 2>&1; then
        echo "Running macdeployqt on $APP_BUNDLE_PATH"
        macdeployqt "$APP_BUNDLE_PATH" -qmldir="$QML_DIR" -verbose=2
    else
        echo "macdeployqt not found. Please ensure Qt is installed and in PATH."
        exit 1
    fi
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux: Use linuxdeployqt
    if command -v linuxdeployqt >/dev/null 2>&1; then
        echo "Running linuxdeployqt on $APP_BUNDLE_PATH"
        linuxdeployqt "$APP_BUNDLE_PATH" -qmldir="$QML_DIR" -appimage
    else
        echo "linuxdeployqt not found. Please install linuxdeployqt."
        exit 1
    fi
else
    echo "No deployment tool configured for this OS: $OSTYPE"
    exit 1
fi
