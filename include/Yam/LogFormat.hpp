/**
 * @file LogFormat.hpp
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 14, 2013
 * @brief Contains the @c Tator::Yam::LogFormat class
 */

#ifndef LOGFORMAT_HPP
#define LOGFORMAT_HPP

// Include the required standard library headers
#include <string>
#include <iostream>
#include <sstream>

// Include the required Yam headers
#include <Yam/LogLevel.hpp>

#define DEFAULT_TIME_FORMAT "[%c]" 		//!< The default format of a time, as parsed by @c strftime#define DEFAULT_DEBUG_STRING "[Debug]"  //!< The default string that is associated with a debug message#define DEFAULT_INFO_STRING "[Info]"	//!< The default string that is associated with a info message
#define DEFAULT_WARN_STRING "[Warn]"	//!< The default string that is associated with a warning message
#define DEFAULT_ERROR_STRING "[Error]"	//!< The default string that is associated with a error message

namespace Tator {
namespace Yam {

/**
 * A class that is used by @c Logger to format log messages.
 * @related Logger
 */
class LogFormat {
public:
	/**
	 * Construct a @c LogFormat with optional custom strings
	 * @param timeFormat time format string that is parsed by @c strftime
	 * @param debugString string that is displayed with debug messages
	 * @param infoString string that is displayed with info messages
	 * @param warnString string that is displayed with warning messages
	 * @param errorString string that is displayed with error messages
	 */
	LogFormat(const std::string& timeFormat = DEFAULT_TIME_FORMAT,
			const std::string& debugString = DEFAULT_DEBUG_STRING,
			const std::string& infoString = DEFAULT_INFO_STRING,
			const std::string& warnString = DEFAULT_WARN_STRING,
			const std::string& errorString = DEFAULT_ERROR_STRING);

	/**
	 * Virtual destructor
	 */
	virtual ~LogFormat() {
	}
	;

	/**
	 * Gets the string associated with the specified log level
	 * @param logLevel the @c LogLevel
	 * @return the string
	 */
	virtual const std::string& GetLevelString(int logLevel) const;

	/**
	 * Formats a @c time_t as a string
	 * @param time the @c time_t
	 * @return the string
	 */
	virtual const std::string FormatTime(time_t time) const;

	/**
	 * Formats a string
	 * @param string the string
	 * @return the formatted string
	 */
	virtual const std::string FormatString(const std::string& string) const;

	/**
	 * Formats a variable with an name
	 * @param name the name of the variable, or an empty string if no name
	 * @param value the value of the variable
	 * @return the formatted string
	 * @tparam T the type of the variable
	 */
	template<typename T>
	const std::string FormatVar(const std::string& name, T value) const;

	/**
	 * Prints a log message to a stream
	 * @param stream a reference to the stream to print to
	 * @param level the log level string
	 * @param time the formatted time string
	 * @param message the message to print
	 */
	void PrintLog(std::ostream& stream, const std::string& level,
			const std::string& time, const std::string& message) const;

private:
	const std::string m_timeFormat;  	//!< The time format string
	const std::string m_debugString;	//!< The debug message string
	const std::string m_infoString;		//!< The info message string
	const std::string m_warnString;		//!< The warning message string
	const std::string m_errorString;	//!< The error message string

};

}  // namespace yam
}  // namespace tator

#include <Yam/LogFormat.inl>

#endif /* LOGFORMAT_HPP */
