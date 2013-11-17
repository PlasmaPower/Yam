/**
 * @file File.cpp
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 13, 2013
 * @brief An example showing logging to multiple @c ostream s, with different log levels
 */

#include <iostream>
#include <fstream>

#include <Yam/Logger.hpp>

int main(int argc, char **argv) {
	// Create and open a file
	std::ofstream file;
	file.open("log", std::ofstream::out | std::ofstream::app);

	// Create the logger
	Tator::Yam::Logger<> log;

	// Register a file stream, cout, and cerr for logging
	log.RegisterLogger(&std::cout, Tator::Yam::INFO | Tator::Yam::WARN);
	log.RegisterLogger(&std::cerr, Tator::Yam::ERROR);
	log.RegisterLogger(&file, Tator::Yam::ALL);

	log.Debug("This is a debug message.");
	log.Info("This is an info message.");
	log.Warn("This is a warning message.");
	log.Error("This is an error message.");
}

/**
 * @example Multiple.cpp
 */
