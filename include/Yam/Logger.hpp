/**
 * @file Logger.hpp
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 13, 2013
 * @brief Contains the @c Tator::Yam::Logger class
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

// Include the required standard library headers
#include <iostream>
#include <map>
#include <string>

// Include the required Yam headers
#include <Yam/LogFormat.hpp>
#include <Yam/LogLevel.hpp>

namespace Tator {
namespace Yam {

/**
 * A class for formatting and directing log messages
 * @tparam Format the class that is used for formatting log messages
 * Usage Example
 */
template<class Format = LogFormat>
class Logger {
public:

	/**
	 * Constructs a @c Logger with the default settings
	 */
	Logger();

	/**
	 * Constructs a @c Logger with a custom @c LogFormat
	 * @param logFormat the custom @c LogFormat
	 */
	Logger(const Format& logFormat);

	/**
	 * Constructs a @c Logger with an @c ostream
	 * @param outputStream the output stream
	 * @param logLevel the log levels that the output stream receives
	 */
	Logger(std::ostream* outputStream, int logLevel);

	/**
	 * Constructs A @c Logger with a custom @c LogFormat and an @c ostream
	 * @param logFormat the custom @c LogFormat
	 * @param outputStream the output stream
	 * @param logLevel the log levels that the output stream receives
	 */
	Logger(const Format& logFormat, std::ostream* outputStream, int logLevel);

	/**
	 * Registers an @c ostream with the @c Logger
	 * @param outputStream a pointer to the @c ostream to register
	 * @param logLevels the log levels that will be outputed to this @c ostream
	 * @warning When the @c Logger is destroyed, any @c ostream s that are added
	 * will not be destroyed. You must destoy the @c ostream yourself to prevent
	 * memory leaks
	 */
	void RegisterLogger(std::ostream* outputStream, int logLevels);

	/**
	 * Unregisters an @c ostream with the @c Logger
	 * @param outputStream a pointer to the @c ostream to unregister
	 * @return true if an @c ostream to unregister was found, false if not
	 */
	bool UnregisterLogger(std::ostream* outputStream);

	/**
	 * Logs a value as the specified @c LogLevel
	 * @param logLevel the @c LogLevel to log as
	 * @param value the value to log
	 * @param name the name of the value to log, or an empty string if no name
	 * @tparam T the type of the value to log
	 */
	template<typename T>
	inline void Log(int logLevel, T value, const std::string& name = "");

	/**
	 * Logs a value as a debug message
	 * @param value the value to log
	 * @param name the name of the value to log, or an empty stream if no name
	 */
	template<typename T>
	inline void Debug(T value, const std::string& name = "");

	/**
	 * Logs a value as an info message
	 * @param value the value to log
	 * @param name the name of the value to log, or an empty stream if no name
	 */
	template<typename T>
	inline void Info(T value, const std::string& name = "");

	/**
	 * Logs a value as a warning message
	 * @param value the value to log
	 * @param name the name of the value to log, or an empty stream if no name
	 */
	template<typename T>
	inline void Warn(T value, const std::string& name = "");

	/**
	 * Logs a value as an error message
	 * @param value the value to log
	 * @param name the name of the value to log, or an empty stream if no name
	 */
	template<typename T>
	inline void Error(T value, const std::string& name = "");

	/**
	 * Logs a raw string with the specified @c LogLevel
	 * @param logLevel the @c LogLevel
	 * @param string the string
	 */
	void LogRaw(int logLevel, const std::string& string);

	/**
	 * Formats a variable with a name
	 * @param name the name of the variable
	 * @param value the value of the variable
	 * @return
	 */
	template<typename T>
	const std::string Var(const std::string& name, T value);

private:
	std::map<std::ostream*, int> m_loggerOutputs; //!< The map of @c ostream s to output to
	const Format m_logFormat; //!< The @c LogFormat to use to format log messages
};

}  // namespace Yam
}  // namespace Tator

#include <Yam/Logger.inl>

#endif /* LOGGER_HPP */
