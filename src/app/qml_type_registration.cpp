
// Global includes: Qt, domain headers first (pyramid approach)

#include "qml_type_registration.hpp"

#include <QtQml/qqml.h>

#include "../domain/include/domain.hpp"

void registerQmlTypes() {
    // Example: Register a C++ type for QML
    qmlRegisterType<JoystickViewModel>("App.Domain", 1, 0, "JoystickViewModel");
}
