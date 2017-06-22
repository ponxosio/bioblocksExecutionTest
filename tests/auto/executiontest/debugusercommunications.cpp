#include "debugusercommunications.h"

DebugUserCommunications::DebugUserCommunications() {

}

DebugUserCommunications::~DebugUserCommunications() {

}

void DebugUserCommunications::sendUserMessage(const std::string & message) {
    stream << message << ";";
}

std::string DebugUserCommunications::getUserResponse() {
    return "OK";
}
