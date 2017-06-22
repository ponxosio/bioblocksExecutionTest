#ifndef DEBUGUSERCOMMUNICATIONS_H
#define DEBUGUSERCOMMUNICATIONS_H

#include <sstream>

#include <bioblocksExecution/usercommunications/usercommunicationinterface.h>

class DebugUserCommunications : public UserCommunicationInterface
{
public:
    DebugUserCommunications();
    virtual ~DebugUserCommunications();

    virtual void sendUserMessage(const std::string & message);
    virtual std::string getUserResponse();

    inline std::string getString() {
        return stream.str();
    }

protected:
    std::stringstream stream;
};

#endif // DEBUGUSERCOMMUNICATIONS_H
