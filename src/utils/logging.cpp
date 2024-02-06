#include "log/logging.h"


namespace da{



    LogMessage::LogMessage(const std::string &l)
        :level(l), ofs(enable ? std::cerr : __nullstream) {
        stream() << "[" << level << "]\t";
    }
    LogMessage::LogMessage(std::ostream &o):level("ERROR"), ofs(o) {
        stream() << "[" << level << "]\t";
    }

    LogMessage::~LogMessage() {
        stream() << std::endl;
    }

    void LogMessage::Enable(bool _enable) {
        enable = _enable;
    }




}









