/**
 * @file Logger.inl
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 13, 2013
 * @brief Contains the implimentation of the @c Tator::Yam::Logger class
 */

namespace Tator {
namespace Yam {

template<class Format>
Logger<Format>::Logger() :
				m_loggerOutputs(),
					m_logFormat() {
}

template<class Format>
Logger<Format>::Logger(const Format& logFormat) :
				m_loggerOutputs(),
					m_logFormat(logFormat) {

}

template<class Format>
Logger<Format>::Logger(std::ostream* outputStream, int logLevel) :
				m_loggerOutputs(),
					m_logFormat() {
	// Add the ostream
	RegisterLogger(outputStream, logLevel);

}

template<class Format>
Logger<Format>::Logger(const Format& logFormat, std::ostream* outputStream,
		int logLevel) :
				m_loggerOutputs(),
					m_logFormat(logFormat) {
	// Add the ostream
	RegisterLogger(outputStream, logLevel);

}

template<class Format>
void Logger<Format>::RegisterLogger(std::ostream* outputStream, int logLevels) {
	// Insert it into the map
	m_loggerOutputs[outputStream] = logLevels;
}

template<class Format>
bool Logger<Format>::UnregisterLogger(std::ostream* outputStream) {
	// Remove it from the map, and return true if successful
	return m_loggerOutputs.erase(outputStream) > 0;
}

template<class Format>
template<typename T>
inline void Logger<Format>::Log(int logLevel, T value,
		const std::string& name) {
	// Iterate through the map
	for (std::map<std::ostream*, int>::iterator it = m_loggerOutputs.begin();
			it != m_loggerOutputs.end(); ++it) {
		// If the stream takes the log level...
		if (it->second & logLevel) {
			// Format and print to the stream
			m_logFormat.PrintLog(*(it->first),
					m_logFormat.GetLevelString(logLevel),
					m_logFormat.FormatTime(time(0)),
					m_logFormat.FormatVar(name, value));
		}
	}
}

template<class Format>
template<typename T>
inline void Logger<Format>::Debug(T value, const std::string& name) {
	Log(DEBUG, value, name);
}

template<class Format>
template<typename T>
inline void Logger<Format>::Info(T value, const std::string& name) {
	Log(INFO, value, name);
}

template<class Format>
template<typename T>
inline void Logger<Format>::Warn(T value, const std::string& name) {
	Log(WARN, value, name);
}

template<class Format>
template<typename T>
inline void Logger<Format>::Error(T value, const std::string& name) {
	Log(ERROR, value, name);
}

template<class Format>
void Logger<Format>::LogRaw(int logLevel, const std::string& string) {
	// Iterate through the map
	for (std::map<std::ostream*, int>::iterator it = m_loggerOutputs.begin();
			it != m_loggerOutputs.end(); ++it) {
		// If the stream takes the log level...
		if (it->second & logLevel) {
			// Print out the raw string
			*(it->first) << string << std::endl;
		}
	}
}

template<class Format>
template<typename T>
const std::string Logger<Format>::Var(const std::string& name, T value) {
	return m_logFormat.FormatVar(name, value); // Format the variable
}

}  // namespace yam
}  // namespace tator

