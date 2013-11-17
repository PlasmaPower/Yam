/**
 * @file Basic.cpp
 * @author Alex Mikhalev (alexmikhalevalex@gmail.com)
 * @date November 13, 2013
 * @brief A basic example showing logging to the standard output stream
 */

#include <iostream>
#include <fstream>

#include <Yam/Logger.hpp>

int main(int argc, char **argv) {
	// Create the logger
	Tator::Yam::Logger<> log;

	// Register cout to receive all log messages
	log.RegisterLogger(&std::cout, Tator::Yam::ALL);

	log.Debug("This is a debug message.");
	log.Info("This is an info message.");
	log.Warn("This is a warning message.");
	log.Error("This is an error message.");
}
 /**
  * @example Basic.cpp
  */
