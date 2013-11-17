/**
 * @file LogFormat.inl
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 14, 2013
 * @brief Contains the implimentation of the @c Tator::Yam::LogFormat class
 */

namespace Tator {
namespace Yam {

LogFormat::LogFormat(const std::string& timeFormat,
		const std::string& debugString, const std::string& infoString,
		const std::string& warnString, const std::string& errorString) :
				m_timeFormat(timeFormat),
					m_debugString(debugString),
					m_infoString(infoString),
					m_warnString(warnString),
					m_errorString(errorString) {

}

const std::string& LogFormat::GetLevelString(int logLevel) const {
	// Switch the log level and return the correct string
	switch (logLevel) {
	case DEBUG:
		return m_debugString;
		break;
	case INFO:
		return m_infoString;
		break;
	case WARN:
		return m_warnString;
		break;
	case ERROR:
		return m_errorString;
		break;
	default:
		return m_errorString;
		break;
	}
}

const std::string LogFormat::FormatTime(time_t time) const {
	struct tm *splitTime = localtime(&time); // Make into a tm object
	char buff[80]; // Temporary buffer
	strftime(buff, 80, DEFAULT_TIME_FORMAT, splitTime); // Print to the buffer
	return std::string(buff); // Return a string
}

const std::string LogFormat::FormatString(const std::string& string) const {
	return string;
}

template<typename T>
const std::string LogFormat::FormatVar(const std::string& name, T value) const {
	// Write the string to a stream, with a space
	std::stringstream ss;
	ss << value << " ";
	if (name != "") { // If the name isn't empty...
		return name + ": " + ss.str(); // Print with the name and a colon
	}
	return ss.str();
}

void LogFormat::PrintLog(std::ostream& stream, const std::string& level,
		const std::string& time, const std::string& message) const {
	// Print to the stream
	stream << time << " " << level << ": " << message << std::endl;
}

}  // namespace Yam
}  // namespace Tator

