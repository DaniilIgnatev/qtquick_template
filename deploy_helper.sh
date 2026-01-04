# Qt App Deployment Helper
# This script runs platform-specific deployment tools after CMake install.

set -e

APP_BUNDLE_PATH="build/src/app/app.app"
QML_DIR="src/ui"

if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS: Use macdeployqt
    MACDEPLOYQT_LOCAL="macdeployqt"
    if ! command -v macdeployqt >/dev/null 2>&1; then
        if [[ ! -f "$MACDEPLOYQT_LOCAL" ]]; then
            echo "macdeployqt not found. Downloading..."
            # Downloading macdeployqt is not as straightforward as linuxdeployqt; usually requires full Qt install.
            # Attempt to fetch from a known location or instruct user.
            echo "Automatic download of macdeployqt is not supported. Please install Qt and ensure macdeployqt is in your PATH."
            exit 1
        fi
        MACDEPLOYQT_BIN="./$MACDEPLOYQT_LOCAL"
    else
        MACDEPLOYQT_BIN="$(command -v macdeployqt)"
    fi
    echo "Running macdeployqt on $APP_BUNDLE_PATH"
    "$MACDEPLOYQT_BIN" "$APP_BUNDLE_PATH" -qmldir="$QML_DIR" -verbose=2
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux: Use linuxdeployqt
    LINUXDEPLOYQT_LOCAL="linuxdeployqt-continuous-x86_64.AppImage"
    if ! command -v linuxdeployqt >/dev/null 2>&1; then
        if [[ ! -f "$LINUXDEPLOYQT_LOCAL" ]]; then
            echo "linuxdeployqt not found. Downloading..."
            wget -O "$LINUXDEPLOYQT_LOCAL" "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage"
            chmod +x "$LINUXDEPLOYQT_LOCAL"
        fi
        LINUXDEPLOYQT_BIN="./$LINUXDEPLOYQT_LOCAL"
    else
        LINUXDEPLOYQT_BIN="$(command -v linuxdeployqt)"
    fi
    echo "Running linuxdeployqt on $APP_BUNDLE_PATH"
    "$LINUXDEPLOYQT_BIN" "$APP_BUNDLE_PATH" -qmldir="$QML_DIR" -appimage
else
    echo "No deployment tool configured for this OS: $OSTYPE"
    exit 1
fi
