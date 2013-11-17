/**
 * @file LogLevel.hpp
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 16, 2013
 * @brief Contains the enum @c Tator::Yam::LogLevel
 */

#ifndef LOGLEVEL_HPP
#define LOGLEVEL_HPP

namespace Tator {
namespace Yam {

/**
 * An enum with the log levels for the @c Logger
 */
enum LogLevel {
	NONE = 0,                        //!< NONE Print to no outputs
	DEBUG = 1 << 0,                  //!< DEBUG A debug message
	INFO = 1 << 1,                   //!< INFO An info message
	WARN = 1 << 2,                   //!< WARN A warning message
	ERROR = 1 << 3,                  //!< ERROR An error message
	ALL = DEBUG | INFO | WARN | ERROR//!< ALL Print to all outputs
};

}  // namespace Yam
}  // namespace Tator

#endif /* LOGLEVEL_HPP */
