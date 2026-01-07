
// Global includes: Qt, domain headers first (pyramid approach)

#include "qml_type_registration.hpp"

#include <QtQml/qqml.h>

#include "../domain/include/domain.hpp"

void registerQmlTypes() {
    // Register QML types - this is a reference example
    // Replace with your own types based on requirements
    qmlRegisterType<JoystickViewModel>("App.Domain", 1, 0, "JoystickViewModel");
}
